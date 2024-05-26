/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:11:52 by lauriago          #+#    #+#             */
/*   Updated: 2023/09/27 19:20:07 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	size_t				i;

	ptr_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		while (ptr_s[i] == (unsigned char)c)
			return ((void *)(ptr_s + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char s[] = "holaT";
	printf ("%p\n", ft_memchr(s, 't', 5));
	printf ("%p\n", memchr(s, 't', 6));
	return (0);
}
*/
