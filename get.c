/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get.c	:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ntrancha <ntrancha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2014/11/25 09:56:37 by ntrancha		  #+#	#+#			 */
/*   Updated: 2014/12/01 15:14:50 by ntrancha         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			 main(void)
{
	char		*line;
	int			fd;
	int			ret;

	line = ft_strnew(BUFF_SIZE + 1);
	//line =NULL;
	fd = open("file", O_RDONLY);
	ret = 1;
	line = gnljoin(0);
	ft_putstr(line);
	while (ret > 0)
	{
		//ret = get_next_line(0, &line);
		//printf("\n***********\n%d:%s\n", ret, line);
	}
	/*ret = get_next_line(0, &line);
	printf("\n***********\n%d:%s\n", ret, line);
	ret = get_next_line(0, &line);
	printf("\n***********\n%d:%s\n", ret, line);
	ret = get_next_line(0, &line);
	printf("\n***********\n%d:%s\n", ret, line);*/
	ft_strdel(&line);
	close(fd);
	return (0);
}
