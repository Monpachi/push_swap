/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:55:28 by vchan             #+#    #+#             */
/*   Updated: 2022/04/27 15:46:41 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_sort(t_list *stack_a)
{
	int		number;
	t_list	*tmp;
	int		this;
	int		the_next;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		this = tmp->number;
		number = this;
		the_next = tmp->next->number;
		if (number > the_next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
