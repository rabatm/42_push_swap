#include "../includes/push_swap.h"

void	ft_r(t_swap **p1)
{
	t_swap	*tmp_swap;
	t_swap	*tmp_last;

	if (*p1 == NULL || (*p1)->next == NULL)
		return ;
	tmp_last = ft_getlast(*p1);
	tmp_swap = *p1;
	*p1 = (*p1)->next;
	(*p1)->prev = NULL;
	tmp_last->next = tmp_swap;
	tmp_swap->prev = tmp_last;
	tmp_swap->next = NULL;
}

void	ft_ra(t_swap **p1)
{
	ft_r(p1);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_swap **p1)
{
	ft_r(p1);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_head **t_stark)
{
	ft_r(&((*t_stark)->head_a));
	ft_r(&((*t_stark)->head_b));
	ft_putstr_fd("rr\n", 1);
}

void	ft_rr_(t_swap **p1)
{
	t_swap	*tmp_s;
	t_swap	*last;

	if (*p1 == NULL || (*p1)->next == NULL)
		return ;
	tmp_s = *p1;
	while (tmp_s->next->next != NULL)
		tmp_s = tmp_s->next;
	last = tmp_s->next;
	last->next = *p1;
	*p1 = last;
	tmp_s->next = NULL;
}

void	ft_rrb(t_swap **head_b)
{
	ft_rr_(head_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rra(t_swap **head_a)
{
	ft_rr_(head_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrr(t_head **t_stark)
{
	ft_rr_(&((*t_stark)->head_a));
	ft_rr_(&((*t_stark)->head_b));
	ft_putstr_fd("rrr\n", 1);
}
