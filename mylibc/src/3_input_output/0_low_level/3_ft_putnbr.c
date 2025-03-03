/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:56:17 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/02/03 12:42:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

static int	int_min(int n)
{
	(void)n;
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr(int n)
{
	int	char_count;

	char_count = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0 && ++char_count)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		char_count += ft_putnbr(n / 10);
		if (char_count == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar (('0' + n)) == -1)
			return (-1);
		char_count++;
	}
	return (char_count);
}

int	ft_putnbr_nbr(int *n, int size)
{
	while (size--)
	{
		if (ft_putnbr(*n) == -1)
			return (-1);
		n++;
	}
	return (0);
}
