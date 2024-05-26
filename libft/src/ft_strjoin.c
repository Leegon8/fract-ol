/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:28:03 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/12 14:39:21 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s2[i])
	{
		total += ft_strlen((char *)s2);
		i++;
	}
	total = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(total + 1);
	if (!s3)
		return (NULL);
	while (j < i)
	{
		ft_strlcat(s3, s1, total);
		j++;
		if (s2[j + 1])
		{
			ft_strlcat(s3, s1, total);
		}
	}
	return (s3);
}

int	main(void)
{
	char const s1[] = "hola";
	char const s2[] = " bro";
	
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/