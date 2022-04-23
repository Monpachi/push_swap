/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_total_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:00:51 by vchan             #+#    #+#             */
/*   Updated: 2022/04/23 15:04:14 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	utils_total_move(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	int		index_b;
	int		k;
	int		i;

	index_b = 0;
	i = countmove_stack(index_b, len_b) + 1;
	k = algoplus(stack_a, (*stack_b)->number);
	k = i + countmove_stack(k, len_a);
	return (k);
}

int	utils_total_move3(int i, int len_a, int index_b, int len_b)
{
	i = countmove_stack(i, len_a);
	i = countmove_stack(index_b, len_b) + 1 + i;
	return (i);
}

int	utils_move2(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	int		i;
	t_list	*tmp2;
	int		index_b;
	int		k;
	int		pos;

	index_b = 0;
	k = utils_total_move(stack_a, stack_b, len_a, len_b);
	tmp2 = (*stack_b)->next;
	while (tmp2 && ++index_b)
	{
		if ((index_b > 0 && index_b < 40)
			|| (index_b >= len_b - 40 && index_b < len_b))
		{
			i = algoplus(stack_a, tmp2->number);
			i = utils_total_move3(i, len_a, index_b, len_b);
		}
		if (i < k)
		{
			k = i;
			pos = index_b;
		}
		tmp2 = tmp2->next;
	}
	return (pos);
}
