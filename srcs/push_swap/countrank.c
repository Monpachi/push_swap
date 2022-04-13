/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countrank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:55 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:07:56 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	rankmin(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = (*stack_a)->next;
	i = (*stack_a)->number;
	while (tmp)
	{
		if (i > tmp->number)
			i = tmp->number;
		tmp = tmp->next;
	}
	return (i);
}

int	rankmax(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = (*stack_a)->next;
	i = (*stack_a)->number;
	while (tmp)
	{
		if (i < tmp->number)
			i = tmp->number;
		tmp = tmp->next;
	}
	return (i);
}

void	pre_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;
	int		max;
	float	rank;

	min = rankmin(stack_a);
	max = rankmax(stack_a);
	rank = ((max - (float)min) / (((float)max - (float)min) + 1)) / 2;
	tmp = (*stack_a);
	while (strlenlistparam(*stack_a) >= 4)
	{
		if (rank > (tmp->number - (float)min) / (((float)max - (float)min) + 1))
		{
			push_to_b(stack_a, stack_b);
			if (strlenlistparam(*stack_b) != 1)
				rotate_b(stack_b);
		}
		else
			push_to_b(stack_a, stack_b);
		tmp = (*stack_a);
	}
	return ;
}
