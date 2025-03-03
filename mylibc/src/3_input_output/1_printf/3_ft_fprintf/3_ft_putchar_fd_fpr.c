/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_fpr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:53:18 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/02/11 13:54:11 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

int	ft_putchar_fd_fpr(long fd, int c)
{
	if (write (fd, &c, 1) != 1)
		return (-1);
	return (1);
}
