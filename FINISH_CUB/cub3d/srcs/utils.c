/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:57:20 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/31 17:56:30 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

int		check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		find_duplicate(char *str, int c)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (str[++i])
		if (str[i] == c)
			num++;
	return (num);
}

int		check_if_digit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
	}
	return (0);
}
