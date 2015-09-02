# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2015/09/02 08:12:51 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re

clean:
		@rm -rf ../42-*

install: clean
	@cd ..;make install; cd conf/
	@gcc func_change_name.c ../libft.a -I../includes/ -o ../42-func_change_name
	@gcc select_lib.c ../libft.a -I../includes/ -o ../42-selec_lib
