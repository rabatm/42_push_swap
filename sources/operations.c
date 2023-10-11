#include "../includes/push_swap.h"
//fonction qui permute les deux premiers elèment de la pile A
//elle retourne le premier item de la liste.
t_swap	*ft_switchhead(t_swap *first_stark)
{
	int	new_first;

	if (!first_stark->next && !first_stark)
		return NULL;
	new_first = first_stark->num;
	first_stark->num = first_stark->next->num;
	first_stark->next->num = new_first;
	return first_stark;
}

t_swap	*ft_sb(t_swap *sb)
{

	sb = ft_switchhead(sb);
	ft_printf("SB\n");	
	return (sb);
}

t_swap	*ft_sa(t_swap *sa)
{
	sa = ft_switchhead(sa);
	ft_printf("SA\n");
	return (sa);	
}

t_head	*ft_ss(t_head *t_stark)
{
	t_stark->head_a = ft_switchhead(t_stark->head_a); 
	t_stark->head_b = ft_switchhead(t_stark->head_b);
	ft_printf("SS\n");
	return  t_stark;
}

