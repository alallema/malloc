/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:22:53 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 13:14:50 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		*init_alloc(size_t size)
{
	t_area	*area;
	t_block	*block;

	if (g_base == NULL)
		g_base = alloc_area(size);
	area = find_area(size);
	block = find_block(area->base, size);
	if ((area && area->type != get_type(size)) || !block)
	{
		area->next = alloc_area(size);
		area->next->prev = area;
		area = area->next;
	}
	if (area && area->type == get_type(size))
	{
		block = find_block(area->base, size);
		if (get_type(size) < 2 && block && block->size > (size + BLOCK_SIZE))
			return (split_block(block, size));
		else
		{
			block->free = 1;
			return (ptr_zone_mem(block, BLOCK_SIZE));
		}
	}
	return (NULL);
}

void			*malloc(size_t size)
{
	void	*ptr;
	t_area	*base;

//	putstr("** MALLOC **\n");
	ptr = NULL;
	base = NULL;
	if (size == 0)
		return (NULL);
//		size = 1;
	ptr = init_alloc(size);
	return (ptr);
}
