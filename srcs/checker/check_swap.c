/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:20:26 by vchan             #+#    #+#             */
/*   Updated: 2022/04/25 18:21:08 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ch_swap(t_list **pile)
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

void	ch_swap_a(t_list **stack_a)
{
	ch_swap(stack_a);
}

void	ch_swap_b(t_list **stack_b)
{
	ch_swap(stack_b);
}

void	ch_swap_them(t_list **stack_a, t_list **stack_b)
{
	ch_swap(stack_a);
	ch_swap(stack_b);
	return ;
}
