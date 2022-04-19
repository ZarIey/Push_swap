/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:29:03 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/19 18:09:17 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	errors(argv);
	creation_stack(argc, argv);
	int i = 0;
	int j = 1;
	t_list *test;
//	t_head head;
	
	test = creation_stack(argc, argv);
	i = ft_lstsize(test);
	printf("list a %d arg\n", i);
// 	printf("head %s\n", head.head->content);

    while(test) 
	{
        printf("lst %d contient %s\n",j, test->content);
		j++;
        test = test->next;
	}


}


