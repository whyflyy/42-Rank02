/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:01:15 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/25 17:19:47 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next) //Verifica se existe o primeiro e segundo node da stack
			return ;
	*stack = (*stack)->next; //Passa o pointer do primeiro da stack para o segundo da stack
	(*stack)->prev->prev = *stack; //Faz com que o prev do segundo da stack seja o primeiro
	(*stack)->prev->next = (*stack)->next; //Aqui o primeiro e segundo tecnicamente ja trocaram, ele so vai buscar ao antigo segundo o next e passa ao antigo primeiro
	if ((*stack)->next) //Vai verificar se o ex-segundo tem um next
		(*stack)->next->prev = 	(*stack)->prev; //Se sim, atualiza o pointer prev desse next para ser o novo segundo 
	(*stack)->next = (*stack)->prev; //Atualiza o next do do ex segundo para ser o prev que ele tinha anteriormente (que era o ex primeiro), trocando assim efetivamente a posicao
	(*stack)->prev = NULL; //Finaliza a operacao passando o prev do novo primeiro a NULL, pois nao tem nada antes dele
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
