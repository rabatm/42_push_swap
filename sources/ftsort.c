#include "../includes/push_swap.h"


int	ft_first_is_big(t_swap *stark)
{
	if ((stark->num > stark->next->next->num) &&
		(stark->num > stark->next->num))
		return (1);
	return (0);
}

int	ft_last_is_big(t_swap *stark)
{
	if ((stark->next->next->num > stark->num) &&
		(stark->next->next->num > stark->next->num))
		return (1);
	return (0);
}

int	ft_mdl_is_the_small(t_swap *stark)
{
	if ((stark->next->num < stark->num) &&
		(stark->next->num < stark->next->next->num))
		return (1);
	return (0);
}

int	ft_mdl_is_big(t_swap *stark)
{
	if ((stark->next->num > stark->num) &&
		(stark->next->num > stark->next->next->num))
		return (1);
	return (0);
}
int	ft_mdl_is_medium(t_swap *stark)
{
	if (ft_mdl_is_the_small(stark) && 
		ft_mdl_is_big(stark) == 0)
		return (1);
	return (0);
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

void ft_sort(t_head **t_stark)
{ 
//	t_swap *tmp_s;
ft_sort_3(&(*t_stark)->head_a);
//	if ((*t_stark)->head_a_size == 2)
//		ft_rra(&(*t_stark)->head_a);
		//ft_ra(&(*t_stark)->head_a);
	// if ((*t_stark)->head_a_size == 3)
	// 	ft_sort_3(t_stark);
	// if ((*t_stark)->head_a_size >= 4)
	// {
	// 	ft_ra(&(*t_stark)->head_a);
	// 	tmp_s = (*t_stark)->head_a;
	// 	if (tmp_s->num > tmp_s->next->num)
	// 		ft_sa(&(*t_stark)->head_a);
	// }
	return;
}

