#include "../includes/push_swap.h"
// fichier qui contient les opérations SS, SA, SB, 
//fonction qui permute les deux premiers elèment de la pile A
//elle retourne le premier item de la liste.
void	ft_s(t_swap **head_)
{
	t_swap	*new_head;

	new_head = (*head_)->next;
	if ((*head_)->next->next)
		(*head_)->next->next->prev = (*head_);
	(*head_)->prev = new_head;
	(*head_)->next = new_head->next;
	new_head->next = (*head_);
	(*head_) = new_head;
}

void	ft_sa(t_swap **head_a)
{
	ft_s(head_a);
	ft_printf("sa\n");
}

void	ft_sb(t_swap **head_b)
{
	ft_s(head_b);
	ft_printf("sb\n");
}

void	ft_ss(t_head *first_stark)
{
	ft_s(&(first_stark)->head_a);
	ft_s(&(first_stark)->head_b);
	ft_printf("ss\n");
}
