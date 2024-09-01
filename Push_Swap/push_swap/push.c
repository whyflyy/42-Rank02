/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:36:31 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 18:30:31 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node *node_to_push;

	if (!*src)
		return ;
	node_to_push = *src; 
	*src = (*src)->next; //Passar o pointer da stack (o primeiro node) seja o atual segundo node
	if (*src)
		(*src)->prev = NULL; //Fazer com que este ex-segundo node nao tenha nada antes, ficando assim efetivamente o primeiro node da stack
	node_to_push->prev = NULL; //Tiramos o anterior do que vai ser pushado para o desprender da stack de destino
	if (!*dst)
	{
		*dst = node_to_push; //Se a stack de destino esta vazia, o node a ser pushado passa a ser o node apontado pelo pointer da stack de destino
		node_to_push->next = NULL; //Como a stack de destino esta vazia, o next do node a ser pushado fica NULL para ficar corretamente terminada a stack
	}
	else
	{
		node_to_push->next = *dst; //O next do node a ser pushado tem de ser o atual primeiro do destino
		node_to_push->next->prev = node_to_push; //O anterior do ex-primeiro do destino tem de ser o que vai ser pushado e vai passar a ser o primeiro
		*dst = node_to_push; //O pointer do destino deve estar a apontar para o novo primeiro
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a,b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b,a);
	ft_printf("pb\n");
}
