/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:47 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:08:49 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*tmplast;
	t_list	*tmp;

	if (strlenlist(*stack) > 2)
	{
		tmplast = *stack;
		tmp = *stack;
		tmplast = ft_lstlast(tmplast);
		while (tmp->next->next)
			tmp = tmp->next;
		tmplast->next = *stack;
		*stack = tmplast;
		tmp->next = NULL;
	}
	return ;
}

void	reverse_rotate_a(t_list **stack)
{
	reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_list **stack)
{
	reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	return ;
}
