/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:40:10 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 21:44:14 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenword(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_nbword(const char *s, char c)
{
	size_t			nb;
	unsigned int	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

static void	f(char **tab, int *nb)
{
	while (*nb >= 0)
		free(tab[*nb--]);
	free(tab);
}

char	**ft_split(const char *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				nb;

	tab = malloc(sizeof(char *) * (ft_nbword(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[nb] = ft_substr(s + i, 0, ft_lenword(s + i, c));
			if (!tab[nb])
				f(tab, &nb);
			nb++;
		}
		i++;
	}
	tab[nb] = NULL;
	return (tab);
}
