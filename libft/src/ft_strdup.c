/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:30:53 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/12 13:37:06 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	*originalStr;
	char		*duplicatedStr;

	originalStr = "test function";
	// Llama a ft_strdup para duplicar la cadena original
	duplicatedStr = ft_strdup(originalStr);
	if (duplicatedStr != NULL)
	{
		// printf("Original string: %s\n", originalStr);
		printf("%s\n", duplicatedStr);
		printf("%s\n", strdup(originalStr));
		// Asegúra de liberar la memoria
		free(duplicatedStr);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}*/