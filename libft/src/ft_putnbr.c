/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:42:33 by lauriago          #+#    #+#             */
/*   Updated: 2023/11/12 20:29:40 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putnbr(int num)
{
	int	count;
	int	temp;

	count = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num = -num;
		count++;
	}
	temp = ft_putunbr(num);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
/*
int main(void)
{
	int num = 999;
	ft_putnbr(num);
	printf("\n%d", num);
	return (0);
}*/
