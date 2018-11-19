RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[94m
PIN =		\033[1;35m
PRR =		\033[0;36m
STD =		\033[39m

NAME =		test
#EXEC =		main.c

IDIR =		./incs/
INCS =		malloc.h

INCC =		$(addprefix $(IDIR),$(INCS))

SDIR =		./srcs/
SRCS =		main.c			\
			malloc.c		\
			list_tools.c	\
			alloc.c			\
			free.c			\
			print.c			\
			show_alloc_mem.c

SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

NORM =		$(SRCC) $(INCC)# $(EXEC)

FLAG =		-Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${PUR}++ Compilation ++ :${STD} $@"
	@gcc $(FLAG) $(OBCC) -o $(NAME)
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
#	@rm -f $(OBCC)

fclean: clean
	@rm -f $(NAME)
	@echo "  ${RED}-Delete objects and binary${STD}"

re: fclean all
