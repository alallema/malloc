/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:24:09 by alallema          #+#    #+#             */
/*   Updated: 2018/11/26 19:18:56 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*check_realloc(t_block *block, size_t size)
{
	void		*buff;

	if (block->next && block->next->free == 0 && ((size_t)block->size\
		+ (size_t)block->next->size) >= (ALIGN(size) + BLOCK_SIZE))
		fusion_block(block);
	if (block->size >= size && block->size <= ALIGN(size))
		return (BLOCK_MEM(block));
	if (block->size > (ALIGN(size) + BLOCK_SIZE))
	{
		buff = split_block(block, size);
		if (block->next)
			ft_bzero(BLOCK_MEM(block->next), block->next->size - BLOCK_SIZE);
		return (BLOCK_MEM(block));
	}
	else
	{
		buff = malloc(size);
		ft_memcpy(buff, BLOCK_MEM(block), block->size);
		free(BLOCK_MEM(block));
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
	if (size == 0)
	{
		free(ptr);
		return (malloc(0));
	}
	if ((block = ptr - BLOCK_SIZE))
		return (check_realloc(block, size));
	return (NULL);
}
