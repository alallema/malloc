/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 16:16:12 by alallema         ###   ########.fr       */
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

void	*init_alloc(size_t size)
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
		area = area->next;
	}
	if (area && area->type == get_type(size))
	{
		block = find_block(area->base, size);
		ptr = split_block(block, size);
	}
	return (ptr);
}

void	*ft_malloc(size_t size)
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

int		main()
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;

	ptr = ft_malloc(9);
	ptr2 = ft_malloc(10 + 1);
	ft_malloc(5500);
	ptr3 = ft_malloc(500);
	ft_malloc(540);
	ft_malloc(540);
	ft_malloc(540);
	strcpy(ptr, "lalalala\n");
	strcpy(ptr2, "ehijklmnok\0");
	print_list();
	printf("ptr : %s", ptr);
	printf("ptr2 : %s", ptr2);
	return (0);
}
