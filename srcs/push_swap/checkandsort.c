/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkandsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:56 by vchan             #+#    #+#             */
/*   Updated: 2022/04/29 16:46:23 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	checkandsort(int argc, t_list **stack_a, t_list **stack_b)
{
	int	i;

	(void)argc;
	i = strlenlistparam(*stack_a);
	if (check_sort(*stack_a) == 1)
	{
		if (i == 2)
			sort_param2(stack_a);
		else if (i == 3)
			sort_param3(stack_a);
		else if (i == 4)
			sort_param4(stack_a, stack_b);
		else if (i == 5)
			sort_param5(stack_a, stack_b);
		else if (i > 5)
			sort_paramplus(stack_a, stack_b);
	}
	return ;
}
