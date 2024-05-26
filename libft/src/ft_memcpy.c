/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:56:40 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/14 21:23:10 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src)
	{
		return (0);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
int	main(void)
{
	printf("%p\n", ft_memcpy("       ",((void *)0), 17));
	printf("%p\n", memcpy("  ",(void *)0), 17));
	return (0);
}*/
