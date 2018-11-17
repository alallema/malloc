/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:34:05 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 12:49:29 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include <string.h>

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

# define GET(p)       (*(int *)(p))
# define PUT(p, val)  (*(int *)(p) = (val))
# define GET_SIZE(p)  (GET(p) & ~0x7)

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

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

void show_alloc_mem();

#endif
