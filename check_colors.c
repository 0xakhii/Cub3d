/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:43:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/14 23:48:42 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_c_color(t_map *map)
{
    int i;

    i = 0;
    while (map->c_color[i] == ' ' || map->c_color[i] == '\t')
        i++;
    while(map->c_color[i])
    {
        if (map->c_color[i] == ',' && ft_isdigit(map->c_color[i + 1]))
        {
            if (ft_atoi(&map->c_color[i + 1]) >= 0 && ft_atoi(&map->c_color[i + 1]) <= 255)
                return (1);
            else
            {
                ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid celling color\n",
                    2);
                return (1);
            }
        }
        else if (map->c_color[i] == ' ' || map->c_color[i] == '\t')
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid celling color\n",
                2), 1);
        else if (!map->c_color[i + 1])
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid celling color\n",
                2), 1);
        i++;
    }
    return (0);
}

int check_f_color(t_map *map)
{
    int i;

    i = 0;
    while (map->f_color[i] == ' ' || map->f_color[i] == '\t')
        i++;
    while(map->f_color[i])
    {
        if (map->f_color[i] == ',' && ft_isdigit(map->f_color[i + 1]))
        {
            if (ft_atoi(&map->f_color[i + 1]) >= 0 && ft_atoi(&map->f_color[i + 1]) <= 255)
                return (1);
            else
            {
                ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid floor color\n",
                    2);
                return (1);
            }
        }
        else if (map->f_color[i] == ' ' || map->f_color[i] == '\t')
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid floor color\n",
                2), 1);
        else if (!map->f_color[i + 1])
            return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid floor color\n",
                2), 1);
        i++;
    }
    return (0);
}
