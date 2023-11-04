#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#undef NULL
#include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
#define MIN_INT (-2147483648)
#define MAX_INT 2147483647
# define ERRINT "ERROR - int overflow.\n"

typedef	struct s_swap	t_swap;
typedef	struct s_head	t_head;
typedef struct s_swap
{
	struct s_swap	*prev;
	int				num;
	int				mycost;
	struct s_swap	*new_post;
	struct s_swap	*next;
	char			position;
	int				top;
}	t_swap;
typedef	struct s_item
{
	int	num;
	int	index;
}	t_item;
typedef	struct s_head
{
	struct s_swap	*head_a;
	int	head_a_size;
	int	a_middle;
	struct s_swap	*head_b;
	int	head_b_size;
	int	b_middle;
}	t_head;
typedef struct s_min
{
	int	min;
	int	index_min;
	int	max;
	int	index_max;
	int	mdl;
	int	index_mdl;
}	t_min;

t_head *ft_init_stark(char *val[], t_head *t_stark);
int	ft_check_doublons(t_swap *first_stark);
int ft_check_is_sort(t_swap *first_stark);

/*
ft for destroy and quit
*/
void	ft_destroy_lst(t_swap *first_start);
void	ft_prterreandfree(char *msg, int err, t_swap *stark);
/*
OPERATIONS
*/
void	ft_sa(t_swap **head_a);
void	ft_sb(t_swap **head_a);
void	ft_ss(t_head *first_stark);
void	ft_pa(t_head *t_stark);
void	ft_pb(t_head *t_stark);
void	ft_p(t_swap **p1, t_swap **p2);
t_swap	*ft_getlast(t_swap *my_stark);
void	ft_rr(t_head **t_stark);
void	ft_rb(t_swap **p1);
void	ft_r(t_swap **p1);
void	ft_ra(t_swap **p1);
void	ft_sort(t_head **t_stark);
void	ft_rra(t_swap **head_a);
void	ft_rrb(t_swap **head_b);
void	ft_rrr(t_head **t_stark);
/*
fonctions pour le try de 3 elements
*/
void ft_sort_3(t_swap **stark_a);
int	ft_first_is_big(t_swap *stark);
int	ft_last_is_big(t_swap *stark);
int	ft_mdl_is_the_small(t_swap *stark);
int	ft_mdl_is_big(t_swap *stark);
int	ft_mdl_is_medium(t_swap *stark);
/*
fonctions pour le try turk
*/
t_min ft_get_min(t_swap *s_stark);
t_swap	*ft_move_min(t_swap *f_stark, int top, int min);
/*
functions du try des 5
*/
void	ft_sort_5(t_head **t_stark);
/*
function cost calcul
*/
void	ft_cacul_cost(t_swap *my_swap, int swap_middle);
void	ft_cacul_b_back(t_head **my_swap);
void	ft_find_closest_in_a(t_head **t_stark);
/*
functions du trie des 100
*/
void	ft_sort_100(t_head **t_stark);
int	ft_im_bigest(int myval, t_swap *my_stark);
int	ft_im_smallest(int myval, t_swap *my_stark);
t_swap *ft_get_min_item(t_swap *s_stark);
int ft_sqrt(int x);
/*
ft display
*/
void	prtlst(t_swap *stark);
void	prtlst_basic(t_swap *stark);
#endif