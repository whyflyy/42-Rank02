/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:41:00 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 11:47:43 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next) //Loopa a stack
	{
		if (stack->nbr > stack->next->nbr) //Se o numero do node atual for maior que o proximo nao esta organizada
			return (false);
		stack = stack->next; //Vai para o proximo node
	}
	return (true);
}

int		stack_len(t_stack_node *stack)
{
	int		c; //Variavel para contar os nodes

	if (!stack)
		return (0);
	c = 0;
	while (stack) //Loopa a satack
	{
		stack = stack->next; //Passa para o proximo node
		c++; //Aumenta a contagem de nodes
	}
	return (c);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loopa a stack ate ao ultimo
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack) //Funcao que vai correr uma stack e devolver o node com o menor valor 
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack) //Loopa a stack
	{
		if (stack->nbr < min) //Se o valor do node for menor que o atual minimo
		{
			min = stack->nbr; //Atualiza o minimo para ser esse tal valor
			min_node = stack; //Atualiza a variavel com o node minimo para ser este node
		}
		stack = stack->next;
	}
	return (min_node); //Devolve o node com o valor menor
}

t_stack_node	*find_max(t_stack_node *stack) //Funcao que vai correr uma stack e devolver o node com o menor valor 
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack) //Loopa a stack
	{
		if (stack->nbr > max) //Se o valor do node for maior que o atual maximo
		{
			max = stack->nbr; //Atualiza o maximo para ser esse tal valor
			max_node = stack; //Atualiza a variavel com o node maximo para ser este node
		}
		stack = stack->next;
	}
	return (max_node); //Devolve o node com o valor maior
}
