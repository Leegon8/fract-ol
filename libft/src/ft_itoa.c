/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:56:34 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/14 18:59:31 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		count;
	long	num;

	num = n;
	count = 1;
	if (num < 0)
	{
		count++;
		num *= (-1);
	}
	while (num >= 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_len(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	num = n;
	if (num < 0)
		num *= (-1);
	str[ft_len(n) - i++] = '\0';
	while (num >= 10)
	{
		str[ft_len(n) - i++] = (num % 10) + '0';
		num /= 10;
	}
	str[ft_len(n) - i++] = (num % 10) + '0';
	return (str);
}
/*
int main() {
    int n = -67;

    printf("%s\n", ft_itoa(n));
    printf("Funcion oficial: %s\n", itoa(n));
    return (0);
}*/
