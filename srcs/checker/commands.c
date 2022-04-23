#include "ft_checker.h"

void	not_command(char *line)
{
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n") || !ft_strcmp(line, "ra\n")
		|| !ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n")
		|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n") || !ft_strcmp(line, "pa\n")
		|| !ft_strcmp(line, "pb\n"))
		return ;
	else
	{
		free(line);
		exit_failure("Error\n");
	}
}

void	ft_read_command(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line && *line != '\0')
	{
		not_command(line);
		if_swap(stack_a, stack_b, line);
		if_push(stack_a, stack_b, line);
		if_reverse(stack_a, stack_b, line);
		if_rotate(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free (line);
	return ;
}
