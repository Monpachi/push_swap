/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:07:56 by vchan             #+#    #+#             */
/*   Updated: 2022/04/29 16:45:38 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	exit_failure(char *s)
{
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

int	parsing(int argc, char **argv)
{
	int		i;
	char	**str;

	if (argc > 1)
	{
		i = 0;
		str = argv + 1;
		if (!str[i])
			return (1);
		while ((str[i] != NULL && argc > i + 1))
		{
			if (is_doublon(str) || is_nbr(str) || int_overflow(str[i]))
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	parsing2(int argc, char **argv)
{
	if (parsing(argc, argv) == 1)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
