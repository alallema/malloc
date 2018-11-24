/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:33:20 by alallema          #+#    #+#             */
/*   Updated: 2018/11/24 18:19:39 by alallema         ###   ########.fr       */
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

//int		clean_area(t_block *block)
//{
//	t_area	*area;
//	t_area	*tmp;
//	int		type;
//	int		type[3];
//
//	type[0] = 0;
//	type[1] = 0;
//	type[2] = 0;
//	area = (t_area *)((unsigned long)tmp - AREA_SIZE);
//	tmp = g_base;
//	while (tmp)
//	{
//		type[area->type] = 1;
//		if (type[0] && type[1] && type[2])
//			return (0);
//		tmp = tmp->next;
//	}
//	return (1);
//}

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

	size = 0;
	tmp = block;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	area = (t_area *)((unsigned long)tmp - AREA_SIZE);
	if (area->type == TINY_TYPE)
		size = TINY_AREA;
	else if (area->type == SMALL_TYPE)
		size = SMALL_AREA;
	else
		size = ALIGN_PAGE(size);
	delete_area(area);
	ft_bzero(area, size);
	putstr("** MUNMAP **\n");
	munmap((void *)area, size);
}

void	*check_ptr(void *ptr)
{
	t_block		*block;
	t_block		*tmp;
	t_area		*area;

	if ((block = ptr - BLOCK_SIZE))
	{
		area = g_base;
		while (area)
		{
			tmp = area->base;
			while (tmp)
			{
				if (block == tmp)
					return (block);
				tmp = tmp->next;
			}
			area = area->next;
		}
	}
	return (NULL);
}

void	free(void *ptr)
{
	t_block		*block;
	size_t		size;

	if (!ptr)
		return ;
	if (!check_ptr(ptr))
		return ;
	putstr("** FREE **\n");
	if ((block = ptr - BLOCK_SIZE))
	{
		block->free = 0;
		size = block->size;
		if (get_type(block->size) == 2 || area_is_empty(block))
			free_area(block);
		else
		{
			if (block->next && block->next->free == 0)
				fusion_block(block);
			if (block->prev && block->prev->free == 0)
				fusion_block(block->prev);
			ft_bzero((void *)BLOCK_MEM(block), size);
		}
	}
}
