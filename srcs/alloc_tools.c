/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:14:32 by alallema          #+#    #+#             */
/*   Updated: 2018/11/26 19:20:57 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (n == 0)
		return (s);
	src = (unsigned char *)s;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
	return (src);
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
