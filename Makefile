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

HEADER = includes/libft.h

OBJS =	$(FILE:.c=.o)

FILE =	ft_memchr.c				ft_putnbr_fd.c			\
		ft_strequ.c				ft_strnequ.c			\
		ft_atoi.c				ft_memcmp.c				\
		ft_strnew.c				ft_bzero.c				\
		ft_memcpy.c				ft_putstr.c				\
		ft_striteri.c			ft_strnstr.c			\
		ft_isalnum.c			ft_memdel.c				\
		ft_putstr_fd.c			ft_strjoin.c			\
		ft_strrchr.c			ft_isalpha.c			\
		ft_memmove.c			ft_strcat.c				\
		ft_isascii.c			ft_memset.c				\
		ft_strchr.c				ft_strlen.c				\
		ft_strsub.c				ft_isdigit.c			\
		ft_putchar.c			ft_strclr.c				\
		ft_strmap.c				ft_strtrim.c			\
		ft_isprint.c			ft_putchar_fd.c			\
		ft_strcmp.c				ft_strmapi.c			\
		ft_tolower.c			ft_itoa.c				\
		ft_putendl.c			ft_strcpy.c				\
		ft_strncat.c			ft_toupper.c			\
		ft_memalloc.c			ft_putendl_fd.c			\
		ft_strdel.c				ft_strncmp.c			\
		ft_memccpy.c			ft_putnbr.c				\
		ft_strdup.c				ft_strncpy.c			\
		ft_strstr.c				ft_strlcat.c			\
		ft_striter.c			ft_gnl.c				\
		ft_strnrpl.c			ft_strmjoin.c			\
		ft_strmore.c			ft_strcchr.c			\
		ft_putnbr_endl.c		ft_readfile.c			\
		ft_tabnew.c				ft_straddchar.c			\
		ft_tabmin.c				ft_tabmax.c				\
		ft_puttab.c				ft_tabclear.c			\
		ft_tabdel.c				ft_abs.c				\
		ft_nbrlen.c				ft_ctos.c				\
		ft_tabup.c				ft_power.c				\
		ft_neg.c				ft_dectobin.c			\
		ft_bintodec.c			ft_rgb.c				\
		ft_strsplit.c			ft_tabstrdel.c			\
		ft_strrvs.c				ft_cinstr.c				\
		ft_strralloc.c			ft_sqrt.c				\
		ft_is_prime.c			ft_find_next_prime.c	\
		ft_strcleanback.c		ft_strcleanfront.c		\
		ft_nbrcat.c				ft_abs_long.c			\
		ft_abs_float.c			ft_atol.c				\
		ft_atof.c				ft_itol.c				\
		ft_ltoi.c				ft_itof.c				\
		ft_longlen.c			ft_ltoa.c				\
		ft_putlong.c			ft_ftoi.c				\
		ft_ftoa.c				ft_putfloat.c			\
		ft_floatlenfloat.c		ft_floatlen.c			\
		ft_fround.c				ft_abs_double.c			\
		ft_atod.c				ft_doublelen.c			\
		ft_doublelendouble.c	ft_dtoi.c				\
		ft_dtoa.c				ft_itod.c				\
		ft_putdouble.c			ft_neg_long.c			\
		ft_strtoupper.c			ft_strtolower.c			\
		ft_facto.c				ft_rsqrt.c				\
		ft_cos.c				ft_sin.c				\
		ft_tan.c				ft_strfusion.c			\
		ft_lstnew.c				ft_lstadd.c				\
		ft_lstdel.c				ft_lstdelone.c			\
		ft_lstiter.c			ft_lstmap.c				\
		ft_abs_longlong.c		ft_isspace.c			\
		ft_istolower.c			ft_istoupper.c			\
		ft_itoll.c				ft_ltoll.c				\
		ft_ltod.c				ft_ltof.c				\
		ft_dtol.c				ft_dtoll.c				\
		ft_dtof.c				ft_ftol.c				\
		ft_ftoll.c				ft_ftod.c				\
		ft_atoll.c				ft_ralloc.c				\
		ft_match.c				ft_neg_double.c			\
		ft_neg_float.c			ft_tabdup.c				\
		ft_listadd.c			ft_listcreate.c			\
		ft_listdel.c			ft_listdelnode.c		\
		ft_listswap.c			ft_listputstr.c			\
		ft_listlen.c

