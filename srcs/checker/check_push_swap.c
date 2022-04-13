#include "ft_push_swap.h"

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
		str = argv + 1;
		if (argc == 2)
			str = ft_split(argv[1], ' ');
		while (str[i] != NULL || argc > i + 1)
		{
			if (is_doublon(str) || is_nbr(str) || int_overflow(str[i]))
				return (ft_printf("Error\n"));
			i++;
		}
		stack_a = newstack(str);
		if (check_sort(stack_a) == 1)
			checkandsort(argc, &stack_a, &stack_b);
		ft_lstclear(&stack_a);
	}
	return (0);
}
