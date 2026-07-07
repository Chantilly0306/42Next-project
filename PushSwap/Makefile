NAME = push_swap

# --- COLORS ---
GREEN       = \033[1;32m
RED         = \033[1;31m
YEL         = \033[1;33m
CYAN        = \033[1;36m
WHITE       = \033[1;37m
RESET       = \033[0m


# --- COMMANDES ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
# -g3 -I. -pedantic -std=c99 -Wconversion -Wunreachable-code -Wshadow -Wundef -Wcast-qual -Wstrict-prototypes
INCLUDES	= -I. -I ./includes -I./libft
RM          = rm -f
RMF         = rm -rf
AR          = ar rcs


# --- FILES ---
MAIN =		main print_pile print_tab print_bench
# BENCH_FILES =
# FREE_FILES =
INIT_FILES = init_data init_lis init_pile init_bench
PILES_FILES = pile_new pile_to_tab
PARSING_FILES = pile_parsing pile_index pile_quicksort_tab pile_lis 
# PUSHSWAP_FILES = pushswap
# ALGOS_FILES = adaptative complex medium simple
# MOVES_FILES = push_mv reverse_rotate_mv rotate_mv swap_mv
UTILS_FILES = error getters is_double


# --- ARCHIVES ---
LIBFT_A = $(LIBFT_DIR)/libft.a


# --- DIRECTORIES ---
# INCLUDES_DIR = includes/
LIBFT_DIR	= libft/
SRCS_DIR	= srcs/
OBJS_DIR    = .objs/
LIBFT_OBJS  = $(OBJS_DIR)$(LIBFT_DIR)
# BENCH_DIR = benchmark/
DATAS_DIR = datas/
PARSING_DIR = parsing/
# PUSHSWAP_DIR = pushswap/
UTILS_DIR = utils/


# --- SUB-DIRECTORIES ---
# FREE_SUBDIR = free/
INIT_SUBDIR = init/
PILES_SUBDIR = piles/
# ALGOS_SUBDIR = algos/
# MOVES_SUBDIR = moves/


# --- SUB-SOURCES ---
# FREE = $(addprefix $(FREE_SUBDIR), $(FREE_FILES))
INIT = $(addprefix $(INIT_SUBDIR), $(INIT_FILES))
PILES = $(addprefix $(PILES_SUBDIR), $(PILES_FILES))
# ALGOS = $(addprefix $(ALGOS_SUBDIR), $(ALGOS_FILES))
# MOVES = $(addprefix $(MOVES_SUBDIR), $(MOVES_FILES))


# --- SOURCES ---
# BENCH = $(addprefix $(BENCH_DIR), $(BENCH_FILES))
# DATAS = $(addprefix $(DATAS_DIR), $(FREE) $(INIT) $(PILES))
DATAS = $(addprefix $(DATAS_DIR), $(INIT) $(PILES))
PARSING = $(addprefix $(PARSING_DIR), $(PARSING_FILES))
# PUSHSWAP = $(addprefix $(PUSHSWAP_DIR), $(PUSHSWAP_FILES) $(MOVES) $(ALGOS))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))


# --- ALL SOURCES & OBJECTS---
# SRCS        = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(MAIN) $(BENCH) $(DATAS) $(PUSHSWAP) $(UTILS)))
# OBJS        = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAIN) $(BENCH) $(DATAS) $(PUSHSWAP) $(UTILS)))
SRCS        = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(MAIN) $(DATAS) $(PARSING) $(UTILS)))
OBJS        = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))


# --- COMPILATION PROGRESS ---
TOTAL_FILES  := $(words $(SRCS))
CURRENT_FILE := 0


# --- RULES ---
all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@echo -e "\n$(YEL)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) OBJS_DIR="../$(LIBFT_OBJS)"

$(NAME): $(OBJS)
	@echo -e "\n$(YEL) Creating Executable $(WHITE)$(NAME)$(YEL)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo -e ""
	@echo -e "$(GREEN)✨ $(NAME) successfully compiled! ✨$(RESET)"
	@make help

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@echo -e "$(CYAN)Compiling [$(CURRENT_FILE)/$(TOTAL_FILES)] $(WHITE)$<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# test: all
# 	@echo -e "Extraction des tests du README.md..."
# 	@sed -n '/<!-- TEST_START -->/,/<!-- TEST_END -->/p' README.md | sed -n '/^```c/,/^```$$/p' | grep -v '^```' > main.c
# 	@if [ -s main.c ]; then \
# 		$(CC) $(CFLAGS) main.c $(NAME) -o test_printf; \
# 		echo -e "$(GREEN)Running tests...$(RESET)\n\n"; \
# 		./test_printf; \
# 	else \
# 		echo -e "$(RED)Erreur : Impossible d'extraire la section de test. Vérifie les balises TEST_START/END dans le README.md.$(RESET)\n"; \
# 		$(RM) main.c; \
# 	fi

clean:
	@echo -e "$(RED)Cleaning objects...$(RESET)"
	@$(RMF) $(OBJS_DIR)
	@echo -e "$(RED)Cleaning libft objects...$(RESET)"
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo -e "$(RED)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo -e "$(RED)Cleaning libft.a...$(RESET)"
	@make fclean -C $(LIBFT_DIR)
	@if [ -s main.c ]; then \
		$(RM) main.c test_printf;\
		echo -e "$(RED)Cleaning tests...$(RESET)\n"; \
	fi
	@if [ -d "printfTester" ]; then \
		$(RMF) printfTester;\
		echo -e "$(RED)Cleaning Tripouille's printf tester...$(RESET)\n"; \
	fi

re: fclean all
	@echo -e ""

help:
	@echo -e ""
	@echo -e ""
	@echo -e "\n$(WHITE)             - PUSH SWAP MAKEFILE MENU -$(RESET)"
	@echo -e "$(CYAN)-------------------------------------------------------$(RESET)"
	@echo -e "$(GREEN)  make$(RESET)			: Compile $(WHITE)$(NAME)$(RESET)"
	@echo -e "$(GREEN)  make clean$(RESET)		: Delete object files ($(OBJS_DIR))"
	@echo -e "$(GREEN)  make fclean$(RESET)		: Delete objects and $(WHITE)$(NAME)$(RESET)"
	@echo -e "$(GREEN)  make re$(RESET)		: Full re-compilation"
	@echo -e "$(GREEN)  make test$(RESET)		: Run main.c in README"
	@echo -e "$(GREEN)  make triptest$(RESET)		: Run Tripouille's printftTester"
	@echo -e "$(CYAN)-------------------------------------------------------$(RESET)\n"
	@echo -e ""
	@echo -e ""


.PHONY: all clean fclean re triptest help test