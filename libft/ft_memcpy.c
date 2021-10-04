/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 04:49:16 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 19:07:40 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*destt;
	size_t	i;

	srcc = (char *)src;
	destt = (char *)dest;
	i = 0;
	while (n > i)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}
