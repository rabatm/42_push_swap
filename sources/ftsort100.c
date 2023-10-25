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
	top.index = i;
	top.num = my_stark->num;
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
	down.index = i;
	down.num = my_stark->num;
	return (down);
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
	ft_pb(*t_stark);
	
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
	ft_pb(*t_stark);
	
}

void	ft_sort_100(t_head **t_stark)
{
	t_item	top;
	t_item down;

	prtlst((*t_stark)->head_a);
	while ((*t_stark)->head_a)
	{
		top = ft_find_start(0, 19, *t_stark);
		down = ft_find_end(0, 19, *t_stark);
		if (down.index == top.index)
		{
			if(down.num < top.num)
				ft_down_move(down, t_stark);
			else
				ft_top_move(top, t_stark);
		}
		if (down.index < top.index)
			ft_down_move(down, t_stark);
		else
			ft_top_move(top, t_stark);	
	prtlst((*t_stark)->head_b);
	}
	
	
	prtlst((*t_stark)->head_b);
}