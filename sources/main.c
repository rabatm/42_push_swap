#include "../includes/push_swap.h"

void	prtlst_basic(t_swap *stark)
{
	while (stark)
	{
		printf("%d\n", stark->num);
		stark = stark->next;
	}
}

void	prtlst(t_swap *stark)
{
	while (stark)
	{
		printf("num : %d cost : %d dest : %d costtotal : %d\n", stark->num,
			stark->mycost, stark->new_post->num,
			(stark->new_post->mycost + stark->mycost));
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
	if (t_stark == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	t_stark = ft_init_stark(argv, t_stark);
	if (ft_check_doublons(t_stark->head_a) == 1)
	{
		ft_printf("Error\n");
		ft_destroy_lst(t_stark->head_a);
		free(t_stark);
		return (0);
	}
	if (ft_check_is_sort(t_stark->head_a) == 1)
	{
		ft_destroy_lst(t_stark->head_a);
		free(t_stark);
		return (0);
	}
	ft_sort_100(&t_stark);
	ft_destroy_lst(t_stark->head_a);
	ft_destroy_lst(t_stark->head_b);
	free(t_stark);
	return (0);
}
