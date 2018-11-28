RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[94m
PIN =		\033[1;35m
PRR =		\033[0;36m
STD =		\033[39m

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =		libft_malloc.so

IDIR =		./incs/
INCS =		malloc.h

INCC =		$(addprefix $(IDIR),$(INCS))

SDIR =		./srcs/
SRCS =		alloc.c			\
			malloc.c		\
			calloc.c		\
			realloc.c		\
			free.c			\
			alloc_tools.c	\
			list_tools.c	\
			print.c			\
			show_alloc_mem.c

SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

NORM =		$(SRCC) $(INCC)

FLAG =		-Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${PUR}++ Compilation ++ :${STD} $@"
	@gcc -g $(FLAG) $(OBCC) -fPIC -shared -Wpadded -o libft_malloc_$(HOSTTYPE).so
	@ln -sf libft_malloc_$(HOSTTYPE).so libft_malloc.so
	@echo "  ${PIN}Compilation terminee !${STD}"

$(ODIR)%.o: $(SDIR)%.c
	@echo "  ${PUR}+Compilation :${STD} $^"
	@mkdir -p $(ODIR)
	@gcc $^ $(FLAG) -c -o $@

header:
	@echo "${PRR}"
	@echo "  ==================="
	@echo "  |  Projet Malloc  |"
	@echo "  ==================="
	@echo "${STD}"

norme: header
	@echo "${PRR}  Verification de la norme${STD}\n"
	@norminette $(NORM)
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

clean: header
	@echo "  ${RED}-Delete all object files${STD}"
	@rm -rf $(ODIR)
	@rm -f $(OBCC)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft_malloc_$(HOSTTYPE).so
	@echo "  ${RED}-Delete objects and binary${STD}"

re: fclean all
