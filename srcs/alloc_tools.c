/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:14:32 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 14:31:58 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_bzero(void *ptr, size_t n)
{
	size_t			i;

	i = 0;
	if (!ptr)
		return (NULL);
	if (n == 0)
		return (ptr);
	while (i < n)
	{
		*((unsigned char *)(ptr + i)) = 0;
		i++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*d;
	char			*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}

void	*ptr_zone_mem(void *ptr, size_t size)
{
	return ((void *)((unsigned long)ptr + size));
}

size_t	align(size_t size)
{
	return (((size) + (PADD - 1)) & ~(PADD - 1));
}

size_t	align_page(size_t size)
{
	return (align(size + MAX_SIZE));
}
