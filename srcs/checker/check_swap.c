#include "ft_push_swap.h"

void	swap(t_list **pile)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	if (strlenlist(*pile) > 2)
	{
		tmp3 = (*pile)->next->next;
		tmp2 = (*pile)->next;
		tmp = *pile;
		*pile = tmp2;
		(*pile)->next = tmp;
		(*pile)->next->next = tmp3;
	}
	return ;
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
}

void	swap_them(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return ;
}
