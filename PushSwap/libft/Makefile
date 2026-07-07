NAME = libft.a

# --- COLORS ---
GREEN       = \033[1;32m
RED         = \033[1;31m
YEL         = \033[1;33m
CYAN        = \033[1;36m
WHITE       = \033[1;37m
RESET       = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

RM = rm -f
RMF = rm -vrf
AR = ar rcs

# --- DIRECTORIES ---
SRCS_DIR = srcs/
OBJS_DIR ?= .objs/
CTYPE_H_DIR = ctype_h/
FT_OF_FT_DIR = ft_of_ft/
LINKED_LIST_DIR = linked_list/
STDIO_H_DIR = stdio_h/
STDLIB_H_DIR = stdlib_h/
STRING_H_DIR = string_h/


# --- SUB-DIRECTORIES ---
PRINTF_DIR = printf/
LIBFT_PRINTF_DIR = libft_printf/

# --- FILES ---
CTYPE_H_FILES = ft_isalpha ft_isascii ft_isdigit ft_is_lowercase ft_is_uppercase \
				ft_is_whitespace ft_isalnum ft_isprint ft_tolower ft_toupper
FT_OF_FT_FILES = ft_striteri ft_strmapi
LINKED_LIST_FILES = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
					ft_lstlast ft_lstmap ft_lstnew ft_lstsize
STDIO_H_FILES = ft_putchar_fd ft_putendl_fd ft_putstr_fd
STDLIB_H_FILES = ft_atoi ft_atol ft_calloc ft_itoa ft_realloc
STRING_H_FILES = ft_bzero ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_split \
					ft_strcmp ft_strchr ft_strdup ft_strjoin ft_strlcpy ft_strlcat ft_strlen \
					ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_swap
PRINTF_FILES =		ft_printf
LIBFT_PRINTF_FILES = 	data_printf_init ft_printf_dispatch_1 ft_printf_dispatch_2 \
						ft_putc_data ft_puts_data ft_putuli_data \
						ft_write_secure ft_absolute \

# --- SUB-SOURCES ---
LIBFT_SRCS	= $(addprefix $(SRCS_DIR)$(CTYPE_H_DIR), $(addsuffix .c, $(CTYPE_H_FILES))) \
			$(addprefix $(SRCS_DIR)$(FT_OF_FT_DIR), $(addsuffix .c, $(FT_OF_FT_FILES))) \
			$(addprefix $(SRCS_DIR)$(LINKED_LIST_DIR), $(addsuffix .c, $(LINKED_LIST_FILES))) \
			$(addprefix $(SRCS_DIR)$(STDIO_H_DIR), $(addsuffix .c, $(STDIO_H_FILES))) \
			$(addprefix $(SRCS_DIR)$(STDLIB_H_DIR), $(addsuffix .c, $(STDLIB_H_FILES))) \
			$(addprefix $(SRCS_DIR)$(STRING_H_DIR), $(addsuffix .c, $(STRING_H_FILES))) \

PRINTF_SRCS = $(addprefix $(SRCS_DIR)$(LIBFT_DIR)$(STDIO_H_DIR)$(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILES))) \
			$(addprefix $(SRCS_DIR)$(LIBFT_DIR)$(STDIO_H_DIR)$(PRINTF_DIR)$(LIBFT_PRINTF_DIR), $(addsuffix .c, $(LIBFT_PRINTF_FILES)))


# --- SOURCES ---
SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

# --- COMPILATION PROGRESS ---
TOTAL_FILES  := $(words $(SRCS))
CURRENT_FILE := 0

all: $(NAME)

$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@echo -e ""
		@echo -e "$(GREEN)Build finished !$(RESET)"
		@echo -e ""

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
		@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@echo -e "$(CYAN)Compiling [$(CURRENT_FILE)/$(TOTAL_FILES)] $(WHITE)$<$(RESET)"
	@$(CC) $(CFLAGS) -I . -I includes -I ../includes -c $< -o $@

clean:
	@$(RMF) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
