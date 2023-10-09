#include "../includes/push_swap.h"
//fonction qui permute les deux premiers elèment de la pile A
//elle retourne le premier item de la liste.
t_swap	*ft_switchhead(t_swap *first_stark)
{
	t_swap	*tmp_item;

	if (!first_stark->next && !first_stark)
		return NULL;
	tmp_item = first_stark->next;
	first_stark->next->next->prev = first_stark;
	tmp_item->prev = NULL;
	first_stark->next = tmp_item->next;
	tmp_item->next = first_stark;
	return tmp_item;
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

t_swap	*ft_ss(t_swap a, t_swap b)
{
	
}