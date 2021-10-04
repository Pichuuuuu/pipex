/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:39:31 by Tamather          #+#    #+#             */
/*   Updated: 2021/09/06 21:47:08 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		ft_putchar_fd('-', 1);
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, 1);
		ft_putchar_fd(tmp % 10 + 48, 1);
	}
	if (tmp < 10)
		ft_putchar_fd(tmp + 48, 1);
}
