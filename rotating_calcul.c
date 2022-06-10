/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_cacul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:46:33 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 17:47:08 by ctardy           ###   ########.fr       */
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

int	verif_place(t_list *pre, t_list *cur, t_list *x)
{
	if ((pre->index > cur->index && (x->index < cur->index
				|| x->index > pre->index))
		|| (x->index > pre->index && x->index < cur->index))
		return (1);
	return (0);
}

int	calcul_rotation_a(t_prog *prog, t_list *stack_a, t_list *x)
{
	t_list	*pre;
	t_list	*cur;
	int		place;
	int		place_max;
	int		i;

	pre = get_last(stack_a);
	cur = stack_a;
	place_max = INT_MAX;
	i = 0;
	while (cur)
	{
		if (verif_place(pre, cur, x) > 0)
		{
			place = i;
			if (place > prog->size / 2)
				place -= prog->size;
			if (nega(place) < place_max)
				place_max = place;
		}
		i++;
		pre = cur;
		cur = cur->next;
	}
	return (place_max);
}

int	calcul_rotation_b(int rot_b, int size)
{
	int	i;

	i = rot_b;
	if (i > size / 2)
		i -= size;
	return (i);
}
