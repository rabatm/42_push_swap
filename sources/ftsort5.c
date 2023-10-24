#include "../includes/push_swap.h"

void	ft_sfive_tob(t_head **t_stark)
{
	ft_pb((*t_stark));
	ft_pb((*t_stark));
}

void	ft_sort_5(t_head **t_stark)
{
	t_swap	*thelast;

	ft_sfive_tob(t_stark);
	ft_sort_3(&(*t_stark)->head_a);
	if ((*t_stark)->head_b->num > (*t_stark)->head_b->next->num)
		ft_sb(&(*t_stark)->head_b);
	//premier nombre
	ft_pa((*t_stark));
	if (((*t_stark)->head_a->num > (*t_stark)->head_a->next->num) &&
	((*t_stark)->head_a->num < (*t_stark)->head_a->next->next->num))
		ft_sa(&(*t_stark)->head_a);
	if ((*t_stark)->head_a->num > (*t_stark)->head_a->next->num)
		ft_ra(&(*t_stark)->head_a);
	//DERNIER NOMBRE
	ft_printf("%d ---- DERNIER B",(*t_stark)->head_b->num);
	ft_ra(&(*t_stark)->head_a);
	ft_pa((*t_stark));
	if (((*t_stark)->head_a->num > (*t_stark)->head_a->next->num) &&
	((*t_stark)->head_a->num < (*t_stark)->head_a->next->next->num))
		ft_sa(&(*t_stark)->head_a);
	if ((*t_stark)->head_a->num > (*t_stark)->head_a->next->num)
		ft_ra(&(*t_stark)->head_a);
	//
	thelast = ft_getlast((*t_stark)->head_a);
	if ((*t_stark)->head_a->num > thelast->num)
		ft_rra(&(*t_stark)->head_a);
	///CHECKKK 
	if (ft_check_is_sort((*t_stark)->head_a))
		ft_printf("OK \\*******/\n");
	else
		ft_printf("KO 	(╯︵╰,)\n");
}