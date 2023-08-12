
/* ************************************************************************** */

/*                                                                            */

/*                                                        :::      ::::::::   */

/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */

/*   Created: 2023/08/12 09:42:24 by sakitaha          #+#    #+#             */

/*   Updated: 2023/08/12 09:56:53 by sakitaha         ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */

#include "ft.h"

void	ft_free(char **src_to_free, size_t limit)
{
	size_t	i;

	i = 0;
	if (!src_to_free)
		return ;
	while (src_to_free[i] && i < limit)
	{
		free(src_to_free[i]);
		src_to_free[i] = NULL;
		++i;
	}
	free(src_to_free);
}
