/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:33:20 by alallema          #+#    #+#             */
/*   Updated: 2018/11/19 18:09:19 by alallema         ###   ########.fr       */
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

int		area_is_empty(t_block *block)
{
	t_block	*tmp;

	tmp = block;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->free == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_area(t_block *block)
{
	t_area	*area;
	t_block	*tmp;
	size_t	size;

	tmp = block;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	area = (t_area *)((unsigned long)tmp - AREA_SIZE);
	if (area->type == TINY)
		size = TINY_AREA;
	else if (area->type == SMALL)
		size = SMALL_AREA;
	else
		size = tmp->size + AREA_SIZE + BLOCK_SIZE;
	delete_area(area);
	ft_bzero(area, size);
	munmap(area, size);
}

void	*fusion_block(t_block *block, size_t *size)
{
	t_block	*ret;

	if (block->next && block->next->free == 0)
	{
		*size += BLOCK_SIZE;
		block->size += block->next->size + BLOCK_SIZE;
		ret = block->next;
		block->next = block->next->next;
		if (block->next && block->next->prev)
			block->next->prev = block;
		ft_bzero(ret, BLOCK_SIZE);
	}
	if (block->prev && block->prev->free == 0)
	{
		*size += BLOCK_SIZE;
		block->prev->size += block->size + BLOCK_SIZE;
		block->prev->next = block->next;
		if (block->next)
			block->next->prev = block->prev;
		block -= BLOCK_SIZE;
	}
	return (block);
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
	if (get_type(block->size) == 2 || area_is_empty(block))
		free_area(block);
	else
	{
		block = fusion_block(block, &size);
		ft_bzero((void *)BLOCK_MEM(block), size);
		munmap((void *)BLOCK_MEM(block), size);
	}
}
