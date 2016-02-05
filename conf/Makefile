# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2016/02/05 22:32:26 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re

clean:
		@rm -rf ../42-*

install: clean
	@gcc select_lib.c ../libft.a -I../includes/ -o ../42-selec_lib
	@gcc proto.c ../libft.a -I../includes/ -o ../42-check_header
	@gcc functions.c ../libft.a -I../includes/ -o ../42-list_proto
	@gcc makemake.c ../libft.a -I../includes/ -o ../42-makefile

test:
	@gcc func_change_name.c ../libft.a -I../includes/ -o ../42-func_change_name
