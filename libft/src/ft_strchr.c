/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:11:44 by lauriago          #+#    #+#             */
/*   Updated: 2023/09/22 13:15:48 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (*s != (char)c))
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *) NULL);
}
/*
int	main(void)
{
	char str[] = "function test";
	printf("%s\n", ft_strchr(str, 't'));
	printf("%s\n", strchr(str, 't'));
	return (0);
}*/
