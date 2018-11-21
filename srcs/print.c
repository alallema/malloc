/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:31 by alallema          #+#    #+#             */
/*   Updated: 2018/11/21 21:57:13 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			putstr(char const *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

static void		putnbr_base(unsigned long n, int base)
{
	char const	*char_base = "0123456789abcdef";

	if (n > ((unsigned long)base - 1))
		putnbr_base(n / base, base);
	write(1, &(char_base[n % base]), 1);
}

static void		print_addr(void *addr)
{
	unsigned long nb;

	nb = (unsigned long)addr;
	putstr("0x");
	putnbr_base(nb, 16);
}

static void		print_block(void *addr)
{
	unsigned long	begin;
	unsigned long	end;

	begin = (unsigned long)BLOCK_MEM(addr);
	if (((t_block *)addr)->next)
		end = (unsigned long)(((t_block *)addr)->next);
	else
		end = begin + ((t_block *)addr)->size;
//	printf("0x%lx", begin);
//	printf(" - 0x%lx", end);
//	printf(" : %lu\n", end - begin);
	print_addr((void *)begin);
	putstr(" - ");
	print_addr((void *)end);
	putstr(" : ");
	putnbr_base(end - begin, 10);
	putstr(" octets\n");
	//** DEBUG A ENLEVER **//
	printf("data :%s\n", (char *)begin);
	printf("free :%d\n", ((t_block *)addr)->free);
}

void			print_area(void *addr, int type)
{
	void	*block;

	if (type == 0)
		putstr("TINY : ");
	if (type == 1)
		putstr("SMALL : ");
	if (type == 2)
		putstr("LARGE : ");
	print_addr(addr);
	putstr("\n");
	block = ((t_area *)addr)->base;
	while (block)
	{
		print_block(block);
		block = ((t_block *)block)->next;
	}
	putstr("\n");
}
