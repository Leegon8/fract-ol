/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:21:49 by lauriago          #+#    #+#             */
/*   Updated: 2023/09/27 16:30:37 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	n;

	result = 0;
	n = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			n = -1;
	}	str++;
	while (*str && ft_isdigit(*str))
	{
		if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && 
					*str - '0' > INT_MAX % 10))
			return (n == 1) ? INT_MAX : INT_MIN;
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * n);
}
/*
int main() {
    const char *str = " -0000000023967";

    printf("%d\n", ft_atoi(str));
    printf("Funcion oficial: %d\n", atoi(str));
    return (0);
}*/
