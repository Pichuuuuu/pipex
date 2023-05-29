/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 06:10:38 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 19:07:22 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*srcc;
	char	*destt;
	size_t	i;

	srcc = (char *)src;
	destt = (char *)dest;
	i = 0;
	while (i < n)
	{
		destt[i] = srcc[i];
		if ((unsigned char)srcc[i] == (unsigned char)c)
			return (&destt[i + 1]);
		i++;
	}
	return (0);
}
