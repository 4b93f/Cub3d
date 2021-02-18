/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:41:22 by chly-huc          #+#    #+#             */
/*   Updated: 2021/02/04 21:14:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	check_cut_map(t_params *params)
{
	int i;
	int j;
	int find_error;

	i = 0;
	j = 0;
	find_error = 0;
	while (params->map[i] && ft_strlen(params->map[i]))
		i++;
	if (params->map[i] && !ft_strlen(params->map[i]))
		find_error++;
	while (params->map[i] && !ft_strlen(params->map[i]))
		i++;
	if (params->map[i] && ft_strlen(params->map[i]) && find_error >= 1)
		ft_error(VOID_LINE, params);
}
