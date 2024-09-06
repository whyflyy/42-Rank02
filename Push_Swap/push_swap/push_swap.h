/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:57:01 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/31 14:13:28 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
} t_stack_node; //Escreve-se este t_stack_node para se chamar por ele na funcao assim em vez de se ter de escrever sempre 'struct s_stack_node'

//Movements
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);

//Algorithm
void	sort_three(t_stack_node **a);

//Utils
bool	sorted(t_stack_node *stack);
int		stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//Handle_errors
int		syntax_error(char *nbr);
int		duplicate_check(t_stack_node *stack, int n);
void	free_stack(t_stack_node **stack);
void	error(t_stack_node **stack);
void	free_argv(char **argv);

//Node Initialization
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);
void	current_index(t_stack_node *stack);

//Init Stack
void	init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	move_to_top(t_stack_node **stack, t_stack_node *node_for_top, char stack_name);

//Sort
void	sort_stacks(t_stack_node **a, t_stack_node **b);

//Others
char	**split(char *s, char c);

//incluir todas as funcoes que nao sao estaticas
//Handle errors
//Stack initalization
//Nodes initialization
//Stacks utils
//Commands
//Algorithms

#endif