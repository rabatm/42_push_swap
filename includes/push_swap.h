#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>



typedef	struct s_swap	t_swap;
typedef struct s_swap
{
	struct s_swap	*prev;
	int				num;
	struct s_swap	*next;
}	t_swap;

#endif