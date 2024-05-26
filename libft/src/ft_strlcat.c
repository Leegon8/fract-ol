/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:16:02 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/14 19:19:45 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	long_dst;
	size_t	long_src;
	size_t	total_length;

	i = 0;
	long_dst = ft_strlen((const char *)dst);
	long_src = ft_strlen(src);
	total_length = long_dst + long_src;
	if (n <= long_dst)
	{
		return (long_src + n);
	}
	while (src[i] && (long_dst + i + 1) < n)
	{
		dst[long_dst + i] = src[i];
		i++;
	}
	dst[long_dst + i] = '\0';
	return (total_length);
}
