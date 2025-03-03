/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:00:30 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/27 22:42:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: char *ft_strrchr(const char *s, int c);
 * @brief: locates the last occurrence of c (converted to a char) in the 
 * 			string pointed to by s.
 * @param: 1. s: The string to be searched.
 * @return: A pointer to the located character, or NULL if the character does 
 * 			not appear in the string.
 * 
 * @note:
 * 
 * @file: ft_strrchr.c
 * @author: Diego <dinepomu@student.42>
 * @created: 03/Aug/2024 12:07
 * @updated: 10/Nov/2024 12:03
 * ************************************************************************** *
 */

#include "mylibc.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	char			cc;

	cc = (char)c;
	res = NULL;
	while (*s)
	{
		if (*s == cc)
			res = (char *)s;
		s++;
	}
	if (*s == cc)
		res = (char *)s;
	return (res);
}

/*
#include <stdio.h>

int main ()
{
	char str[] = "Born to code";
	printf("%s",ft_strrchr(str, 111));
	return 0;
}*/