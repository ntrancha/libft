/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lorem_ipsum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 17:51:02 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/05 15:14:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void ft_straddstr(char **dst, char *str)
{
	ft_strfusion(dst, &str);
}

char		*ft_lorem_ipsum(void)
{
	char	*ret;

	ret = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
	ft_straddstr(&ret, " Sed non risus. Suspendisse lectus tortor, dignissimi");
	ft_straddstr(&ret, " sit amet, adipiscing nec, ultricies sed, dolor. Cras");
	ft_straddstr(&ret, " elementum ultrices diam. Maecenas ligula massa, ");
	ft_straddstr(&ret, "varius a, semper congue, euismod non, mi. Proin ");
	ft_straddstr(&ret, "porttitor, orci nec nonummy molestie, enim est ");
	ft_straddstr(&ret, "eleifend mi, non fermentum diam nisl sit amet erat. ");
	ft_straddstr(&ret, "Duis semper. Duis arcu massa, scelerisque vitae, ");
	ft_straddstr(&ret, "consequat in, pretium a, enim. Pellentesque congue. ");
	ft_straddstr(&ret, "Ut in risus volutpat libero pharetra tempor. Cras ");
	ft_straddstr(&ret, "vestibulum bibendum augue. Praesent egestas leo in ");
	ft_straddstr(&ret, "pede. Praesent blandit odio eu enim. Pellentesque ");
	ft_straddstr(&ret, "sed dui ut augue blandit sodales. Vestibulum ante ");
	ft_straddstr(&ret, "ipsum primis in faucibus orci luctus et ultrices ");
	ft_straddstr(&ret, "posuere cubilia Curae; Aliquam nibh. Mauris ac mauris");
	ft_straddstr(&ret, "sed pede pellentesque fermentum. Maecenas adipiscing ");
	ft_straddstr(&ret, "ante non diam sodales hendrerit. Ut velit mauris, ");
	ft_straddstr(&ret, "egestas sed, gravida nec, ornare ut, mi. Aenean ut ");
	ft_straddstr(&ret, "orci vel massa suscipit pulvinar. Nulla sollicitudin.");
	ft_straddstr(&ret, " usce varius, ligula non tempus aliquam, nunc turpis ");
	ft_straddstr(&ret, "ullamcorper nibh, in tempus sapien eros vitae ligula.");
	return (ret);
}
