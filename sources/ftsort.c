#include "../includes/push_swap.h"

void	ft_sort_3(t_swap **stark_a)
{
	if (ft_mdl_is_big((*stark_a)))
		ft_sa(stark_a);
	if ((ft_last_is_big((*stark_a)))
		&& (ft_mdl_is_the_small((*stark_a))))
		ft_sa(stark_a);
	if (ft_first_is_big((*stark_a)))
		ft_ra(stark_a);
	if (ft_mdl_is_medium((*stark_a)))
		ft_sa(stark_a);
}
