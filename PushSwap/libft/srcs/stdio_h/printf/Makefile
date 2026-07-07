NAME        = libftprintf.a

# --- COLORS ---
GREEN       = \033[1;32m
RED         = \033[1;31m
YEL         = \033[1;33m
CYAN        = \033[1;36m
WHITE       = \033[1;37m
RESET       = \033[0m


# --- COMMANDES ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -pedantic -std=c99 -Wconversion -Wunreachable-code -Wshadow -Wundef -Wcast-qual -Wstrict-prototypes
RM          = rm -f
RMF         = rm -rf
AR          = ar rcs


# --- FILES ---
FTPRINTF_FILES = data_init ft_printf ft_printf_dispatch_1 ft_printf_dispatch_2
LIBFT_PRINTF_FILES = ft_memchr ft_memcpy ft_memset \
					ft_putc_data ft_puts_data ft_putuli_data \
					ft_strlen ft_absolute ft_write_secure

OBJS_DIR    = objs/
LIBFT_PRINTF_DIR    = $(addprefix libft_printf/, $(LIBFT_PRINTF_FILES)) 
SRCS        = $(addsuffix .c, $(LIBFT_PRINTF_DIR) $(FTPRINTF_FILES))
OBJS        = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(LIBFT_PRINTF_DIR) $(FTPRINTF_FILES)))


# --- COMPILATION PROGRESS ---
TOTAL_FILES  := $(words $(LIBFT_FILES) $(LIBFT_PRINTF_FILES))
CURRENT_FILE := 0


# --- RULES ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "\n$(YEL)Archiving $(WHITE)$(NAME)$(YEL)...$(RESET)"
	@$(AR) $(NAME) $(OBJS)
	@echo -e ""
	@echo -e "$(GREEN)✨ $(NAME) successfully compiled! ✨$(RESET)"
	@make help

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "$(CYAN)Compiling [%d/%d] $(WHITE)%-20s$(RESET)\r" $(CURRENT_FILE) $(TOTAL_FILES) $<
	@$(CC) $(CFLAGS) -I. -c $< -o $@

test: all
	@$(CC) main.c $(NAME) -o test_printf
	@printf "$(GREEN)Running test...$(RESET)\n"
	@./test_printf
	@$(RM) test_printf

clean:
	@echo -e "$(RED)Cleaning objects...$(RESET)"
	@$(RMF) $(OBJS_DIR)

fclean: clean
	@echo -e "$(RED)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all
	@echo -e ""

triptest:
	@if [ ! -d "libftTester" ]; then \
		echo "$(YEL)Cloning Tripouille/printfTester...$(RESET)"; \
		git clone https://github.com/Tripouille/printfTester.git; \
	fi
	@make -C libftTester

help:
	@echo -e ""
	@echo -e ""
	@echo -e "\n$(WHITE)             - LIBFT MAKEFILE MENU -$(RESET)"
	@echo -e "$(CYAN)-------------------------------------------------------$(RESET)"
	@echo -e "$(GREEN)  make$(RESET)          : Compile $(WHITE)$(NAME)$(RESET)"
	@echo -e "$(GREEN)  make clean$(RESET)    : Delete object files ($(OBJS_DIR))"
	@echo -e "$(GREEN)  make fclean$(RESET)   : Delete objects and $(WHITE)$(NAME)$(RESET)"
	@echo -e "$(GREEN)  make re$(RESET)       : Full re-compilation"
# 	@echo -e "$(GREEN)  make triptest$(RESET) : Run Tripouille's libftTester"
	@echo -e "$(CYAN)-------------------------------------------------------$(RESET)\n"
	@echo -e ""
	@echo -e ""


.PHONY: all clean fclean re triptest help