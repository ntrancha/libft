# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2016/02/04 14:10:01 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTEUR	=	ntrancha

PROJECT	=	libft

NAME	=	$(PROJECT).a
 
FLAG	=	-Wall -Wextra -Werror -g
   
HEADER	=	includes/macros.h

GIT		=	https://github.com/$(AUTEUR)/

SCRIPT	= 	$(GIT)Script.git 

DEPOT	= 	$(GIT)$(PROJECT).git

OBJS	=	$(FILE:.c=.o)

FILE	=	src/mem/ft_memalloc.c                \
			src/mem/ft_memmove.c                 \
			src/mem/ft_memset.c                  \
			src/mem/ft_memdel.c                  \
			src/mem/ft_memcmp.c                  \
			src/mem/ft_memccpy.c                 \
			src/mem/ft_memchr.c                  \
			src/mem/ft_ralloc.c                  \
			src/mem/ft_memcpy.c                  \
			src/mem/ft_bzero.c                   \
			src/tab/ft_tabnew.c                  \
			src/tab/ft_tabup.c                   \
			src/tab/ft_tabdel.c                  \
			src/tab/ft_tabdup.c                  \
			src/tab/ft_tabmax.c                  \
			src/tab/ft_tabmin.c                  \
			src/tab/ft_tabclear.c                \
			src/tab/ft_puttab.c                  \
			src/count/ft_longlen.c               \
			src/count/ft_doublelen.c             \
			src/count/ft_strlen.c                \
			src/count/ft_cinstr.c                \
			src/count/ft_nbrlen.c                \
			src/count/ft_floatlen.c              \
			src/count/ft_doublelendouble.c       \
			src/count/ft_floatlenfloat.c         \
			src/screen/ft_screenfull.c           \
			src/screen/ft_casedelend.c           \
			src/screen/ft_screenget_offset.c     \
			src/screen/ft_screenwrite_charl.c    \
			src/screen/ft_screenset_size.c       \
			src/screen/ft_screenfree.c           \
			src/screen/ft_screenget_size.c       \
			src/screen/ft_screenget_row.c        \
			src/screen/ft_screenprint.c          \
			src/screen/ft_screenwrite_charf.c    \
			src/screen/ft_screenbuffering.c      \
			src/screen/ft_screenwrite_str.c      \
			src/screen/ft_screeninit.c           \
			src/screen/ft_screenget_col.c        \
			src/screen/ft_screenset_cursor.c     \
			src/screen/ft_screenis_full.c        \
			src/screen/ft_caseset.c              \
			src/screen/ft_screenset_lcursor.c    \
			src/screen/ft_screenset_offset.c     \
			src/screen/ft_screenclear.c          \
			src/screen/ft_screenwrite_char.c     \
			src/screen/ft_casendel.c             \
			src/screen/ft_screenget_buffer.c     \
			src/screen/ft_screenclean.c          \
			src/screen/ft_casescreate.c          \
			src/screen/ft_screenreset.c          \
			src/screen/ft_casesdel.c             \
			src/screen/ft_screenwrite_strf.c     \
			src/screen/ft_caseadd.c              \
			src/screen/ft_casedel.c              \
			src/screen/ft_casedelete.c           \
			src/screen/ft_screenget_original.c   \
			src/screen/ft_screenget_cursor.c     \
			src/opt/ft_optgetopt_simple.c        \
			src/opt/ft_optget.c                  \
			src/opt/ft_optgetopt_next.c          \
			src/opt/ft_isopt.c                   \
			src/opt/ft_optdel.c                  \
			src/opt/ft_optgetopt_double.c        \
			src/opt/ft_opttest.c                 \
			src/bits/ft_bits_cmp.c               \
			src/bits/ft_bitsvalue.c              \
			src/bits/ft_octetgetbit.c            \
			src/bits/ft_octet_not.c              \
			src/bits/ft_octetsetbit.c            \
			src/bits/ft_octet_add.c              \
			src/bits/ft_bitssetbit.c             \
			src/bits/ft_bitscreate_empty.c       \
			src/bits/ft_octet_sub.c              \
			src/bits/ft_bitsgetoctet.c           \
			src/bits/ft_octet_ror.c              \
			src/bits/ft_octetvalue.c             \
			src/bits/ft_bitscreate.c             \
			src/bits/ft_octet_shl.c              \
			src/bits/ft_bitsdel.c                \
			src/bits/ft_octet_or.c               \
			src/bits/ft_bitssetoctet.c           \
			src/bits/ft_bits_add.c               \
			src/bits/ft_bitsgetaddr.c            \
			src/bits/ft_octet_xor.c              \
			src/bits/ft_bits_addition.c          \
			src/bits/ft_bits_isneg.c             \
			src/bits/ft_bits_debug.c             \
			src/bits/ft_bitscopy.c               \
			src/bits/ft_bits_abs.c               \
			src/bits/ft_bits_neg.c               \
			src/bits/ft_octet_shr.c              \
			src/bits/ft_bits_less.c              \
			src/bits/ft_octet_and.c              \
			src/bits/ft_octet_rol.c              \
			src/list/ft_listaddafter.c           \
			src/list/ft_listswap.c               \
			src/list/ft_listcontent.c            \
			src/list/ft_listtostr.c              \
			src/list/ft_lstdelone.c              \
			src/list/ft_listdelnext.c            \
			src/list/ft_listtotab.c              \
			src/list/ft_listadd.c                \
			src/list/ft_listtostrd.c             \
			src/list/ft_liststrlen.c             \
			src/list/ft_listputstr.c             \
			src/list/ft_listaddfirst.c           \
			src/list/ft_lstadd.c                 \
			src/list/ft_listreverse.c            \
			src/list/ft_listdelnode.c            \
			src/list/ft_listdel.c                \
			src/list/ft_listdelnodenext.c        \
			src/list/ft_listlen.c                \
			src/list/ft_lstiter.c                \
			src/list/ft_lstnew.c                 \
			src/list/ft_listcreate.c             \
			src/list/ft_lstdel.c                 \
			src/list/ft_lstmap.c                 \
			src/list/ft_listdelnoden.c           \
			src/list/ft_liststrlenmax.c          \
			src/extra/ft_getrow.c                \
			src/extra/ft_getcol.c                \
			src/extra/ft_getpid.c                \
			src/extra/ft_test.c                  \
			src/extra/ft_rgb.c                   \
			src/date/ft_date_convert.c           \
			src/date/ft_date_mins.c              \
			src/date/ft_date_timestamp.c         \
			src/date/ft_date_mtos.c              \
			src/date/ft_date_modiftime.c         \
			src/date/ft_date_htos.c              \
			src/date/ft_date_dtos.c              \
			src/date/ft_date_dins.c              \
			src/date/ft_date_diny.c              \
			src/date/ft_date_modifdate.c         \
			src/date/ft_date_summertime.c        \
			src/date/ft_date_hins.c              \
			src/date/ft_timestamp.c              \
			src/strings/ft_lorem_ipsum.c         \
			src/strings/ft_strdel.c              \
			src/strings/ft_strint.c              \
			src/strings/ft_strncpy.c             \
			src/strings/ft_toupper.c             \
			src/strings/ft_strnrpl.c             \
			src/strings/ft_striter.c             \
			src/strings/ft_strjoin.c             \
			src/strings/ft_strnequ.c             \
			src/strings/ft_strcpy.c              \
			src/strings/ft_strfusiondel.c        \
			src/strings/ft_straddchar.c          \
			src/strings/ft_tabstrdel.c           \
			src/strings/ft_strrvs.c              \
			src/strings/ft_strlen.c              \
			src/strings/ft_strtolower.c          \
			src/strings/ft_strmapi.c             \
			src/strings/ft_straddcharf.c         \
			src/strings/ft_strchr.c              \
			src/strings/ft_strcat.c              \
			src/strings/ft_strdoublon.c          \
			src/strings/ft_match.c               \
			src/strings/ft_strcleanfront.c       \
			src/strings/ft_strncmp.c             \
			src/strings/ft_strfusion.c           \
			src/strings/ft_strdup.c              \
			src/strings/ft_strsplit.c            \
			src/strings/ft_strmjoin.c            \
			src/strings/ft_strisoctet.c          \
			src/strings/ft_tolower.c             \
			src/strings/ft_strmap.c              \
			src/strings/ft_strmore.c             \
			src/strings/ft_strsub.c              \
			src/strings/ft_strlcat.c             \
			src/strings/ft_strmmjoin.c           \
			src/strings/ft_strclr.c              \
			src/strings/ft_strralloc.c           \
			src/strings/ft_strstr.c              \
			src/strings/ft_strtoupper.c          \
			src/strings/ft_strnew.c              \
			src/strings/ft_strrchr.c             \
			src/strings/ft_strisnum.c            \
			src/strings/ft_strcchr.c             \
			src/strings/ft_strcleanback.c        \
			src/strings/ft_strcmp.c              \
			src/strings/ft_strncat.c             \
			src/strings/ft_striteri.c            \
			src/strings/ft_strnstr.c             \
			src/strings/ft_strtrim.c             \
			src/strings/ft_strequ.c              \
			src/strings/ft_strf.c                \
			src/strings/ft_strgetline.c          \
			src/bag/ft_bag_get.c                 \
			src/bag/ft_bag_delnode.c             \
			src/bag/ft_bag_addvar.c              \
			src/bag/ft_bag_create.c              \
			src/bag/ft_bag_delvar.c              \
			src/bag/ft_bag_content.c             \
			src/bag/ft_bag_del.c                 \
			src/socket/ft_socket_end_co.c        \
			src/socket/ft_socket_end.c           \
			src/socket/ft_socket_init.c          \
			src/socket/ft_socket_write.c         \
			src/socket/ft_socket_init_client.c   \
			src/socket/ft_socket_read.c          \
			src/socket/ft_socket_init_server.c   \
			src/test/ft_isalnum.c                \
			src/test/ft_isalpha.c                \
			src/test/ft_istoupper.c              \
			src/test/ft_isopt.c                  \
			src/test/ft_isprint.c                \
			src/test/ft_isascii.c                \
			src/test/ft_istolower.c              \
			src/test/ft_isspace.c                \
			src/test/ft_is_prime.c               \
			src/test/ft_isdigit.c                \
			src/file/ft_fileindos.c              \
			src/file/ft_finpath.c                \
			src/file/ft_getdirtab_f.c            \
			src/file/ft_getdirtab.c              \
			src/file/ft_dos_del.c                \
			src/file/ft_getdir.c                 \
			src/file/ft_gnl_list.c               \
			src/file/ft_readstdin.c              \
			src/file/ft_write_file.c             \
			src/file/ft_get_file.c               \
			src/file/ft_write_file_end.c         \
			src/file/ft_filedel.c                \
			src/file/ft_getdirdeep.c             \
			src/file/ft_fdos_del.c               \
			src/file/ft_fileinfo.c               \
			src/file/ft_filefind.c               \
			src/file/ft_filetype.c               \
			src/file/ft_fdos_displaycol.c        \
			src/file/ft_readfile.c               \
			src/file/ft_deldir.c                 \
			src/file/ft_pathisdir.c              \
			src/file/ft_filecopy.c               \
			src/file/ft_pathisfile.c             \
			src/file/ft_pathexist.c              \
			src/file/ft_filemove.c               \
			src/file/ft_closedir.c               \
			src/file/ft_fileget_rights.c         \
			src/file/ft_catfile_list.c           \
			src/file/ft_catfile.c                \
			src/file/ft_opendir.c                \
			src/file/ft_getdir_rec.c             \
			src/file/ft_dircreate.c              \
			src/file/ft_fileindos_rec.c          \
			src/file/ft_filestrrpl.c             \
			src/file/ft_dinpath.c                \
			src/file/ft_gnl.c                    \
			src/file/ft_readfile_list.c          \
			src/math/ft_neg_double.c             \
			src/math/ft_power.c                  \
			src/math/ft_pointcreate.c            \
			src/math/ft_nbrcat.c                 \
			src/math/ft_substr.c                 \
			src/math/ft_neg.c                    \
			src/math/ft_abs.c                    \
			src/math/ft_neg_long.c               \
			src/math/ft_rsqrt.c                  \
			src/math/ft_tan.c                    \
			src/math/ft_sin.c                    \
			src/math/ft_sqrt.c                   \
			src/math/ft_addsubstr.c              \
			src/math/ft_addstr.c                 \
			src/math/ft_facto.c                  \
			src/math/ft_abs_double.c             \
			src/math/ft_abs_float.c              \
			src/math/ft_sintaddint.c             \
			src/math/ft_abs_long.c               \
			src/math/ft_cos.c                    \
			src/math/ft_abs_longlong.c           \
			src/math/ft_neg_float.c              \
			src/math/ft_find_next_prime.c        \
			src/sig/ft_signalsend.c              \
			src/sig/ft_signalread.c              \
			src/put/ft_putchar.c                 \
			src/put/ft_putstr_fd.c               \
			src/put/ft_puthexa.c                 \
			src/put/ft_putendl.c                 \
			src/put/ft_putnbr_fd.c               \
			src/put/ft_putchar_fd.c              \
			src/put/ft_putendl_fd.c              \
			src/put/ft_putoctet.c                \
			src/put/ft_putlong.c                 \
			src/put/ft_putoctets.c               \
			src/put/ft_putdouble.c               \
			src/put/ft_putfloat.c                \
			src/put/ft_putbits.c                 \
			src/put/ft_putnbr_endl.c             \
			src/put/ft_putnbr.c                  \
			src/put/ft_putstr.c                  \
			src/put/ft_putaddr.c                 \
			src/convert/ft_atof.c                \
			src/convert/ft_dtoll.c               \
			src/convert/ft_hextodec.c            \
			src/convert/ft_ltoll.c               \
			src/convert/ft_ctos.c                \
			src/convert/ft_itof.c                \
			src/convert/ft_itoa.c                \
			src/convert/ft_itoll.c               \
			src/convert/ft_atoll.c               \
			src/convert/ft_ftoll.c               \
			src/convert/ft_dectohex.c            \
			src/convert/ft_sbintocdec.c          \
			src/convert/ft_ltoi.c                \
			src/convert/ft_sinttooct.c           \
			src/convert/ft_dtol.c                \
			src/convert/ft_ltoa.c                \
			src/convert/ft_dtoi.c                \
			src/convert/ft_ftoi.c                \
			src/convert/ft_ltof.c                \
			src/convert/ft_dtoa.c                \
			src/convert/ft_dtof.c                \
			src/convert/ft_ftoa.c                \
			src/convert/ft_atol.c                \
			src/convert/ft_ltod.c                \
			src/convert/ft_dectobin.c            \
			src/convert/ft_itod.c                \
			src/convert/ft_itol.c                \
			src/convert/ft_ftod.c                \
			src/convert/ft_atoi.c                \
			src/convert/ft_bintodec.c            \
			src/convert/ft_fround.c              \
			src/convert/ft_ftol.c                \
			src/convert/ft_atod.c                \

