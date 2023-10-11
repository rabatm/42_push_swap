#include "../includes/push_swap.h"

void ft_sort(t_head **t_stark)
{
	t_swap *tmp_s;

	if ((*t_stark)->head_a_size == 2)
		ft_ra(&(*t_stark)->head_a);
	if ((*t_stark)->head_a_size == 3)
	{
		ft_ra(&(*t_stark)->head_a);
		tmp_s = (*t_stark)->head_a;
		if (tmp_s->num > tmp_s->next->num)
			ft_sa((*t_stark)->head_a);
	}
		if ((*t_stark)->head_a_size == 4)
	{
		ft_ra(&(*t_stark)->head_a);
		tmp_s = (*t_stark)->head_a;
		if (tmp_s->num > tmp_s->next->num)
			ft_sa((*t_stark)->head_a);
	}
	return;
}