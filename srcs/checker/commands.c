#include "ft_push_swap.h"

void	use_commands(t_list	*commands, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = commands->next;
	while (tmp)
	{
		swap_fct(stack_a, stack_b, tmp);
		push_fct(stack_a, stack_b, tmp);
		rotate_fct(stack_a, stack_b, tmp);
		rev_rotate_fct(stack_a, stack_b, tmp);
		tmp = tmp->next;
	}
	return ;
}

int	ft_read_command(t_list *commands)
{
	char	*ret;

	ret = 0;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO);
		if (!ft_strcmp(ret, "sa") || !ft_strcmp(ret, "sb")
			|| !ft_strcmp(ret, "ss"))
			get_swap(commands, ret);
		else if (!ft_strcmp(ret, "pa") || !ft_strcmp(ret, "pb"))
			get_push(commands, ret);
		else if (!ft_strcmp(ret, "ra") || !ft_strcmp(ret, "rb")
			|| !ft_strcmp(ret, "rr"))
			get_rotate(commands, ret);
		else if (!ft_strcmp(ret, "rra")
			|| !ft_strcmp(ret, "rrb") || !ft_strcmp(ret, "rrr"))
			get_rev_rotate(commands, ret);
		else
		{
			free(ret);
			return (-1);
		}
		free(ret);
	}
	return (0);
}
