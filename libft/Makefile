# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 12:04:24 by sgoffaux          #+#    #+#              #
#    Updated: 2021/06/25 13:43:33 by sgoffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isascii.c \
			ft_memcpy.c \
			ft_strjoin.c \
			ft_strrchr.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_strtrim.c \
			ft_bzero.c \
			ft_isprint.c \
			ft_memset.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_split.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_strdup.c \
			ft_strnstr.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_isint.c \
			ft_isspace.c \
			ft_atoi_base.c \

BONUS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJS	=	$(SRCS:%.c=%.o)

BOBJS	=	$(BONUS:%.c=%.o)

CC		=	gcc

INCLUDE =	includes

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE) -c

RM		=	rm -f

NAME	=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

bonus:		$(NAME) $(BOBJS)
			ar r $(NAME) $(BOBJS)

.c.o:
			$(CC) $(CFLAGS) $< -o ${<:.c=.o}

clean:
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
