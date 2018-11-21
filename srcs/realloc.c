/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:24:09 by alallema          #+#    #+#             */
/*   Updated: 2018/11/21 22:02:17 by alallema         ###   ########.fr       */
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

	if (!ptr)
		return (ft_malloc(size));
	if (size == 0)
	{
		ft_free(ptr);
		return (ft_malloc(0));
	}
	block = ptr - BLOCK_SIZE;
	if (block->size == size)
		return (ptr);
	if (block->size > size + BLOCK_SIZE)
	{
//		printf(" ** block : \ndata :%s\n", ptr);
		split_block(block, size);
//		block->size = size;
//		ft_free(split_block(block, size));
		return (ptr);
	}
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
