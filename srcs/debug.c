/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:20:50 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 16:16:15 by alallema         ###   ########.fr       */
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
		printf("g_base : %d", g_base->type);
		area = g_base;
		while (area)
		{
			printf("\nArea : %d\n", area->type);
			block = area->base;
			while (block)
			{
				printf("block size : %lu\n", block->size);
				printf("block free : %d\n", block->free);
				printf("block data : %s\n", BLOCK_MEM(block));
				block = block->next;
			}
			area = area->next;
		}
	}
	else
		printf("No g_base ...");
}
