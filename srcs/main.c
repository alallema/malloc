/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/17 20:09:36 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_type(size_t size)
{
	if (size <= TINY)
		return (TINY_TYPE);
	else if (size <= SMALL)
		return (SMALL_TYPE);
	else if (size >= SMALL)
		return (LARGE_TYPE);
	return (-1);
}

void	init_alloc(size_t size)
{
	if (g_base == NULL)
		g_base = alloc_area(size);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;
	t_area	*base;

	ptr = NULL;
	base = NULL;
	if (size == 0)
		return (NULL);
	init_alloc(size);
	base = find_area(size);
	if (base && base->type == get_type(size))
		ptr = alloc_block(NULL, AREA_MEM(base), size);
	else
	{
		base->next = alloc_area(size);
		base = base->next;
		ptr = alloc_block(NULL, AREA_MEM(base), size);
	}
	printf("g_base & base : %d %d \n", g_base->type, base->type);
	return (ptr);
}

int main()
{
	void	*ptr;

	ptr = ft_malloc(9);
	if (g_base)
	{
		printf("g_base : %d\n", g_base->type);
		printf("g_base :%d\n", GET(g_base));
		if (g_base && g_base->base)
			printf("block : %lu\n", g_base->base->size);
		else
			printf("no no ...");
	}
	strcpy(ptr, "lalalala");
	printf("ptr : %s", ptr);
	return (0);
}
