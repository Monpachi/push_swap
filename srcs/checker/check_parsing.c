#include "ft_push_swap.h"

int	parsing(int argc, char **argv)
{
	int		i;
	char	**str;

	if (argc > 1)
	{
		i = 0;
		str = argv + 1;
		if (argc == 2)
			str = ft_split(argv[1], ' ');
		while (str[i] != NULL || argc > i + 1)
		{
			if (is_doublon(str) || is_nbr(str) || int_overflow(str[i]))
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}
