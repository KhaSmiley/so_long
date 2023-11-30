# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 21:55:09 by kboulkri          #+#    #+#              #
#    Updated: 2023/11/27 22:41:51 by kboulkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS		=	srcs/count_ecp.c srcs/exit_and_free.c srcs/flood_and_fill.c srcs/graphics.c srcs/move_player.c srcs/parsing_utils_two.c srcs/parsing_utils.c srcs/parsing.c srcs/so_long.c

OBJS_DIR	=	objs
OBJS_1		=	$(SRCS:$(SRCS)/%.c=$(OBJS_DIR)/%.o)


LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft

CC			=		clang
CPPFLAGS	=		-I./include -I./libft/include
MLX			=		-L./minilibx-linux
MLXFLAGS	=		-lmlx -lX11 -lXext
CFLAGS		=		-Wall -Werror -Werror -g3

$(NAME):		$(OBJS_1) 
					$(MAKE) -C $(LIBFT_DIR)
					$(CC) $(CFLAGS) $(CPPFLAGS) $(MLX) -lm $(OBJS_1) $(MLXFLAGS) -o $(NAME) $(LIBFT)

all:			$(NAME)

clean:
					rm -rf $(OBJS_DIR)
					$(MAKE) clean -C $(LIBFT_DIR)

fclean:				clean
						rm -f $(NAME)
						rm -f $(NAME_BONUS)
						$(MAKE) fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean bonus re