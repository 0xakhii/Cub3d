/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 07:34:19 by lahamoun          #+#    #+#             */
/*   Updated: 2023/11/02 00:04:01 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_walkable_tile(t_gameworld *world, int x, int y)
{
    printf("Checking tile: (%d, %d)\n", x, y);

    if (x < 0 || y < 0 || y >= world->map_info->map_len || x >= world->map_info->max_line)
    {
        printf("Tile is out of bounds.\n");
        return (0);
    }
    printf("map len : (%d, %d)\n", world->map_info->map_len , world->map_info->max_line);

    if (world->map_info->map[y][x] == '1')
    {
        printf("Tile is a wall.\n");
        return (0);
    }

    printf("Tile is walkable.\n");
    return (1);
}
int pixel_to_grid(int pixel_coordinate, int tile_size)
{
    return (pixel_coordinate / tile_size);
}

void move_player(t_gameworld *world, t_keys key)
{
    int step_size = player_size / 4;
    int old_x = world->map_info->player_x;
    int old_y = world->map_info->player_y;
    int new_x = old_x;
    int new_y = old_y;

    if (key == key_forward)
        new_y -= step_size;
    else if (key == key_backward)
        new_y += step_size;
    else if (key == key_left)
        new_x -= step_size;
    else if (key == key_right)
        new_x += step_size;

    if (is_walkable_tile(world, pixel_to_grid(new_x, world->tile_size), pixel_to_grid(new_y, world->tile_size)) &&
        is_walkable_tile(world, pixel_to_grid(new_x + player_size, world->tile_size), pixel_to_grid(new_y, world->tile_size)) &&
        is_walkable_tile(world, pixel_to_grid(new_x, world->tile_size), pixel_to_grid(new_y + player_size, world->tile_size)) &&
        is_walkable_tile(world, pixel_to_grid(new_x + player_size, world->tile_size), pixel_to_grid(new_y + player_size, world->tile_size)))
    {
        draw_square(world, old_x, old_y, player_size, 0x000000);
        world->map_info->player_x = new_x;
        world->map_info->player_y = new_y;
        draw_square(world, new_x, new_y, player_size, 0x0FF000);
    }
}

void    rotate_vector(double angle, t_point2D *vector)
{
    double cosAngle;
    double sinAngle;
    double prev_x;

    cosAngle = cos(ROTATION_SPEED * angle);
    sinAngle = sin(ROTATION_SPEED * angle);
    prev_x = vector->x;
    vector->x = prev_x * cosAngle - vector->y * sinAngle;
    vector->y = prev_x * sinAngle + vector->y * cosAngle;
}

void rotate_player(t_gameworld *world, double angle)
{
    rotate_vector(angle, &world->player.direction);
    rotate_vector(angle, &world->player.viewslice);
    printf("Player Direction: (%f, %f)\n", world->player.direction.x, world->player.direction.y);
}

void ft_drawline(t_gameworld *world,int radius,int angle, int color)
{
    double x;
    double y;
    (void)radius;

    x =  (double)world->map_info->player_x + 5;
    y =  (double)world->map_info->player_y  + 5;
    while(1)
    {
        x+= cos(angle * M_PI/180);
        y-= sin(angle * M_PI/180) ;
        if (world->map_info->map[(int)y / world->tile_size][(int)x / world->tile_size] == '1')
        {
            break;
        }
       if (abs((int)x - (world->map_info->player_x + 5)) > 5 || abs((int)y - (world->map_info->player_y + 5)) > 5)
            mlx_pixel_put(world->mlx, world->window,(int)x,(int)y, color);
    }
}
void ft_view(t_gameworld *world,int radius,int angle, int color)
{
    int i;

    i = 0;
    (void)radius;
    while (i <= 60)
    {
        ft_drawline(world,world->tile_size,angle - 30 + i ,color);
        i++;
    }
}
int key_hendler(int key, t_gameworld *world)
{
    int angle = world->map_info->pov;
    ft_view(world,world->tile_size, angle,0);
    if (key == key_forward)
        move_player(world, key_forward);
    else if (key == key_backward)
        move_player(world, key_backward);
    else if (key == key_left)
        move_player(world, key_left);
    else if (key == key_right)
        move_player(world, key_right);
    else if (key == MLX_KEY_Q)
        angle++;
        //rotate_player(world, -1);
    else if (key == MLX_KEY_E)
        angle--;
    //rotate_player(world, 1);
    else if (key == KEY_ESC)
        exit(0);
    ft_view(world,world->tile_size, angle,0x00ffff);
    return (0);
}


