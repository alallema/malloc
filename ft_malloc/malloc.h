/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:34:05 by alallema          #+#    #+#             */
/*   Updated: 2018/11/16 09:10:55 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

void show_alloc_mem();

