#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef	struct s_swap	t_swap;
typedef struct s_swap
{
	struct s_swap	*prev;
	int				num;
	struct s_swap	*next;
}	t_swap;

typedef	struct s_head
{
	struct s_swap	*head_a;
	struct s_swap	*head_b;
}	t_head;

t_swap *ft_init_stark(char *val[]);
int	ft_check_doublons(t_swap *first_stark);
int ft_check_is_sort(t_swap *first_stark);
void	ft_destroy_lst(t_swap *first_start);

/*
OPERATIONS
*/
t_swap	*ft_sa(t_swap *first_stark);
t_swap	*ft_sb(t_swap *first_stark);
t_swap	*ft_ss(t_swap *first_stark);
#endif