/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:38:45 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 19:16:35 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_type(size_t size)
{
	if (size <= TINY)
		return (TINY_TYPE);
	else if (size <= SMALL)
		return (SMALL_TYPE);
	else if (size >= SMALL)
		return (LARGE_TYPE);
	return (-1);
}

void	*alloc_block(void *prev, void *next, void *ptr, size_t size, int free)
{
	t_block	*block;

	block = ptr;
	block->next = next;
	block->prev = prev;
	block->size = size;
	block->free = free;
	return (BLOCK_MEM(ptr));
}

void	*alloc_area(size_t size)
{
	size_t	area[3];
	void	*ptr;
	t_area	*base;

	area[TINY_TYPE] = TINY_AREA;
	area[SMALL_TYPE] = SMALL_AREA;
	area[LARGE_TYPE] = size + AREA_SIZE + BLOCK_SIZE;
	ptr = mmap(0, area[get_type(size)], PROT_READ | \
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base = (t_area *)ptr;
	base->type = get_type(size);
	base->base = AREA_MEM(base);
	base->next = NULL;
	alloc_block(NULL, NULL, AREA_MEM(base), area[get_type(size)] -\
			AREA_SIZE - BLOCK_SIZE, 0);
	return (base);
}

void	*split_block(t_block *block, size_t size)
{
	void	*new;
	t_block	*next;

	next = block->next;
	if (get_type(size) == 2)
	{
		block->free = 1;
		return (BLOCK_MEM(block));
	}
	block->size = block->size - size - BLOCK_SIZE;
	new = ((void *)((unsigned long)(block) + block->size));
	block->next = new;
	if (next)
		next->prev = new;
	new = alloc_block(block, next, new, size, 1);
	return (new);
}
