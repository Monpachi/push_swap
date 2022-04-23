#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"
# include "ft_utils.h"

void	ft_read_command(t_list **stack_a, t_list **stack_b);
void	checker(t_list *stack_a, t_list *stack_b);
void	exit_success(t_list *stack_a);
void	if_swap(t_list **stack_a, t_list **stack_b, char *line);
void	if_push(t_list **stack_a, t_list **stack_b, char *line);
void	if_rotate(t_list **stack_a, t_list **stack_b, char *line);
void	if_reverse(t_list **stack_a, t_list **stack_b, char *line);
void	ch_push_to_b(t_list **stack_a, t_list **stack_b);
void	ch_push_to_a(t_list **stack_b, t_list **stack_a);
void	ch_swap_a(t_list **stack_a);
void	ch_swap_b(t_list **stack_b);
void	ch_swap_them(t_list **stack_a, t_list **stack_b);
void	ch_rotate_a(t_list **stack);
void	ch_rotate_b(t_list **stack);
void	ch_rotate_rr(t_list **stack_a, t_list **stack_b);
void	ch_reverse_rotate_a(t_list **stack);
void	ch_reverse_rotate_b(t_list **stack);
void	ch_reverse_rrr(t_list **stack_a, t_list **stack_b);
int		ft_strcmp(char *s1, char *s2);

#endif
