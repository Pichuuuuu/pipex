/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:41:15 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 19:12:00 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*out;

	i = 0;
	if (!s[0])
		return (0);
	if (start >= ft_strlen((char *)s))
		return ("");
	out = ft_calloc(sizeof(char), len + 1);
	if (!out)
		return (0);
	while (s[i + start] && i < (int)len)
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}
