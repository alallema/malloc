/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:07:35 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 21:01:10 by alallema         ###   ########.fr       */
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
# include <pthread.h>

# define BLOCK_SIZE sizeof(t_block)
# define AREA_SIZE sizeof(t_area)
# define MAX_SIZE (BLOCK_SIZE + AREA_SIZE)

# define TINY 128
# define SMALL 2048
# define PAGE getpagesize()
# define PADD 16

# define TINY_AREA ((((((BLOCK_SIZE + TINY)*100) + AREA_SIZE)/PAGE) + 1)*PAGE)
# define SMALL_AREA ((((((BLOCK_SIZE + SMALL)*100) + AREA_SIZE)/PAGE) + 1)*PAGE)

# define TINY_TYPE 0
# define SMALL_TYPE 1
# define LARGE_TYPE 2

typedef struct		s_block
{
	size_t			size;
	struct s_block	*next;
	struct s_block	*prev;
	int				free;
}					t_block;

typedef struct		s_area
{
	int				type;
	t_block			*base;
	struct s_area	*next;
	struct s_area	*prev;
}					t_area;

t_area				*g_base;
pthread_mutex_t		g_mutex;

void				print_block_list(t_block *block);
void				print_list();

int					get_type(size_t size);

void				*alloc_area(size_t size);
void				*find_area(size_t type);
void				*find_block(t_block *block, size_t size);
void				*split_block(t_block *block, size_t size);
void				fusion_block(t_block *block);
void				delete_area(t_area *area);
void				*ft_bzero(void *ptr, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*check_ptr(void *ptr);
void				*ptr_zone_mem(void *ptr, size_t size);
size_t				align(size_t size);
size_t				align_page(size_t size);

void				free(void *ptr);
void				*malloc(size_t size);
void				*calloc(size_t count, size_t size);
void				*realloc(void *ptr, size_t size);

void				show_alloc_mem();
size_t				print_area(void *addr, int type, int pos);
void				putnbr_base(unsigned long n, int base);
void				putstr(char const *str);

#endif
