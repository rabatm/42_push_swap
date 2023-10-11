#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#undef NULL
#include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define ERRINT "ERROR - int overflow.\n"


typedef	struct s_swap	t_swap;
typedef	struct s_head	t_head;
typedef struct s_swap
{
	struct s_swap	*prev;
	int				num;
	struct s_swap	*next;
}	t_swap;

typedef	struct s_head
{
	struct s_swap	*head_a;
	int	head_a_size;
	struct s_swap	*head_b;
	int	head_b_size;
}	t_head;

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
t_swap	*ft_sa(t_swap *first_stark);
t_swap	*ft_sb(t_swap *first_stark);
t_head	*ft_ss(t_head *first_stark);
void	ft_pa(t_head *t_stark);
void	ft_pb(t_head *t_stark);
void	ft_p(t_swap **p1, t_swap **p2);
t_swap	*ft_getlast(t_swap *my_stark);
void	prtlst(t_swap *stark);
void ft_rr(t_head **t_stark);
void ft_rb(t_swap **p1);
void	ft_r(t_swap **p1);
void ft_ra(t_swap **p1);
void ft_sort(t_head **t_stark);
#endif