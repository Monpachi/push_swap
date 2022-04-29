/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:03:38 by vchan             #+#    #+#             */
/*   Updated: 2022/04/29 16:58:05 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	checker(t_list *stack_a, t_list *stack_b)
{
	ft_read_command(&stack_a, &stack_b);
	if (!stack_a)
		exit_failure("Error\n");
	if (stack_b || check_sort(stack_a) == 1)
		exit_failure("\033[1;31mKO\n\033[0m");
	else
		exit_success(stack_a);
}

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
		checker(stack_a, stack_b);
	}
	return (0);
}
