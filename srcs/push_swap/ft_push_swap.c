/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:45:43 by vchan             #+#    #+#             */
/*   Updated: 2022/04/29 17:01:57 by vchan            ###   ########.fr       */
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

static int	strlentab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
		str = NULL;
		str = ft_parse_av(argc, argv);
		if (parsing(strlentab(str), str) == 1)
			exit_failure("Error\n");
		stack_a = newstack(str);
		checkandsort(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
	}
	return (0);
}
