# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2016/02/04 14:03:54 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re

clean:
		@rm -rf ../42-*

install: clean
	@gcc func_change_name.c ../libft.a -I../includes/ -o ../42-func_change_name
	@gcc select_lib.c ../libft.a -I../includes/ -o ../42-selec_lib
	@gcc proto.c ../libft.a -I../includes/ -o ../42-check_header
