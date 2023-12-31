#include "../includes/push_swap.h"

t_swap *ft_lst_mk_item(int valini)
{
	t_swap *stark;

	stark = malloc(sizeof(t_swap));
	if (!stark)
		return NULL;
	stark->num = valini;
	stark->next = NULL;
	stark->prev = NULL;
	return (stark);
}
void ft_lst_add_next(t_swap *st_current, t_swap *st_next)
{
	st_current->next = st_next;
	st_next->prev = st_current;
}
void ft_lst_add_prev(t_swap *st_current, t_swap *st_prev)
{
	st_current->prev = st_prev;
	st_prev->next = st_current;
}

t_head *ft_init_stark(char *val[], t_head *t_stark)
{
	int i;
	t_swap *current_stark;
	t_swap *prev_stark;
	t_swap *first_stark;
	int	tmp_num;

	i = 1;
	prev_stark = NULL;
	while (val[i])
	{
		tmp_num = ft_atoi(val[i]);
		current_stark = ft_lst_mk_item(tmp_num);
		if (i > 1)
			ft_lst_add_prev(current_stark, prev_stark);
		else 
			first_stark = current_stark;
		prev_stark = current_stark;
		i++;
	}
	t_stark->head_a = first_stark;
	t_stark->head_a_size = i - 1;
	return t_stark;
}

void	ft_destroy_lst(t_swap *first_start)
{
    t_swap	*current_stark;
    t_swap	*next_stark;

    if (!first_start)
        return ;
    current_stark = first_start;
    while (current_stark)
    {
        next_stark = current_stark->next;
        free(current_stark);
        current_stark = next_stark;
    }
}

t_swap	*ft_getlast(t_swap *my_stark)
{
	t_swap	*tmp_stark;

	tmp_stark = my_stark;
	if (!tmp_stark)
		return (NULL);
	while (tmp_stark->next)
	{
		tmp_stark = tmp_stark->next;
	}
	
	return (tmp_stark);
}	