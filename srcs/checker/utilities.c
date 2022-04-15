#include "ft_push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] > s2[i])
	{
		return (1);
	}
	if (s1[i] < s2[i])
	{
		return (-1);
	}
	return (0);
}

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	return (ft_lstsize(lst->next) + 1);
}

t_list	*ft_lstnew_checker(void *command)
{
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->command = command;
	str->next = NULL;
	return (str);
}
