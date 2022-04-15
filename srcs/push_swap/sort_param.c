/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:57 by vchan             #+#    #+#             */
/*   Updated: 2022/04/15 19:07:34 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_param2(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	if (tmp->number > tmp->next->number)
		swap_a(stack_a);
	return ;
}

void	sort_param3(t_list	**stack_a)
{
	algo3_superior_inferior(stack_a);
	algo3_onlysup(stack_a);
	algo3_inf_sup(stack_a);
	algo3_biginf_inf(stack_a);
	return ;
}

void	sort_param5(t_list **stack_a, t_list **stack_b)
{
	pre_sort(stack_a, stack_b);
	sort_param3(stack_a);
	bestmove(stack_a, stack_b);
	margoulin(stack_a);
	return ;
}

void	sort_param4(t_list **stack_a, t_list**stack_b)
{
	int	i;

	pre_sort(stack_a, stack_b);
	sort_param3(stack_a);
	i = algoplus(stack_a, (*stack_b)->number);
	move_a(stack_a, i);
	push_to_a(stack_b, stack_a);
	margoulin(stack_a);
}

void	sort_paramplus(t_list **stack_a, t_list **stack_b)
{
	pre_sort(stack_a, stack_b);
	sort_param3(stack_a);
	bestmove(stack_a, stack_b);
	margoulin(stack_a);
	return ;
}
