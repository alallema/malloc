/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:27:53 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 19:33:02 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size > 0 && count > (~(size_t)0) / size)
		return (NULL);
	size = align(count * size) + PADD;
	ptr = malloc(size);
	return (ft_bzero(ptr, size));
}
