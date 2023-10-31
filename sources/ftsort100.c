#include "../includes/push_swap.h"

t_item	ft_find_start(int v_start, int v_end, t_head *stark)
{
	int	i;
	t_item	top;
	t_swap	*my_stark;

	i = 0;
	my_stark = stark->head_a;
	while (my_stark)
	{
		if ((my_stark->num >= v_start) && (my_stark->num <= v_end))
		{
			break;
		}
		i++;
		my_stark = my_stark->next;
	}
	if (my_stark)
	{
		top.index = i;
		top.num = my_stark->num;
	}
	else 
		top.index = -1;
	return (top);
	
}

t_item	ft_find_end(int v_start, int v_end, t_head *stark)
{
	int	i;
	t_item down;
	t_swap	*my_stark;

	i = 0;
	my_stark = ft_getlast(stark->head_a);
	while (my_stark)
	{
		if ((my_stark->num >= v_start) && (my_stark->num <= v_end))
		{
			break;
		}
		i++;
		my_stark = my_stark->prev;
	}
	if (my_stark)
	{
		down.index = i;
		down.num = my_stark->num;
	}
	else 
		down.index = -1;
	return (down);
}

void	ft_push_b(t_head **t_stark)
{
	int	rotate;

	rotate = 0;
	if (!(*t_stark)->head_b)
	{
		ft_pb(*t_stark);
		return ;
	}
	if (ft_im_bigest((*t_stark)->head_a->num, (*t_stark)->head_b))
	{
		ft_pb(*t_stark);
		return ;
	}
	if (ft_im_smallest((*t_stark)->head_a->num, (*t_stark)->head_b))
	{
		ft_pb(*t_stark);
		ft_rb(&(*t_stark)->head_b);
		return ;
	}
	while ((*t_stark)->head_a->num < (*t_stark)->head_b->num)
	{
		ft_rb(&(*t_stark)->head_b);
		rotate++;
	}
	ft_pb(*t_stark);
	while (rotate)
	{
		ft_rrb(&(*t_stark)->head_b);
		rotate--;
	}
	(void)rotate;
	
}

void	ft_down_move(t_item my_item, t_head **t_stark)
{
	if (my_item.index > ((*t_stark)->head_a_size / 2))
	{
		while (my_item.index + 1  > 0)
		{
			ft_ra(&(*t_stark)->head_a);
			my_item.index--;
		}
	}
	else
	{
		while (my_item.index + 1 > 0)
		{
			ft_rra(&(*t_stark)->head_a);
			my_item.index--;
		}
	}
	ft_push_b(t_stark);
	
}
void	ft_top_move(t_item my_item, t_head **t_stark)
{
	if (my_item.index < ((*t_stark)->head_a_size / 2))
	{
		while (my_item.index > 0)
		{
			ft_ra(&(*t_stark)->head_a);
			my_item.index--;
		}
	}
	else
	{
		while (my_item.index > 0)
		{
			ft_rra(&(*t_stark)->head_a);
			my_item.index--;
		}
	}
	ft_push_b(t_stark);
	
}

void	ft_find_and_stock_b(int start, int end, t_head **t_stark)
{
	t_item	top;
	t_item down;

	while ((*t_stark)->head_a)
	{
		top = ft_find_start(start, end, *t_stark);
		down = ft_find_end(start, end, *t_stark);
		if ((top.index == -1) && top.index == -1)
			break;
		if (top.index == -1)
			ft_down_move(down, t_stark);
		if (down.index == -1)
			ft_down_move(top, t_stark);
		if (down.index == top.index)
		{
			if(down.num > top.num)
				ft_down_move(down, t_stark);
			else
				ft_top_move(top, t_stark);
		} else if (down.index < top.index)
			ft_down_move(down, t_stark);
		else
			ft_top_move(top, t_stark);
}
}

void	ft_back_to_a(t_head **t_stark)
{
	while ((*t_stark)->head_b)
	{
		ft_pa(*t_stark);
	}
	
}

void	ft_sort_100(t_head **t_stark)
{
	ft_find_and_stock_b(0, 30, t_stark);
	ft_find_and_stock_b(31, 50, t_stark);
	ft_find_and_stock_b(50, 79, t_stark);
	ft_find_and_stock_b(80, 100, t_stark);
	ft_back_to_a(t_stark);
	//prtlst((*t_stark)->head_a);
}