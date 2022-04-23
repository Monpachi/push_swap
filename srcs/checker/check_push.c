#include "ft_checker.h"

void	ch_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return ;
}

void	ch_push_to_b(t_list **stack_a, t_list **stack_b)
{
	ch_push(stack_a, stack_b);
	return ;
}

void	ch_push_to_a(t_list **stack_b, t_list **stack_a)
{
	if(!*stack_b)
		return ;
	ch_push(stack_b, stack_a);
	return ;
}
