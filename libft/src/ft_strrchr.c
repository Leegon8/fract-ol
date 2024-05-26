/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:34:05 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/12 13:03:32 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*n;

	n = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			n = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (n);
}

/*
int	main(void)
{
	char p[50] = "hola como estas";
	printf("antes de memset: %s\n", p);
	ft_memset(p, 'p', 5);
	printf("despues: %s\n", p);
	return (0);
}*/
