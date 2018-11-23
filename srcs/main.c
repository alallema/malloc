/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/23 23:08:19 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#define M (1024 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
//	void	*ptr;
//	void	*ptr2;
//	void	*ptr3;
//	int i;
//	char *addr;
//	ptr2 = ft_malloc(16);
//	void *la = ft_malloc(610);
//		i = 0;
//		while (i < 1024)
//		{
//			addr = (char*)ft_malloc(1024);
//			addr[0] = 42;
//			ft_free(addr);
//			i++;
//		}
//	char *addr1;
//	char *addr3;
//	addr1 = (char*)ft_malloc(16 * M);
//	strcpy(addr1, "Bonjours\n");
//	show_alloc_mem();
//	print(addr1);
//	if (ft_realloc((void *)addr1 + 5, 10) == NULL)
//		print("Bonjours\n");
//	addr3 = (char*)ft_realloc(addr1, 128*M);
//	show_alloc_mem();
//	addr3[127*M] = 42;
//	print(addr3);
	char *addr;
	addr = ft_malloc(16);
	ft_free(NULL);
	ft_free((void *)addr + 5);
	if (ft_realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
//	ptr = ft_malloc(1024);
//	ptr3 = ft_malloc(10);
//
//	void *pp = ft_malloc(0);
//	void *pt = ft_malloc(510);
//
//	ft_malloc(610);
//	void *p = ft_malloc(7570);
//	(void)la;
//	(void)pp;
//	(void)p;
//	(void)ptr;
//	(void)pt;
////	ft_malloc(4610);
//	strcpy(ptr, "lalalala\0");
//	strcpy(ptr2, "abcdefgh\0");
//	strcpy(ptr3, "AAAAAAAA\0");
//	strcpy(la, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa\0");
//	show_alloc_mem();
//	ft_free(la);
//	ft_free(p);
//	print_list();
//	print_list();
//	ft_realloc(la, 698);
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
//	show_alloc_mem();
//	printf("ptr : %s", ptr);
//	printf("ptr2 : %s", ptr2);
	return (0);
}
