/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:55:13 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/10 18:41:00 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: void ft_bzero(void *s, size_t n);
 * @brief:	The bzero() function writes n zeroed bytes to the string s.
 * 			If n is zero, bzero() does nothing.
 * @param: s: The pointer to the string to be zeroed.
 * @return: None.
 * 
 * @note: 
 * 
 * @file: ft_bzero.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:43
 * ************************************************************************** *
 */

#include "mylibc.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ft_bzero_2d(void **array, size_t lines, size_t size)
{
	size_t	i;

	i = 0;
	while (i < lines)
	{
		ft_bzero(array[i], size);
		i++;
	}
}

/*
int main ()
{
	// Char Test
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore bzero(): %s\n", str);
	ft_bzero(str + 13, 8 * sizeof(char));
	printf("After bzero():  %s\n", str);

	//Int Test
		
		//before bzero
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("\nBefore bzero(): ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
		
		//after bzero
	ft_bzero(arr, 10 * sizeof(int));
	printf("\nAfter bzero():  ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}
*/

/*

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_ptr;

	tmp_ptr = (char *) s;
	while (n > 0)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}
*/