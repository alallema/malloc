/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:01:48 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 13:20:33 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*find_area(size_t size)
{
	t_area	*ptr;
	int		type;

	ptr = g_base;
	type = get_type(size);
	while (ptr && ptr->next)
	{
		if (ptr->type == type)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

void	*find_block(t_block *ptr, size_t size)
{
	t_block	*block;

	block = ptr;
	while (block && block->next)
	{
		if (size <= block->size && block->free == 0)
			return (block);
		block = block->next;
	}
	return block;
}

