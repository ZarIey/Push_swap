/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:22:30 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/25 14:13:11 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*inter;

	while (*lst)
	{
		del((*lst)->content);
		inter = *lst;
		*lst = inter->next;
		free(inter);
	}
	*lst = NULL;
}*/
