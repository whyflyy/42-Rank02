/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:19:50 by jcavadas          #+#    #+#             */
/*   Updated: 2024/08/24 12:28:52 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_in_int(char **argv, int argc) //Verifica se os numeros estao dentro dos limites minimos e maximos de int e verifica tambem se tem algum repetido
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i++ < argc)
	{
		while (j++ < argc)
		{
			if (ft_long_atoi(argv[i]) == ft_long_atoi(argv[j]))
			{
				ft_printf("Error");
				return (0);
			}
		}
		j = i + 1;
		if (ft_long_atoi(argv[i]) >= INT_MAX || ft_long_atoi(argv[i]) <= INT_MIN)
		{
			ft_printf("Error");
			return (0);
		}
	}
	return (1);
}

int main(int argc, char **argv)
{
	int 	i;
	int		j;
	long	current_num;

	if (argc > 1)
	{
		i = 1;
		current_num = 0;
		if (argc > 2) //Se os elementos forem um array no terminal
		{
			while (i++ < argc) 
			{
				j = 0;
				while (argv[i][j++]) //Verificar se e tudo digito
				{
					if (!ft_isdigit(argv[i][j]))
					{
						if (!(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+')))
						{
							ft_printf("Error");
							return (0);
						}
					}
				}
				if (check_in_int(argv + 1, argc) == 0)
					return (0);
				// current_num = ft_long_atoi(argv[i]);
				// if (current_num >= INT_MAX || current_num <= INT_MIN)
				// {

				// }
				// //Passar o arg para a stack 
			}
		}
		else  //Se os elementos vierem numa string
		{
			//Posso provavelmente fazer a len da string e correr tudo primeiro a ver se e tudo digitos, 
			//para os menos, se for '-' o anterior tem de ser espaco se nao tem de dar erro a mesma
			//Fazer split

			//FUNCAO depois do split com o array
			//Passar o arg para a stack 
		}
		
	}
	ft_printf("\n");
	return (0);
}
