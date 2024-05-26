/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:27:04 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/12 13:39:08 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_ptr;
	unsigned char		*dest_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr < src_ptr)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	else if (dest_ptr > src_ptr)
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*--dest_ptr = *--src_ptr;
	}
	return (dest);
}
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr < src_ptr)
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else if (dest_ptr > src_ptr)
	{
		while (n > 0)
		{
		n--;
		dest_ptr[n] = src_ptr[n];
		}
	}
	else
		return(NULL);
	return (dest);
}

int main ()
{
	char src[] = "function test";
	char dest[20];
	printf ("%p\n", ft_memmove(dest, src, 8));
	printf ("%p\n", memmove(dest, src, 8));
	return (0);
}*/
