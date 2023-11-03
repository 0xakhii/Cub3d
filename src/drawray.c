/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:51:10 by lahamoun          #+#    #+#             */
/*   Updated: 2023/10/28 03:15:26 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int isWall(int x, int y, t_gameworld *world)
// {
//     if (x < 0 || y < 0 || y >= world->map_info->map_len || x >= world->map_info->max_line)
//         return (1);
//     return (world->map_info->map[y][x] == '1');
// }

// void castSingleRay(t_gameworld *world, double angle)
// {
//     double dx = cos(angle);
//     double dy = sin(angle);
    
//     double rayX = world->map_info->player_x;
//     double rayY = world->map_info->player_y;
//     int rayLength = 0;
    
//     while (!isWall(pixel_to_grid(rayX, world->tile_size), pixel_to_grid(rayY, world->tile_size), world) && rayLength < world->max_ray_distance)
//     {
//         draw_square(world, rayX, rayY, world->tile_size, 0xFF0000);
//         rayX += dx * world->tile_size;
//         rayY += dy * world->tile_size;
//         rayLength += world->tile_size;
//     }
// }
// void castRays(t_gameworld *world)
// {
//     double halfFOV = world->player_fov / 2;
//     double startAngle = world->player.direction.x - halfFOV;
//     double endAngle = world->player.direction.x + halfFOV;
//     double currentAngle = startAngle;
    
//     while (currentAngle <= endAngle)
//     {
//         castSingleRay(world, currentAngle);
//         currentAngle += world->ray_gap;
//     }
// }