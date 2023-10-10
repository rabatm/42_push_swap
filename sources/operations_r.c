#include "../includes/push_swap.h"

void ft_r(t_swap **p1) {
	
	t_swap *tmp_swap;
	t_swap *tmp_last;

	if ((*p1 == NULL) || ((*p1)->next == NULL))
		return ;
	if ((*p1)->next->next == NULL)
	{
		tmp_swap = *p1;
		*p1 = (*p1)->next;
		(*p1)->next = tmp_swap;
		(*p1)->prev = NULL;
		tmp_swap->prev = *p1;
		tmp_swap->next = NULL;
	}
	else
	{
		tmp_last = ft_getlast(*p1);
		tmp_swap = *p1;
		tmp_swap->next = NULL;
		tmp_swap->prev = tmp_last;
		*p1 = (*p1)->next;
		if ((*p1)->prev == NULL)
			(*p1)->prev = NULL;
		ft_printf("tmp_last->value ");
	}
}