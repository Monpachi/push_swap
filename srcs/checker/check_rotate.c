#include "ft_checker.h"

void	ch_rotate(t_list **stack)
{
	t_list	*tmp;

	if (strlenlist(*stack) > 2)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
	}
}

void	ch_rotate_a(t_list **stack)
{
	ch_rotate(stack);
}

void	ch_rotate_b(t_list **stack)
{
	ch_rotate(stack);
}

void	ch_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	ch_rotate(stack_a);
	ch_rotate(stack_b);
}
