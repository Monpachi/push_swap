#include "ft_push_swap.h"

void	checker(t_list **stack_a, t_list **stack_b, t_list *commands, int argc)
{
	char	*ret;

	ret = 0;
	if (ft_read_command(commands) == -1)
	{
		exit_failure(stack_a, stack_b, commands);
	}
	use_commands(commands, stack_a, stack_b);
	checker_sort(argc, stack_a);
}

int	main(int argc char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*commands;
	char	**str;

	i = 1;
	stack_b = NULL;
	commands = ft_lstnew(NULL);
	if (argc < 2)
		exit_success(*stack_a, *stack_b, commands);
	else
	{
		if (check_parsing2(argc, argv) == 1)
			exit_failure(*stack_a, *stack_b commands);
		stack_a = newstack(str);
	}
	checker(stack_a, stack_b, commands, argc);
	exit_success(*stack_a, *stack_b, commands);
}
