SRC_FILES = \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_strlen \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memmove \
	ft_strlcpy \
	ft_strlcat \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_memchr \
	ft_memcmp \
	ft_strnstr \
	ft_atoi \
	ft_calloc \
	ft_strdup \
	ft_strdup_v2 \
	ft_substr \
	ft_strjoin \
	ft_strjoin_and_free \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \
	ft_lstlast \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap \
	ft_printf \
	ft_printf_hex \
	ft_printf_nbr \
	ft_strlen_null_safe \
	get_next_line \
	get_next_line_v2 \
	vec_new_free_from_copy_resize \
	vec_push_pop_get_insert_remove \
	vec_append_prepend \
	vec_iter_map_filter_reduce_find

SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

NAME = libft.a
LIBC = ar rcs
CC = cc
EXTRA_FLAGS ?=
CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(EXTRA_FLAGS)
INCLUDE = -I./include
OBJ_CACHE = $(OBJ_DIR).obj_cache

all: $(NAME)

$(OBJ_CACHE):
	@mkdir -p $(OBJ_DIR) > /dev/null
	@touch $(OBJ_CACHE) > /dev/null

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_CACHE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ > /dev/null

$(NAME): $(OBJ)
	@$(LIBC) $(NAME) $(OBJ) > /dev/null
	@echo "$(CC) $(CFLAGS) $(INCLUDE) <- compilation flags used for libft"
	@echo "libft.a created"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine ./include/ $(SRC_DIR)*.h

.PHONY: all clean fclean re norm