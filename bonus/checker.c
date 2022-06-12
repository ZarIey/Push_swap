/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:22:57 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/12 17:42:04 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include "../../libft/libft.h"

int	void_arg(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			return (0);
		while (argv[i] && argv[i] == 32)
		{
			if (argv[i] != 32)
			{
				if ((argv[i] >= 48 && argv[i] <= 57))
					return (0);
				return (1);
			}
			i++;
		}
		if ((argv[i] >= 48 && argv[i] <= 57))
			return (0);
		return (1);
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	if (argc == 2)
	{
		if (void_arg(argv[1]) > 0)
			return (1);
	}
	return (0);
}

int	ch_size_list(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return(i);
}

void action_commands(t_checker *checker, char *commands)
{
	if (ft_strncmp(commands, "rrr", 3) == 0)
		ch_reverse_rotate_both(checker);
	if (ft_strncmp(commands, "rra", 3) == 0)
		ch_reverse_rotate_a(&checker->stack_a);
	if (ft_strncmp(commands, "rrb", 3) == 0)
		ch_reverse_rotate_b(&checker->stack_b);
	if (ft_strncmp(commands, "ra", 2) == 0)
		ch_rotate_a(&checker->stack_a);
	if (ft_strncmp(commands, "rb", 2) == 0)
		ch_rotate_b(&checker->stack_a);
	if (ft_strncmp(commands, "pa", 2) == 0)
		ch_push_a(&checker->stack_a, &checker->stack_b);
	if (ft_strncmp(commands, "pb", 2) == 0)
		ch_push_b(&checker->stack_a, &checker->stack_b);
	if (ft_strncmp(commands, "sa", 2) == 0)
		ch_swap_a(&checker->stack_a);
	if (ft_strncmp(commands, "sa\n", 3) == 0)
		ch_swap_b(&checker->stack_b);
}

void	sorted_or_not_uh_uh(t_checker *checker, int size)
{
	t_list	*stack_a;
	int	resize;

	stack_a = checker->stack_a;
	resize = ch_size_list(stack_a);
	if (resize == size)
	{
		while (stack_a->next)
		{
			if (stack_a->content > stack_a->next->content)
			{
				write(1, "KO\n", 3);
				exit(0) ;
			}
			stack_a = stack_a->next;
		}	
	}
	write (1, "OK\n", 3);
}

int main(int argc, char **argv)
{
	t_checker	checker;
	int 		i;
	int			size;
	char		*str;

	if (check_argv(argc, argv) > 0 || argc == 1)
	{
		write (1, "Error\n", 6);
		exit(0);
	}
	errors(argv);
	i = 0;
	checker.stack_a = creation_stack(argc, argv);
	checker.stack_b = NULL;
	size = ch_size_list(checker.stack_a);
	str = "";
	while (str)
	{
		str = get_next_line(0);
		if (str)
		{
			action_commands(&checker, str);
			free(str);
		}
	}
	sorted_or_not_uh_uh(&checker, size);
	return (0);
}



// 	(void)argv;
// //	int count = argc;
// //	int i = 0;
// 	char buff[5];
// 	char **split;
// 	int	command = 0;
// 	char *str;

// 	command = read(STDIN_FILENO, buff, 4);
// 	str = get_next_line(command);
// 	while ()
// 		split = malloc(sizeof (char *) * argc + 1);

	// while (split[i])
	// {
	// 	split[i] = malloc(sizeof(char) * 5);
	// 	i++

