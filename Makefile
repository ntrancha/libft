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
FILE =	ft_memchr.c				ft_putnbr_fd.c \
		ft_strequ.c				ft_strnequ.c \
		ft_atoi.c				ft_memcmp.c \
		ft_strnew.c				ft_bzero.c \
		ft_memcpy.c				ft_putstr.c \
		ft_striteri.c			ft_strnstr.c \
		ft_isalnum.c			ft_memdel.c \
		ft_putstr_fd.c			ft_strjoin.c \
		ft_strrchr.c			ft_isalpha.c \
		ft_memmove.c			ft_strcat.c \
		ft_isascii.c			ft_memset.c \
		ft_strchr.c				ft_strlen.c \
		ft_strsub.c				ft_isdigit.c \
		ft_putchar.c			ft_strclr.c \
		ft_strmap.c				ft_strtrim.c \
		ft_isprint.c			ft_putchar_fd.c \
		ft_strcmp.c				ft_strmapi.c \
		ft_tolower.c			ft_itoa.c \
		ft_putendl.c			ft_strcpy.c \
		ft_strncat.c			ft_toupper.c \
		ft_memalloc.c			ft_putendl_fd.c \
		ft_strdel.c				ft_strncmp.c \
		ft_memccpy.c			ft_putnbr.c \
		ft_strdup.c				ft_strncpy.c \
		ft_strstr.c				ft_strlcat.c \
		ft_striter.c			ft_gnl.c \
		ft_strnrpl.c			ft_strmjoin.c \
		ft_strmore.c			ft_strcchr.c \
		ft_putnbr_endl.c		ft_readfile.c \
		ft_tabnew.c				ft_straddchar.c \
		ft_tabmin.c				ft_tabmax.c \
		ft_puttab.c				ft_tabclear.c \
		ft_tabdel.c				ft_abs.c \
		ft_nbrlen.c				ft_ctos.c \
		ft_tabup.c				ft_power.c \
		ft_neg.c				ft_dectobin.c \
		ft_bintodec.c			ft_rgb.c \
		ft_strsplit.c			ft_tabstrdel.c \
		ft_strrvs.c				ft_cinstr.c \
		ft_strralloc.c			ft_sqrt.c \
		ft_is_prime.c			ft_find_next_prime.c \
		ft_strcleanback.c		ft_strcleanfront.c \
		ft_nbrcat.c				ft_abs_long.c \
		ft_abs_float.c			ft_atol.c \
		ft_atof.c				ft_itol.c \
		ft_ltoi.c				ft_itof.c \
		ft_longlen.c			ft_ltoa.c \
		ft_putlong.c			ft_ftoi.c \
		ft_ftoa.c				ft_putfloat.c \
		ft_floatlenfloat.c		ft_floatlen.c \
		ft_fround.c				ft_abs_double.c \
		ft_atod.c				ft_doublelen.c \
		ft_doublelendouble.c	ft_dtoi.c \
		ft_dtoa.c				ft_itod.c \
		ft_putdouble.c			ft_neg_long.c

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $@ $^
		@ranlib $(NAME)

%.o: %.c
		@gcc $(FLAG) -c -o $@ $^

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

install: re
		@rm -rf $(OBJS)
		@curl -s http://vgs.zz.mu/42/main.c > main.c
		@curl -s http://vgs.zz.mu/42/unit_test.c > unit_test.c
		@curl -s http://vgs.zz.mu/42/unit_test.h > unit_test.h
		@gcc main.c unit_test.c libft.a
		@./a.out
		@rm main.c unit_test.c unit_test.h a.out

manuel:
		@curl -s http://vgs.zz.mu/42/libft.txt > manuel.txt
		@cat manuel.txt
		@echo ""
		@rm manuel.txt
