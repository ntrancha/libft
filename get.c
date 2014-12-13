/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get.c	:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ntrancha <ntrancha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2014/11/25 09:56:37 by ntrancha		  #+#	#+#			 */
/*   Updated: 2014/12/13 10:32:15 by ntrancha         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "includes/libft.h"
#include <fcntl.h>
#include <unistd.h>

int			 main(void)
{
	char		*line;
	int			fd;
	int			ret;

	line = ft_strnew(1);
	fd = open("file", O_RDONLY);
	ret = 1;
	if (ft_readfile(0, &line) >= 0)
		ft_putstr(line);
	
	close(fd);
	return (0);
}
