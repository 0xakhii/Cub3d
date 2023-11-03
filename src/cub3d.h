#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include<stdbool.h>
# include <ctype.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"


// # define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2
# define DEG_TO_RAD(degrees) ((degrees) * M_PI / 180.0)
# define ROTATION_SPEED DEG_TO_RAD(5.0)
# define M_PI 3.14159265358979323846
# define player_size 10
# define SCREEN_WIDTH 1152
# define SCREEN_HEIGHT 512
# define PLAYER_SPEED 0.1
# define MLX_KEY_W 119
# define MLX_KEY_S 115
# define MLX_KEY_A 97
# define MLX_KEY_D 100
# define KEY_ESC 9
# define SQUARE_SIZE 30
# define MLX_KEY_Q 101
# define MLX_KEY_E 104

typedef enum e_keys {
    key_forward = MLX_KEY_W,
    key_backward = MLX_KEY_S,
    key_left = MLX_KEY_A,
    key_right = MLX_KEY_D,
}   t_keys;

typedef struct s_color
{
	int		flag;
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_map
{
	char	*line;
	char	*get_line;
	char	**map;
	char	**map_clone;
	char	*n_path;
	char	*e_path;
	char	*w_path;
	char	*s_path;
	char	*f_color;
	char	*c_color;
	int		pov;
	int		player;
	int		max_line;
	int		map_len;
	int		player_x;
	int		player_y;
	t_color	floor;
	t_color	celling;
}	t_map;



typedef struct s_point2D
{
    double	x;
    double	y;
}	t_point2D;

typedef struct s_gridpoint
{
    int	row;
    int	col;
}	t_gridpoint;

typedef struct s_character
{
    t_point2D	location;
    t_point2D	direction;
	t_point2D	viewslice;
}	t_character;

typedef struct s_gameworld
{
	double      	player_fov;
    double      	ray_gap;
    int        		max_ray_distance;
	int				tile_size;
	t_map			*map_info;
	char			**map;		
    t_character		player;
	void			*mlx;
	void			*window;
	void		 	*mlximage;
    t_map			info;
    uint32_t		colors[2];
}	t_gameworld;


int 	is_walkable_tile(t_gameworld *world, int x, int y);
void	map_fill(char **str, t_map *map);
int		check_for_textures(t_map *map);
int		map_check(t_map *map);
void	map_printing(t_map *map);
void	get_map(char **str, t_map *map);
void	free_str(char **str);
int 	check_colors(char *color, t_color *rgb);
int 	calculatetilesize(char **map);
int 	key_hendler(int key, t_gameworld *world);
void	draw_square(t_gameworld *world, int x_start, int y_start, int size, int color);
int 	pixel_to_grid(int pixel_coordinate, int tile_size);

#endif