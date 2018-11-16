#include <stdlib.h>
#include <sys/mman.h>

int		main(int ac, char **av)
{
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
//	int nb;
//	int i;
//	char c;
//	char *str;
//
//	nb = atoi(av[2]);
//	c = av[1][0];
//	str = (char*)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//	i = 0;
//	while (i < nb)
//	{
//		str[i] = c;
//		i++;
//	}
//	str[i] = '\0';
//	printf("%s\n", str);
//	return (0);
}

t_list	*ft_lstnew(void const *content, size_t content_size, int i)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
		elem->i = 0;
	}
	else
	{
		elem->content = malloc(content_size);
		if (elem->content == NULL)
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->i = i;
	}
	elem->next = NULL;
	return (elem);
}
