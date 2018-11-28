/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:31 by alallema          #+#    #+#             */
/*   Updated: 2018/11/28 20:31:26 by alallema         ###   ########.fr       */
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

void			putnbr_base(unsigned long n, int base)
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

	begin = (unsigned long)ptr_zone_mem(addr, BLOCK_SIZE);
	if (((t_block *)addr)->next)
		end = (unsigned long)(((t_block *)addr)->next);
	else
		end = begin + ((t_block *)addr)->size;
	print_addr((void *)begin);
	putstr(" - ");
	print_addr((void *)end);
	putstr(" : ");
	putnbr_base(end - begin, 10);
	putstr(" octets\n");
}

size_t			print_area(void *addr, int type, int pos)
{
	void	*block;
	size_t	size;

	if (type == 0 && pos == 0)
		putstr("TINY : ");
	if (type == 1 && pos == 0)
		putstr("SMALL : ");
	if (type == 2 && pos == 0)
		putstr("LARGE : ");
	if (pos == 0)
	{
		print_addr(addr);
		putstr("\n");
	}
	block = ((t_area *)addr)->base;
	size = 0;
	while (block)
	{
		print_block(block);
		size += ((t_block *)block)->size;
		block = ((t_block *)block)->next;
	}
	return (size);
}
