/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:22:53 by alallema          #+#    #+#             */
/*   Updated: 2018/11/19 18:09:21 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		*init_alloc(size_t size)
{
	void	*ptr;
	t_area	*area;
	t_block	*block;

	ptr = NULL;
	if (g_base == NULL)
		g_base = alloc_area(size);
	area = find_area(size);
	if (area && area->type != get_type(size))
	{
		area->next = alloc_area(size);
		area->next->prev = area;
		area = area->next;
	}
	if (area && area->type == get_type(size))
	{
		block = find_block(area->base, size);
		ptr = split_block(block, size);
	}
	return (ptr);
}

void			*ft_malloc(size_t size)
{
	void	*ptr;
	t_area	*base;

	ptr = NULL;
	base = NULL;
	if (size == 0)
		return (NULL);
	ptr = init_alloc(size);
	return (ptr);
}
