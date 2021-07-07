# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 16:22:42 by sgoffaux          #+#    #+#              #
#    Updated: 2021/07/07 11:50:16 by sgoffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
LIBFT_A		=	libft.a
GNL_A		=	libgnl.a
MLX_A		=	libmlx.a

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f

LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	minilibx/

SRCS		=	fdf.c \
				srcs/alg_utils.c \
				srcs/controls.c \
				srcs/mouse.c \
				srcs/keyboard.c \
				srcs/draw.c \
				srcs/line_alg.c \
				srcs/project.c \
				srcs/parse_map.c \
				srcs/utils.c \

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) -L. -lft -lgnl -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit -g
				@echo "Linked into executable \033[0;32mfdf\033[0m."

$(LIBFT_A):	
				@$(MAKE) -s -C $(LIBFT)
				@echo "Compiled $(LIBFT_A)."
				@cp -p $(addprefix $(LIBFT), $(LIBFT_A)) $(LIBFT_A)

$(GNL_A):	
				@$(MAKE) -s -C $(GNL)
				@echo "Compiled $(GNL_A)."
				@cp -p $(addprefix $(GNL), $(GNL_A)) $(GNL_A)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)
				@echo "Compiled $(MLX_A)"
				@cp -p $(addprefix $(MLX), $(MLX_A)) $(MLX_A)

bonus:			all

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) $(OBJS)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Clean libft."
				@$(MAKE) clean -s -C $(GNL)
				@echo "Clean gnl."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Clean mlx."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(MAKE) fclean -s -C $(GNL)
				@echo "Full clean gnl."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Clean mlx."
				@$(RM) $(LIBFT_A)
				@$(RM) $(GNL_A)
				@$(RM) $(MLX_A)
				@echo "Removed libs."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus