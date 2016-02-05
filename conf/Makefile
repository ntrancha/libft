# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2016/02/06 00:20:48 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re

clean:
		@rm -rf ../42-*

install: clean
	@gcc func_change_name.c ../libft.a -I../includes/ -o ../42-func_change_name
	@gcc proto.c ../libft.a -I../includes/ -o ../42-check_header
	@gcc functions.c ../libft.a -I../includes/ -o ../42-list_proto
	@gcc makemake.c ../libft.a -I../includes/ -o ../42-makefile
	@echo "#!/bin/sh" > ../42-update
	@chmod 755 ../42-update
	@echo " " >> ../42-update
	@echo "./42-check_header" >> ../42-update
	@echo "./42-makefile -all" >> ../42-update

test:
	@gcc select_lib.c ../libft.a -I../includes/ -o ../42-selec_lib
