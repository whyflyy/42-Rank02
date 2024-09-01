/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:34:45 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 14:40:16 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; //O next do anterior do atual ultimo fica null, para este ficar o novo ultimo da stack
	last->next = *stack; //O next do atual ultimo passa a ser o primeiro, para o que era ultimo agora ser o primeiro
	last->prev = NULL; //Como o que era o ultimo esta agora em primeiro, o seu prev tem de ser null
	*stack = last; //Para o primeiro node da stack ser o que era o ultimo
	last->next->prev = last; //O prev do que esta a seguir ao novo primeiro e o novo primeiro (tambem pode ser representado como (*stack)->prev = rotate_bag; mas teria de ser feito antes de fazer o codigo na linha anterior)
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
