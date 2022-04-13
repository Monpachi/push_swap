/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:08:10 by vchan             #+#    #+#             */
/*   Updated: 2022/04/13 15:52:21 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
 # include <limits.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

void	to_sort3(t_list **stack_a, t_list **stack_b);
void	algo3_superior_inferior(t_list **stack_a);
void	algo3_onlysup(t_list **stack_a);
void	algo3_inf_sup(t_list **stack_a);
void	algo3_biginf_inf(t_list **stack_a);
void	algo5_inf(t_list **stack_a, t_list **stack_b);
void	algo5_onlysup(t_list **stack_a, t_list **stack_b);
int		is_between_for_inf(t_list **stack_a, int bvalue, int i);
int		algoplus_inf1(t_list **stack_a, int bvalue, int j);
int		algoplus_inf(t_list **stack_a, int bvalue, int j);
int		algoplus(t_list **stack_a, int bvalue);
int		get_to_max(t_list **stack_a);
int		algoplus_sup(t_list **stack_a, int bvalue);
void	move_a(t_list **stack_a, int i);
void	move_b(t_list **stack_b, int i);
void	if_double(t_list **stack_a, t_list **stack_b, int pos);
void	if_not_double(t_list **stack_a, t_list **stack_b, int pos);
void	bestmove(t_list **stack_a, t_list **stack_b);
void	checkandsort(int argc, t_list **stack_a, t_list **stack_b);
int		if_both_rr(t_list **stack, int i);
int		if_both_rrr(t_list **stack, int i);
int		countmove_both(t_list **stack_a, t_list **stack_b, int i, int k);
void	both_ra(t_list **stack_a, t_list **stack_b, int pos, int i);
void	both_rrr(t_list **stack_a, t_list **stack_b, int pos, int i);
int		lowest(t_list **stack_a);
int		countmove_stack(int i, int len);
int		total_move(t_list **stack_a, t_list **stack_b, int pos);
int		get_the_best(t_list	**stack_a, t_list **stack_b);
int		get_to_b(t_list **stack_b, int pos);
int		rankmin(t_list **stack_a);
int		rankmax(t_list **stack_a);
void	pre_sort(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	*newstack(char **argv);
void	print_stack(t_list *list);
int		ft_strlen(char *str);
int		mini_atoi(char *str);
int		int_overflow(char *str);
int		is_doublon(char	**valstr);
int		ft_isdigit(int c);
int		is_nbr(char **valstr);
void	push(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	push_to_a(t_list **stack_b, t_list **stack_a);
void	reverse_rotate(t_list **stack);
void	reverse_rotate_a(t_list **stack);
void	reverse_rotate_b(t_list **stack);
void	reverse_rrr(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rotate_rr(t_list **stack_a, t_list **stack_b);
void	sort_param2(t_list **stack_a);
void	sort_param3(t_list	**stack_a);
void	sort_param5(t_list **stack_a, t_list **stack_b);
void	margoulin(t_list **stack_a);
void	sort_paramplus(t_list **stack_a, t_list **stack_b);
void	swap(t_list **pile);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_them(t_list **stack_a, t_list **stack_b);
int		strlenlist(t_list *stack);
int		strlenlistparam(t_list *stack);
char	**ft_split(char const *s, char c);
int		check_sort(t_list *stack_a);
void	ft_lstclear(t_list **stack);
void	ft_putstr_fd(char *s, int fd);

#endif
