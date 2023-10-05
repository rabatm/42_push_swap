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

t_swap *ft_init_stark(char *val[])
{
	int i;
	t_swap *current_stark;
	t_swap *prev_stark;
	t_swap *first_stark;

	i = 1;
	prev_stark = NULL;
	while (val[i])
	{
		current_stark = ft_lst_mk_item(ft_atoi(val[i]));
		if (i > 1)
			ft_lst_add_prev(current_stark, prev_stark);
		else 
			first_stark = current_stark;
		prev_stark = current_stark;

		i++;
	}
	return first_stark;
}

void	ft_destroy_lst(t_swap *first_start)
{
	t_swap	*current_stark;
	t_swap	*next_stark;

	current_stark = first_start;
	while (current_stark)
	{
		if(current_stark->next)
			next_stark = current_stark->next;
		else 
			next_stark = NULL;
		if (current_stark)
			free(current_stark);
		current_stark = next_stark;
	}
	current_stark = NULL;
	next_stark = NULL;
}
