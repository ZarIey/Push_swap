/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:13:47 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/12 18:55:00 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_checker
{
	char	**stack;
	t_list	*stack_a;
	t_list  *stack_b;
} t_checker;

int			size_list(t_list *stack);
int			get_mini(t_list *stack_a);
int			get_maxi(t_list *stack_a);
t_list		*get_last(t_list *stack);
int			nega(int content);
void		error(void);

int			errors(char **argv);
int			check_sorted(t_prog *prog);
t_list		*creation_stack(int argc, char **argv);

void		ghost_sorting(t_list **pstack_a);
void		init_rank(t_list *stack_a, t_prog *prog);

void		sort_triple(t_prog *prog);
void		sort_five(t_prog *prog);

void		all_in_b(t_prog *prog);
int			distance_to_top(t_prog *prog, int tag);
void		double_rotate(t_prog *prog, int *rot_a, int *rot_b);
void		keep_rotating(t_prog *prog, int rot_a, int rot_b);
int			verif_place(t_list *pre, t_list *cur, t_list *x);
int			calcul_rotation_a(t_prog *prog, t_list *stack_a, t_list *x);
int			calcul_rotation_b(int rot_b, int size);
void		ch_double_rotate(t_prog *prog, int *rot_a, int *rot_b);
void		secure_stay(t_prog *prog);
int			check_if_sequence(t_prog *prog);
int			secure_sequence(t_prog *prog);
void		rotate_sequence(t_prog *prog);
void		keep_rotating(t_prog *prog, int rot_a, int rot_b);
t_list		*init_sequence(t_prog *prog, t_list *stack_a);
void		final_sort(t_prog *prog);

void		fake_swap_a(t_list **pstack_a);
void		fake_swap_b(t_list **pstack_b);
void		init_swap(t_prog *prog);
void		swap_test_a(t_prog *prog, t_list *x);
void		swap_test_b(t_prog *prog, t_list *stack_b, t_list *x, int rot_b);

void		ch_swap_a(t_list **pstack_a);
void		ch_swap_b(t_list **pstack_b);
void		ch_swap_both(t_list **pstack_a, t_list **pstack_b);
void		ch_push_a(t_list **pstack_a, t_list **pstack_b);
void		ch_push_b(t_list **pstack_a, t_list **pstack_b);

void		ch_rotate_a(t_list **pstack_a);
void		ch_rotate_b(t_list **pstack_b);
void		ch_rotate_both(t_checker *checker);

void		ch_reverse_rotate_a(t_list **pstack_a);
void		ch_reverse_rotate_b(t_list **pstack_b);
void		ch_reverse_rotate_both(t_checker *checker);

#endif

