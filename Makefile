# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m

NAME = push_swap
CHK = checker

# Dossiers
SRCDIR = sources
OBJDIR = obj
PSSOURCES = sources/push_swap/main.c
CHKSOURCES = sources/checker/main.c
INCLUDEDIR = includes
LIBFTDIR = includes/libft
TESTDIR = test

# Compilateur et options
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -g

# Noms des fichiers
LIBFT = $(LIBFTDIR)/libft.a

# Fichiers sources et objets
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Règle par défaut
all: $(NAME)

# Règle de construction de l'exécutable
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PSSOURCES) -o $(NAME)
	@echo "$(BLUE)$(NAME) READY IN BIN FOLDER$(DEF_COLOR)"

# Règle de construction de l'exécutable
$(CHK): $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(CHKSOURCES) -o $(CHK)
	@echo "$(BLUE)$(CHK) READY IN BIN FOLDER$(DEF_COLOR)"

# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ CREATED$(DEF_COLOR)"

# Règle de construction des fichiers de test
$(OBJDIR)/%.o: $(TESTDIR)/%.c
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) $(TEST_CFLAGS) -c $< -o $@
	@echo "$(YELLOW)TEST OBJ CREATED$(DEF_COLOR)"

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

watch:
	@echo "$(BLUE)Watching for changes...$(DEF_COLOR)"
	./run.sh
	fswatch -r $(SRCDIR) $(INCLUDEDIR) | xargs -n1 -I{} ./run.sh

.PHONY: all clean fclean re test