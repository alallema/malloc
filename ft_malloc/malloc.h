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

# define BLOCK_SIZE sizeof(t_block)
# define ZONE_SIZE sizeof(t_zone)

# define TINY 128 // 16 bytes
# define SMALL 4096 // 512 bytes

typedef struct	s_block
{
	size_t			size;
	struct s_block	*next;//??? a calculer
	struct s_block	*prev;
	int				free;
}					t_block;

typedef struct		s_zone
{
	int				type;
	size_t			remaining;
	t_block			*base;
	struct s_zone	*next;
}					t_zone;

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

void show_alloc_mem();
