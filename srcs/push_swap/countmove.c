/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:47 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:07:47 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//Va venir chercher le nombre le plus petit, et trouver son index
int	lowest(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		k;

	i = 0;
	tmp = (*stack_a);
	k = tmp->number;
	while (tmp->next)
	{
		if (k > tmp->next->number)
			k = tmp->next->number;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp->number != k)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// compte le nombre de move pour se retrouver en haut de la stack
int	countmove_stack(int i, int len)
{
	int		k;
	int		j;
	int		move;

	j = 0;
	move = 0;
	k = len;	
	if (i <= k / 2)
		j = i;
	else if (i > k / 2)
		j = k - i;
	while (j > 0)
	{
		if (i <= k / 2)
		{
			move++;
			j--;
		}
		if (i > k / 2)
		{
			move++;
			j--;
		}
	}
	return (move);
}

//Pour calculer le nombre de coup A et B;
int	total_move(t_list **stack_a, t_list **stack_b, int pos)
{
	int		i;
	t_list	*tmp2;
	int		index_b;
	int		k;
	int		len_a;
	int		len_b;

	len_a = strlenlistparam(*stack_a);
	len_b = strlenlistparam(*stack_b);
	pos = 0;
	index_b = 0;
	i = countmove_stack(index_b, len_b) + 1;
	k = algoplus(stack_a, (*stack_b)->number);
	k = i + countmove_stack(k, len_a);
	tmp2 = (*stack_b)->next;
	while (tmp2)
	{
		index_b++;
		if ((index_b > 0 && index_b < 40) || (index_b >= len_b - 40 && index_b < len_b ))
		{
			i = algoplus(stack_a, tmp2->number);
			i = countmove_stack(i, len_a);
			i = countmove_stack(index_b, len_b) + 1 + i;
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

int	get_the_best(t_list	**stack_a, t_list **stack_b)
{
	int		pos;
	int		best;
	t_list	*tmp2;

	tmp2 = (*stack_b);
	pos = 0;
	best = total_move(stack_a, stack_b, pos);
	while (tmp2)
	{
		if (pos == best)
			return (pos);
		pos++;
	}
	return (0);
}

int	get_to_b(t_list **stack_b, int pos)
{
	t_list	*tmp2;
	int		i;

	i = 0;
	tmp2 = (*stack_b);
	while (tmp2 && i < pos)
	{
		i++;
		tmp2 = tmp2->next;
	}
	return (tmp2->number);
}
