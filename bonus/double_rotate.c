/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:56:51 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 18:57:59 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
