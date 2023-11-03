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

void	ft_update_cost(t_head **t_stark)
{
	ft_find_closest_in_a(t_stark);
	ft_cacul_cost((*t_stark)->head_b, (*t_stark)->b_middle);
	ft_cacul_cost((*t_stark)->head_a, (*t_stark)->a_middle);
}

t_swap	*ft_get_cheaper(t_swap *stark_a)
{
	int		cheaper;
	int		tmp_cheaper;
	t_swap	*current_stark;
	t_swap	*cheaper_stark;

	current_stark = stark_a;
	cheaper = MAX_INT;
	tmp_cheaper = 0;
	while(current_stark)
	{
		tmp_cheaper = current_stark->before + current_stark->mycost;
		tmp_cheaper = tmp_cheaper + current_stark->new_post->mycost;
		if (tmp_cheaper < cheaper)
		{	
			cheaper_stark = current_stark;
			cheaper = tmp_cheaper;
		}
		current_stark = current_stark->next;
	}
	return (cheaper_stark);
}

void	ft_sort_100(t_head **t_stark)
{
	t_swap	*current_cheaper_stark;
	int		tmp_i_cheaper;
	int i = 0;
	while ((*t_stark)->head_a_size > 3)
		ft_pb(*t_stark);
	ft_sort_3(&(*t_stark)->head_a);
	
	(void)i;
	//while ((*t_stark)->head_b)
	while (i != 9)
	{
		i ++;
		ft_update_cost(t_stark);
		prtlst_basic((*t_stark)->head_a);
		prtlst((*t_stark)->head_b);
		current_cheaper_stark = ft_get_cheaper((*t_stark)->head_b);
		tmp_i_cheaper = current_cheaper_stark->before;
		printf("chepest %d ", current_cheaper_stark->num);
		printf("%d \n", current_cheaper_stark->before);
		(void)tmp_i_cheaper;
		if (current_cheaper_stark->top == current_cheaper_stark->new_post->top)
		while (((*t_stark)->head_a != current_cheaper_stark->new_post)
			&& ((*t_stark)->head_b != current_cheaper_stark))
		{
			if (current_cheaper_stark->new_post->top)
				ft_rrr(t_stark);
			else
				ft_rr(t_stark);
		}
		while ((*t_stark)->head_a != current_cheaper_stark->new_post)
		{	
			if (current_cheaper_stark->new_post->top)
				ft_rra(&(*t_stark)->head_a);
			else
				ft_ra(&(*t_stark)->head_a);
		}
		while ((*t_stark)->head_b != current_cheaper_stark)
		{
			if (current_cheaper_stark->top)
				ft_rrb(&(*t_stark)->head_b);
			else
				ft_rb(&(*t_stark)->head_b);
		}
		if (((*t_stark)->head_b == current_cheaper_stark) &&
			((*t_stark)->head_b->new_post == (*t_stark)->head_a))
			ft_pa(*t_stark);
		//if ((*t_stark)->head_a->num > (*t_stark)->head_a->next->num)
			//&& tmp_i_cheaper == 0)
		//	ft_sa(&(*t_stark)->head_a);
		
		prtlst_basic((*t_stark)->head_a);
	}
//	while (!ft_check_is_sort((*t_stark)->head_a))
//		ft_ra(&(*t_stark)->head_a);
}