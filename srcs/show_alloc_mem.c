/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:52:08 by alallema          #+#    #+#             */
/*   Updated: 2018/11/19 15:08:03 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	show_alloc_mem(void)
{
	t_area	*area;

	area = NULL;
	if (g_base)
	{
		printf("**** LIST ****\n");
		area = g_base;
		while (area)
		{
			print_area(area, area->type);
			area = area->next;
		}
		printf("**** END ****\n");
	}
}
