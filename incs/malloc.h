/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:07:35 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 20:08:13 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define BLOCK_SIZE sizeof(t_block)
# define AREA_SIZE sizeof(t_area)

# define TINY 512 // 15 pages
# define SMALL 4096 // 101 pages

# define TINY_AREA 14 * getpagesize()
# define SMALL_AREA 101 * getpagesize()

# define TINY_TYPE 0
# define SMALL_TYPE 1
# define LARGE_TYPE 2

# define BLOCK_MEM(ptr) ((void *)((unsigned long)ptr + BLOCK_SIZE))
# define AREA_MEM(ptr) ((void *)((unsigned long)ptr + AREA_SIZE))

# define GET(ptr)       (*(int *)(ptr))
# define PUT(ptr, val)  (*(int *)(ptr) = (val))
# define GET_SIZE(ptr)  (GET(ptr) & ~0x7)

//# define ALIGN(ptr)
//# define ALIGN(x) (((((x) -1) >> 2) << 2) +4)
//# define ALIGN(p) (((size_t)(p) + (ALIGNMENT-1)) & ~0x7)

typedef struct	s_block
{
	size_t			size;
	struct s_block	*next;//??? a calculer
	struct s_block	*prev;
	int				free;
}				t_block;

typedef struct	s_area
{
	int				type;
	t_block			*base;
	struct s_area	*next;
}				t_area;

t_area				*g_base;

//void	*alloc(t_block *base, size_t type);

int		get_type(size_t size);

void	*alloc_area(size_t size);
void	*alloc_block(void *prev, void *ptr, size_t size);
void	*find_area(size_t type);

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

void show_alloc_mem();

#endif
