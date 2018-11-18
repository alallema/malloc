/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:33:20 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 20:13:12 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (n == 0)
		return (s);
	src = (unsigned char *)s;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
	return (src);
}

void	ft_free(void *ptr)
{
	t_block		*block;
	size_t		size;

	if (!ptr)
		return ;
	block = ptr - BLOCK_SIZE;
	block->free = 0;
	size = block->size;
	print_block(block);
	if (block->next && block->next->free == 0)
	{
		size += BLOCK_SIZE;
		block->size += block->next->size + BLOCK_SIZE;
		t_block *ret = block->next;
		block->next = block->next->next;
		block->next->prev = block;
		ft_bzero(ret , BLOCK_SIZE);
	}
	if (block->prev && block->prev->free == 0)
	{
		size += BLOCK_SIZE;
		block->prev->size += block->size + BLOCK_SIZE;
		block->prev->next = block->next;
		if (block->next)
			block->next->prev = block->prev;
		block -= BLOCK_SIZE;
	}
	ft_bzero((void *)BLOCK_MEM(block), size);
	munmap((void *)BLOCK_MEM(block), size);
}
