/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:38:45 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 20:09:57 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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
	void	*ptr;
	t_area	*base;

	area[TINY_TYPE] = TINY_AREA;
	area[SMALL_TYPE] = SMALL_AREA;
	area[LARGE_TYPE] = size;
	ptr = mmap(0, area[get_type(size)], PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base = (t_area *)ptr;
	base->type = get_type(size);
	base->base = AREA_MEM(base);
	base->next = NULL;
	return (base);
}
