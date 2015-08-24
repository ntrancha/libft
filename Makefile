# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2015/08/22 22:25:27 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

FLAG =	-Wall -Wextra -Werror -g

OBJS =	$(FILE:.c=.o)

FILE =	../minilibft/src/mem/ft_memchr.c\
		../minilibft/src/mem/ft_memcpy.c\
		../minilibft/src/mem/ft_memccpy.c\
		../minilibft/src/mem/ft_memmove.c\
		../minilibft/src/mem/ft_ralloc.c\
		../minilibft/src/mem/ft_memset.c\
		../minilibft/src/mem/ft_bzero.c\
		../minilibft/src/mem/ft_memalloc.c\
		../minilibft/src/mem/ft_memdel.c\
		../minilibft/src/mem/ft_memcmp.c\
		../minilibft/src/strings/ft_strequ.c\
		../minilibft/src/strings/ft_strnequ.c\
		../minilibft/src/strings/ft_strcmp.c\
		../minilibft/src/strings/ft_strncmp.c\
		../minilibft/src/strings/ft_strdel.c\
		../minilibft/src/strings/ft_tabstrdel.c\
		../minilibft/src/strings/ft_strnew.c\
		../minilibft/src/strings/ft_striter.c\
		../minilibft/src/strings/ft_striteri.c\
		../minilibft/src/strings/ft_strmap.c\
		../minilibft/src/strings/ft_strmapi.c\
		../minilibft/src/strings/ft_strcchr.c\
		../minilibft/src/strings/ft_match.c\
		../minilibft/src/strings/ft_strchr.c\
		../minilibft/src/strings/ft_strrchr.c\
		../minilibft/src/strings/ft_strstr.c\
		../minilibft/src/strings/ft_strnstr.c\
		../minilibft/src/strings/ft_strdup.c\
		../minilibft/src/strings/ft_strcpy.c\
		../minilibft/src/strings/ft_strncpy.c\
		../minilibft/src/strings/ft_strmore.c\
		../minilibft/src/strings/ft_strlcat.c\
		../minilibft/src/strings/ft_strlen.c\
		../minilibft/src/strings/ft_strcat.c\
		../minilibft/src/strings/ft_strncat.c\
		../minilibft/src/strings/ft_strjoin.c\
		../minilibft/src/strings/ft_strmjoin.c\
		../minilibft/src/strings/ft_strmmjoin.c\
		../minilibft/src/strings/ft_straddchar.c\
		../minilibft/src/strings/ft_strfusion.c\
		../minilibft/src/strings/ft_strfusiondel.c\
		../minilibft/src/strings/ft_strtrim.c\
		../minilibft/src/strings/ft_strcleanback.c\
		../minilibft/src/strings/ft_strcleanfront.c\
		../minilibft/src/strings/ft_strclr.c\
		../minilibft/src/strings/ft_strtoupper.c\
		../minilibft/src/strings/ft_strtolower.c\
		../minilibft/src/strings/ft_toupper.c\
		../minilibft/src/strings/ft_tolower.c\
		../minilibft/src/strings/ft_strnrpl.c\
		../minilibft/src/strings/ft_strralloc.c\
		../minilibft/src/strings/ft_strsplit.c\
		../minilibft/src/strings/ft_strsub.c\
		../minilibft/src/strings/ft_strrvs.c\
		../minilibft/src/strings/ft_strdoublon.c\
		../minilibft/src/strings/ft_strisnum.c\
		../minilibft/src/strings/ft_strgetline.c\
		../minilibft/src/test/ft_isdigit.c\
		../minilibft/src/test/ft_isalpha.c\
		../minilibft/src/test/ft_isalnum.c\
		../minilibft/src/test/ft_isascii.c\
		../minilibft/src/test/ft_isprint.c\
		../minilibft/src/test/ft_istolower.c\
		../minilibft/src/test/ft_istoupper.c\
		../minilibft/src/test/ft_isspace.c\
		../minilibft/src/test/ft_is_prime.c\
		../minilibft/src/math/ft_abs.c\
		../minilibft/src/math/ft_find_next_prime.c\
		../minilibft/src/math/ft_neg.c\
		../minilibft/src/math/ft_power.c\
		../minilibft/src/math/ft_sqrt.c\
		../minilibft/src/math/ft_facto.c\
		../minilibft/src/math/ft_abs_long.c\
		../minilibft/src/math/ft_neg_long.c\
		../minilibft/src/math/ft_abs_longlong.c\
		../minilibft/src/math/ft_abs_float.c\
		../minilibft/src/math/ft_neg_float.c\
		../minilibft/src/math/ft_rsqrt.c\
		../minilibft/src/math/ft_cos.c\
		../minilibft/src/math/ft_sin.c\
		../minilibft/src/math/ft_tan.c\
		../minilibft/src/math/ft_abs_double.c\
		../minilibft/src/math/ft_neg_double.c\
		../minilibft/src/math/ft_nbrcat.c\
		../minilibft/src/bag/ft_bag_create.c\
		../minilibft/src/bag/ft_bag_addvar.c\
		../minilibft/src/bag/ft_bag_delvar.c\
		../minilibft/src/bag/ft_bag_delnode.c\
		../minilibft/src/bag/ft_bag_del.c\
		../minilibft/src/bag/ft_bag_content.c\
		../minilibft/src/count/ft_strlen.c\
		../minilibft/src/count/ft_nbrlen.c\
		../minilibft/src/count/ft_floatlenfloat.c\
		../minilibft/src/count/ft_floatlen.c\
		../minilibft/src/count/ft_longlen.c\
		../minilibft/src/count/ft_doublelen.c\
		../minilibft/src/count/ft_doublelendouble.c\
		../minilibft/src/count/ft_cinstr.c\
		../minilibft/src/date/ft_date_convert.c\
		../minilibft/src/date/ft_date_modiftime.c\
		../minilibft/src/date/ft_date_modifdate.c\
		../minilibft/src/date/ft_date_summertime.c\
		../minilibft/src/date/ft_date_diny.c\
		../minilibft/src/date/ft_date_mtos.c\
		../minilibft/src/date/ft_date_htos.c\
		../minilibft/src/date/ft_date_dtos.c\
		../minilibft/src/date/ft_date_timestamp.c\
		../minilibft/src/date/ft_timestamp.c\
		../minilibft/src/extra/ft_rgb.c\
		../minilibft/src/extra/ft_getcol.c\
		../minilibft/src/extra/ft_getrow.c\
		../minilibft/src/extra/ft_getpid.c\
		../minilibft/src/opt/ft_optget.c\
		../minilibft/src/opt/ft_isopt.c\
		../minilibft/src/opt/ft_optdel.c\
		../minilibft/src/opt/ft_opttest.c\
		../minilibft/src/opt/ft_optgetopt_simple.c\
		../minilibft/src/opt/ft_optgetopt_double.c\
		../minilibft/src/opt/ft_optgetopt_next.c\
		../minilibft/src/put/ft_putnbr_fd.c\
		../minilibft/src/put/ft_putchar_fd.c\
		../minilibft/src/put/ft_putstr_fd.c\
		../minilibft/src/put/ft_putendl_fd.c\
		../minilibft/src/put/ft_putchar.c\
		../minilibft/src/put/ft_putstr.c\
		../minilibft/src/put/ft_putendl.c\
		../minilibft/src/put/ft_putnbr.c\
		../minilibft/src/put/ft_putnbr_endl.c\
		../minilibft/src/put/ft_putfloat.c\
		../minilibft/src/put/ft_putlong.c\
		../minilibft/src/put/ft_putdouble.c\
		../minilibft/src/tab/ft_tabmin.c\
		../minilibft/src/tab/ft_tabmax.c\
		../minilibft/src/tab/ft_tabup.c\
		../minilibft/src/tab/ft_tabdup.c\
		../minilibft/src/tab/ft_puttab.c\
		../minilibft/src/tab/ft_tabclear.c\
		../minilibft/src/tab/ft_tabdel.c\
		../minilibft/src/tab/ft_tabnew.c\
		../minilibft/src/socket/ft_socket_init.c\
		../minilibft/src/socket/ft_socket_init_server.c\
		../minilibft/src/socket/ft_socket_init_client.c\
		../minilibft/src/socket/ft_socket_read.c\
		../minilibft/src/socket/ft_socket_end.c\
		../minilibft/src/socket/ft_socket_end_co.c\
		../minilibft/src/screen/ft_casescreate.c\
		../minilibft/src/screen/ft_caseadd.c\
		../minilibft/src/screen/ft_caseset.c\
		../minilibft/src/screen/ft_casendel.c\
		../minilibft/src/screen/ft_casedel.c\
		../minilibft/src/screen/ft_casedelend.c\
		../minilibft/src/screen/ft_casedelete.c\
		../minilibft/src/screen/ft_casesdel.c\
		../minilibft/src/screen/ft_screeninit.c\
		../minilibft/src/screen/ft_screenget_row.c\
		../minilibft/src/screen/ft_screenget_col.c\
		../minilibft/src/screen/ft_screenget_offset.c\
		../minilibft/src/screen/ft_screenget_cursor.c\
		../minilibft/src/screen/ft_screenget_size.c\
		../minilibft/src/screen/ft_screenget_buffer.c\
		../minilibft/src/screen/ft_screenget_original.c\
		../minilibft/src/screen/ft_screenset_offset.c\
		../minilibft/src/screen/ft_screenset_cursor.c\
		../minilibft/src/screen/ft_screenset_lcursor.c\
		../minilibft/src/screen/ft_screenset_size.c\
		../minilibft/src/screen/ft_screenwrite_charl.c\
		../minilibft/src/screen/ft_screenwrite_char.c\
		../minilibft/src/screen/ft_screenwrite_str.c\
		../minilibft/src/screen/ft_screenwrite_charf.c\
		../minilibft/src/screen/ft_screenwrite_strf.c\
		../minilibft/src/screen/ft_screenprint.c\
		../minilibft/src/screen/ft_screenbuffering.c\
		../minilibft/src/screen/ft_screenfree.c\
		../minilibft/src/screen/ft_screenclear.c\
		../minilibft/src/screen/ft_screenclean.c\
		../minilibft/src/screen/ft_screenreset.c\
		../minilibft/src/screen/ft_screenfull.c\
		../minilibft/src/screen/ft_screenis_full.c\
		../minilibft/src/convert/ft_itoa.c\
		../minilibft/src/convert/ft_ltoa.c\
		../minilibft/src/convert/ft_ftoa.c\
		../minilibft/src/convert/ft_dtoa.c\
		../minilibft/src/convert/ft_ctos.c\
		../minilibft/src/convert/ft_atoi.c\
		../minilibft/src/convert/ft_ltoi.c\
		../minilibft/src/convert/ft_ftoi.c\
		../minilibft/src/convert/ft_dtoi.c\
		../minilibft/src/convert/ft_dectobin.c\
		../minilibft/src/convert/ft_bintodec.c\
		../minilibft/src/convert/ft_atol.c\
		../minilibft/src/convert/ft_itol.c\
		../minilibft/src/convert/ft_dtol.c\
		../minilibft/src/convert/ft_ftol.c\
		../minilibft/src/convert/ft_itoll.c\
		../minilibft/src/convert/ft_ltoll.c\
		../minilibft/src/convert/ft_dtoll.c\
		../minilibft/src/convert/ft_ftoll.c\
		../minilibft/src/convert/ft_atoll.c\
		../minilibft/src/convert/ft_atof.c\
		../minilibft/src/convert/ft_itof.c\
		../minilibft/src/convert/ft_ltof.c\
		../minilibft/src/convert/ft_dtof.c\
		../minilibft/src/convert/ft_fround.c\
		../minilibft/src/convert/ft_atod.c\
		../minilibft/src/convert/ft_itod.c\
		../minilibft/src/convert/ft_ltod.c\
		../minilibft/src/convert/ft_ftod.c\
		../minilibft/src/file/ft_gnl.c\
		../minilibft/src/file/ft_gnl_list.c\
		../minilibft/src/file/ft_readstdin.c\
		../minilibft/src/file/ft_readfile.c\
		../minilibft/src/file/ft_readfile_list.c\
		../minilibft/src/file/ft_catfile.c\
		../minilibft/src/file/ft_get_file.c\
		../minilibft/src/file/ft_write_file.c\
		../minilibft/src/file/ft_write_file_end.c\
		../minilibft/src/file/ft_opendir.c\
		../minilibft/src/file/ft_closedir.c\
		../minilibft/src/file/ft_fileinfo.c\
		../minilibft/src/file/ft_fileget_rights.c\
		../minilibft/src/file/ft_filedel.c\
		../minilibft/src/file/ft_filecopy.c\
		../minilibft/src/file/ft_filemove.c\
		../minilibft/src/file/ft_filefind.c\
		../minilibft/src/file/ft_filestrrpl.c\
		../minilibft/src/file/ft_getdir.c\
		../minilibft/src/file/ft_getdirtab.c\
		../minilibft/src/file/ft_getdir_rec.c\
		../minilibft/src/file/ft_fileindos.c\
		../minilibft/src/file/ft_fileindos_rec.c\
		../minilibft/src/file/ft_fdos_displaycol.c\
		../minilibft/src/file/ft_fdos_del.c\
		../minilibft/src/file/ft_dos_del.c\
		../minilibft/src/file/ft_filetype.c\
		../minilibft/src/file/ft_dinpath.c\
		../minilibft/src/file/ft_finpath.c\
		../minilibft/src/list/ft_listadd.c\
		../minilibft/src/list/ft_listaddfirst.c\
		../minilibft/src/list/ft_listaddafter.c\
		../minilibft/src/list/ft_listcreate.c\
		../minilibft/src/list/ft_listtostr.c\
		../minilibft/src/list/ft_listtotab.c\
		../minilibft/src/list/ft_listtostrd.c\
		../minilibft/src/list/ft_listcontent.c\
		../minilibft/src/list/ft_listdel.c\
		../minilibft/src/list/ft_listdelnode.c\
		../minilibft/src/list/ft_listdelnoden.c\
		../minilibft/src/list/ft_listlen.c\
		../minilibft/src/list/ft_liststrlen.c\
		../minilibft/src/list/ft_liststrlenmax.c\
		../minilibft/src/list/ft_listreverse.c\
		../minilibft/src/list/ft_listswap.c\
		../minilibft/src/list/ft_listputstr.c\
		../minilibft/src/list/ft_lstdel.c\
		../minilibft/src/list/ft_lstdelone.c\
		../minilibft/src/list/ft_lstnew.c\
		../minilibft/src/list/ft_lstadd.c\
		../minilibft/src/list/ft_lstmap.c\
		../minilibft/src/list/ft_lstiter.c\
		../minilibft/src/sig/ft_signalsend.c\
		../minilibft/src/sig/ft_signalread.c\

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAG) -c -o $@ $^

.PHONY: clean fclean re

clean:
		@rm -rf $(OBJS)

fclean: clean 
		@rm -rf $(NAME)

re: fclean $(NAME)
