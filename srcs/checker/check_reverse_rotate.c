void	reverse_rotate(t_list **stack)
{
	t_list	*tmplast;
	t_list	*tmp;

	if (strlenlist(*stack) > 2)
	{
		tmplast = *stack;
		tmp = *stack;
		tmplast = ft_lstlast(tmplast);
		while (tmp->next->next)
			tmp = tmp->next;
		tmplast->next = *stack;
		*stack = tmplast;
		tmp->next = NULL;
	}
	return ;
}

void	reverse_rotate_a(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return ;
}
