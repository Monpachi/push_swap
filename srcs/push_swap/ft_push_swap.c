/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:45:43 by vchan             #+#    #+#             */
/*   Updated: 2022/04/23 15:59:57 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

/*
void	print_stack(t_list *list)
{
	printf("----==== PRINT STACK ====----\n");
	while (list)
	{
		printf("%d\n", list->number);
		list = list->next;
	}
	printf("-----------------------------\n");
}
*/

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
		parsing2(argc, argv);
		if (parsing(argc, argv) == 1)
			return (0);
		stack_a = newstack(str);
		checkandsort(argc, &stack_a, &stack_b);
		ft_lstclear(&stack_a);
	}
	return (0);
}
