/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:02:01 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/14 20:02:22 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *cpr, const char *subc, size_t n)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	result = (char *)cpr;
	if (subc[0] == '\0')
		return (result);
	if (n == 0 || cpr[0] == '\0')
		return (NULL);
	while (i < n && cpr[i] != '\0')
	{
		j = 0;
		while (cpr[i + j] == subc[j] && i + j < n)
		{
			if (subc[j +1] == '\0')
			{
				result = (char *)(cpr + i);
				return (result);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main() 
{
	char s1[] = "";
	char s2[] = "";
	printf("%s\n", ft_strnstr(s1, s2, 0));
	printf("%ld\n", (void *)ft_strnstr(s1, s2, 0) - (void *)s1);
	printf("%s\n", strnstr(s1, s2, 0));
	//printf("%d\n", strnstr(s1, s2, 15) - (int)s1);
}*/
