/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:26:46 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/06 18:23:30 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_one_list(t_list **stack_a, t_list *list); 

void secure_stay(t_prog *prog)
{
	t_list *stack_a;

	stack_a = prog->stack_a;
	while (stack_a)
	{
		stack_a->stay = 0;
		stack_a = stack_a->next;
	}
}

t_list *init_sequence(t_prog *prog)
{
	t_list *stack_a;
	t_list *stack_first;
	t_list *stack_save;
	int i;

	stack_first = prog->stack_a;
	stack_save = NULL;
	stack_a = prog->stack_a;
	prog->strike = -1;
	while (stack_a->next)
	{
		i = 0;
		while (stack_a->next && stack_a->content < stack_a->next->content)
		{
			 if (i == 0)
				stack_first = stack_a;
			i++;
			stack_a = stack_a->next;
		}
		if (prog->strike <= i)
		{
			prog->strike = i;
			stack_save = stack_first;
		}
		if (i == 0)
			stack_a = stack_a->next;
	}
	return (stack_save);
}

int secure_sequence(t_prog *prog)
{
	t_list *stack_a;
	t_list *stack_save;
	int i;
	int j;

	stack_a = prog->stack_a;
	i = 0;
	j = 0;
	int distance;

	stack_save = init_sequence(prog);
	distance = distance_to_top(prog, stack_save->index);
//	printf("Hey la distance est a %d\n", distance);
	while (stack_a)
	{
		while (i < distance)
		{
			stack_a = stack_a->next;
			i++;
		}
		secure_stay(prog);
		while (stack_a && j <= prog->strike)
		{
			stack_a->stay = 1;
			stack_a = stack_a->next;
			j++;
		}
		break;
	}
	return (i);
}

void rotate_sequence(t_prog *prog)
{
	int i;
	int j;
	int k;
	t_list *stack_save;
	t_list *stack_a;

	stack_a = prog->stack_a;
	stack_save = init_sequence(prog);	
	i = distance_to_top(prog, stack_save->index);
//	printf("Valeur de i : %d\n", i);
//	print_one_list(&stack_a, stack_save);
	j = i + prog->strike;
	k = prog->size - j;
//	printf("Valeur de size : %d\n", prog->size);
//	printf("Valeur de strike : %d\n", prog->strike);
//	printf("Valeur de j : %d\n", j);
//	printf("Valeur de k : %d\n", k);
//	printf("avant secure\n");
	secure_sequence(prog);
	printf("apres secure\n");
	if (k > i)
	{
//	printf("1er cas\n");
		while (j >= 0)
		{
//		printf("boucle cas 1\n");
			rotate_a(&prog->stack_a);
			j--;
		}
		return ;
	}
	while (k > 1)
	{
//		printf("boucle cas 2\n");
		reverse_rotate_a(&prog->stack_a);
		k--;
	}
//	printf("fini\n");
}

// 	if (i >= prog->size)
// 	{
// 		i -= prog->size;
// 		while (i < (nega(prog->strike)))
// 		{
// 			reverse_rotate_a(&prog->stack_a);
// 			i++;
// 		}
// 		return ;
// 	}
// 	while (i > (i - (prog->strike)))
// 	{
// 		rotate_a(&prog->stack_a);
// 		i--;
// 	}



