#include "ft_push_swap.h"

void	swap_fct(t_list **stack_a, t_list **stack_b, t_list *command)
{
	if (!ft_strcmp(command->command, "sa"))
		swap_a(stack_a);
	else if (!ft_strcmp(command->command, "sb"))
		swap_b(stack_b);
	else if (!ft_strcmp(command->command, "ss"))
		swap_them(stack_a, stack_b);
}

void	push_fct(t_list **stack_a, t_list **stack_b, t_list *command)
{
	if (!ft_strcmp(command->command, "pa"))
		push_to_a(stack_b, stack_a);
	else if (!ft_strcmp(command->command, "pb"))
		push_to_b(stack_a, stack_b);
}

void	rotate_fct(t_list **stack_a, t_list **stack_b, t_list *command)
{
	if (!ft_strcmp(command->command, "ra"))
		rotate_a(stack_a);
	if (!ft_strcmp(command->command, "rb"))
		rotate_b(stack_b);
	if (!ft_strcmp(command->command, "rr"))
		rotate_rr(stack_a, stack_b);
}

void	rev_rotate_fct(t_list **stack_a, t_list **stack_b, t_list *command)
{
	if (!ft_strcmp(command->command, "rra"))
		reverse_rotate_a(stack_a);
	if (!ft_strcmp(command->command, "rrb"))
		reverse_rotate_b(stack_b);
	if (!ft_strcmp(command->command, "rrr"))
		reverse_rrr(stack_a, stack_b);
}
