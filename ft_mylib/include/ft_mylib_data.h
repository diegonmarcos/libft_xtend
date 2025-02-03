/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylib_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:19:46 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/03 14:40:17 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYLIB_DATA_H
# define FT_MYLIB_DATA_H

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0.0 MACROS															*/
/*#####################################################################	*/

// GARBAGE COLLECTOR
# ifndef MAX_ALLOCATIONS
#  define MAX_ALLOCATIONS 102400
# endif

# include "ft_mylib.h"

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/* ************************************************************* */
/* MEMORY MANAGEMENT / GARBAGE COLLECTOR						 */
/* ************************************************************* */

typedef struct s_list_garbage
{
	void	*allocated_pointers[MAX_ALLOCATIONS];
	int		blocks_count;
}			t_list_garbage;

void			*ft_malloc_gb(size_t size, t_list_garbage *list_garbage);
int				add_allocation(void *ptr, t_list_garbage *list_garbage);
int				is_allocated(void *ptr, t_list_garbage *list_garbage);
void			remove_allocation(void *ptr, t_list_garbage *list_garbage);
void			ft_free_gb(void *ptr, t_list_garbage *list_garbage);
void			ft_free_gb_all(t_list_garbage *list_garbage);
t_list_garbage	*ft_initializator_list_gargabe(void);
//# include "ft_mylib_utils.h" //*ft_initializator_list_gargabe(void);

/* ************************************************************* */
/* DATA STRUCTURE / HASHTABLE/MAP/DIC							 */
/* ************************************************************* */
typedef struct s_node_
{
	char			*key;
	int				value;
	struct s_node_	*next;
}				t_node_;

void			insert(t_node_ **table, int size, const char *key, int value);
int				get(t_node_ **table, int size, const char *key);
void			free_hashtable(t_node_ **table, int size);
size_t			hash(char *key, int size);
t_node_			*create_node(char *key, int value);

/* ************************************************************* */
/* ************************************************************* */
// DATA STRUCTURE FOR SINGLY LINEKD LIST

typedef struct s_list_s
{
	void				*content;
	struct s_list_s		*next;
}					t_list_s;

void			ft_free_ls_simple(t_list_s *stack);
/*
t_list_s	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list_s **lst, t_list *new);
int		ft_lstsize(t_list_s *lst);
t_list_s	*ft_lstlast(t_list_s *lst);
void	ft_lstadd_back(t_list_s **lst, t_list *new);
void	ft_lstdelone(t_list_s *lst, void (*del)(void*));
void	ft_lstclear(t_list_s **lst, void (*del)(void*));
void	ft_lstiter(t_list_s *lst, void (*f)(void*));
t_list_s	*ft_lstmap(t_list_s *lst, void *(*f)(void*), void (*del)(void*));
*/

/* ************************************************************* */
/* ************************************************************* */
// DATA STRUCTURE FOR DOUBLY LINKED LIST

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list			*array_to_d_linked_list(char **argv);
t_list			*array_int_to_d_linked_list(int *argv, int size);
t_list			*ft_lstnew(int value, int index);
void			ft_lstadd_back(t_list **stack, t_list *new_node);
int				ft_lstsize(t_list *lst);
t_list			*find_min_node(t_list *stack);
void			ft_swap_pointers(t_list **a, t_list **b);
void			ft_print_ls_doubly(t_list *stack);
void			ft_free_ls_doubly(t_list *stack);

#endif