#include "ft_push_swap.h"

void	margoulin(t_list **stack_a)
{
	int	i;

	i = lowest(stack_a);
	move_a(stack_a, i);
}
