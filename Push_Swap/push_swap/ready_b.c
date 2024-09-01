/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:11:10 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/30 12:29:00 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			closest_biggest;

	while (b)
	{
		closest_biggest = LONG_MAX; ////No inicio, o melhor 'match' e o maximo long
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr 
				&& current_a->nbr < closest_biggest) //Tem de encontrar o "closest biggest number" ou seja o valor de b tem de ser maior que o valor de a e menor que o melhor match
			{
				closest_biggest = current_a->nbr; //Se for o closest biggest number, atualiza a variavel que o guarda para o valor do b atual
				target_node = current_a; //Atribui a variavel que guarda o target node o node de 'a' atual
			}
			current_a = current_a->next;
		}
		if (closest_biggest == LONG_MAX) //Se o closest biggest for o LONG_MAX quer dizer que nao encontrou nenhum maior
			b->target = find_min(a); //Entao, encontra o menor valor em 'a' e faz com que o node com esse valor seja o target node
		else
			b->target = target_node; //Se nao, muda o valor de target seja a variavel target node
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
