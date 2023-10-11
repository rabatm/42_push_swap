#include "../includes/push_swap.h"

void	ft_prterreandfree(char *msg, int err, t_swap *stark)
{
	if (err != 0)
		ft_putstr_fd(msg, 2);
	if(stark)
		ft_destroy_lst(stark);
	exit(err);
}

void	ft_help(void)
{
	ft_putstr_fd("Push_Swap: How to ...\n", 1);
	ft_putstr_fd("To run the program, please use...\n", 1);
	ft_putstr_fd("./push_swap \"Number sequence\"\n", 1);
}