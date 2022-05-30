/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:27:22 by ctardy            #+#    #+#             */
/*   Updated: 2022/05/30 07:09:00 by ctardy           ###   ########.fr       */
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



			// !!!!!!!!!!!!!!!!!
void print_list (t_prog *prog);
int nega(int content);
			// !!!!!!!!!!!!!!!!!

t_list *creation_stack(int argc, char **argv);
int errors(char **argv);
void	init_rank(t_list *stack_a, t_prog *prog);
int	find_biggest_asc_order(t_list *start, int set);

int size_list(t_list *stack);
int get_mini(t_list *stack_a);
int get_maxi(t_list *stack_a);
int compare_big(int a, int b);

int     check_sorted(t_prog *prog);
void sort_triple(t_prog *prog);
void sort_five(t_prog *prog);
void initial_push(t_list *stack_a, t_list *stack_b);

void	sort(t_list *stack_a, t_list *stack_b);
void	push_bigger(t_list **pstack_a);

void swap_a(t_list **pstack_a);
void swap_b(t_list **pstack_b);
void swap_both(t_list **pstack_a, t_list **pstack_b);
void push_a(t_list **pstack_a, t_list **pstack_b);
void push_b(t_list **pstack_a, t_list **pstack_b);

void	rotate_a(t_list **pstack_a);
void	rotate_b(t_list **pstack_b);
void	rotate_both(t_list **pstack_a, t_list **pstack_b);

void reverse_rotate_a(t_list **pstack_a);
void reverse_rotate_b(t_list **pstack_b);
void reverse_rotate_both(t_list **pstack_a, t_list **pstack_b);



#endif