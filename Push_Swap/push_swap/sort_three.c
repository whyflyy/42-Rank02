/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:54:30 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 18:30:35 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a); //tenho de programar esta funcao
	if (biggest_node == *a)
		ra(a); //tenho de programar esta funcao
	else if ((*a)->next == biggest_node)
		rra(a); //tenho de programar esta funcao
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a); //tenho de programar esta funcao
}