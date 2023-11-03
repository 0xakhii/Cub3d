/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:51:10 by lahamoun          #+#    #+#             */
/*   Updated: 2023/10/27 21:41:05 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int getmaxcolumns(char **map)
{
    int max_columns;
    int i;
    int len;
    
    max_columns = 0;
    i = 0;
    while (map[i])
    {
        len = ft_strlen(map[i]);
        if (len > max_columns)
            max_columns = len;
        i++;
    }
    return (max_columns);
}

int getmapheight(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int calculatetilesize(char **map)
{
    int map_width;
    int map_height;
    int tile_size_width;
    int tile_size_height;
    
    map_width = getmaxcolumns(map);
    map_height = getmapheight(map);
    tile_size_width = SCREEN_WIDTH / map_width;
    tile_size_height = SCREEN_HEIGHT / map_height;

    if (tile_size_width < tile_size_height)
        return (tile_size_width);
    else
        return (tile_size_height);
}
