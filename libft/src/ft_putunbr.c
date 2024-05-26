/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:54 by lauriago          #+#    #+#             */
/*   Updated: 2023/11/09 13:10:41 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	tmp;

	count = 0;
	if (n > 9)
	{
		tmp = ft_putunbr(n / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (++count);
}