ifeq ($(OS),Windows_NT)
	OS = WIN32
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        SYS = AMD64
    endif
    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        SYS = IA32
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        OS = LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        OS = OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        SYS = AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        SYS = IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        SYS = ARM
    endif
endif

all: binaire $(NAME)

$(NAME): $(OBJS)
		@if [ -f '$(NAME)' ]; then \
			error=1; \
			else \
			echo "Compilation [$(NAME)]"; \
			ar rc $@ $^; \
			ranlib $(NAME); \
			echo "Done"; \
		fi

%.o: %.c
		@if [ -f '$(NAME)' ]; then \
			error=1; \
		else \
			gcc $(FLAG) -c -o $@ $^; \
		fi

.PHONY: verbose quiet clean fclean re install proto reset binaire fichier

verbose: binaire fichier $(OBJS)
		@if [ -f '$(NAME)' ]; then \
			error=1; \
			else \
			echo "Compilation [$(NAME)]"; \
			ar rc $(NAME) $(OBJS); \
			ranlib $(NAME); \
			echo "Done"; \
		fi

quiet: $(OBJS)
		@if [ -f '$(NAME)' ]; then \
			echo "$(NAME) exists"; \
		else \
			ar rc $(NAME) $^; \
			ranlib $(NAME); \
		fi

clean:
		@rm -rf $(OBJS)

fclean: clean reset
		@rm -rf $(NAME)

re: fclean all

install: re
		@rm -rf $(OBJS)

proto:
		@grep "^[a-z]" *.c | cut -d ":" -f 2
		@echo "total: `ls *.c | wc -l` fonction(s)"

binaire:
		@if [ -f '$(NAME)' ]; then \
    	    echo "$(NAME) exists"; \
		else \
			echo "$(shell echo $(OBJS) | wc -w) source files (Flags: $(FLAG)) on $(OS) $(SYS)"; \
			cat $(HEADER) | sed -e "s/OS_UNKNOW/$(OS)/g" > $(HEADER).nk; \
			mv $(HEADER).nk $(HEADER); \
			cat $(HEADER) | sed -e "s/SYS_UNKNOW/$(SYS)/g" > $(HEADER).nk; \
			mv $(HEADER).nk $(HEADER); \
		fi

reset:
		@cat $(HEADER) | sed -e "s/WIN32/OS_UNKNOW/g" > $(HEADER).nk; \
            mv $(HEADER).nk $(HEADER); \
            cat $(HEADER) | sed -e "s/OSX/OS_UNKNOW/g" > $(HEADER).nk; \
            mv $(HEADER).nk $(HEADER); \
            cat $(HEADER) | sed -e "s/LINUX/OS_UNKNOW/g" > $(HEADER).nk; \
            mv $(HEADER).nk $(HEADER);
		@cat $(HEADER) | sed -e "s/IA32/SYS_UNKNOW/g" > $(HEADER).nk; \
            mv $(HEADER).nk $(HEADER); \
            cat $(HEADER) | sed -e "s/AMD64/SYS_UNKNOW/g" > $(HEADER).nk; \
            mv $(HEADER).nk $(HEADER); \
            cat $(HEADER) | sed -e "s/ARM/SYS_UNKNOW/g" > $(HEADER).nk; \
            mv $(HEADER).nk $(HEADER);

fichier:
		@if [ -f '$(NAME)' ]; then \
            error=1 ;\
        else \
			ls -1 *.c > ls.nk; \
			cat ls.nk; \
			rm ls.nk; \
		fi
