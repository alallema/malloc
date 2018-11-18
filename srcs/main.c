/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 13:50:08 by alallema         ###   ########.fr       */
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

	ptr = ft_malloc(9);
	ptr2 = ft_malloc(8763);
	print_list();
//	strcpy(ptr, "lalalala");
//	strcpy(ptr2, "lalaskdfjhgkdxjbfvlksdjbfjkvlala");
//	printf("ptr : %s", ptr);
//	printf("ptr2 : %s", ptr2);
	return (0);
}
