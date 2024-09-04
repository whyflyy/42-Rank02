/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:44:34 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 18:30:35 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !(*stack) ||  !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->next = *stack; //O proximo a seguir ao ultimo node e o atual primeiro
	*stack = (*stack)->next; //O Segundo passa a ser o primeiro
	(*stack)->prev = NULL; //O anterior do novo primeiro e null, pois nao tem nada antes dele
	last->next->prev = last; //O anterior do agora ultimo(antigo primeiro) e o anterior ultimo node
	last->next->next = NULL; //O agora ultimo (antes primeiro) nao tem proximo, logo tem de se igualar a null para fechar a stack corretamente
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
