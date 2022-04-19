/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:29:57 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/22 18:25:49 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*new_lst(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_list	*last_lst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void back_lst(t_list *lst, int content)
{
	t_list	*inter;

	if (!content)
		return ;
	inter = last_lst(lst);
	//if (!(lst))
		//return ;
	//else
		inter->next = new_lst(content);
}

void	argv_reader(char **argv)
{
	t_list *head;
	int i;

	i = 1;
	head = new_lst(ft_atoi(argv[i++]));
	//head->next = new_lst(ft_atoi(argv[i]));
	while (argv)
	{
		head->next = new_lst(ft_atoi(argv[i]));
		back_lst(head, ft_atoi(argv[i++]));
		head->next = NULL;
	}
		
	printf("valeur de lst %d\n", head->content);
//	printf("valeur de lst 2 %d\n", head->next->content);
	
}

int main (int argc, char **argv)
{
	argv_reader(argv);
	return (0);
}