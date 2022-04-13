/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:57 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:11:45 by vchan            ###   ########.fr       */
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
	//t_list	*tmp;
	//int		i;

	//i = 0 ;
	//tmp = *stack_a;
	pre_sort(stack_a, stack_b);
	sort_param3(stack_a);
	bestmove(stack_a, stack_b);
	margoulin(stack_a);
	return ;
}

void	margoulin(t_list **stack_a)
{
	int	i;

	i = lowest(stack_a);
	move_a(stack_a, i);
}

void	sort_paramplus(t_list **stack_a, t_list **stack_b)
{
	pre_sort(stack_a, stack_b);
	sort_param3(stack_a);
	bestmove(stack_a, stack_b);
	margoulin(stack_a);
	return ;
}
