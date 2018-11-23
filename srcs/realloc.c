/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:24:09 by alallema          #+#    #+#             */
/*   Updated: 2018/11/23 15:50:51 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*d;
	char			*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}

void		*realloc(void *ptr, size_t size)
{
	t_block		*block;
	void		*buff;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (malloc(0));
	}
	block = ptr - BLOCK_SIZE;
	if (block->next && block->next->free == 0 &&((size_t)block->size + (size_t)block->next->size) >= (ALIGN(size) + BLOCK_SIZE))
		fusion_block(block);
	if (block->size >= size && block->size <= ALIGN(size))
		return (ptr);
	if (block->size > (ALIGN(size) + BLOCK_SIZE))
	{
		buff = split_block(block, size);
		if (block->next)
			ft_bzero(BLOCK_MEM(block->next), block->next->size - BLOCK_SIZE);
		return (ptr);
	}
	else
	{
		buff = malloc(size);
		ft_memcpy(buff, ptr, block->size);
		free(ptr);
	}
	return (NULL);
}
