/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:43:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/10/17 04:11:26 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_color(char *str)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i])
    {
        if (str[i] == ',')
        {
            if (count == 0)
                j++;
            count = 0;
        }
        else if (!ft_isdigit(str[i]) || !(ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 255))
            return (ft_putstr_fd("\033[1;31mError\nCube3D :\033[0;0m Invalid color format\n", 2), 1);
        else if (ft_isdigit(str[i]) && ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 255)
            count++;
        if ((count > 3 && count > 0) && j > 2)
            return (ft_putstr_fd("\033[1;31mError\nCube3D :\033[0;0m Invalid color format\n", 2), 1);
        i++;
    }
    return (0);
}
