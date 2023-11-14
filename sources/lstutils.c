#include "../includes/push_swap.h"

t_swap	*ft_lst_mk_item(int valini)
{
	t_swap	*stark;

	stark = malloc(sizeof(t_swap));
	if (!stark)
		return (NULL);
	stark->num = valini;
	stark->top = 0;
	stark->next = NULL;
	stark->prev = NULL;
	return (stark);
}

void	ft_lst_add_next(t_swap *st_current, t_swap *st_next)
{
	st_current->next = st_next;
	st_next->prev = st_current;
}

void	ft_lst_add_prev(t_swap *st_current, t_swap *st_prev)
{
	st_current->prev = st_prev;
	st_prev->next = st_current;
}

t_head	*ft_init_val(t_head *t_stark, int i)
{
	t_stark->head_b = NULL;
	t_stark->head_b_size = 0;
	t_stark->b_middle = 0;
	t_stark->head_a_size = i - 1;
	t_stark->a_middle = i / 2;
	return (t_stark);
}

t_head	*ft_init_stark(char *val[], t_head *t_stark, int initi)
{
	int		i;
	t_swap	*current_stark;
	t_swap	*prev_stark;
	t_swap	*first_stark;
	int		tmp_num;

	i = initi;
	prev_stark = NULL;
	while (val[i])
	{
		tmp_num = ft_atoi(val[i]);
		current_stark = ft_lst_mk_item(tmp_num);
		if (i > initi)
			ft_lst_add_prev(current_stark, prev_stark);
		else
			first_stark = current_stark;
		prev_stark = current_stark;
		i++;
	}
	t_stark->head_a = first_stark;
	t_stark = ft_init_val(t_stark, i);
	return (t_stark);
}
