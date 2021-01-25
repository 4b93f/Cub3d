/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:16:21 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/25 19:58:34 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		parameters(t_params *params, int argc, char **argv)
{
	if (argc > 1 && argc < 4)
	{
		if (argc == 3)
		{
			if (ft_strncmp(argv[2], "--save", 6) == 0)
				params->image->save = 1;
			else
				ft_error(ERROR_ARGUMENT, params);
		}
	}
	else
		ft_error(ERROR_ARGUMENT, params);
}

static void	param_r(t_params *params, char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	params->res_x = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	params->res_y = ft_atoi(str + i);
	while (ft_isspace(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		quit(ERROR_ARGUMENT, params);
	return ;
}

void		ft_resolution(t_params *params)
{
	char	**tmp;
	int		res_screen_x;
	int		res_screen_y;
	void	*mlx;

	mlx = mlx_init();
	tmp = NULL;
	if (!params->res)
		ft_error(ANOMALY_RES, params);
	param_r(params, params->res);
	mlx_get_screen_size(mlx, &res_screen_x, &res_screen_y);
	params->screenwidth = params->res_x > res_screen_x
	? res_screen_x : params->res_x;
	params->screenheight = params->res_y > res_screen_y
	? res_screen_y : params->res_y;
	if (params->screenwidth < 1 || params->screenheight < 1)
		quit(ANOMALY_RES, params);
}

void		ft_getpose_sprite(char **map, t_params *params)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				params->sprites[k].x = i + 1;
				params->sprites[k].y = j + 1;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int			ft_check_map(t_params *params, char **map)
{
	int i;
	int j;
	int k;

	i = 1;
	j = -1;
	k = 0;
	if (!map[2])
		ft_error(WRONG_MAP_FORMAT, params);
	if (ft_updownwall(map[0]) == 0)
		ft_error(WRONG_MAP_FORMAT, params);
	while (map[i + 1] != NULL)
	{
		if (ft_check_char(params, map[i]) == FALSE)
			ft_error(WRONG_MAP_FORMAT, params);
		i++;
	}
	if (ft_check_space(j, k, params, map) == 0)
		ft_error(WRONG_MAP_FORMAT, params);
	if (params->find_pos != 1)
		ft_error(WRONG_MAP_FORMAT, params);
	return (TRUE);
}
