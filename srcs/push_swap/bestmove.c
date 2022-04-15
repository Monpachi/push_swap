/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:52 by vchan             #+#    #+#             */
/*   Updated: 2022/04/15 18:59:59 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//Deplacement de la la stack
void	move_a(t_list **stack_a, int i)
{
	int		k;
	t_list	*tmp;
	int		j;

	tmp = *stack_a;
	k = strlenlistparam(*stack_a);
	if (i <= k / 2)
		j = i;
	else if (i > k / 2)
		j = k - i;
	while (tmp && j > 0)
	{
		if (i <= k / 2)
		{
			rotate_a(stack_a);
			j--;
		}
		if (i > k / 2)
		{
			reverse_rotate_a(stack_a);
			j--;
		}
	}
	return ;
}

void	move_b(t_list **stack_b, int i)
{
	int		k;
	t_list	*tmp;
	int		j;

	tmp = *stack_b;
	k = strlenlistparam(*stack_b);
	if (i <= k / 2)
		j = i;
	else if (i > k / 2)
		j = k - i;
	while (tmp && j > 0)
	{
		if (i <= k / 2)
		{
			rotate_b(stack_b);
			j--;
		}
		if (i > k / 2)
		{
			reverse_rotate_b(stack_b);
			j--;
		}
	}
	return ;
}

void	if_double(t_list **stack_a, t_list **stack_b, int pos)
{
	int	i;

	i = algoplus(stack_a, get_to_b(stack_b, pos));
	if (if_both_rr(stack_a, i) && if_both_rr(stack_b, pos))
		both_ra(stack_a, stack_b, pos, i);
	else if (if_both_rrr(stack_a, i) && if_both_rrr(stack_b, pos))
		both_rrr(stack_a, stack_b, pos, i);
	return ;
}

void	if_not_double(t_list **stack_a, t_list **stack_b, int pos)
{
	int	i;

	i = algoplus(stack_a, get_to_b(stack_b, pos));
	move_b(stack_b, pos);
	i = algoplus(stack_a, (*stack_b)->number);
	move_a(stack_a, i);
	push_to_a(stack_b, stack_a);
}

void	bestmove(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		pos;

	while (stack_b)
	{
		pos = get_the_best(stack_a, stack_b);
		i = algoplus(stack_a, get_to_b(stack_b, pos));
		if ((if_both_rr(stack_a, i) && if_both_rr(stack_b, pos))
			|| (if_both_rrr(stack_a, i) && if_both_rrr(stack_b, pos)))
			if_double(stack_a, stack_b, pos);
		else
			if_not_double(stack_a, stack_b, pos);
		if ((*stack_b)->next == NULL)
		{
			i = algoplus(stack_a, (*stack_b)->number);
			move_a(stack_a, i);
			push_to_a(stack_b, stack_a);
			return ;
		}
	}
	return ;
}
