/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:27:22 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/21 20:26:42 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
			// !!!!!!!!!!!!!!!!!
			# include <stdio.h>
			// !!!!!!!!!!!!!!!!!
# include "./libft/libft.h"


t_list *creation_stack(int argc, char **argv);
int errors(char **argv);

t_list *creation_b(void *content);

void swap_a(t_list **pstack_a);
void swap_b(t_list **pstack_b);
void swap_both(t_list **pstack_a, t_list **pstack_b);
void push_a(t_list **pstack_a, t_list **pstack_b);
void push_b(t_list **pstack_b, t_list **pstack_a);

void	rotate_a(t_list **pstack_a);
void	rotate_b(t_list **pstack_b);
void	rotate_both(t_list **pstack_a, t_list **pstack_b);



#endif