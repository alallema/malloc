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

size_t		get_size(size)
{
	if (size <= TINY)
		return TINY_AREA;
	else if (size <= SMALL)
		return SMALL_AREA;
	else if (size >= SMALL)
		return size;
}

void	*alloc(t_block *base, size_t size)
{
	void	*ptr;

	ptr = mmap(0, get_size(size), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return (ptr);
}

void	init_alloc(size_t size)
{
	void	*ptr;

	ptr = mmap(0, get_type(size), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);


//	t_area	*base;
//	t_block	*block;

//	base = init_base(size);
//	block = init_block(size);
//	area_size = type(size) * page_type(size);
//	if (g_base->base == NULL)
//		init_area(size);
}

void	*malloc(size_t *size)
{
	if (size == 0)
		return (-1);
	if (g_base == NULL)
		init_alloc(size);
//	if (g_base->base == NULL)
//		init_area(size);
}

int main() {
	
}
