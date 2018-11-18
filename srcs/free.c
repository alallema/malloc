/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:33:20 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 18:35:56 by alallema         ###   ########.fr       */
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

	block = ptr - BLOCK_SIZE;
	ft_bzero((void *)BLOCK_MEM(block), block->size);
	munmap((void *)BLOCK_MEM(block), block->size);
	printf("**** FREE ****\n");
	if (block->prev && block->prev->free == 0)
	{
		printf("**** PREV ****\n");
		block->prev->size += block->size + BLOCK_SIZE;
		block->prev->next = block->next;
		ft_bzero((void *)block, BLOCK_SIZE);
		munmap((void *)block, BLOCK_SIZE);
	}
	if (block->next && block->prev)
	{
		printf("**** NEXT ****\n");
	}
	printf("block size : %lu\n", block->size);
	printf("block data : %s\n", (char *)(BLOCK_MEM(block)));
}
