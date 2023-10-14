/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:00:21 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/14 01:49:46 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_north(t_map *map, int i)
{
    i = 0;
    while (map->n_path[i] == ' ' || map->n_path[i] == '\t')
		i++;
	while(map->n_path[i])
	{
		if (map->n_path[i] == '.')
		{
			if (!ft_strcmp(&map->n_path[i], ".xpm"))
				return (1);
			else if (map->n_path[i] == ' ' || map->n_path[i] == '\t')
				return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid north texture\n",
					2), 1);
			else
			{
				ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid north texture\n",
					2);
				return (1);
			}
		}
        else if (!map->n_path[i + 1])
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid north texture\n",
                2), 1);
		i++;
	}
    return (0);
}
int check_south(t_map *map, int i)
{
    i = 0;
    while (map->s_path[i] == ' ' || map->s_path[i] == '\t')
		i++;
	while(map->s_path[i])
	{
		if (map->s_path[i] == '.')
		{
			if (!ft_strcmp(&map->s_path[i], ".xpm"))
				return (1);
			else if (map->s_path[i] == ' ' || map->s_path[i] == '\t')
				return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid south texture\n",
					2), 1);
			else
			{
				ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid south texture\n",
					2);
				return (1);
			}
		}
        else if (!map->s_path[i + 1])
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid south texture\n",
                2), 1);
		i++;
	}
    return (0);
}
int check_east(t_map *map, int i)
{
    i = 0;
    while (map->e_path[i] == ' ' || map->e_path[i] == '\t')
		i++;
	while(map->e_path[i])
	{
		if (map->e_path[i] == '.')
		{
			if (!ft_strcmp(&map->e_path[i], ".xpm"))
				return (1);
			else
			{
				ft_putstr_fd("\033[1;31mCube3D 2:\033[0;0m Invalid east texture\n",
					2);
				return (1);
			}
		}
        else if (map->e_path[i] == ' ' || map->e_path[i] == '\t')
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid east texture\n",
                2), 1);
        else if (!map->e_path[i + 1])
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid east texture\n",
                2), 1);
		i++;
	}
    return (0);
}

int check_west(t_map *map, int i)
{
    i = 0;
    while (map->w_path[i] == ' ' || map->w_path[i] == '\t')
		i++;
	while(map->w_path[i])
	{
		if (map->w_path[i] == '.')
		{
			if (!ft_strcmp(&map->w_path[i], ".xpm"))
				return (1);
			else if (map->w_path[i] == ' ' || map->w_path[i] == '\t')
				return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid west texture\n",
					2), 1);
			else
			{
				ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid west texture\n",
					2);
				return (1);
			}
		}
        else if (!map->w_path[i + 1])
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid west texture\n",
                2), 1);
		i++;
	}
    return (0);
}
