/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:45:43 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 18:28:47 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**str;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc > 1)
	{
		i = 0;
		str = argv + 1;
		if (argc == 2)
			str = ft_split(argv[1], ' ');
		while (str[i] != NULL || argc > i + 1)
		{
			if (is_doublon(str) || is_nbr(str) || int_overflow(str[i]))
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			i++;
		}
		stack_a = newstack(str);
		if (check_sort(stack_a) == 1)
			checkandsort(argc, &stack_a, &stack_b);
		ft_lstclear(&stack_a);
	}
	return (0);
}
