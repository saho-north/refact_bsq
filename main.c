/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 11:55:05 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read(int ifd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	content = NULL;
	while ((n = read(ifd, buf, FT_BUFSIZ)) > 0)
	{
		buf[n] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
			content = ft_strjoin(content, buf);
	}
	return (content);
}

t_result	ft_process_map(int ifd)
{
	char	*content;
	char	**map;
	t_info	*info;

	content = ft_read(ifd);
	if (ft_validate_4(content) == FAIL)
		return (FAIL);
	map = ft_split(content, "\n");
	free(content);
	if (ft_validate_5(map) == FAIL)
		return (FAIL);
	if (!(info = ft_prse(map)))
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	ft_free(map, SIZE_MAX);
	free(info);
	return (SUCCESS);
}

int	ft_open_map_from_file(char *argv[], int i)
{
	int			ifd;
	t_result	result;

	ifd = open(argv[i], O_RDONLY);
	if (ifd == -1)
		return (FAIL);
	result = ft_process_map(ifd);
	close(ifd);
	if (result == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
	{
		if (ft_process_map(STDIN) == FAIL)
			ft_puterror(FT_ERR_MAP);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (ft_open_map_from_file(argv, i) == FAIL)
				ft_puterror(FT_ERR_MAP);
			if (!(i + 1 == argc))
				ft_putstr("\n");
		}
	}
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q bsq");
// }
