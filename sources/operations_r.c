#include "../includes/push_swap.h"

void ft_r(t_swap **p1) 
{
	t_swap *tmp_swap;
	t_swap *tmp_last;

	if (*p1 == NULL || (*p1)->next == NULL)
		return;
	tmp_last = ft_getlast(*p1);
	tmp_swap = *p1;
	*p1 = (*p1)->next;
	(*p1)->prev = NULL;
	tmp_last->next = tmp_swap;
	tmp_swap->prev = tmp_last;
	tmp_swap->next = NULL;
}

void ft_ra(t_swap **p1)
{
	ft_r(p1);
	ft_putstr_fd("RA\n", 1);
}

void ft_rb(t_swap **p1)
{
	ft_r(p1);
	ft_putstr_fd("RB\n", 1);
}

void ft_rr(t_head **t_stark)
{
	ft_r(&((*t_stark)->head_a));
	ft_r(&((*t_stark)->head_b));
	ft_putstr_fd("RR\n", 1);
}

void	ft_rra(t_swap **head_a)
{
	t_swap	*tmp_s;
	t_swap	*last;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	tmp_s = *head_a;
	while (tmp_s->next->next != NULL)
		tmp_s = tmp_s->next;
	last = tmp_s->next;
	last->next = *head_a;
	*head_a = last;
	tmp_s->next = NULL;
	ft_putstr_fd("RRA\n", 1);
}

void	ft_rrb(t_swap **head_b)
{
	t_swap	*tmp_s;
	t_swap	*last;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp_s = *head_b;
	while (tmp_s->next->next != NULL)
		tmp_s = tmp_s->next;
	last = tmp_s->next;
	last->next = *head_b;
	*head_b = last;
	tmp_s->next = NULL;
	ft_putstr_fd("RRB\n", 1);
}