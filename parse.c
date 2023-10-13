/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:02:46 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/13 03:43:49 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_diretions(t_map *map, char **str, int *i, int j)
{
	int k;

	k = 0;
	while (!ft_strncmp(str[(*i)], "NO", 2) || !ft_strncmp(str[(*i)], "SO", 2)
		|| !ft_strncmp(str[(*i)], "WE", 2) || !ft_strncmp(str[(*i)], "EA", 2))
	{
		j = 0;
		if (!ft_strncmp(str[(*i)], "NO", 2))
		{
			while (str[(*i)] && str[(*i)][j++] != '.')
			map->n_path = ft_strdup(str[(*i)] + j);
			k++;
		}
		else if (!ft_strncmp(str[(*i)], "SO", 2))
		{
			while (str[(*i)] && str[(*i)][j++] != '.')
			map->s_path = ft_strdup(str[(*i)] + j);
			k++;
		}
		else if (!ft_strncmp(str[(*i)], "WE", 2))
		{
			while (str[(*i)] && str[(*i)][j++] != '.')
			map->w_path = ft_strdup(str[(*i)] + j);
			k++;
		}
		else if (!ft_strncmp(str[(*i)], "EA", 2))
		{
			while (str[(*i)] && str[(*i)][j++] != '.')
			map->e_path = ft_strdup(str[(*i)] + j);
			k++;
		}
		(*i)++;
	}
	if (k != 4)
	{
		ft_putstr_fd("\033[1;31mError\nCub3D: \033[0mInvalid textures\n", 2);
		exit(0);
	}
}

void	get_colors(char **str, t_map *map, int *i, int j)
{
	int	k;

	k = 0;
	while (!ft_strncmp(str[(*i)], "F", 1) || !ft_strncmp(str[(*i)], "C", 1))
	{
		j = 0;
		if (!ft_strncmp(str[(*i)], "F", 1))
		{
			while (!ft_isdigit(str[(*i)][j++]))
			map->f_color = ft_strdup(str[(*i)] + j);
			k++;
		}
		else if (!ft_strncmp(str[(*i)], "C", 1))
		{
			while (!ft_isdigit(str[(*i)][j++]))
			map->c_color = ft_strdup(str[(*i)] + j);
			k++;
		}
		(*i)++;
	}
	if (k != 2)
	{
		ft_putstr_fd("\033[1;31mError\nCub3D: \033[0mInvalid colors\n", 2);
		exit(0);
	}
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	map_fill(char **str, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		get_diretions(map, str, &i, j);
		get_colors(str, map, &i, j);
		map->map = &str[i];
		get_map(&str[i], map);
		break ;
	}
}
