/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 01:55:38 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void	ft_free(char **res, size_t word_count)
{
	size_t	i;

	i = 0;
	while (res[i] && i < word_count)
	{
		free(res[i]);
		res[i] = NULL;
		++i;
	}
	free(res);
}

static t_bool	ft_is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (TRUE);
		++charset;
	}
	return (FALSE);
}

static size_t	ft_count_words(char *str, char *charset)
{
	t_word_state	word_state;
	size_t			word_count;

	word_state = OUT_OF_WORD;
	word_count = 0;
	while (*str)
	{
		if (ft_is_in_charset(*str, charset))
			word_state = OUT_OF_WORD;
		else if (word_state == OUT_OF_WORD)
		{
			word_state = IN_WORD;
			++word_count;
		}
		++str;
	}
	return (word_count);
}

static size_t	ft_strlen_not_charset(char *str, char *charset)
{
	size_t	len;

	len = 0;
	while (*str && !ft_is_in_charset(*str, charset))
	{
		++len;
		++str;
	}
	return (len);
}

static char	*ft_add_line(char *str, char *charset, char **endpos)
{
	char	*line;
	size_t	index;
	size_t	current_str_len;

	current_str_len = ft_strlen_not_charset(str, charset);
	line = malloc(sizeof(char) * (current_str_len + 1));
	if (!line)
		return (NULL);
	index = 0;
	while (*str && index < current_str_len)
	{
		line[index] = *str;
		++index;
		++str;
	}
	line[index] = '\0';
	*endpos = str;
	return (line);
}

static char	**ft_initialize_split(char *str, char *charset, size_t *word_count)
{
	char	**res;

	*word_count = ft_count_words(str, charset);
	res = malloc(sizeof(char *) * (*word_count + 1));
	return (res);
}

static t_bool	ft_fill_res(char **res, char *str, char *charset,
		size_t word_count)
{
	size_t	word_index;
	char	*endpos;

	word_index = 0;
	while (*str && word_index < word_count)
	{
		if (!ft_is_in_charset(*str, charset))
		{
			res[word_index] = ft_add_line(str, charset, &endpos);
			if (!res[word_index])
			{
				ft_free(res, word_index);
				return (FALSE);
			}
			str = endpos;
			++word_index;
		}
		else
			++str;
	}
	res[word_index] = 0;
	return (TRUE);
}

//長すぎるみたい
char	**ft_split(char *str, char *charset)
{
	char	**res;
	size_t	word_count;

	res = ft_initialize_split(str, charset, &word_count);
	if (!res)
		return (NULL);
	ft_fill_res(res, str, charset, word_count);
	if (!res)
		return (NULL);
	return (res);
}
