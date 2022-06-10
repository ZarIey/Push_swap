/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:26:47 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 14:57:50 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_content(t_list **pstack, int content)
{
	t_list	*inter;

	inter = ft_lstnew(content);
	inter->content = content;
	inter->next = *pstack;
	*pstack = inter;
}
