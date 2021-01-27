/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:49:00 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/27 20:32:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_void_algo(int i, int j, int k, char **map)
{
	k = i;
	if (map[k - 1] != NULL && map[k + 1] != NULL)
	{
		while (strlen(map[k]) >= strlen(map[k + 1]) && k > 0 && map[k][j] == ' ')
			k--;
		if (strlen(map[k]) >= strlen(map[k + 1]) && map[k][j] != '1' && k != 0)
		{
			printf("%s et %d\n", map[k], k);
			printf("VERS LE HAUT\n");
			return (0);
		}
	}
	k = i;
	if (k != 0 && map[k + 1] != NULL)
	{
		while (strlen(map[k]) >= strlen(map[k - 1]) && map[k] != NULL && map[k][j] == ' ')
			k++;
		if (strlen(map[k]) >= strlen(map[k - 1]) && map[k] != NULL && map[k][j] != '1')
		{
			printf("VERS LE BAS\n");
			return (0);
		}
	}
	k = j;
	while (k > 0 && map[i][k] == ' ')
		k--;
	if (map[i][k] != '1' && k != 0)
	{
		printf("{%s} et %d\n", map[i], k);
		printf("VERS LA GAUCHE\n");
		return (0);
	}
	k = j;
	while (map[i][k] && map[i][k] == ' ')
		k++;
	if (map[i][k] != '1' && map[i][k])
	{
		printf("VERS LA DROITE");
		return (0);
	}
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
		if (map[k--][j] == ' ')
			return (0);
	k = i;
	if (map[k + 1] != NULL)
	{
		while (map[k][j] != '1')
			if (map[k++][j] == ' ')
				return (0);
	}
	return (!map[k] ? 0 : 1);
}
