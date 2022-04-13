/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:22:19 by vchan             #+#    #+#             */
/*   Updated: 2022/03/16 18:50:24 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ischarset(char c, char charset)
{
	if (c == charset)
	{
		return (1);
	}
	return (0);
}

static unsigned int	countword(char const *str, char charset)
{
	unsigned int	i;
	unsigned int	count;
	char			*strs;

	strs = (char *)str;
	count = 0;
	i = 0;
	while (str[i])
	{
		while (ischarset(strs[i], charset) && str[i])
			i++;
		if (!ischarset(strs[i], charset) && str[i])
			count++;
		while (!ischarset(strs[i], charset) && str[i])
			i++;
	}
	return (count);
}

static int	lenword(char const *str, char charset)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (ischarset(str[i], charset) && str[i])
		i++;
	while (!ischarset(str[i], charset) && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	x;
	char			**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (countword(s, c) + 1));
	if (result == NULL || s == NULL)
		return (0);
	i = 0;
	x = 0;
	while (x < countword(s, c))
	{
		k = 0;
		result[x] = malloc(sizeof(char) * (lenword(&s[i], c) + 1));
		while (ischarset(s[i], c) && s[i])
			i++;
		while (!ischarset(s[i], c) && s[i])
			result[x][k++] = s[i++];
		result[x][k] = '\0';
		x++;
	}
	result[x] = 0;
	return (result);
}
