#include "../includes/push_swap.h"

void	prtlst_basic(t_swap *stark)
{
	while (stark)
	{
		printf("num : %d \n", stark->num);
		stark = stark->next;
	}
}

void	prtlst(t_swap *stark)
{
	while (stark)
	{
		printf("num : %d cost : %d dest : %d befor : %d costtotal : %d\n", stark->num, stark->mycost, stark->new_post->num, 
		stark->before, (stark->new_post->mycost+ stark->mycost + stark->before));
		stark = stark->next;
	}
}

void	prtlst_a(t_swap *stark)
{
	while (stark)
	{
		printf("num : %d mycost : %d\n", stark->num, stark->mycost);
		stark = stark->next;
	}
}

int	main(int argc, char *argv[])
{
	t_head	*t_stark;

	if (argc < 2)
		return (0);
	t_stark = malloc(sizeof(t_head));
	t_stark = ft_init_stark(argv, t_stark);
	if ((ft_check_is_sort(t_stark->head_a)) || ft_check_doublons(t_stark->head_a))
	{
		ft_destroy_lst(t_stark->head_a);
		ft_printf("finito pi po\n");
		return (0);
	}
	//prtlst_basic(t_stark->head_a);
	ft_sort_100(&t_stark);
		prtlst(t_stark->head_b);
		prtlst_a(t_stark->head_a);
		//prtlst_basic(t_stark->head_a);
		return (0);
}