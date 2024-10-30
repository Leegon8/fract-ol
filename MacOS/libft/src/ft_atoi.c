/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:21:49 by lauriago          #+#    #+#             */
/*   Updated: 2024/06/18 12:02:16 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	n;

	result = 0;
	n = 1;
	while (*str && (*str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
	{
		str++;
	}
	if (*str && *str == '-')
		n = -1;
	if (*str && (*str == '+' || *str == '-'))
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * n);
}

double	ft_atod(char *str)
{
	long	int_part;
	double	fract_part;
	double	pow;
	int		n;

	int_part = 0;
	fract_part = 0;
	pow = 1;
	n = +1;
	while (ft_isspace(*str))
		str++;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			n = -n;
	while (*str != '.' && *str)
		int_part = (int_part * 10) + (*str++ - 48);
	if (*str == '.')
		++str;
	while (*str)
	{
		pow /= 10;
		fract_part = fract_part + (*str++ - 48) * pow;
	}
	return ((int_part + fract_part) * n);
}

/*
int main() {
    const char *str = " -67";

    printf("%d\n", ft_atoi(str));
    printf("Funcion oficial: %d\n", atoi(str));
    return (0);
}*/
