/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_forplus_sup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:46 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:05:46 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_to_max(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		max;

	max = rankmax(stack_a);
	i = 0;
	tmp = (*stack_a);
	while (tmp->number != max)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->number > ft_lstlast(*stack_a)->number)
		i++;
	return (i);
}

int	algoplus_sup(t_list **stack_a, int bvalue)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = rankmax(stack_a);
	tmp = (*stack_a);
	while (tmp && bvalue > tmp->number)
	{
		i++;
		tmp = tmp->next;
	}
	if (bvalue > j && j > ft_lstlast(*stack_a)->number)
		return (get_to_max(stack_a));
	if (i == strlenlistparam(*stack_a))
		return (0);
	return (i);
}
