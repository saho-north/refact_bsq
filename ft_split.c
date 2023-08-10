/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/11 05:20:14 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				g_word_index = 0;
int				g_start = 0;
int				g_end = 0;
int				g_state = 0;

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	to_find;

	str = (char *)s;
	to_find = (char)c;
	while (*str)
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	if (*str == to_find)
		return (str);
	return (NULL);
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

static char	*ft_add_word(char **res, char *str, char **endpos)
{
	int	j;

	res[g_word_index] = malloc(sizeof(char) * ((i - g_start) + 1));
	j = -1;
	while (g_start <= i)
		res[g_word_index][++j] = str[g_start++];
	res[g_word_index][++j] = '\0';
	g_word_index++;
}

char	**ft_split(char *str, char *charset)
{
	char			**res;
	char			*endpos;
	int				j;
	t_word_state	word_state;
	size_t			word_count;

	word_count = ft_count_words(str, charset);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	word_state = OUT_OF_WORD;
	while (*str)
	{
		if (ft_is_in_charset(*str, charset) && word_state == IN_WORD)
		{
			ft_add_word(res, str, &endpos);
			word_state = OUT_OF_WORD;
		}
		else if (word_state == OUT_OF_WORD)
		{
			word_state = IN_WORD;
			++word_count;
		}
		++str;
	}
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

static long	convert_num(const char *str, const char **endpos, bool is_negative)
{
	long	num;
	long	ov_div;
	long	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (is_negative)
		ov_mod++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > ov_div || (num == ov_div && (*str - '0') > ov_mod))
		{
			if (!is_negative)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	*endpos = str;
	if (is_negative)
		num *= -1;
	return (num);
}

long	ft_strtol(const char *str, const char **endpos)
{
	bool	is_negative;

	is_negative = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = true;
		str++;
	}
	return (convert_num(str, endpos, is_negative));
}
