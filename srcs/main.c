/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/22 22:43:06 by alallema         ###   ########.fr       */
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
	ptr3 = ft_malloc(10);

	void *pp = ft_malloc(0);
	void *pt = ft_malloc(510);

	void *la = ft_malloc(610);
//	ft_malloc(610);
	void *p = ft_malloc(7570);
	(void)la;
	(void)pp;
	(void)p;
	(void)pt;
//	ft_malloc(4610);
	strcpy(ptr, "lalalala\0");
	strcpy(ptr2, "abcdefgh\0");
	strcpy(ptr3, "AAAAAAAA\0");
	strcpy(la, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa\0");
	show_alloc_mem();
//	ft_free(la);
	ft_free(p);
//	print_list();
//	print_list();
	ft_realloc(la, 698);
//	ft_realloc(la, 10);
//	ft_free(pp);
//	show_alloc_mem();
//	ft_free(ptr3);
//	show_alloc_mem();
//	ft_free(ptr2);
//	show_alloc_mem();
//	ft_free(ptr);
//	show_alloc_mem();
//	ft_free(pt);
	show_alloc_mem();
//	printf("ptr : %s", ptr);
//	printf("ptr2 : %s", ptr2);
	return (0);
}
