/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:17:41 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/10 19:47:58 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*charstack;

	charstack = (char *) h;
	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (charstack);
	while (charstack[i] && needle[j])
	{
		if (charstack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (!(needle[j]) && len >= i)
		return (&charstack[i - j]);
	return (NULL);
}
/*
int main (int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("%s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	return (0);
}
*/