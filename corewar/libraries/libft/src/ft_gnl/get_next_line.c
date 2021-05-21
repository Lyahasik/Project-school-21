/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:06:58 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/01/22 17:03:10 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int		ft_read_line(char **inter, char **line, int fd)
{
	int		ret;
	int		len;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if (!(*inter))
		*inter = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if ((len = ft_strchr_num(buf, '\n')) >= 0)
		{
			tmp = ft_strsub(buf, 0, len);
			*line = ft_strjoin_free(*inter, tmp);
			*inter = ft_strsub(buf, len + 1, ret - len - 1);
			return (1);
		}
		tmp = ft_strjoin(*inter, buf);
		ft_strdel(inter);
		*inter = tmp;
	}
	return (ret == 0 && !(**inter) ? 2 : ret);
}

static int		ft_process_inter(char **inter, char **line)
{
	int		len;
	char	*tmp;

	if (!(*inter) || !(**inter))
		return (0);
	if ((len = ft_strchr_num(*inter, '\n')) >= 0)
	{
		*line = ft_strsub(*inter, 0, len);
		tmp = ft_strsub_free(*inter, len + 1, ft_strlen(*inter) - len - 1);
		*inter = tmp;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret0;
	int				ret1;
	static char		*inter[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFF_SIZE <= 0)
		return (-1);
	if ((ret0 = ft_process_inter(&inter[fd], line)) == 1)
		return (1);
	if ((ret1 = ft_read_line(&inter[fd], line, fd)) == -1)
	{
		ft_strdel(&inter[fd]);
		return (-1);
	}
	if (ret1 == 1)
		return (1);
	if (ret1 == 2)
	{
		ft_strdel(&inter[fd]);
		return (0);
	}
	*line = ft_strdup(inter[fd]);
	ft_strdel(&inter[fd]);
	return (2);
}
