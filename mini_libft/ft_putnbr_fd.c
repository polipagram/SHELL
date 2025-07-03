/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouarfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:41:12 by kbouarfa          #+#    #+#             */
/*   Updated: 2024/11/11 23:41:21 by kbouarfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-', fd);
		i = i * -1;
	}
	if ((i >= 0) && (i <= 9))
	{
		ft_putchar((i + '0'), fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putchar((i % 10) + '0', fd);
	}
}
