/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:20:39 by vchan             #+#    #+#             */
/*   Updated: 2022/04/25 18:20:40 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ch_reverse_rotate(t_list **stack)
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

void	ch_reverse_rotate_a(t_list **stack)
{
	ch_reverse_rotate(stack);
}

void	ch_reverse_rotate_b(t_list **stack)
{
	ch_reverse_rotate(stack);
}

void	ch_reverse_rrr(t_list **stack_a, t_list **stack_b)
{
	ch_reverse_rotate(stack_a);
	ch_reverse_rotate(stack_b);
	return ;
}
