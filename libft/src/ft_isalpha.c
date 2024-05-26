/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:11:12 by lauriago          #+#    #+#             */
/*   Updated: 2023/10/14 19:16:01 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (1);
	if (i >= 'a' && i <= 'z')
		return (1);
	else
		return (0);
}
