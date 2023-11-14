#include "../includes/push_swap.h"

void	ft_prterreandfree(char *msg, int err, t_swap *stark)
{
	if (err != 0)
		ft_putstr_fd(msg, 2);
	if (stark)
		ft_destroy_lst(stark);
	exit (err);
}

void	ft_help(void)
{
	ft_putstr_fd("Push_Swap: How to ...\n", 1);
	ft_putstr_fd("To run the program, please use...\n", 1);
	ft_putstr_fd("./push_swap \"Number sequence\"\n", 1);
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
