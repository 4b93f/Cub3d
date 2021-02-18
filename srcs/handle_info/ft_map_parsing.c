/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:26:08 by root              #+#    #+#             */
/*   Updated: 2021/01/28 19:23:20 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**ft_realloc(t_params *params, char **str, char *line,
char **strfree)
{
	char	**cpy;
	int		i;

	cpy = NULL;
	i = 0;
	while (str[i] != NULL)
		i++;
	if (!(cpy = malloc(sizeof(char *) * (i + 2))))
		quit(MALLOC_ERROR, params);
	i = -1;
	while (str[++i] != NULL)
		cpy[i] = (str[i]);
	cpy[i] = line;
	cpy[i + 1] = NULL;
	free(strfree);
	return (cpy);
}

char		**ft_map_parsing(t_params *params, int fd, char *firstline)
{
	char	**str;
	int		cmpt;
	char	*line;
	char	**tmp;

	if (!(str = malloc(sizeof(char*) * 1)))
		quit(MALLOC_ERROR, params);
	str[0] = NULL;
	tmp = str;
	if (!(str = ft_realloc(params, str, firstline, tmp)))
		return (NULL);
	cmpt = -1;
	while (get_next_line(fd, &line) > 0)
	{
		cmpt++;
		tmp = str;
		if (!(str = ft_realloc(params, str, line, tmp)))
			return (NULL);
	}
	tmp = str;
	if (!(str = ft_realloc(params, str, line, tmp)))
		return (NULL);
	return (str);
}
