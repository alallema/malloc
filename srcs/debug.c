/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:20:50 by alallema          #+#    #+#             */
/*   Updated: 2018/11/19 14:49:58 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*** DEBUG **
*/

#include "malloc.h"

void	rev_print_list(t_block *block)
{
	printf("**** REVERSE ****\n");
	while (block)
	{
		printf("block size : %lu\n", block->size);
		printf("block free : %d\n", block->free);
		printf("block data : %s\n", BLOCK_MEM(block));
		block = block->prev;
	}
}

void	print_list(void)
{
	t_area	*area;
	t_block	*block;

	area = NULL;
	if (g_base)
	{
		//printf("g_base : %d", g_base->type);
		printf("**** LIST ****\n");
		area = g_base;
		while (area)
		{
//			printf("\nArea : %d\n", area->type);
			print_area(area, area->type);
			block = area->base;
			while (block)
			{
//				print_block(block);
//				unsigned long buff = (unsigned long)block;
//				printf("block addr : %lx\n", buff);
//				printf("block addr : %lu\n", buff);
//				printf("block addr : %p\n", (void*)block);
//				printf("block size : %lu\n", block->size);
//				printf("block free : %d\n", block->free);
//				printf("block data : %s\n", BLOCK_MEM(block));
//				if (!block->next)
//					rev_print_list(block);
				block = block->next;
			}
			area = area->next;
		}
		printf("**** END ****\n");
	}
	else
		printf("No g_base ...");
}

void	print_block_list(t_block *block)
{
	printf("block size : %lu\n", block->size);
	printf("block free : %d\n", block->free);
	printf("block data : %s\n", BLOCK_MEM(block));
}
