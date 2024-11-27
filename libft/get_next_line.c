/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:21:24 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/05/01 23:21:28 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	helper_func(char *buffer, int fd)
{
	int	read_byt;

	read_byt = read(fd, buffer, BUFFER_SIZE);
	buffer[read_byt] = '\0';
	return (read_byt);
}

void	helper_2(char **res, char **line)
{
	*line = ft_substr2(*res, 0, nl_(*res) + 1, 'n');
	*res = ft_substr2(*res, nl_(*res) + 1, ft_strlen(*res), 'f');
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;
	char		*buffer;
	int			a;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(res), res = NULL, NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(res), res = NULL, NULL);
	a = 1;
	while (a > 0)
	{
		a = helper_func(buffer, fd);
		res = ft_strjoin2(res, buffer);
		if (!res)
			return (free(buffer), NULL);
		if (nl_(res) != -1)
			return (helper_2(&res, &line), free(buffer), line);
	}
	if (res && res[0])
		return (line = res, free(buffer), res = NULL, line);
	return (free(res), res = NULL, free(buffer), NULL);
}
