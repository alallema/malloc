/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/18 19:43:19 by alallema         ###   ########.fr       */
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
	ft_malloc(510);
	ft_malloc(510);
	strcpy(ptr, "lalalala\n");
	strcpy(ptr2, "ehijklmnok\0");
	print_list();
	ft_free(ptr2);
	print_list();
	ft_free(ptr3);
	print_list();
	ft_free(ptr);
	print_list();
//	printf("ptr : %s", ptr);
//	printf("ptr2 : %s", ptr2);
	return (0);
}
