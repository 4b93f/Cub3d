/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:49:00 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/31 17:04:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_void_algo(int i, int j, int k, char **map)
{
	k = i;
	while (k > 0 && ft_isspace(map[k][j]))
		k--;
	if (map[k][j] != '1' && k != 0)
		return (0);
	k = i;
	if (map[k + 1] != NULL)
	{
		while (map[k] != NULL && ft_isspace(map[k][j]))
			k++;
		if (map[k] != NULL && map[k][j] != '1')
			return (0);
	}
	k = j;
	while (k > 0 && ft_isspace(map[i][k]))
		k--;
	if (map[i][k] != '1' && k != 0)
		return (0);
	k = j;
	while (map[i][k] && ft_isspace(map[i][k]))
		k++;
	if (map[i][k] != '1' && map[i][k])
		return (0);
	return (1);
}

int	ft_zero_algo(int i, int j, int k, char **map)
{
	while (k > 0 && map[i][k] != '1')
		k--;
	if (map[i][k] != '1' && k != 0)
		return (0);
	k = j;
	while (map[i][k] && map[i][k] != '1')
		k++;
	if (map[i][k] != '1' && map[i - 1][k] && map[i + 1][k])
		return (0);
	k = i;
	while (k >= 0 && map[k][j] != '1')
		if (ft_isspace(map[k--][j]))
			return (0);
	k = i;
	while (map[k] != NULL && map[k][j] != '1')
		if (ft_isspace(map[k++][j]))
			return (0);
	return (1);
}
