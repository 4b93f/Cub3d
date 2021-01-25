/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 01:14:46 by root              #+#    #+#             */
/*   Updated: 2020/11/16 18:53:47 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		ft_create_params_bis(t_params *params)
{
	params->color = NULL;
	params->sp = NULL;
	params->sv = NULL;
	params->tex = NULL;
	params->image = NULL;
	params->player = NULL;
	params->event = NULL;
	params->ray = NULL;
	params->bmp = NULL;
	params->sprites = NULL;
}

static t_params	ft_create_params(void)
{
	t_params	params;

	params.temp = 0;
	params.screenwidth = 0;
	params.screenheight = 0;
	params.map_find = 0;
	params.find_pos = 0;
	params.player_orientation = 0;
	params.res = NULL;
	params.textno = NULL;
	params.textso = NULL;
	params.textwe = NULL;
	params.textea = NULL;
	params.textsp = NULL;
	params.colorc = NULL;
	params.argbcolorc = NULL;
	params.colorf = NULL;
	params.argbcolorf = NULL;
	params.map = NULL;
	return (params);
}

t_params		*ft_malloc_params(void)
{
	t_params	*malloc_params;

	if (!(malloc_params = malloc(sizeof(t_params))))
		return (0);
	*malloc_params = ft_create_params();
	ft_create_params_bis(malloc_params);
	return (malloc_params);
}

void			ft_free_params(t_params *to_free)
{
	int			i;

	i = -1;
	if (to_free->map != NULL)
	{
		while (to_free->map[++i])
			free(to_free->map[i]);
	}
	free(to_free->map);
	free(to_free);
}
