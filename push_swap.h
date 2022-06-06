/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:27:22 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/06 17:08:14 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

int secure_sequence(t_prog *prog);
t_list *init_sequence(t_prog *prog);
void rotate_sequence(t_prog *prog);
void keep_rotating (t_prog *prog, int rot_a, int rot_b);


t_list *creation_stack(int argc, char **argv);
int errors(char **argv);
void	init_rank(t_list *stack_a, t_prog *prog);
int	find_biggest_asc_order(t_list *start, int set);

int size_list(t_list *stack);
int get_mini(t_list *stack_a);
int get_maxi(t_list *stack_a);
int compare_big(int a, int b);
int compare_little(int a, int b);
t_list *get_last(t_list *stack);

int     check_sorted(t_prog *prog);
void sort_triple(t_prog *prog);
void sort_five(t_prog *prog);
void initial_push(t_list *stack_a, t_list *stack_b);
void final_sort(t_prog *prog);

void	sort(t_list *stack_a, t_list *stack_b);
void	ghost_sorting(t_list **pstack_a);
int distance_to_top(t_prog *prog, int tag);

void swap_a(t_list **pstack_a);
void swap_b(t_list **pstack_b);
void swap_both(t_list **pstack_a, t_list **pstack_b);
void push_a(t_list **pstack_a, t_list **pstack_b);
void push_b(t_list **pstack_a, t_list **pstack_b);

void	rotate_a(t_list **pstack_a);
void	rotate_b(t_list **pstack_b);
void	rotate_both(t_prog *prog, int rot_a, int rot_b);

void reverse_rotate_a(t_list **pstack_a);
void reverse_rotate_b(t_list **pstack_b);
void reverse_rotate_both(t_prog *prog, int rot_a, int rot_b);



#endif