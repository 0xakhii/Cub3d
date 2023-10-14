/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:28:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/14 01:57:41 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_for_textures(t_map *map)
{
	if (!map->n_path)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid north texture",
				2), 1);
	if (!map->e_path)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid east texture",
				2), 1);
	if (!map->s_path)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid south texture",
				2), 1);
	if (!map->w_path)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid west texture",
				2), 1);
	return (0);
}

int	check_for_colors(t_map *map)
{
	if (!map->f_color)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid floor color", 2),
			1);
	if (!map->c_color)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid celling color",
				2), 1);
	return (0);
}

int	check_charset(t_map *map, char charset, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == charset || charset == '\t')
		{
			if (charset == 'N' || charset == 'S'
				|| charset == 'E' || charset == 'W')
					map->player++;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_chars(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	map->player = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (!check_charset(map, map->map[i][j], "01NSEW "))
				return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid charset", 2),
					1);
			j++;
		}
		i++;
	}
	if (map->player != 1)
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mInvalid player", 2), 1);
	return (0);
}

int	check_ups(t_map *map, int i, int j)
{
	int	k;

	k = i - 1;
	if (k > 0 && map->map_clone[k][j] != '1' && map->map_clone[k][j] != 'x')
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mUnclosed wall", 2), 1);
	k = i + 1;
	if (k < map->map_len && map->map_clone[k][j] != '1' && map->map_clone[k][j] != 'x'
		&& map->map_clone[k][j] != '0')
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mUnclosed wall", 2), 1);
	return (0);
}

int	check_sides(t_map *map, int j, int i)
{
	int	k;

	k = j - 1;
	if (k > 0 && map->map_clone[i][k] != '1' && map->map_clone[i][k] != 'x')	
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mUnclosed wall", 2), 1);
	k = j + 1;
	if (k > 0 && k < map->max_line && map->map_clone[i][k] != '1' && map->map_clone[i][k] != 'x'
		&& map->map_clone[i][k] != '0')
		return (ft_putendl_fd("\033[1;31mError\nCub3D: \033[0mUnclosed wall", 2), 1);
	return (0);
}

int	map_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_for_textures(map) || check_directions(map)
		|| check_for_colors(map) || check_chars(map))
		return (1);
	while(map->map_clone[i])
	{
		j = 0;
		while(map->map_clone[i][j])
		{
			if (map->map_clone[i][j] == 'x')
			{
				if (check_sides(map, j, i))
					return (1);
				if (check_ups(map, i, j))
					return (1);
			}
			j++;
		}	
		i++;
	}
	return (0);
}
