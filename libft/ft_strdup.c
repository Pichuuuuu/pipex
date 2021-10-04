/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:34:21 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 19:09:14 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	n;

	n = 0;
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!cpy)
		return (0);
	return (ft_strcpy(cpy, (char *)src));
}
