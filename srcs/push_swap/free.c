/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:55:38 by vchan             #+#    #+#             */
/*   Updated: 2022/04/23 14:56:21 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lstclear(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack);
			*stack = (*stack)->next;
			free(tmp);
		}
	}
	return ;
}
