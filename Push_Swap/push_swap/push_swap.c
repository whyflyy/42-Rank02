/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:47:38 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/31 14:39:22 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1); //tenho de testar esta funcao //tem argv + 1 porque queremos comecar pelo segundo elemento pois o primeiro e o nome de programa
	if (!sorted(a)) //tenho de testar esta funcao
	{
		if (stack_len(a) == 2) //tenho de programar esta funcao
			sa(&a); //tenho de programar esta funcao
		else if (stack_len(a) == 3) //tenho de programar esta funcao
			sort_three(&a); //tenho de programar esta funcao
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a); //tenho de programar esta funcao
	return (0);
}
