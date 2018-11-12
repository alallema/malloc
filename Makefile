RED =	\033[31m
GRE =	\033[32m
YEL =	\033[33m
BLU =	\033[34m
STD =	\033[39m

NAME =		libft_malloc.so

SDIR =		./srcs/
SRCS =		malloc.c

SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

IDIR =		./incs/
INCS =		malloc.h

INCC =		$(addprefix $(IDIR),$(INCS))

NORM =		$(SRCC) $(INCC) $(EXEC)

FLAG =		-Wall -Wextra -Werror -I$(IDIR)

.SILENT:

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${BLU}+Compilation:${STD} $@"
	@gcc -g $(FLAG) $(OBCC) -L$(LDIR) $(LIBS) -o $(NAME)
	#gcc -g $(CFLAGS) $(OBJ) -fPIC -shared -o libft_malloc_$(HOSTTYPE).so
	#gcc -shared -o lib.so file.c
	#ln -sf libft_malloc_$(HOSTTYPE).so libft_malloc.so
	@echo "  ${YEL}Compilation terminee !${STD}"

	$(ODIR)%.o: $(SDIR)%.c
	@echo "  ${GRE}+Compilation :${STD} $^"
	@gcc $^ $(FLAG) -c -o $@
	#gcc -g $(CFLAGS) -c $< -I./include  -o $@

	header:
	@echo "${YEL}"
	@echo "  ==================="
	@echo "  |  Projet Malloc  |"
	@echo "  ==================="
	@echo "${STD}"

	norme: header
	@echo "${GRE}  Verification de la norme${STD}\n"
	@norminette $(NORM)
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

	clean: header
	@echo "  ${RED}-Nettoyage des fichiers objet...${STD}"
	@rm -f $(OBCC)

	fclean: clean
	@rm -f $(NAME)
	@echo "  ${RED}-Nettoyage de l'exécutable...${STD}"

	re: fclean all
