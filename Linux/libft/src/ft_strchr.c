/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:11:44 by lauriago          #+#    #+#             */
/*   Updated: 2024/04/27 17:42:53 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
