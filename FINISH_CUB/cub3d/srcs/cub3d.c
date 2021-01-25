/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:18:15 by chly-huc          #+#    #+#             */
/*   Updated: 2021/01/25 17:13:20 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	start(t_params *params)
{
	if (params->image->save == 1)
		save(params);
	mlx_put_image_to_window(params->ray->mlx, params->ray->window,
			params->image->img, 0, 0);
	key_event(params);
	return (1);
}

void		ft_mlx_hook(t_params *params)
{
	mlx_hook(params->ray->window, 2, 1L << 0, key_pressed, params);
	mlx_hook(params->ray->window, 3, 1L << 0, key_released, params);
	mlx_hook(params->ray->window, 17, 1L << 17, mouse_event, params);
	mlx_loop_hook(params->ray->mlx, start, params);
	if (!(mlx_loop(params->ray->mlx) == 0))
		exit(0);
}

static void	game(t_params *params)
{
	ft_get_tex(params);
	ft_get_sprite(params, params->textsp);
	if (params->map_find == 0)
		ft_error(NO_MAP, params);
	if (ft_check_map(params, params->map) == 0)
		ft_error(WRONG_MAP_FORMAT, params);
	if (!(params->sprites = malloc(sizeof(params->sp) * params->sp->numsprite)))
		ft_error(MALLOC_ERROR, params);
	ft_orientation(params);
	ft_getpose_sprite(params->map, params);
	ft_getposplayer(params->map, params->player);
	if (!(params->image->img = mlx_new_image(params->ray->mlx,
					params->screenwidth, params->screenheight)))
		ft_error(MALLOC_ERROR, params);
	params->image->imgdata = mlx_get_data_addr(params->image->img,
			&params->image->bpp, &params->image->sizeline,
			&params->image->endian);
	params->image->imgsave = mlx_get_data_addr(params->image->img,
			&params->image->bpp, &params->image->sizeline,
			&params->image->endian);
	
	ft_raycast(params, params->ray, params->color);
	ft_mlx_hook(params);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_params	*params;

	params = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		quit(NO_MAPFILE, params);
	if (ft_strncmp(argv[1], ".cub", ft_strlen(argv[1])) == 0)
		quit(NO_MAPFILE, params);
	if (!(params = ft_malloc_params()))
		return (0);
	ft_init_game(params, fd);
	parameters(params, argc, argv);
	game(params);
	exit(0);
}
