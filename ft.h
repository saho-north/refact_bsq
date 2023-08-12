/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 09:59:50 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <fcntl.h>
# include <libgen.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_BUFSIZ 320000
# define IN 1
# define OUT 0
# define SUCCESS 1
# define FAIL 0
# define FT_ERR_MAP "map error\n"
# define STDIN 0

// typedef enum e_result_status
// {
// 	RESULT_SUCCESS,
// 	RESULT_FAIL
// }			t_result_status;

typedef enum e_word_state
{
	OUT_OF_WORD,
	IN_WORD
}			t_word_state;

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_bsq
{
	int		x;
	int		y;
	int		size;
}			t_bsq;

typedef struct s_info
{
	int		num_rows;
	char	empty;
	char	obstacle;
	char	full;
}			t_info;

typedef struct s_tempcrs
{
	int		col;
	int		row;
	int		size;
}			t_tempcrs;

int			g_max;
int			g_col;
int			g_row;
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_puterror(char *str);
int			ft_strlen(char *str);
int			ft_is_printable(char c);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *str, char *charset);
int			ft_atoi(char *str);
int			ft_isspace(int c);
int			ft_validate_5(char **map);
t_info		*ft_prse(char **map);
int			ft_validate(char **map, t_info *info);
int			ft_validate_4(char *content);
void		set_tempcrs(t_tempcrs *p_tempcrs);
int			ft_check_1(char **map, int col, int row, t_info *p_info);
void		ft_make_map(char **map, t_info *p_info);
void		set_bsq(t_bsq *p_bsq);
int			ft_map_colsize(char **map);
void		ft_free(char **src_to_free, size_t limit);

#endif
