/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:02 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/17 17:37:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_error(int error, t_params *params)
{
	if (params->image->img)
		mlx_destroy_image(params->ray->mlx, params->image->img);
	if (params->sp->mlx_sprite)
		mlx_destroy_image(params->ray->mlx, params->sp->mlx_sprite);
	if (params->mlx_txt_n)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_n);
	if (params->mlx_txt_s)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_s);
	if (params->mlx_txt_w)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_w);
	if (params->mlx_txt_e)
		mlx_destroy_image(params->ray->mlx, params->mlx_txt_e);
	if (params->ray->window)
		mlx_destroy_window(params->ray->mlx, params->ray->window);
	if (error > 0)
		quit(error, params);
	return (1);
}

void		free_struct(t_params *params)
{
	ft_free_sprite(params->sp);
	ft_free_tex(params->tex);
	free(params->color);
	free(params->sv);
	free(params->sprites);
	free(params->image);
	free(params->bmp);
	free(params->player);
	ft_free_params(params);
}

void		quit(int num, t_params *params)
{
	static char *error[] = {
		"Error\nMap file not include\n",
		"Error\nWrong parameters in map file\n",
		"Error\nMap not found\n",
		"Error\nMalloc error\n",
		"Error\nx2 same parameters in map file\n",
		"Error\nAnomaly with textures\n",
		"Error\nRGB color need to be < 256 and >= 0\n",
		"Error\nMissing something in RGB Color\n",
		"Error\nWrong format in RGB color\n",
		"Error\nMissing/Wrong Resolution\n",
		"Error\nPlayer not found\n",
		"Error\nAnomaly with sprite\n",
		"Error\nMissing parameters\n",
		"Error\nWrong format in map\n",
		"Error\nInvalid argument\n"
	};

	if (num > 0)
		free_struct(params);
	ft_printf("%s", error[num]);
	exit(0);
}
