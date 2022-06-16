/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:13:47 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/16 16:02:23 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_checker
{
	char	**stack;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_checker;

int			errors(char **argv);
int			check_sorted(t_checker *checker);
t_list		*creation_stack(int argc, char **argv);

int			ch_size_list(t_list *stack_a);
void		action_commands(t_checker *checker, char *commands);
void		checker_b_not_empty(t_checker *checker, char *commands);
void		sorted_or_not_uh_uh(t_checker *checker, int size);

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
