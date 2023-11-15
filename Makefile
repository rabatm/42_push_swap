# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m

NAME = push_swap

# Compilater and options
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -g

# FOLDERS
SRCDIR = sources
OBJDIR = obj
PSSOURCES = $(SRCDIR)/push_swap
CHKSOURCES = $(SRCDIR)/checker
OPSOURCES = $(SRCDIR)/operations
LSTSOURCES = $(SRCDIR)/lst
SRTSOURCES = $(SRCDIR)/sortfunc
INCLUDEDIR = includes
LIBFTDIR = includes/libft

#files for operations
SRCOP = $(OPSOURCES)/operations.c $(OPSOURCES)/operations_p.c \
$(OPSOURCES)/operations_r.c $(OPSOURCES)/operations_rr.c

#files for lst
SRCLST = $(LSTSOURCES)/ftcostutils.c $(LSTSOURCES)/ftsort100.c \
$(LSTSOURCES)/ft_sort100_u.c $(LSTSOURCES)/ftsort100_utils.c \
$(LSTSOURCES)/ftsort3.c $(LSTSOURCES)/ftsort.c \
$(LSTSOURCES)/ftturksor.c

#file for sortfunctions
SRCSRT = $(SRTSOURCES)/ftcostutils.c $(SRTSOURCES)/ftsort100.c $(SRTSOURCES)/ft_sort100_u.c \
$(SRTSOURCES)/ftsort100_utils.c $(SRTSOURCES)/ftsort3.c $(SRTSOURCES)/ftsort.c \
$(SRTSOURCES)/ftturksort.c

#files for push_swap
PSSRCS = $(SRCOP) $(SRCLST) $(SRCSRT) $(PSSOURCES)/main.c

# files name
LIBFT = $(LIBFTDIR)/libft.a

# Fichiers sources et objets
OBJPS = $(PSSRCS:.c=.o)

# Règle par défaut
all: $(NAME)

# Règle de construction de l'exécutable
$(NAME): $(LIBFT) $(OBJPS)
	$(CC) $(CFLAGS) $(OBJPS) $(LIBFT)  -o $(NAME)
	@echo "$(BLUE)$(NAME) READY IN BIN FOLDER$(DEF_COLOR)"


# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(PSSRCS)
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ CREATED$(DEF_COLOR)"

# Règle de construction de la bibliothèque libft.a
$(LIBFT):
	$(MAKE) -sC $(LIBFTDIR) all
	@echo "$(YELLOW)LIBFT COMPILED$(DEF_COLOR)"

# Règle de nettoyage des fichiers objets
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)
	@echo "$(BLUE)cleaned!$(DEF_COLOR)"

# Règle de nettoyage complet
fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm $(NAME)
	@echo "$(RED)cleaned!$(DEF_COLOR)"

# Règle de recompilation complète
re: fclean all

.PHONY: all clean fclean re