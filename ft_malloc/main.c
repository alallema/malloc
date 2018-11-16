/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:14:49 by alallema          #+#    #+#             */
/*   Updated: 2018/11/16 09:06:10 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include "malloc.h"

int main() {
	int		nb;
	void	*s;
	void	*base;
	t_block	block;

	base = NULL;
	nb = 32;
	block.size = 0;
	block.next = NULL;
	block.free = 0;
	s = mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//	strcpy(s, "lalalala");
	memcpy(s, &block, sizeof(block));
	memcpy(s + sizeof(block), &block, sizeof(block));
	printf("pagesize :%d\n", getpagesize());
	printf("size :%lu\n", sizeof(block));
	printf("size :%lu\n", sizeof(int));
//	printf("size :%lu\n", sizeof(*block));
	printf("size :%lu\n", sizeof(block));
	//printf("%s", s);
}
