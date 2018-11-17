/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:01:48 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 20:14:31 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*find_area(size_t size)
{
	t_area	*ptr;
	int		type;

	ptr = g_base;
	type = get_type(size);
	printf("ptr : %d\n", (unsigned int)g_base);
	while (ptr && ptr->next)
	{
		if (ptr->type == type)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

void	*find_block(t_area *area, size_t size)
{
	t_block	*block;

	block = area->base;
	if (block && block->next)
	{
		block;
		while (ptr->next && type != ptr->type)
			ptr = ptr->next;
		return (ptr);
	}
	while (block && block->free == 1)
	{

	}
	return NULL;
}
