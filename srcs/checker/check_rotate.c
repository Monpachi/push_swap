#include "ft_push_swap.h"
/**
 * Rotate le premier qui va en bas
 */
void	rotate(t_list **stack)
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

void	rotate_a(t_list **stack)
{
	rotate(stack);
}

void	rotate_b(t_list **stack)
{
	rotate(stack);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
