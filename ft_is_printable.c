/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_printable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:53:46 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/12 13:00:02 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_printable(char c)
{
	if (c < 0x20 || c == 0x7f)
		return (0);
	return (1);
}

int	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}