ifeq ($(OS),Windows_NT)
	OS = WIN32
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        SYS = IA64
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
       SYS = IA64
   endif
   ifneq ($(filter %86,$(UNAME_P)),)
       SYS = IA32
   endif
   ifneq ($(filter arm%,$(UNAME_P)),)
       SYS = ARM
   endif
endif

all: reset binaire $(NAME)

update:
	@echo "Update ..."
	@git clone $(DEPOT) tmp > /dev/null 2> /dev/null
	@cd tmp/; cp -R * ..; cd ..; rm -rf tmp/
	@echo "Done"

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
		gcc $(FLAG) -c -o $@ $^ -fPIC; \
	fi

timestamp:
	@echo `/bin/date "+%s"` > t.nk

make:timestamp tools maker re

header:
	@echo "`./42-check_header`"

maker: header 
	@echo "`./42-makefile -all`"

.PHONY: verbose quiet clean fclean re install proto reset binaire fichier timestamp test dynamique make maker tools reboot finstall

dynamique: fclean reset binaire $(OBJS) libso
	 
libso:
	@echo "Compilation [libft.so]";
	@gcc -o libft.so -shared $(OBJS)
	@echo "Done;"
	@rm -rf $(OBJS)

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
 
fclean: clean reset clean_tools
	@rm -rf $(NAME)

