# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2015/08/25 04:03:04 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re

clean:
		@rm -rf libft-*

install: clean
	@cd ..;make install; cd conf/
	@gcc func_change_name.c ../libft.a -I../includes/ -o libft-func_change_name
