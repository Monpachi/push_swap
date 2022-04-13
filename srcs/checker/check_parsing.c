/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:50:13 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:50:15 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_push_swap.h"

int	mini_atoi(char *str)
{
	long	nb;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (sign * -1);
		i++;
	}
	nb = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	int_overflow(char *str)
{
	long	nb;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (sign * -1);
		i++;
	}
	nb = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	is_doublon(char	**valstr)
{
	int	i;
	int	j;
	int	str;

	i = -1;
	while (valstr[++i])
	{
		str = mini_atoi(valstr[i]);
		j = 0;
		while (valstr[i + ++j])
		{
			if (str == mini_atoi(valstr[i + j]))
				return (1);
		}
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9' ) || c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_nbr(char **valstr)
{
	int	i;

	while (*valstr)
	{
		i = 0;
		while ((*valstr)[i])
		{
			if (!ft_isdigit((*valstr)[i]))
				return (1);
			i++;
		}
		valstr++;
	}
	return (0);
}
