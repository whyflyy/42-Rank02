/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:40:00 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 11:46:51 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n) //Funcao que vai anexar um node ao fim de uma stack 
{
	t_stack_node	*node; //pointer para o novo node 
	t_stack_node	*last_node; //Pointer para o ultimo node da stack dada

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); 
	if (!node)
		return ;
	node->next = NULL; //O proximo do novo node deve ser NULL pois ele vai ficar no fim da stack
	node->nbr = n; //Coloca o valor do node para o 'n'
	if (!(*stack)) //Verifica se a stack esta vazia, se sim, o node vai ser o primeiro da stack
	{
		*stack = node; //Como e o primeiro node, o pointer da stack vai ser este novo node
		node->prev = NULL; //Como e o primeiro node, nao tem nenhum antes dele
	}
	else
	{
		last_node = find_last(*stack); //Vai procurar o ultimo node da stack
		last_node->next = node; //O proximo do ultimo node e o novo node
		node->prev = last_node; //O anterior do novo node e o ultimo node
	}
}

void	init_stack_a(t_stack_node **a, char **argv) //Funcao que inicia a stack a, para depois colocar os nodes com os valores de argv nela
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error(a);
		n = ft_long_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Verifica se esta dentro dos Inteiros
			error(a);
		if (duplicate_check(*a, (int)n))
			error(a);
		append_node(a, (int)n); //Se nao tiver erros, agrega o node a stack, com o valor n no node
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack) //Verifica se a stack existe 
		return (NULL);
	while (stack)
	{
		if (stack->cheapest) //Verifica o boolean no node, ou sejas, se e o cheapest
			return (stack); //Devolve esse node
		stack = stack->next;
	}
	return (NULL);
}

void	move_to_top(t_stack_node **stack, t_stack_node *node_for_top, char stack_name) //Funcao que vai mover o node pedido para o topo da stack (para depois este ser pushado)
{
	while (*stack != node_for_top) //Verifica se o node pretendido ja nao esta no topo, e faz um loop ate este estar no topo
	{ 
		if (stack_name == 'a')
		{
			if (node_for_top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (node_for_top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
