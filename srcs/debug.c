/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:20:50 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 13:48:00 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**** DEBUG ***/

#include "malloc.h"

void	print_list()
{
	t_area	*area;
	t_block	*block;

	area = NULL;
	if (g_base)
	{
		printf("g_base : %d\n", g_base->type);
		area = g_base;
		block = area->base;
		while (area)
		{
			printf("area : %d\n", area->type);
			while (block)
			{
				printf("block size : %lu\n", block->size);
				printf("block free : %d\n", block->free);
				block = block->next;
			}
			area = area->next;
		}
	}
	else
		printf("No g_base ...");
}
