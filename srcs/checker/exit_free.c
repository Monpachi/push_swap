#include "ft_push_swap.h"
#include "stdio.h"

void	free_all(t_list **stack_a, t_list **stack_b, t_list *commands)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	ft_lstclear(&commands);
}

void	exit_failure(t_list **stack_a, t_list **stack_b, t_list *commands)
{
	ft_putstr_fd("\033[1;31mError\n\033[0;m", 1);
	free_all(stack_a, stack_b, commands);
	exit(EXIT_FAILURE);
}

void	exit_success(t_list **stack_a, t_list **stack_b, t_list *commands)
{
	free_all(stack_a, stack_b, commands);
	write (1, "ok\n", 3);
	ft_putstr_fd("ok\n", 1);
	exit(EXIT_SUCCESS);
}
