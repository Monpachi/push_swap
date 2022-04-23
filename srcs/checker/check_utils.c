#include "ft_checker.h"

int	strlenlist(t_list *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack = (stack)->next;
		i++;
	}
	return (i);
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

void	ft_lstclear(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack);
			*stack = (*stack)->next;
			free(tmp);
		}
	}
	return ;
}
