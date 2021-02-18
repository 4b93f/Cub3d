/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:57:20 by chly-huc          #+#    #+#             */
/*   Updated: 2021/02/05 15:08:31 by chly-huc         ###   ########.fr       */
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

void	check_params(t_params *params, char *line)
{
	if (line[0] == 'E' && line[1] == 'A')
		if ((ft_strncmp("EA ", line, 3) && ft_strncmp("EA\t", line, 3)))
			quit(WRONG_PARAMS, params);
	if (line[0] == 'W' && line[1] == 'E')
		if ((ft_strncmp("WE ", line, 3) && ft_strncmp("WE\t", line, 3)))
			quit(WRONG_PARAMS, params);
	if (line[0] == 'N' && line[1] == 'O')
		if ((ft_strncmp("NO ", line, 3) && ft_strncmp("NO\t", line, 3)))
			quit(WRONG_PARAMS, params);
	if ((line[0] == 'S' && line[1] == 'O') || line[0] == 'S')
		if ((ft_strncmp("SO ", line, 3) && ft_strncmp("SO\t", line, 3)
		&& (ft_strncmp("S ", line, 2) && ft_strncmp("S\t", line, 2))))
			quit(WRONG_PARAMS, params);
	if (line[0] == 'R')
		if ((ft_strncmp("R ", line, 2) && ft_strncmp("R\t", line, 2)))
			quit(WRONG_PARAMS, params);
	if (line[0] == 'F')
		if ((ft_strncmp("F ", line, 2) && ft_strncmp("F\t", line, 2)))
			quit(WRONG_PARAMS, params);
	if (line[0] == 'C')
		if ((ft_strncmp("C ", line, 2) && ft_strncmp("C\t", line, 2)))
			quit(WRONG_PARAMS, params);
}
