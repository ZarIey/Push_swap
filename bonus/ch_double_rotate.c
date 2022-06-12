/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_double_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:52:26 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/12 15:27:58 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	double_rotate(t_prog *prog, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		ch_rotate_both(prog, *rot_a, *rot_b);
		(*rot_a)--;
		(*rot_b)--;
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		ch_reverse_rotate_both(prog, *rot_a, *rot_b);
		(*rot_a)++;
		(*rot_b)++;
	}
}
