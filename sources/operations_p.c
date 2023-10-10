#include "../includes/push_swap.h"
//fonction qui copi l'element au top de a 
//et le mets u top de b.
t_head	*ft_pb(t_head *t_stark)
{
    t_swap	*temp_item;

    temp_item = NULL;
    if (!t_stark->head_a)
        return (NULL);
    t_stark->head_b = t_stark->head_a;
    t_stark->head_a = t_stark->head_a->next;
    t_stark->head_a->prev = NULL;
    return (t_stark);
}
