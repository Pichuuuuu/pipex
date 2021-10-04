/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tamather <Tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:03:29 by tamather          #+#    #+#             */
/*   Updated: 2021/09/06 19:08:04 by Tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		ft_putchar_fd('-', fd);
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putchar_fd(tmp % 10 + 48, fd);
	}
	if (tmp < 10)
		ft_putchar_fd(tmp + 48, fd);
}
