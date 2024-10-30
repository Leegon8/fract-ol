/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:54 by lauriago          #+#    #+#             */
/*   Updated: 2024/04/27 17:42:46 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
