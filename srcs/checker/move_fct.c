/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:21:30 by vchan             #+#    #+#             */
/*   Updated: 2022/04/25 18:21:31 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	if_swap(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		ch_swap_a(stack_a);
	if (!ft_strcmp(line, "sb\n"))
		ch_swap_b(stack_b);
	if (!ft_strcmp(line, "ss\n"))
		ch_swap_them(stack_a, stack_b);
	return ;
}

void	if_push(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		ch_push_to_a(stack_b, stack_a);
	if (!ft_strcmp(line, "pb\n"))
		ch_push_to_b(stack_a, stack_b);
	return ;
}

void	if_rotate(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		ch_rotate_a(stack_a);
	if (!ft_strcmp(line, "rb\n"))
		ch_rotate_b(stack_b);
	if (!ft_strcmp(line, "rr\n"))
		ch_rotate_rr(stack_a, stack_b);
	return ;
}

void	if_reverse(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "rra\n"))
		ch_reverse_rotate_a(stack_a);
	if (!ft_strcmp(line, "rrb\n"))
		ch_reverse_rotate_b(stack_b);
	if (!ft_strcmp(line, "rrr\n"))
		ch_reverse_rrr(stack_a, stack_b);
	return ;
}
