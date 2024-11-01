/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:58:14 by lauriago          #+#    #+#             */
/*   Updated: 2024/04/27 17:42:35 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>

int	ft_toupper(int x)
{
	if (x >= 'a' && x <= 'z')
		return (x - 'a' + 'A');
	return (x);
}

int	ft_puthex(unsigned long n, int uppercase)
{
	int		count;
	int		tmp;
	char	hex_char;

	count = 0;
	if (n > 15)
	{
		tmp = ft_puthex(n / 16, uppercase);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	hex_char = "0123456789abcdef"[n % 16];
	if (uppercase)
		hex_char = ft_toupper(hex_char);
	if (ft_putchar(hex_char) == -1)
		return (-1);
	return (++count);
}
