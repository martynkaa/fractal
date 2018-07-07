.PHONY: all, clean, fclean, re

NAME := libft.a

LIB := ft_atoi.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_max.c \
	ft_min.c \
	ft_search_and_replace.c \
	ft_pow.c \
	ft_strnlen.c \
	ft_strrev.c \
	ft_list_size.c \
	ft_lowercase.c \
	ft_wstrlen.c \
	ft_itoa_ubase.c \
	ft_strndup.c \
	ft_loweret.c \
	ft_len_num.c \
	ft_uppercase.c \
	get_next_line.c \
	ft_atoi_base.c \
	ft_free_mass.c \
	ft_strjoin_freestrs.c \
	ft_strjoin_freestr1.c \
	greater_num.c \
	lower_num.c	

LIB_OBJ = $(LIB:.c=.o)

all: $(NAME)

$(NAME): $(LIB_OBJ)
		@ar rc $(NAME) $(LIB_OBJ)
		@ranlib $(NAME)
		@echo "\033[0;32mlib compiled.\033[0m "

clean:
		@rm -rf $(LIB_OBJ)
		@echo "\033[0;32mCLEANED\033[0m "

fclean: clean
		@rm -f $(NAME)

re: fclean all

$(LIB_OBJ): %.o : %.c ./../inc/libft.h
	@gcc -o $@ -c $< -Wall -Werror -Wextra -I./../inc
	

