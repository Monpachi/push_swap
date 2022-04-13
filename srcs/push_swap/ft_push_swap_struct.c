/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:02 by vchan             #+#    #+#             */
/*   Updated: 2022/04/11 17:08:02 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_lstnew(int number)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!*alst)
	{
		*alst = new ;
	}
	else
	{
		temp = ft_lstlast(*alst);
		temp -> next = new;
	}
	return ;
}

void	*newstack(char **argv)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (argv[i])
	{
		ft_lstadd_back(&stack, ft_lstnew(mini_atoi(argv[i])));
		i++;
	}
	return (stack);
}
