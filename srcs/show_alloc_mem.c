/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:52:08 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 20:40:24 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		loop_area(t_area *area, int type)
{
	size_t	size;
	int		pos;

	pos = 0;
	size = 0;
	while (area)
	{
		if (area->type == type)
		{
			size += print_area(area, area->type, pos);
			pos++;
		}
		area = area->next;
	}
	return (size);
}

void		show_alloc_mem(void)
{
	t_area	*area;
	size_t	size;
	int		type;
	int		pos;

	area = NULL;
	size = 0;
	type = 0;
	pos = 0;
	pthread_mutex_lock(&g_mutex[MUTEX_SHOW]);
	if (g_base)
	{
		while (type < 3)
		{
			area = g_base;
			size += loop_area(area, type);
			type++;
		}
		putstr("Total : ");
		putnbr_base(size, 10);
		putstr(" octets\n");
	}
	pthread_mutex_unlock(&g_mutex[MUTEX_SHOW]);
}
