/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:54 by vchan             #+#    #+#             */
/*   Updated: 2022/04/23 14:52:28 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
 * Rotate le premier qui va en bas
 */
void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (strlenlist(*stack) > 2)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
	}
}

void	rotate_a(t_list **stack)
{
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **stack)
{
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
