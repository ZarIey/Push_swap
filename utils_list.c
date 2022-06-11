/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:18:43 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/11 19:09:34 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nega(int content)
{
	if (content < 0)
		return (content *= -1);
	return (content);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
