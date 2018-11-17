/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 12:12:30 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
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

void	*alloc_block(void *ptr, size_t size)
{
	t_block	*block;

	block = ptr;
	block->size = 32;
	block->next = NULL;
	block->prev = NULL;
	return (BLOCK_MEM(ptr));
}

void	*alloc_area(size_t size)
{
	void		*ptr;
	t_area	*base;

	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base = ptr;
	base->type = 1;
	base->base = AREA_MEM(base);
	base->next = NULL;
//	printf("type :%d\n", GET(base));
	alloc_block(AREA_MEM(base), size);
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
//	if (g_base->base == NULL)
//			printf ("lala");
	printf ("base base : %lu\n", g_base->base->size);
}

void	*ft_malloc(size_t size)
{
	size_t	area[3];

	area[TINY_TYPE] = TINY_AREA;
	area[SMALL_TYPE] = SMALL_AREA;
	area[LARGE_TYPE] = size;
	printf("size : %lu\n", size);
	printf("size : %lu\n", area[get_type(size)]);
	if (size == 0)
		return (NULL);
	if (g_base == NULL)
		init_alloc(area[get_type(size)] + AREA_SIZE);
//	if (g_base->base == NULL)
//		init_area(size);
	return (NULL);
}

int main() {
	void	*ptr;

	ptr = ft_malloc(sizeof(t_block));
	if (g_base)
		printf("g_base : %d\n", g_base->type);
		printf("block : %lu", g_base->base->size);
	return (0);
}
