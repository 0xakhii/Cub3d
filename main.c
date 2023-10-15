/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:23:38 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/15 02:43:19 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (!ft_strcmp(&str[i], ".cub"))
				return (0);
			else
			{
				ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid map name\n",
					2);
				return (1);
			}
		}
		else if (!str[i + 1])
			return (ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid map name\n",
				2), 1);
		i++;
	}
	return (0);
}

t_map	*read_map(int fd, t_map *map)
{
	if (fd == -1)
	{
		ft_putstr_fd("\033[1;31mCube3D:\033[0;0m Invalid file", 2);
		return (NULL);
	}
	map->get_line = NULL;
	map->line = NULL;
	map->get_line = get_next_line(fd);
	if (!map->get_line)
	{
		ft_putendl_fd("\033[1;31mCube3D:\033[0;0m Invalid file", 2);
		return (NULL);
	}
	while (map->get_line)
	{
		map->line = ft_strjoin(map->line, map->get_line);
		free(map->get_line);
		map->get_line = get_next_line(fd);
	}
	free(map->get_line);
	map->map = ft_split(map->line, '\n');
	free(map->line);
	return (map);
}

void	free_map(t_map **map)
{
	free((*map)->n_path);
	free((*map)->e_path);
	free((*map)->w_path);
	free((*map)->s_path);
	free((*map)->f_color);
	free((*map)->c_color);
	free_str((*map)->map_clone);
	free(*map);
}

void	map_init(t_map *map)
{
	map->c_color = NULL;
	map->f_color = NULL;
	map->e_path = NULL;
	map->w_path = NULL;
	map->s_path = NULL;
	map->n_path = NULL;
}

int	main(int ac, char **av)
{
	t_map *map;

	if (ac == 2)
	{
		if (check_filename(av[1]))
			return (1);
		else
		{
			map = malloc(sizeof(t_map));
			map = read_map(open(av[1], O_RDONLY, 0666), map);
			map_init(map);
			map_fill(map->map, map);
			if (map_check(map))
			{
				free_map(&map);
				return (1);
			}
			printf("\033[1;32mCube3D:\033[0;0m Map is valid\n");
			// map_printing(map);
		}
		free_map(&map);
	}
	else
		ft_putstr_fd("\033[1;31mCube3D:\033[0;0m ./cub3d <map_path>\n", 2);
	return (0);
}
