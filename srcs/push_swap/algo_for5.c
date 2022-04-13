/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:28 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:05:28 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	algo5_inf(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	tmp2 = *stack_b;
	while (tmp2)
	{
		if (tmp2->number < tmp2->next->number)
		{
			swap_b(stack_b);
			push_to_a(stack_b, stack_a);
		}
		if ((*stack_a)->number > tmp->number)
		{
			swap_a(stack_a);
		}
		return ;
	}
}

void	algo5_onlysup(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	tmp2 = *stack_b;
	while (stack_b)
	{
		if (tmp2->number > tmp2->next->number)
		{
			if (tmp2->number > tmp->number && tmp2->number > tmp->next->number)
			{
				reverse_rotate_a(stack_a);
				push_to_a(stack_b, stack_a);
				rotate_a(stack_a);
				rotate_a(stack_a);
			}
			push_to_a(stack_b, stack_a);
			tmp = (*stack_a)->next;
		}
		if ((*stack_a)->number > tmp->number)
			swap_a(stack_a);
		return ;
	}
	return ;
}
