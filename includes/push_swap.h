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


t_swap *ft_init_stark(char *val[]);
int	ft_check_doublons(t_swap *first_stark);
int ft_check_is_sort(t_swap *first_stark);
void	ft_destroy_lst(t_swap *first_start);
#endif