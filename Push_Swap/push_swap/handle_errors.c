/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:35:19 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/31 16:42:12 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		syntax_error(char *nbr)
{
	if (!(*nbr == '-' || *nbr == '+' || (*nbr >= '0' && *nbr <= '9'))) //Verifica se o primeiro caracter nao e ou um sinal ou um digito
		return (1);
	if ((*nbr == '-' || *nbr == '+') && !(nbr[1] >= '0' && nbr[1] <= '9')) //Verifica se o primeiro caracter e um sinal e se o segundo nao e um digito
		return (1);
	while (*++nbr) //pre incrementa para nao verificar o primeiro de novo (caso seja sinal, e o caso de ser digito ja estao considerados em cima)
	{
		if (!(*nbr >= '0' && *nbr <= '9')) //Loopa o "numero" que e uma string ainda e verifica se sao somente digitos
			return (1);
	}
	return (0);
}

int		duplicate_check(t_stack_node *stack, int n)
{
	if (!stack) //Verifica se a stack esta vazia (se estiver e impossivel ter um repetido)
		return (0);
	while (stack)
	{
		if (stack->nbr == n) //Verifica se o nbr do node e igual ao numero a analisar
			return (1);
		stack = stack->next; //passa para o proximo da stack
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*node;

	if (!stack)
		return ;
	node = *stack; //Atribui a variavel node o node atual
	while (node)
	{
		temp = node->next; //Passa o next do atual para a variavel temp porque depois do atual ser freed ja nao seria possivel acessar o seu next
		node->nbr = 0; //Nao e obrigatorio, mas igualo o nbr a 0 para evitar erros de leaks e ajudar com o debugging
		free(node);
		node = temp; //Atribui o temp ao node, para continuar o loop ate nao haver mais nada na stack
	}
	*stack = NULL; //Igualo o pointer da stack a NULL para terminar de libertar tudo
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
