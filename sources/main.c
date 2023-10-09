#include "../includes/push_swap.h"

void	prtlst(t_swap *stark)
{
	while (stark)
	{
		printf("%d\n", stark->num);
		stark = stark->next;
	}
}

int	main(int argc, char *argv[])
{
	t_swap	*stark_a;
	t_swap	*stark_b;
	t_head	*t_stark;
	
	if (argc < 2)
		return (0);
	stark_a = ft_init_stark(argv);
	if ((ft_check_is_sort(stark_a)) || ft_check_doublons(stark_a))
	{
		ft_destroy_lst(stark_a);
		ft_printf("finito pipo\n");
		return (0);
	}
		ft_printf("BEFORE SA\n");
		prtlst(stark_a);
		ft_printf("AFTER SA\n");
		stark_a = ft_sa(stark_a);
		prtlst(stark_a);
		return (0);
	
}
