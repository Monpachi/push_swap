/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkandsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:05:56 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:25:49 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	checkandsort(int argc, t_list **stack_a, t_list **stack_b)
{
	if (argc > 1)
	{
		if (argc == 3)
			sort_param2(stack_a);
		else if (argc == 4)
			sort_param3(stack_a);
		else if (argc == 5 || argc == 6)
			sort_param5(stack_a, stack_b);
		else if (argc > 6)
			sort_paramplus(stack_a, stack_b);
	}
	return ;
}
