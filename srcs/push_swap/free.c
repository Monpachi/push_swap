#include "ft_push_swap.h"

void	ft_lstclear(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack);
			*stack = (*stack)->next;
			free(tmp);
		}
	}
	return ;
}
