#include "../includes/push_swap.h"

void	ft_sfive_tob(t_head **t_stark)
{
	ft_pb((*t_stark));
	ft_pb((*t_stark));
}

void	ft_sort_5(t_head **t_stark)
{
	ft_sfive_tob(t_stark);
	ft_sort_3(&(*t_stark)->head_a);
	ft_pa((*t_stark));
	ft_ra(&(*t_stark)->head_a);
	ft_pa((*t_stark));
}