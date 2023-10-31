#include "../includes/push_swap.h"

void	ft_sfive_tob(t_head **t_stark)
{
	ft_pb((*t_stark));
	ft_pb((*t_stark));
}

int	ft_get_my_pos(t_head *mystack)
{
	t_swap	*currentstark;
	int		i;

	i = 0;
	currentstark = mystack->head_a;
	while ((mystack->head_b->num > currentstark->num) 
		 && (currentstark->next)
		 && (mystack->head_b->num > currentstark->next->num))
	{
		currentstark = currentstark->next;
		i++;
	}
	return (i);
}

void	ft_sort_5(t_head **t_stark)
{
	int	my_new_place;
	ft_sfive_tob(t_stark);
	ft_sort_3(&(*t_stark)->head_a);
	if ((*t_stark)->head_b->num > (*t_stark)->head_b->next->num)
		ft_sb(&(*t_stark)->head_b);
	//premier nombre

	prtlst((*t_stark)->head_a);
	my_new_place = ft_get_my_pos(*t_stark);

	if (my_new_place == 1)
		ft_ra(&(*t_stark)->head_a);
	ft_pa((*t_stark));
	if (my_new_place == 1)
	{
		ft_sa(&(*t_stark)->head_a);
		ft_rra(&(*t_stark)->head_a);
	}
	if (my_new_place == 2)
		ft_ra(&(*t_stark)->head_a);
	if ((my_new_place == 0 ) && 
		((*t_stark)->head_a->num > (*t_stark)->head_a->next->num))
		ft_sa(&(*t_stark)->head_a);
	prtlst((*t_stark)->head_a);
	//DERNIER NOMBRE
	my_new_place = ft_get_my_pos(*t_stark);
	if (my_new_place == 1)
		ft_ra(&(*t_stark)->head_a);
	if (my_new_place == 2)
		ft_rra(&(*t_stark)->head_a);
	ft_pa((*t_stark));
	if (my_new_place == 2)
	{
		ft_ra(&(*t_stark)->head_a);
		ft_ra(&(*t_stark)->head_a);
	}
	if (my_new_place == 1)
	{
		ft_sa(&(*t_stark)->head_a);
		ft_rra(&(*t_stark)->head_a);
	}
	
	if (my_new_place == 3)
		ft_ra(&(*t_stark)->head_a);
	if ((my_new_place == 0 ) && 
			((*t_stark)->head_a->num > (*t_stark)->head_a->next->num))
		ft_sa(&(*t_stark)->head_a);
}