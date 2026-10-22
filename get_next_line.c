/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 12:06:39 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/04 12:06:40 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*join_n_freeold(char *str, char *buf);
static char	*read_n_join(int fd, char *str);
static char	*ft_strdup_mod(const char *src);

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*dest;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_n_join(fd, str);
	if (!str || *str == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!ft_strchr(str, '\n'))
	{
		dest = str;
		str = NULL;
		return (dest);
	}
	dest = ft_substr(str, 0, ft_zero2nl(str, '\n') + 1);
	tmp = str;
	str = ft_strdup_mod(ft_strchr(str, '\n') + 1);
	free (tmp);
	return (dest);
}

static char	*read_n_join(int fd, char *str)
{
	char	*buf;
	int		read_letter;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_letter = 1;
	while (!ft_strchr(str, '\n') && read_letter > 0)
	{
		read_letter = read(fd, buf, BUFFER_SIZE);
		if (read_letter == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[read_letter] = '\0';
		str = join_n_freeold(str, buf);
		if (!str)
			break ;
	}
	free(buf);
	return (str);
}

static char	*join_n_freeold(char *str, char *buf)
{
	char	*tmp;

	if (!str)
		return (ft_strdup_mod(buf));
	tmp = str;
	str = ft_strjoin(str, buf);
	free(tmp);
	return (str);
}

static char	*ft_strdup_mod(const char *src)
{
	char	*cpy;
	size_t	size;
	size_t	i;

	size = ft_strlen(src) + 1;
	cpy = malloc(size);
	i = 0;
	if (cpy == NULL)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
