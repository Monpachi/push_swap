#include "ft_push_swap.h"

int	check_sort(t_list *stack_a)
{
	int		number;
	t_list	*tmp;
	int		this;
	int		the_next;

	tmp = stack_a;
	while (tmp->next)
	{
		this = tmp->number;
		number = this;
		the_next = tmp->next->number;
		if (number > the_next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
