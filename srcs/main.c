/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/19 18:01:11 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;

	ptr = ft_malloc(9);
	ptr2 = ft_malloc(10 + 1);
	void *la = ft_malloc(610);
	void *p = ft_malloc(7570);
	ptr3 = ft_malloc(10);
	void *pp = ft_malloc(510);
	ft_malloc(510);
//	ft_malloc(4610);
	strcpy(ptr, "lalalala\n");
	strcpy(ptr2, "ehijklmnok\0");
	show_alloc_mem();
//	print_list();
//	ft_free(ptr);
//	print_list();
	ft_free(pp);
	ft_free(p);
//	print_list();
	ft_free(ptr3);
//	print_list();
	ft_free(ptr2);
	ft_free(la);
//	print_list();
	show_alloc_mem();
//	printf("ptr : %s", ptr);
//	printf("ptr2 : %s", ptr2);
	return (0);
}
