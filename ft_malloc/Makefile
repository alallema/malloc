
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
#libft_malloc_$HOSTTYPE.so
#ln -sf libft_malloc_$(HOSTTYPE).so libft_malloc.so

#INCS = 

SRCS = main.c

OBJS = $(SRCS:.c=.o)

FLAG =  -Wall -Werror -Wextra -Wno-unused-function
