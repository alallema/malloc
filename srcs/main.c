/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 16:01:05 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

int		get_type(size)
{
	if (size <= TINY)
		return TINY_TYPE;
	else if (size <= SMALL)
		return SMALL_TYPE;
	else if (size >= SMALL)
		return LARGE_TYPE;
	return (-1);
}

void	*alloc_block(void *prev, void *ptr, size_t size)
{
	t_block	*block;

	block = ptr;
	block->next = NULL;
	block->prev = prev;
	block->size = size;
	block->free = 1;
	return (BLOCK_MEM(ptr));
}

void	*alloc_area(size_t size)
{
	size_t	area[3];
	void		*ptr;
	t_area	*base;

	area[TINY_TYPE] = TINY_AREA;
	area[SMALL_TYPE] = SMALL_AREA;
	area[LARGE_TYPE] = size;
	printf("size : %lu\narea size : %lu\n", size, area[get_type(size)]);
	ptr = mmap(0, area[get_type(size)] + AREA_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base = ptr;
	base->type = get_type(size);
	base->base = AREA_MEM(base);
	base->next = NULL;
	alloc_block(NULL, AREA_MEM(base), size);
	return (base);
}

void	init_alloc(size_t size)
{
//	void	*ptr;

//	ptr = mmap(0, get_type(size), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//	t_area	*base;
//	t_block	*block;

//	base = init_base(size);
//	block = init_block(size);
//	area_size = type(size) * page_type(size);
	if (g_base == NULL)
		g_base = alloc_area(size);
	else
		alloc_area(size);
//	if (g_base->base == NULL)
//			printf ("lala");
	printf ("base base : %lu\n", g_base->base->size);
}

void	*ft_malloc(size_t size)
{
	if (size == 0)
		return (NULL);
	if (g_base == NULL)
		init_alloc(size);
//	if (g_base->base == NULL)
//		init_area(size);
	return (NULL);
}

int main() {
	void	*ptr;

	ptr = ft_malloc(9);
	strcpy(ptr, "lalalala");
	if (g_base)
	{
		printf("g_base : %d\n", g_base->type);
		printf("g_base :%d\n", GET(g_base));
		printf("block : %lu", g_base->base->size);
	}
	return (0);
}
