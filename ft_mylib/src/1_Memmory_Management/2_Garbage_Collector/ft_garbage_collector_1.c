/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:57:56 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/27 20:35:29 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_mylib.h"
/*
//#include "../../../include/ft_mylib.h"
#define MAX_ALLOCATIONS 1024
typedef struct s_list_garbage
{
	void	*allocated_pointers[MAX_ALLOCATIONS];
	int		blocks_count;
}			t_list_garbage;


int	add_allocation(void *ptr, t_list_garbage *list_garbage);
void	remove_allocation(void *ptr, t_list_garbage *list_garbage);
int	is_allocated(void *ptr, t_list_garbage *list_garbage);
void	*ft_malloc_gb(size_t size, t_list_garbage *list_garbage);

*/

// Wrapper for free that also removes the allocation from tracking
void	ft_free_gb(void *ptr, t_list_garbage *list_garbage)
{
	if (ptr)
		remove_allocation(ptr, list_garbage);
	free(ptr);
}

// Function to free all allocated memory and reset block count
void	ft_free_gb_all(t_list_garbage *list_garbage)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (list_garbage->allocated_pointers[i] != NULL)
		{
			free(list_garbage->allocated_pointers[i]);
			list_garbage->allocated_pointers[i] = NULL;
			list_garbage->blocks_count = 0;
		}
		i++;
	}
}

void	ft_struct_initializator(t_list_garbage *list_garbage)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		list_garbage->allocated_pointers[i] = NULL;
		i++;
	}
	list_garbage->blocks_count = 0;
}

/*
int	main()
{
//	t_list_garbage list_garbage = { .allocated_pointers = {NULL},
			 .blocks_count = 0 };
	t_list_garbage list_garbage;

	
	ft_struct_initializator(&list_garbage);
	// Allocate some memory using ft_malloc_gb
	int *intPtr = (int *)ft_malloc_gb(sizeof(int) * 10, &list_garbage);
	char *charPtr = (char *)ft_malloc_gb(sizeof(char) * 20, &list_garbage);
	double *dblPtr = (double *)ft_malloc_gb(sizeof(double) * 5, &list_garbage);

	// Check if the allocations were successful and tracked
	if (intPtr && charPtr && dblPtr)
	{
		printf("Memory allocated successfully!\n\n");

		// Check if the pointers are tracked
		if (is_allocated(intPtr, &list_garbage))
			printf("intPtr is allocated\n");
		if (is_allocated(charPtr, &list_garbage))
			printf("charPtr is allocated\n");
		if (is_allocated(dblPtr, &list_garbage))
			printf("dblPtr is allocated\n\n");

		// Free some memory using ft_free_gb
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
//		ft_free_gb(intPtr, &list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
//		ft_free_gb(dblPtr, &list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
//		ft_free_gb(charPtr, &list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
		ft_free_gb_all(&list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
		

	// Check if the pointers are no longer tracked
	if (!is_allocated(charPtr, &list_garbage))
		printf("charPtr is now freed\n");
	else
		printf("charPtr is still allocated\n");
	if (!is_allocated(intPtr, &list_garbage))
		printf("intPtr is now freed\n");
	else
		printf("intPtr is still allocated\n");
	if (!is_allocated(dblPtr, &list_garbage))
		printf("dblPtr is now freed\n");
	else
		printf("dblPtr is still allocated\n");
	}
	else
		printf("Memory allocation failed!\n");

	
	return 0;
}*/