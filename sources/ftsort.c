#include "../includes/push_swap.h"

void	ft_sort(t_head **t_stark)
{
	ft_sort_3(&(*t_stark)->head_a);
	return ;
}

void	ft_sort_3(t_swap **stark_a)
{
	if (ft_mdl_is_big((*stark_a)))
		ft_sa(stark_a);
	if (ft_last_is_big((*stark_a)))
		ft_sa(stark_a);
	if (ft_first_is_big((*stark_a)))
		ft_ra(stark_a);
	if (ft_mdl_is_medium((*stark_a)))
		ft_sa(stark_a);
}
