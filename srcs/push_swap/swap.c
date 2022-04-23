/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:09:02 by vchan             #+#    #+#             */
/*   Updated: 2022/04/23 19:06:51 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_list **pile)
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

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_them(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	return ;
}
