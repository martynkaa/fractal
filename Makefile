# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 17:00:59 by rnovodra          #+#    #+#              #
#    Updated: 2018/05/05 15:16:41 by mpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re 

NAME = fractol

MAIN = $(addprefix main/, main.c ft_putpixel.c key_hookie.c mlx_initiation.c \
		create_strctr.c key_hook.c clear_window.c mouse_hook.c draw_fract.c \
		settings.c opencl_initiation.c read_source.c legend.c usage.c)

OBJ = $(MAIN:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit -framework OpenCL

HEADER = ./inc/fractol.h

all : $(NAME)

$(NAME) : $(MAIN) $(HEADER)
	make -C libft/
	gcc $(FLAGS) $(FLAGS_MLX) -L libft/ -lft -I ./inc $(MAIN) -o $(NAME)

%.o : %.c
	gcc -c -o $@ $< $(FLAGS) -I./inc

clean :
	@rm -rf $(OBJ)
	@rm -rf $(main)
	make -C libft/ clean
fclean : clean
	rm -rf $(NAME) 
	make -C libft/ fclean 

re : fclean all
