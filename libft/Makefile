# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 10:45:53 by ntrancha          #+#    #+#              #
#    Updated: 2015/08/25 03:43:46 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

FLAG =	-Wall -Wextra -Werror -g

OBJS =	$(FILE:.c=.o)


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
	
install: re
		@rm -rf $(OBJS)
