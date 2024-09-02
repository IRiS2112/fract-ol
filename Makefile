# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 18:01:34 by hakaraou          #+#    #+#              #
#    Updated: 2024/03/02 11:53:24 by hakaraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

NAME = fractol

B_NAME = fractol_bonus

SRC = mandatory/fractol.c mandatory/key_tools.c mandatory/libft.c \
	mandatory/ft_fractol.c mandatory/mandelbrot_julia.c \

B_SRC = bonus/fractol_bonus.c bonus/key_tools_bonus.c bonus/libft_bonus.c \
	bonus/ft_fractol_bonus.c bonus/all_fractol_bonus.c bonus/ft_color_bonus.c \

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mandatory/%.o: mandatory/%.c mandatory/fractol.h
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(B_NAME)

bonus/%.o: bonus/%.c bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME) $(B_NAME)
	
re : fclean all

.PHONY : all clean fclean re bonus