clean_tools:
	@rm -rf 42-*
			 
re: fclean all

finstall: reboot install
	
install: timestamp re tools
	@rm -rf $(OBJS)
	@echo "`/bin/date "+%s"` - `cat t.nk`" > t.nk
	@echo "in `cat t.nk | bc`s"
	@rm -rf t.nk

proto:
	@grep "^[a-z]" *.c | cut -d ":" -f 2
	@echo "total: `ls -R src/*.c | wc -l` fonction(s)"

binaire:
	@if [ -f '$(NAME)' ]; then \
   	    echo "$(NAME) exists"; \
	else \
		echo "$(shell find src/ -type f -print | grep .c$ | wc -l) files (Flags: $(FLAG)) on $(OS) $(SYS)"; \
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
    cat $(HEADER) | sed -e "s/IA64/SYS_UNKNOW/g" > $(HEADER).nk; \
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
	
test: fclean quiet fclean
	@echo "No error"
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@git clone $(SCRIPT) script > /dev/null 2> /dev/null
	@python script/norme.py $(FILE)
	@script/./test_header.sh $(FILE)
	@script/./test_file_makefile.sh
	@rm -rf script

tools: clean_tools
	@echo "Tools creation ..."
	@gcc conf/src/select_lib.c			libft.a	-Iincludes/	-o	42-selec_lib
	@gcc conf/src/func_change_name.c	libft.a -Iincludes/ -o	42-func_change_name
	@gcc conf/src/proto.c				libft.a -Iincludes/ -o	42-check_header
	@gcc conf/src/functions.c			libft.a -Iincludes/ -o	42-list_proto
	@gcc conf/src/makemake.c			libft.a -Iincludes/ -o	42-makefile
	@echo "#!/bin/sh" 					>						42-update
	@chmod								755						42-update
	@echo " "							>>						42-update
	@echo "./42-check_header"			>>						42-update
	@echo "./42-makefile -all"			>>						42-update
	@echo "Done";
	
reboot:
	@echo "libft.h [restoration ...]"
	@cp conf/files/libft.h includes/
	@echo "Makefile [restoration ...]"
	@cp conf/files/Makefile_full Makefile

