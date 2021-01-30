/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:47:26 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/30 17:21:12 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_startend(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] != '1' && !ft_isspace(str[i]) && str[i] != 0)
		return (FALSE);
	i = ft_strlen(str) - 1;
	while (i > 0 && ft_isspace(str[i]))
		i--;
	if (str[i] != '1' && !ft_isspace(str[i]) && str[i] != 0)
		return (TRUE);
	return (TRUE);
}

int		ft_updownwall(char *map)
{
	int i;

	i = 0;
	if (ft_check_startend(map) == FALSE)
		return (FALSE);
	while (map[i])
	{
		if (map[i] != '1' && !ft_isspace(map[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_check_char(t_params *params, char *map)
{
	int i;

	i = 0;
	if (ft_check_startend(map) == FALSE)
		return (FALSE);
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
		{
			params->find_pos++;
			params->player_orientation = map[i];
		}
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W'
		|| map[i] == 'E' || map[i] == '\n' || map[i] == '0'
		|| map[i] == '1' || map[i] == '2' || ft_isspace(map[i]))
		{
			if (map[i] == '2')
				params->sp->numsprite += 1;
			i++;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int		ft_check_space(int j, int k, t_params *params)
{
	int i;

	i = -1;
	floodfill(params, params->map);
	while (params->mapfill[++i])
	{
		while (params->mapfill[i][++j])
		{
			if (params->mapfill[i][j] == ' ')
			{
				k = j;
				if (!(ft_void_algo(i, j, k, params->mapfill)))
					ft_error(RGB_ERROR, params);
			}
			if (params->mapfill[i][j] == '0')
			{
				if (!(ft_zero_algo(i, j, k, params->mapfill)))
					ft_error(WRONG_MAP_FORMAT, params);
			}
		}
		j = -1;
	}
	return (TRUE);
}
