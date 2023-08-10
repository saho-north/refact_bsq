/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/11 04:30:34 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				g_word_index = 0;
int				g_start = 0;
int				g_end = 0;
int				g_state = 0;

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

void	ft_update_in_word(int i)
{
	if (g_state == OUT)
	{
		g_state = IN;
		g_start = i;
		g_end = i;
	}
	else
		g_end = i;
}

void	ft_add_last_word(char **res, char *str, int i)
{
	int	j;

	if (g_state == IN)
	{
		res[g_word_index] = malloc(sizeof(char) * ((i - g_start) + 1));
		j = -1;
		while (g_start <= i)
			res[g_word_index][++j] = str[g_start++];
		res[g_word_index][++j] = '\0';
		g_word_index++;
	}
	res[g_word_index] = 0;
	g_word_index = 0;
	g_start = 0;
	g_end = 0;
	g_state = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	size_t	word_count;

	word_count = ft_count_words(str, charset);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (*str)
	{
		if (ft_is_in_charset(*str, charset))
		{
			if (g_state == OUT)
				continue ;
			g_state = OUT;
			res[g_word_index] = malloc(sizeof(char) * ((g_end - g_start) + 1));
			j = -1;
			while (g_start <= g_end)
				res[g_word_index][++j] = str[g_start++];
			res[g_word_index][++j] = '\0';
			g_word_index++;
		}
		else
			ft_update_in_word(i);
	}
	ft_add_last_word(res, str, i);
	return (res);
}
