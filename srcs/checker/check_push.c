#include "ft_push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return ;
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	return ;
}

void	push_to_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	return ;
}
