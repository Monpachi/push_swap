#!/usr/bin/env python3


from tkinter import *
import sys, getopt, random
import subprocess
import os


"""
__project__ = "push_swap visualizer"
__author__ = "Emmanuel Ruaud"
__email__ = "eruaud@student.le-101.fr"
This python script was created to visualize your work with the PUSH_SWAP
42 Project.
You must put this script in the same path or in a sibling path of your program
Of course you need Python3 with the builtin Tkinter.
You can install it with Brew.
--> Brew install python3
Execute the script with :
--> python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
You can change the PUSHS_PATH to get to the relative path of your push_swap
You can decrease or increase the speed with the matching buttons.
"""


RELATIVE_PATH = r'push_swap'


class PsGui:
    def __init__(self, master, stack_size, continuous, push_swap):
        self.ww = 600
        self.wh = 600

        self.master = master
        self.stack_size = stack_size
        self.stack_opts = [3, 5, 10, 20, 50, 100, 500]
        if self.stack_size not in self.stack_opts:
            self.stack_opts = [self.stack_size] + self.stack_opts
        self.continuous = continuous
        self.push_swap = push_swap

        self.create_vars()

        self.master.title("Push_swap viewer")

        self.menuframe = Frame(self.master)
        self.menuframe.pack(side=TOP, fill=X)

        self.settings_frame = Frame(self.menuframe)
        self.settings_frame.pack(side=LEFT, fill=Y)
        self.stack_size_ctl = OptionMenu(self.settings_frame, self.stack_size, *self.stack_opts)
        self.stack_size_ctl.pack(side=LEFT)
        self.new_stack_ctl = Button(self.settings_frame, text="New Stack", command=self.create_new_stack)
        self.new_stack_ctl.pack(side=LEFT)

        self.butframe = Frame(self.menuframe)
        self.butframe.pack(side=RIGHT, fill=Y)
        self.speedscale_label = Label(self.butframe, text='Speed: ', font=("monospace", 10))
        self.speedscale_label.pack(side=LEFT)
        self.speedscale = Scale(self.butframe, from_=10.5, to=0, showvalue=0, resolution=0.1, orient=HORIZONTAL, variable=self.speed)
        self.speedscale.pack(side=LEFT)
        self.PrevCtl = Button(self.butframe, text="-1◀", command=lambda: self.do_one_cmd_reverse(self.i.get() -1))
        self.PrevCtl.pack(side=LEFT)
        self.NextCtl = Button(self.butframe, text="▶+1", command=lambda: self.do_one_cmd(self.i.get()))
        self.NextCtl.pack(side=LEFT)
        self.PauseCtl = Button(self.butframe, text="▶", command=self.pause_toggle)
        self.PauseCtl.pack(side=LEFT)
        self.ResetCtl = Button(self.butframe, text="↺ Reset", command=self.reset)
        self.ResetCtl.pack(side=LEFT)
        self.clear_ctl = Button(self.butframe, text="Clear", command=self.clear_cmds)
        self.clear_ctl.pack(side=LEFT)

        self.mainframe = Frame(self.master)
        self.mainframe.pack(fill=BOTH, expand=True)
        self.can = Canvas(self.mainframe, width=self.ww, height=self.wh, bg="black")
        self.can.pack(side=LEFT, expand=True, fill=BOTH)
        self.can.bind("<Configure>", self.resize)

        self.toolframe = Frame(self.mainframe)
        self.toolframe.pack(side=RIGHT, fill=BOTH)

        self.create_cmds_panel()
        self.create_status_frame()
        #action list
        self.listbox = Listbox(self.toolframe, bg='black', fg='light cyan',
                               font=("monospace", 12), relief=FLAT)
        self.listbox.pack(side=LEFT, fill=BOTH, expand=1)
        self.scrollbar = Scrollbar(self.toolframe, command=self.listbox.yview)
        self.scrollbar.pack(side=RIGHT, fill=BOTH)
        for cmd in self.cmds:
            self.listbox.insert(END, cmd)
        self.listbox.config(yscrollcommand=self.scrollbar.set)

        self.define_event_listeners()
        self.draw_rectangles()

    def create_vars(self):
        self.i = IntVar(self.master, 0)
        self.i_prev = 0
        self.i_count = 0
        self.pause = IntVar(self.master, 1)
        self.speed = DoubleVar(self.master, 5.7)
        self.stack_size = IntVar(self.master, self.stack_size)
        self.create_stack()
        self.create_move_list()
        self.total_count_var = IntVar(self.master, len(self.cmds))
        if self.total_count_var.get() != 0:
            self.i_count = 0
        #if len(self.pile_a) != 0:
        #    self.speed.set() = 1 / len(self.pile_a)
        #    self.prespeed = 100
        #else:
        #    self.prespeed = -1

    def create_stack(self):
        self.generate_nblist(self.stack_size.get())
        self.first_pile = self.pile_a[:]
        self.pile_b = []

    def create_move_list(self):
        if self.push_swap == "":
            dirname = os.path.dirname(os.path.abspath(__file__))
            PUSHS_PATH = os.path.join(dirname, RELATIVE_PATH)
        else:
            PUSHS_PATH = self.push_swap
        try:
            self.cmds = subprocess.run([PUSHS_PATH] + self.argv, stdout=subprocess.PIPE,
                    stderr=subprocess.STDOUT, text=True, timeout=12).stdout.splitlines()
        except FileNotFoundError:
            self.cmds = []

    def generate_nblist(self, stack_size):
        if self.continuous:
            up = (stack_size // 2) + (stack_size % 2)
            down = (stack_size // 2)
            self.pile_a = random.sample(range(-down,up), stack_size)
        else:
            self.pile_a = random.sample(range(-stack_size,stack_size), stack_size)
        self.argv = [str(int) for int in self.pile_a]
        print(' '.join(self.argv))

    def create_new_stack(self):
        print('==== New Stack ====')
        self.pause.set(1)
        self.i.set(0)
        #self.i_count = 0
        del self.pile_a[:]
        del self.pile_b[:]
        del self.first_pile[:]
        self.generate_nblist(self.stack_size.get())
        self.first_pile = self.pile_a[:]
        self.can.delete("all")
        del self.cmds[:]
        self.listbox.delete(0, END)
        self.create_move_list()
        self.total_count_var.set(len(self.cmds))
        if self.total_count_var.get() != 0:
            self.i_count = 0
        for cmd in self.cmds:
            self.listbox.insert(END, cmd)
        self.draw_rectangles()

    def define_event_listeners(self):
        self.master.bind("<space>", self.pause_toggle)
        self.i.trace('w', self.total_count_updt)
        self.total_count_var.trace('w', self.total_count_updt)
        self.pause.trace('w', self.pause_updt)
        self.speed.trace('w', self.speed_updt)

    def pause_updt(self, *args):
        if self.pause.get() == 1:
            self.PauseCtl.config(text='▶')
        else:
            self.PauseCtl.config(text='||')

    def speed_updt(self, *args):
        self.speedmeter.config(text='frame rate = ' + str(self.calc_speed()) + 'ms/move')

    def calc_speed(self):
        return round(2**self.speed.get()) - 1

    def create_cmds_panel(self):
        # swap
        self.swap_frame = Frame(self.toolframe)
        self.swap_frame.pack(side=TOP, fill=Y)
        self.swap_a_ctl = Button(self.swap_frame, text="sa", command=lambda: self.add_cmd('sa'))
        self.swap_a_ctl.pack(side=LEFT)
        self.swap_b_ctl = Button(self.swap_frame, text="sb", command=lambda: self.add_cmd('sb'))
        self.swap_b_ctl.pack(side=LEFT)
        self.swap_ab_ctl = Button(self.swap_frame, text="ss", command=lambda: self.add_cmd('ss'))
        self.swap_ab_ctl.pack(side=LEFT)
        #push
        self.push_frame = Frame(self.toolframe)
        self.push_frame.pack(side=TOP, fill=Y)
        self.push_a_ctl = Button(self.push_frame, text="pa", command=lambda: self.add_cmd('pa'))
        self.push_a_ctl.pack(side=LEFT)
        self.push_b_ctl = Button(self.push_frame, text="pb", command=lambda: self.add_cmd('pb'))
        self.push_b_ctl.pack(side=LEFT)
        #rotate
        self.rotate_frame = Frame(self.toolframe)
        self.rotate_frame.pack(side=TOP, fill=Y)
        self.rotate_a_ctl = Button(self.rotate_frame, text="ra", command=lambda: self.add_cmd('ra'))
        self.rotate_a_ctl.pack(side=LEFT)
        self.rotate_b_ctl = Button(self.rotate_frame, text="rb", command=lambda: self.add_cmd('rb'))
        self.rotate_b_ctl.pack(side=LEFT)
        self.rotate_ab_ctl = Button(self.rotate_frame, text="rr", command=lambda: self.add_cmd('rr'))
        self.rotate_ab_ctl.pack(side=LEFT)
        #rev rotate
        self.revrotate_frame = Frame(self.toolframe)
        self.revrotate_frame.pack(side=TOP, fill=Y)
        self.revrotate_a_ctl = Button(self.revrotate_frame, text="rra", command=lambda: self.add_cmd('rra'))
        self.revrotate_a_ctl.pack(side=LEFT)
        self.revrotate_b_ctl = Button(self.revrotate_frame, text="rrb", command=lambda: self.add_cmd('rrb'))
        self.revrotate_b_ctl.pack(side=LEFT)
        self.revrotate_ab_ctl = Button(self.revrotate_frame, text="rrr", command=lambda: self.add_cmd('rrr'))
        self.revrotate_ab_ctl.pack(side=LEFT)

    def create_status_frame(self):
        self.status_frame = Frame(self.master)
        self.status_frame.pack(side=TOP, fill=X)
        self.speedmeter = Label(self.status_frame,
                                text='frame rate = ' + str(self.calc_speed()) + 'ms/move',
                                font=("monospace", 10))
        self.speedmeter.pack(side=LEFT)
        self.total_count = Label(self.status_frame,
                                text='- operations = ' + str(self.i_count) + '/' + str(self.total_count_var.get()),
                                font=("monospace", 10))
        self.total_count.pack(side=LEFT)

    def total_count_updt(self, *args):
        if self.i_prev != self.i.get():
            if self.i.get() >= 0 and self.i.get() < self.total_count_var.get():
                if self.i_prev < self.i.get() and self.i.get() > 0:
                    self.listbox.selection_clear(0, self.i.get() - 1)
                    self.listbox.activate(self.i.get() -1)
                    self.listbox.selection_set(self.i.get() -1)
                    self.listbox.see(self.i.get() -1)
                elif self.i_prev > self.i.get():
                    self.listbox.selection_clear(self.i.get(), END)
                    self.listbox.activate(self.i.get())
                    self.listbox.selection_set(self.i.get())
                    self.listbox.see(self.i.get())
                elif self.i.get() == 0:
                    self.listbox.selection_clear(self.i.get(), END)
            #self.listbox.activate(self.i.get())
            #self.listbox.selection_set(self.i.get())
            #self.listbox.see(self.i.get())
            self.i_count = self.i.get()
            self.i_prev = self.i.get()
            #if self.i_count == self.total_count_var.get():
                #self.listbox.selection_clear(0, END)
                #self.pause.set(1)
        self.total_count.config(text='- operations = ' + str(self.i_count) + '/' + str(self.total_count_var.get()))

    def reset(self):
        self.pause.set(1)
        self.listbox.see(0)
        self.listbox.selection_clear(0, END)
        self.i.set(0)
        self.i_prev = 0
        del self.pile_a[:]
        self.pile_a = self.first_pile[:]
        del self.pile_b[:]
        self.can.delete("all")
        self.draw_rectangles()
        

    def pause_toggle(self, *e):
        if self.pause.get() == 0:
            self.pause.set(1)
        elif self.total_count_var.get() != 0 and self.i.get() < self.total_count_var.get():
            self.pause.set(0)
            self.launch()

    def add_cmd(self, cmd):
        curpos = self.listbox.curselection()
        if curpos:
            cmd_pos = curpos[0]+1
        else:
            cmd_pos = self.total_count_var.get()
        self.listbox.insert(cmd_pos, cmd)
        self.cmds.insert(cmd_pos, cmd)
        self.total_count_var.set(len(self.cmds))
        self.listbox.see(cmd_pos)
        if self.pause.get() == 1 and self.i.get() == cmd_pos:
            self.do_one_cmd(cmd_pos)

    def clear_cmds(self):
        del self.cmds[:]
        self.total_count_var.set(len(self.cmds))
        self.listbox.delete(0, END)
        self.reset()

    def launch_reverse_cmds(self,cmd):
        if cmd == 'sa':
            return self.launch_cmds('sa')
        if cmd == 'sb':
            return self.launch_cmds('sb')
        if cmd == 'ss':
            return self.launch_cmds('ss')
        if cmd == 'ra':
            return self.launch_cmds('rra')
        if cmd == 'rb':
            return self.launch_cmds('rrb')
        if cmd == 'rr':
            return self.launch_cmds('rrr')
        if cmd == 'rra':
            return self.launch_cmds('ra')
        if cmd == 'rrb':
            return self.launch_cmds('rb')
        if cmd == 'rrr':
            return self.launch_cmds('rr')
        if cmd == 'pa':
            return self.launch_cmds('pb')
        if cmd == 'pb':
            return self.launch_cmds('pa')

    def launch_cmds(self, cmd):
        if cmd == 'sa' and len(self.pile_a) >= 2:
            self.pile_a[0], self.pile_a[1] = self.pile_a[1], self.pile_a[0]
        if cmd == 'sb' and len(self.pile_b) >= 2:
            self.pile_b[0], self.pile_b[1] = self.pile_b[1], self.pile_b[0]
        if cmd == 'ss':
            if (len(self.pile_a) >= 2):
                self.pile_a[0], self.pile_a[1] = self.pile_a[1], self.pile_a[0]
            if (len(self.pile_b) >= 2):
                self.pile_b[0], self.pile_b[1] = self.pile_b[1], self.pile_b[0]
        if cmd == 'ra' and len(self.pile_a) >= 2:
            self.pile_a.append(self.pile_a[0])
            del self.pile_a[0]
        if cmd == 'rb' and len(self.pile_b) >= 2:
            self.pile_b.append(self.pile_b[0])
            del self.pile_b[0]
        if cmd == 'rr':
            if (len(self.pile_a) >= 2):
                self.pile_a.append(self.pile_a[0])
                del self.pile_a[0]
            if (len(self.pile_b) >= 2):
                self.pile_b.append(self.pile_b[0])
                del self.pile_b[0]
        if cmd == 'rra' and len(self.pile_a) >= 2:
            self.pile_a = [self.pile_a[-1]] + self.pile_a
            del self.pile_a[-1]
        if cmd == 'rrb' and len(self.pile_b) >= 2:
            self.pile_b = [self.pile_b[-1]] + self.pile_b
            del self.pile_b[-1]
        if cmd == 'rrr':
            if (len(self.pile_a) >= 2):
                self.pile_a = [self.pile_a[-1]] + self.pile_a
                del self.pile_a[-1]
            if (len(self.pile_b) >= 2):
                self.pile_b = [self.pile_b[-1]] + self.pile_b
                del self.pile_b[-1]
        if cmd == 'pa' and len(self.pile_b) >= 1:
            self.pile_a = [self.pile_b[0]] + self.pile_a
            del self.pile_b[0]
        if cmd == 'pb' and len(self.pile_a) >= 1:
            self.pile_b = [self.pile_a[0]] + self.pile_b
            del self.pile_a[0]
        return self.pile_a, self.pile_b

    def set_color(self, index):
        col = '#%02x%02x%02x' % (int(255 * (index - 0.3) * (index > 0.3)),
                                 int(255 * index
                                     - ((510 * (index - 0.6)) * (index > 0.6))),
                                 int((255 - 510 * index) * (index < 0.5)))
        return col

    def draw_rectangles(self):
        vi = 0
        ww = self.ww
        wh = self.wh
        hw = ww / 2
        hm = len(self.pile_a) + len(self.pile_b)
        mx, mn = (0, 0)
        if (hm != 0):
            mx = max(self.pile_a + self.pile_b)
            mn = min(self.pile_a + self.pile_b)
        rects = []
        if len(self.pile_a) > 0:
            a_val = [(num - mn) / ((mx - mn) + 1) for num in self.pile_a]
            for vala in a_val:
                rects.append(self.can.create_rectangle(0, vi,
                                                       10 + vala * (hw - (hw/3)), vi + wh / hm,
                                                       fill=self.set_color(vala), outline=""))
                vi += wh / hm
        vi = 0
        if len(self.pile_b) > 0:
            b_val = [(num - mn) / ((mx - mn) + 1) for num in self.pile_b]
            for valb in b_val:
                rects.append(self.can.create_rectangle(hw, vi,
                                                       hw + 10 + valb * (hw - (hw/3)), vi + wh / hm,
                                                       fill=self.set_color(valb), outline=""))
                vi += wh / hm

    def resize(self, event):
        self.ww = event.width
        self.wh = event.height
        self.can.delete("all")
        self.draw_rectangles()
        self.can.update()

    def do_one_cmd(self, cmd_pos):
        #print(self.i_count)
        #print(cmd_pos)
        if cmd_pos < self.total_count_var.get():
            self.can.delete("all")
            self.pile_a, self.pile_b = \
                self.launch_cmds(self.cmds[cmd_pos])
            self.draw_rectangles()
            self.i.set(cmd_pos + 1)
            self.can.update()

    def do_one_cmd_reverse(self, cmd_pos):
        #print(self.i_count)
        #print(cmd_pos)
        if cmd_pos >= 0:
            self.can.delete("all")
            self.pile_a, self.pile_b = \
                self.launch_reverse_cmds(self.cmds[cmd_pos])
            self.draw_rectangles()
            self.i.set(cmd_pos)
            self.can.update()

    def launch(self):
        if self.i.get() < self.total_count_var.get():
            if self.pause.get() == 0:
                self.do_one_cmd(self.i.get())
                if self.i.get() == self.total_count_var.get():
                    self.pause.set(1)
                else:
                    self.can.after(self.calc_speed(), self.launch)
                

def print_usage_exit(status):
    print('python3 pyviz.py [-c] [-s <stack_size>] [-p <push_swap_path>]\n')
    print(' -h, --help')
    print('     Print this help dialog\n')
    print(' -c, --continuous')
    print('     The number generated are folowing each other with a "1" increment.')
    print('      $ python3 pyviz.py -c -s 4')
    print('     Will generate for example the sequence: 0 -1 2 1\n')
    print(' -s, --stack-size <Integer>')
    print('     The size of the random stack of number (ex: 3 or 5 or 100 or 500)')
    print('     If not specified, this script will generate a 100 numbers stack by default.')
    print('      $ python3 pyviz.py -s 4')
    print('     Will generate for example the sequence: 1 0 -3 -2\n')
    print(' -p, --push-swap <Path>')
    print('     The absolute or relative path to your push_swap binary')
    sys.exit(status)

def main(argv):
    stack_size = 100
    push_swap = ""
    continuous = False
    try:
        opts, args = getopt.getopt(argv,"hcs:p:",["help","continous","stack-size=","push-swap="])
    except getopt.GetoptError:
        print_usage_exit(2)
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print_usage_exit()
        elif opt in ("-c", "--continuous"):
            continuous = True
        elif opt in ("-s", "--stack-size"):
            try:
                stack_size = int(arg)
                if stack_size < 0:
                    print_usage_exit(0)
            except ValueError:
                print_usage_exit(2)
        elif opt in ("-p", "--push-swap"):
            push_swap = arg
    root = Tk()
    root.resizable(width=True, height=True)
    gui = PsGui(root, stack_size, continuous, push_swap)
    root.mainloop()

if __name__ == "__main__":
    main(sys.argv[1:])
