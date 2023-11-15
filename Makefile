# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m

NAME = push_swap

# Compiler and options
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

# FOLDERS
SRCDIR = sources
OBJDIR = obj
INCLUDEDIR = includes
LIBFTDIR = includes/libft

# Files for operations
SRCOP = $(SRCDIR)/operations.c $(SRCDIR)/operations_p.c \
	$(SRCDIR)/operations_r.c $(SRCDIR)/operations_rr.c

# Files for lst
SRCLST = $(SRCDIR)/lstutils_err.c $(SRCDIR)/lstutils_s.c $(SRCDIR)/lstutils.c

# Files for sortfunctions
SRCSRT = $(SRCDIR)/ftcostutils.c $(SRCDIR)/ftsort100.c $(SRCDIR)/ft_sort100_u.c \
		$(SRCDIR)/ftsort100_utils.c $(SRCDIR)/ftsort3.c $(SRCDIR)/ftsort.c \
		$(SRCDIR)/ftturksort.c $(SRCDIR)/swaputils.c

# Files for push_swap
PSSRCS = $(SRCOP) $(SRCLST) $(SRCSRT) $(SRCDIR)/main.c

# Files name
LIBFT = $(LIBFTDIR)/libft.a

# Fichiers sources et objets
OBJPS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(PSSRCS))

# Rule to compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ CREATED: $@$(DEF_COLOR)"

# Rule to build the executable
all: $(NAME)

$(NAME): $(LIBFT) $(OBJPS)
	$(CC) $(CFLAGS) $(OBJPS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)$(NAME) READY IN BIN FOLDER$(DEF_COLOR)"

# Rule to build the library libft.a
$(LIBFT):
	$(MAKE) -sC $(LIBFTDIR) all
	@echo "$(YELLOW)LIBFT COMPILED$(DEF_COLOR)"

# Rule to clean object files
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)
	@echo "$(BLUE)Cleaned!$(DEF_COLOR)"

# Rule to clean everything
fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)
	@echo "$(RED)Removed everything!$(DEF_COLOR)"

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re
