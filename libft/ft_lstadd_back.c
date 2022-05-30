/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:59:49 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/16 17:56:06 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*inter;

	if (!new)
		return ;
	inter = ft_lstlast(*alst);
	if (!(*alst))
		*alst = new;
	else
		inter->next = new;
		inter->next_sort = new;
}
