/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo_for3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:13 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:05:13 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	to_sort3(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while ((tmp->next) && (strlenlistparam((*stack_a)) >= 4))
	{
		if (tmp->number < tmp->next->number)
		{
			push_to_b(stack_a, stack_b);
			tmp = *stack_a;
		}
		if (tmp->number > tmp->next->number)
		{
			rotate_a(stack_a);
			tmp = *stack_a;
		}
	}
	return ;
}

void	algo3_superior_inferior(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = tmp->next;
	if (((*stack_a)->number > tmp->number)
		&& ((*stack_a)->number < tmp->next->number))
	{
		swap_a(stack_a);
		return ;
	}
	return ;
}

void	algo3_onlysup(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = tmp->next;
	if ((*stack_a)->number > tmp->number)
	{
		rotate_a(stack_a);
		if ((*stack_a)->number > tmp->next->number)
			swap_a(stack_a);
		return ;
	}
	return ;
}

void	algo3_inf_sup(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = tmp->next;
	if (((*stack_a)->number < tmp->number)
		&& ((*stack_a)->number > tmp->next->number))
		reverse_rotate_a(stack_a);
	return ;
}

void	algo3_biginf_inf(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = tmp->next;
	if (((*stack_a)->number < tmp->number)
		&& (tmp->number > tmp->next->number))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	return ;
}
