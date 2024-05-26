/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:23:31 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/12 14:23:55 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**ft_free(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*start;
	char	**result;

	result = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i])
				return (ft_free(result));
			i++;
		}
	}
	return (result);
}
/*
int main() {
	char str[] = "Hola como estas?";
	char **tokens = ft_split(str, ' ');
	
	if (tokens) {
		int i = 0;
		while (tokens[i]) {
			printf("%s\n", tokens[i]);
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	return 0;
}
*/