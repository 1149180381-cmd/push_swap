/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:03:34 by xinyu             #+#    #+#             */
/*   Updated: 2026/09/24 14:03:54 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free_all(char **buf, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

static size_t	ft_word_len(char const *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

static char	**ft_fill_buf(char **buf, char const *s, char c, size_t n)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	while (i < n)
	{
		while (s[start] && s[start] == c)
			start++;
		len = ft_word_len(s, start, c);
		buf[i] = ft_substr(s, start, len);
		if (!buf[i])
		{
			ft_free_all(buf, i);
			return (NULL);
		}
		start += len;
		i++;
	}
	return (buf);
}

char	**ft_split_mod(char const *s, char c, int *argc)
{
	char	**buf;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_count_words(s, c);
	buf = malloc(sizeof(char *) * (n));
	if (!buf)
		return (NULL);
	*argc = n;
	return (ft_fill_buf(buf, s, c, n));
}
