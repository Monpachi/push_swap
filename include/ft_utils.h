#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	char			*command;
}	t_list;

int		strlenlist(t_list *stack);
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	*newstack(char **argv);
void	ft_lstclear(t_list **stack);
void	ft_putstr_fd(char *s, int fd);
int		mini_atoi(char *str);
char	exit_failure(char *s);
int		ft_isdigit(int c);
int		mini_atoi(char *str);
int		int_overflow(char *str);
int		is_doublon(char	**valstr);
int		is_nbr(char **valstr);
int		check_sort(t_list *stack_a);
int		parsing2(int argc, char **argv);
int		parsing(int argc, char **argv);
char	**ft_split(char const *s, char c);

#endif
