/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:28:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/10 02:17:35 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_for_textures(t_map *map)
{
	if (!map->n_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid north texture",
				2), 1);
	if (!map->e_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid east texture",
				2), 1);
	if (!map->s_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid south texture",
				2), 1);
	if (!map->w_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid west texture",
				2), 1);
	return (0);
}

int	check_for_colors(t_map *map)
{
	if (!map->f_color)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid floor color", 2),
			1);
	if (!map->c_color)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid celling color",
				2), 1);
	return (0);
}

void	map_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_for_textures(map) || check_for_colors(map))
		return ;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			//floodfill check on map
			j++;
		}	
		i++;
	}
}
