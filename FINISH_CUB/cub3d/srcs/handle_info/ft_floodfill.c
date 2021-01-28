/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:23:08 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/28 20:25:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	floodfill2(t_params *params, char **map, int len)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		if (!(params->mapfill[i] = malloc(sizeof(char) * len + 1)))
			ft_error(MALLOC_ERROR, params);
		while (++j < len)
			params->mapfill[i][j] = ' ';
		params->mapfill[i][j] = '\0';
	}
	i = -1;
	while (map[++i])
	{
		params->mapfill[i] = ft_memcpy(params->mapfill[i],
		map[i], strlen(map[i]));
	}
	params->mapfill[i] = NULL;
}

void		floodfill(t_params *params, char **map)
{
	int i;
	int j;
	int len;

	i = 0;
	while (map[i])
		i++;
	if (!(params->mapfill = malloc(sizeof(char*) * (i + 1))))
		ft_error(MALLOC_ERROR, params);
	i = -1;
	len = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		len = len < j ? j : len;
	}
	floodfill2(params, map, len);
}
