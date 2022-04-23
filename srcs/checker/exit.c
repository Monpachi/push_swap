#include "ft_checker.h"

void	exit_success(t_list *stack_a)
{
	ft_lstclear(&stack_a);
	ft_putstr_fd("\033[1;32mOK\n", 1);
	exit (EXIT_SUCCESS);
}
