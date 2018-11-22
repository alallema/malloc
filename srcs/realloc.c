/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:24:09 by alallema          #+#    #+#             */
/*   Updated: 2018/11/22 22:57:19 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*find_alloc(t_block *block, size_t size)
{
	size_t	alloc;

	alloc = block->size;
	while (alloc < size)
	{
		if (block->next && block->next->free == 0)
		{
//			fusion_block(block, &size);
			alloc = alloc + block->next->size;
		}
	}
	return (NULL);
}

void		*ft_realloc(void *ptr, size_t size)
{
	t_block		*block;
	void		*buff;

	if (!ptr)
		return (ft_malloc(size));
	if (size == 0)
	{
		ft_free(ptr);
		return (ft_malloc(0));
	}
	block = ptr - BLOCK_SIZE;
	if (block->next && block->next->free == 0 &&((size_t)block->size + (size_t)block->next->size) >= (ALIGN(size) + BLOCK_SIZE))
		fusion_block(block);
	if (block->size >= size && block->size <= ALIGN(size))
		return (ptr);
	if (block->size > (ALIGN(size) + BLOCK_SIZE))
	{
		putstr(" ** 1 ** \n");
		buff = split_block(block, size);
		block->free = 1;
		putstr(" ** 1 ** \n");
		ft_free(BLOCK_MEM(((t_block *)(buff - BLOCK_SIZE))->next));
		putstr(" ** 1 ** \n");
//		printf("size: %lu\n", block->size);
//		block->size = ALIGN(size);
//		ft_free(split_block(block, size));
		return (ptr);
	}
//	if (block->size < size && block->next && block->next->free == 0)
//	else if (block->size > size && block->next && block->next->free == 0)
//	{
//		putstr(" ** 2 ** \n");
//		fusion_block(block);
//		if (block->size > (size + BLOCK_SIZE))
//			split_block(block, size);
//	}
//	else if (get_type(size) < 2)
//	{
//		if (block->next && block->next->free == 1)
//			fusion_block(block, size);
//		if (block->prev && block->prev->free == 1)
//			printf("FREE PREV");
//	}
//	else
//	{
//		memcpy(ft_malloc(size), block, block->size);
//		ft_free(block);
//		return (ft_malloc(size));
//	}
	return (NULL);
}
