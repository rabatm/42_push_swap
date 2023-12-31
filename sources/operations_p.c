#include "../includes/push_swap.h"

void	ft_p(t_swap **p1, t_swap **p2)
{
	t_swap *temp;
	
	temp = *p1;
	if (temp == NULL)
		return ;
	*p1 = (*p1)->next;
	if (*p1 != NULL)
		(*p1)->prev = NULL;
	temp->next = *p2;
	if (*p2 != NULL)
		(*p2)->prev = temp;
	*p2 = temp;
}

void	ft_pb(t_head *t_stark)
{
	ft_p(&t_stark->head_a,&t_stark->head_b);
	ft_printf("PB\n");
}

void	ft_pa(t_head *t_stark)
{
	ft_p(&t_stark->head_b,&t_stark->head_a);
	ft_printf("PA\n");
}