NAME=libft.a

SRCS=ft_atoi.c \
ft_atoi_base.c \
ft_atol.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_ltoa_base.c \
ft_ultoa_base.c \
ft_itoa.c \
ft_itoa_base.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_free_split.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_printf/ft_printf.c \
ft_printf/ft_printf_funcs.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c

BONUS=ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c

OBJ=$(SRCS:%.c=%.o)

OBJ_BONUS=$(BONUS:%.c=%.o)

HEADER=libft.h

CC=cc

CFLAGS=-Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar cr $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I .

all: $(NAME)

clean:
	rm $(OBJ) $(OBJ_BONUS) -f

fclean: clean
	rm $(NAME) -f

re: fclean
	$(MAKE) all

bonus: $(OBJ) $(OBJ_BONUS)
	@make "SRCS=$(SRCS) $(BONUS)" --no-print-directory

.PHONY: all clean re fclean bonus
