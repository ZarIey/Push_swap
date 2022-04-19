/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:27:22 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/19 18:06:22 by ctardy           ###   ########.fr       */
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


#endif