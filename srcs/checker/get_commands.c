#include "ft_push_swap.h"

void	get_push(t_list *commands, char *s)
{
	t_list	*new;

	if (!ft_strcmp(s, "pa"))
	{
		new = ft_lstnew_checker(ft_strdup("pa"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "pb"))
	{
		new = ft_lstnew_checker(ft_strdup("pb"));
		ft_lstadd_back(&commands, new);
	}
}

void	get_swap(t_list *commands, char *s)
{
	t_list	*new;

	if (!ft_strcmp(s, "sa"))
	{
		new = ft_lstnew_checker(ft_strdup("sa"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "sb"))
	{
		new = ft_lstnew_checker(ft_strdup("sb"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "ss"))
	{
		new = ft_lstnew_checker(ft_strdup("ss"));
		ft_lstadd_back(&commands, new);
	}
}

void	get_rotate(t_list *commands, char *s)
{
	t_list	*new;

	if (!ft_strcmp(s, "ra"))
	{
		new = ft_lstnew_checker(ft_strdup("ra"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "rb"))
	{
		new = ft_lstnew_checker(ft_strdup("rb"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "rr"))
	{
		new = ft_lstnew_checker(ft_strdup("rr"));
		ft_lstadd_back(&commands, new);
	}
}

void	get_rev_rotate(t_list *commands, char *s)
{
	t_list	*new;

	if (!ft_strcmp(s, "rra"))
	{
		new = ft_lstnew_checker(ft_strdup("rra"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "rrb"))
	{
		new = ft_lstnew_checker(ft_strdup("rrb"));
		ft_lstadd_back(&commands, new);
	}
	else if (!ft_strcmp(s, "rrr"))
	{
		new = ft_lstnew_checker(ft_strdup("rrr"));
		ft_lstadd_back(&commands, new);
	}
}
