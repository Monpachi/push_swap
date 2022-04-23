/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:45:00 by vchan             #+#    #+#             */
/*   Updated: 2022/04/23 14:55:49 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	strlenlist(t_list *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack = (stack)->next;
		i++;
	}
	return (i);
}

int	strlenlistparam(t_list *stack)
{
	int	i;

	i = 1;
	while (stack->next)
	{
		stack = (stack)->next;
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
}
