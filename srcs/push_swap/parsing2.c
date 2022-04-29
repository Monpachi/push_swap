/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:07:56 by vchan             #+#    #+#             */
/*   Updated: 2022/04/29 17:20:00 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	**ft_parse_av(int ac, char **av)
{
	char	**nbr;
	char	*av_str;
	char	*tmp;
	int		i;

	av_str = ft_strdup("");
	i = 0;
	while (++i < ac)
	{
		tmp = ft_strjoin(av_str, av[i]);
		free(av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free(av_str);
		av_str = tmp;
	}
	nbr = ft_split(av_str, ' ');
	free(av_str);
	return (nbr);
}

char	exit_failure(char *s)
{
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

int	parsing(int argc, char **str)
{
	int		i;

	i = 0;
	if (!str[i] || is_doublon(str))
		return (1);
	while ((str[i] != NULL && argc > i))
	{
		if (is_nbr(str) || int_overflow(str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing2(int argc, char **argv)
{
	if (parsing(argc, argv) == 1)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
