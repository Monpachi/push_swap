/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:38:45 by vchan             #+#    #+#             */
/*   Updated: 2022/04/15 18:33:58 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	checker_sort(int argc, t_list *stack_a)
{
	int		number;
	t_list	*tmp;
	int		this;
	int		the_next;

	tmp = stack_a;
	if (ft_lstsize(tmp) != (argc - 1))
	{
		ft_putstr_fd("\033[1;31mKO\n\033[0;m", 1);
		return ;
	}
	while (tmp->next)
	{
		this = tmp->number;
		number = this;
		the_next = tmp->next->number;
		if (number > the_next)
		{
			ft_putstr_fd("\033[1;31mKO\n\033[0;m", 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("\033[1;32mOK\n\033[0;m", 1);
}
