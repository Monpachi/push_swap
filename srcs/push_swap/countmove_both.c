/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countmove_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:06:03 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:07:28 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	if_both_rr(t_list **stack, int i)
{
	int		k;
	int		j;

	j = 0;
	k = strlenlistparam(*stack);
	if (i <= k / 2)
		j = i;
	else if (i > k / 2)
		j = k - i;
	while (j > 0)
	{
		if (i <= k / 2)
		{
			j--;
			if (j == 0)
				return (1);
		}
		if (i > k / 2)
		{
			j--;
			if (j == 0)
				return (0);
		}
	}
	return (0);
}

int	if_both_rrr(t_list **stack, int i)
{
	int		k;
	int		j;

	j = 0;
	k = strlenlistparam(*stack);
	if (i <= k / 2)
		j = i;
	else if (i > k / 2)
		j = k - i;
	while (j > 0)
	{
		if (i <= k / 2)
		{
			j--;
			if (j == 0)
				return (0);
		}
		if (i > k / 2)
		{
			j--;
			if (j == 0)
				return (1);
		}
	}
	return (0);
}

void	both_ra(t_list **stack_a, t_list **stack_b, int pos, int i)
{
	while (pos > 0 && i > 0)
	{
		rotate_rr(stack_a, stack_b);
		pos--;
		i--;
	}
	while (i > 0)
	{
		rotate_a(stack_a);
		i--;
	}
	while (pos > 0)
	{
		rotate_b(stack_b);
		pos--;
	}
	push_to_a(stack_b, stack_a);
	return ;
}

void	both_rrr(t_list **stack_a, t_list **stack_b, int pos, int i)
{
	int	j;
	int	l;
	int	len_a;
	int	len_b;

	len_a = strlenlistparam(*stack_a);
	len_b = strlenlistparam(*stack_b);
	l = countmove_stack(i, len_a);
	j = countmove_stack(pos, len_b);
	while (j > 0 && l > 0)
	{
		reverse_rrr(stack_a, stack_b);
		j--;
		l--;
	}
	while (l > 0)
	{
		reverse_rotate_a(stack_a);
		l--;
	}
	while (j > 0)
	{
		reverse_rotate_b(stack_b);
		j--;
	}
	push_to_a(stack_b, stack_a);
	return ;
}
