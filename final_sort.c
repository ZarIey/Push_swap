/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:28:35 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/09 17:33:58 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_in_b(t_prog *prog)
{
	t_list	*stack_a;

	stack_a = prog->stack_a;
	while (stack_a && stack_a->stay != 1)
	{
		push_b(&prog->stack_a, &prog->stack_b);
		stack_a = prog->stack_a;
	}
	prog->size = size_list(stack_a);
}

void	double_rotate(t_prog *prog, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		rotate_both(prog, *rot_a, *rot_b);
		(*rot_a)--;
		(*rot_b)--;
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		reverse_rotate_both(prog, *rot_a, *rot_b);
		(*rot_a)++;
		(*rot_b)++;
	}
}

void	keep_rotating(t_prog *prog, int rot_a, int rot_b)
{
	double_rotate(prog, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		rotate_a(&prog->stack_a);
	}
	while (rot_a < 0)
	{
		rot_a++;
		reverse_rotate_a(&prog->stack_a);
	}
	while (rot_b > 0)
	{
		rot_b--;
		rotate_b(&prog->stack_b);
	}
	while (rot_b < 0)
	{
		rot_b++;
		reverse_rotate_b(&prog->stack_b);
	}
}

int	calcul_rotation_a(t_prog *prog, t_list *stack_a, t_list *stack_b, t_list *inter)
{
	int place;
	int place_max;
	int i;
	t_list *pre;
	t_list *cur;
	

	(void)stack_b;
	pre = get_last(stack_a);
	cur = stack_a;
	i = 0;
	place_max = INT_MAX;
	while (cur)
	{
		if ((pre->index > cur->index && (inter->index < cur->index || inter->index > pre->index)) 
		 	|| (inter->index > pre->index && inter->index < cur->index))
		{
				place = i;
				if (place > prog->size / 2)
					place -= prog->size;
				if (nega(place) < place_max)
					place_max = place;
			// }
		}
		i++;
		pre = cur;
		cur = cur->next;		
	}
	return (place_max);
}

t_list	*take_fastest_moove(t_list *stack_b)
{
	t_list *save_list;
	int i;
	int j;
	int k[2];
	
	save_list = stack_b;
	k[0] = INT_MAX;
	while (stack_b)
	{
		i = stack_b->rot_a;
		j = stack_b->rot_b;
		k[1] = nega(i) + nega(j);
		if (k[1] < k[0])
		{
			k[0] = k[1];
			save_list = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (save_list);
}

int calcul_rotation_b(int rot_b, int size)
{
	int i;

	i = rot_b;
	if (i > size / 2)
		i -= size;
	return (i);
}

void print_one_list2(t_list **stack_a, t_list *list)
{
	t_list *inter;

	inter = *stack_a;
	while (inter && inter != list)
	{
		inter = inter->next;
	}
}

void save_rot(t_prog *prog)
{
	t_list *stack_b;
	int i;
	int size;

	stack_b = prog->stack_b;
	i = 0;
	size = size_list(stack_b);
	while (stack_b)
	{
		stack_b->rot_a = calcul_rotation_a(prog, prog->stack_a, prog->stack_b, stack_b);
		stack_b->rot_b = calcul_rotation_b(i, size);
		i++;
		stack_b = stack_b->next;
	}
}

void final_sort(t_prog *prog)
{

	t_list *save;

	t_list *stack_b;
	int i;

	i = 0;
	all_in_b(prog);
	stack_b = prog->stack_b;
	while (stack_b)
	{
		save_rot(prog);
		save = take_fastest_moove(prog->stack_b);
		keep_rotating(prog, save->rot_a, save->rot_b);
		push_a(&prog->stack_a, &prog->stack_b);
		prog->size++;
		stack_b = prog->stack_b;
	}
	keep_rotating(prog, distance_to_top(prog, 0), 0);
}