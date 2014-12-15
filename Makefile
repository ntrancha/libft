# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2014/12/11 13:36:26 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
FLAG =	-Wall -Wextra -Werror
OBJS =	$(FILE:.c=.o)
FILE =	ft_memchr.c			ft_putnbr_fd.c \
		ft_strequ.c			ft_strnequ.c \
		ft_atoi.c			ft_memcmp.c \
		ft_strnew.c			ft_bzero.c \
		ft_memcpy.c			ft_putstr.c \
		ft_striteri.c		ft_strnstr.c \
		ft_isalnum.c		ft_memdel.c \
		ft_putstr_fd.c		ft_strjoin.c \
		ft_strrchr.c		ft_isalpha.c \
		ft_memmove.c		ft_strcat.c \
		ft_isascii.c		ft_memset.c \
		ft_strchr.c			ft_strlen.c \
		ft_strsub.c			ft_isdigit.c \
		ft_putchar.c		ft_strclr.c \
		ft_strmap.c			ft_strtrim.c \
		ft_isprint.c		ft_putchar_fd.c \
		ft_strcmp.c			ft_strmapi.c \
		ft_tolower.c		ft_itoa.c \
		ft_putendl.c		ft_strcpy.c \
		ft_strncat.c		ft_toupper.c \
		ft_memalloc.c		ft_putendl_fd.c \
		ft_strdel.c			ft_strncmp.c \
		ft_memccpy.c		ft_putnbr.c \
		ft_strdup.c			ft_strncpy.c \
		ft_strstr.c			ft_strlcat.c \
		ft_striter.c		ft_gnl.c \
		ft_strnrpl.c		ft_strmjoin.c \
		ft_strmore.c		ft_strcchr.c \
		ft_putnbr_endl.c	ft_readfile.c \
		ft_tabnew.c			ft_straddchar.c \
		ft_tabmin.c			ft_tabmax.c \
		ft_puttab.c			ft_tabclear.c \
		ft_tabdel.c			ft_pointnew.c \
		ft_pointcpy.c		ft_pointdel.c \
		ft_nbrlen.c			ft_ctos.c

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $@ $^

%.o: %.c
		@gcc $(FLAG) -c -o $@ $^

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
