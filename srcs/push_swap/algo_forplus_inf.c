/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_forplus_inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:43 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:05:43 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_between_for_inf(t_list **stack_a, int bvalue, int i)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = (*stack_a);
	while (j < i)
	{
		tmp = tmp->next;
		j++;
	}
	j = i;
	while ((bvalue > tmp->number)
		&& (bvalue < ft_lstlast(*stack_a)->number))
	{
		j++;
		tmp = tmp ->next;
	}
	return (j);
}

int	algoplus_inf1(t_list **stack_a, int bvalue, int j)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp->number > bvalue)
	{
		i++;
		if ((j == i && bvalue < tmp->next->number)
			&& (bvalue < ft_lstlast(*stack_a)->number))
		{
			while (bvalue > tmp->next->number)
			{
				i++;
				tmp = tmp->next;
			}
			return (i);
		}
		if (strlenlistparam(*stack_a) == i)
			return (0);
		tmp = tmp->next;
	}
	return (i);
}

int	algoplus_inf(t_list **stack_a, int bvalue, int j)
{
	t_list	*tmp;
	int		i;

	i = algoplus_inf1(stack_a, bvalue, j);
	tmp = (*stack_a);
	j = 0;
	while (tmp && j < i)
	{
		j++;
		tmp = tmp->next;
	}
	if ((bvalue > tmp->number)
		&& (bvalue < ft_lstlast(*stack_a)->number))
	{
		j = is_between_for_inf(stack_a, bvalue, i);
		return (j);
	}
	if (bvalue > tmp->number)
		return (0);
	return (j);
}

int	algoplus(t_list **stack_a, int bvalue)
{
	t_list	*tmp;
	int		i;
	int		j;

	j = lowest(stack_a);
	i = 0;
	tmp = (*stack_a);
	if (tmp->number > bvalue)
		i = algoplus_inf(stack_a, bvalue, j);
	else if (bvalue > tmp->number)
		i = algoplus_sup(stack_a, bvalue);
	return (i);
}
