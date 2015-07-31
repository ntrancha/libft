# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/31 21:35:11 by ntrancha          #+#    #+#             *#
#    Updated: 2015/07/31 21:52:01 by ntrancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

head -n `echo "\`cat includes/libft.h | wc -l\` -2" | bc` includes/libft.h | tail -n `echo "\`cat includes/libft.h | wc -l\` - 18" | bc` | cut -d \" -f 2
