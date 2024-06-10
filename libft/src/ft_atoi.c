/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:21:49 by lauriago          #+#    #+#             */
/*   Updated: 2024/04/27 17:40:12 by lauriago         ###   ########.fr       */
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
/*
int main() {
    const char *str = " -67";

    printf("%d\n", ft_atoi(str));
    printf("Funcion oficial: %d\n", atoi(str));
    return (0);
}*/
