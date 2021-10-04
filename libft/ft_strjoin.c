/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:43:19 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 21:54:31 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*d;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2) + 1;
	d = (char *)malloc((n1 + n2) * sizeof(char));
	if (d)
	{
		ft_memcpy(d, s1, n1);
		ft_memcpy(d + n1, s2, n2);
	}
	return (d);
}
