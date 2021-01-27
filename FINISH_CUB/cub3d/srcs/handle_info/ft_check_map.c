/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:47:26 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/27 21:32:43 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_startend(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (FALSE);
	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] == ' ')
		i--;
	if (str[i] != '1')
		return (FALSE);
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
		if (map[i] != '1' && map[i] != ' ')
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
		|| map[i] == 'E' || map[i] == ' ' || map[i] == '0'
		|| map[i] == '1' || map[i] == '2')
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

void floodfill(t_params *params, char **map)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	params->mapfill = NULL;
	while (map[i])
		i++;
	params->mapfill = malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (len < j)
			len = j;
	}
	i = -1;
	printf("%d\n", len);
	while (map[++i])
	{
		j = -1;
		params->mapfill[i] = malloc(sizeof(char) * len + 1);
		while (++j < len)
			params->mapfill[i][j] = ' ';
		params->mapfill[i][j] = '\0';
	}
	i = 0;
	j = 0;
	while (map[i])
	{
		params->mapfill[i] = ft_memcpy(params->mapfill[i], map[i], strlen(map[i]));
		i++;
	}
	params->mapfill[i] = NULL;
}

int		ft_check_space(int j, int k, t_params *params, char **map)
{
	int i;

	i = -1;
	floodfill(params, map);
	//print_tab(params->mapfill);
	while (params->mapfill[++i])
	{
		while (params->mapfill[i][++j])
		{
			if (params->mapfill[i][j] == ' ')
			{
				k = j;
				if (!(ft_void_algo(i, j, k, params->mapfill)))
					ft_error(WRONG_MAP_FORMAT, params);
			}
			if (params->mapfill[i][j] == '0')
			{
				k = j;
				//if (!(ft_zero_algo(i, j, k, params->mapfill)))
					//ft_error(WRONG_MAP_FORMAT, params);
			}
		}
		j = -1;
	}
	return (TRUE);
}
