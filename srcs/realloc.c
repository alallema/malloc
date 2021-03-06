/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:24:09 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 19:23:24 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*check_realloc(t_block *block, size_t size)
{
	void		*buff;

	if (block->next && block->next->free == 0 && ((size_t)block->size\
		+ (size_t)block->next->size) >= (align(size) + BLOCK_SIZE))
		fusion_block(block);
	if (block->size >= size && block->size <= (align(size) + BLOCK_SIZE))
		return (ptr_zone_mem(block, BLOCK_SIZE));
	if (block->size > (align(size) + BLOCK_SIZE))
	{
		buff = split_block(block, size);
		block = buff - BLOCK_SIZE;
		if (block->next)
			ft_bzero(ptr_zone_mem(block->next, BLOCK_SIZE),
				block->next->size - BLOCK_SIZE);
		return (buff);
	}
	else
	{
		buff = malloc(size);
		ft_memcpy(buff, ptr_zone_mem(block, BLOCK_SIZE), block->size);
		free(ptr_zone_mem(block, BLOCK_SIZE));
		return (buff);
	}
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	t_block		*block;

	if (!ptr)
		return (malloc(size));
	if (!check_ptr(ptr))
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	if (size == 0)
	{
		free(ptr);
		pthread_mutex_unlock(&g_mutex);
		return (malloc(1));
	}
	if ((block = ptr - BLOCK_SIZE))
	{
		pthread_mutex_unlock(&g_mutex);
		return (check_realloc(block, size));
	}
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}
