/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/16 09:06:10 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include "malloc.h"

int		get_type(size)
{
	if (size <= TINY)
		return TINY_TYPE;
	else if (size <= SMALL)
		return SMALL_TYPE;
	else if (size >= SMALL)
		return LARGE_TYPE;
	return (-1);
}

void	*alloc_area(size_t size)
{
	void	*ptr;
	t_area	*base;

	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	base = ptr;
	base->type = 1;
	base->base = NULL;
	base->next = NULL;
	return (ptr);
}

void	init_alloc(size_t size)
{
//	void	*ptr;

//	ptr = mmap(0, get_type(size), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//	t_area	*base;
//	t_block	*block;

//	base = init_base(size);
//	block = init_block(size);
//	area_size = type(size) * page_type(size);
	if (g_base == NULL)
//	if (g_base->base == NULL)
		alloc_area(size);
}

void	*ft_malloc(size_t size)
{
	size_t	area[3];

	area[TINY_TYPE] = TINY_AREA;
	area[SMALL_TYPE] = SMALL_AREA;
	area[LARGE_TYPE] = size;
	printf("size : %lu\n", size);
	printf("size : %lu\n", area[get_type(size)]);
	if (size == 0)
		return (NULL);
	if (g_base == NULL)
		init_alloc(area[get_type(size)] + AREA_SIZE);
//	if (g_base->base == NULL)
//		init_area(size);
	return (NULL);
}

int main() {
	void	*ptr;

	ptr = ft_malloc(sizeof(t_block));
//	printf(" g_base : %d", g_base->type);
	return (0);
}
