#include "solong.h"

void	draw_meluch(t_state *state, t_img mel, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	size = ft_min(mel.height, mel.width);
	ratio = (size / state->square_size);
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			state->img.addr[(y + j / ratio)*state->img.line_len / 4 + (x + i / ratio)] = mel.addr[j * mel.line_len / 4 + i];
			//state->img.addr[(y + j / ratio)*state->img.line_len / 4 + (x + i / ratio)] = BLUE;
	}
}

void	render_square_pic(t_state *state, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	size = ft_min(img.height, img.width);
	ratio = (size / state->square_size);
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			state->img.addr[(y + j / ratio)*state->img.line_len / 4 + (x + i / ratio)] = img.addr[j * img.line_len / 4 + i];
	}
}

void	render_square_pic_evolved(t_state *state, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	size = ft_min(img.height, img.width);
	ratio = (size / state->square_size);
	j = size;
	while (--j >= 0)
	{
		i = -1;
		while (++i < size)
		{
			if (img.addr[j * img.line_len / 4 + i] > 0)
				state->img.addr[(y + (j / ratio)) * state->img.line_len / 4 + (x + (i / ratio))] = img.addr[j * img.line_len / 4 + i];
		}
	}
}

void	render_square_sprite(t_state *state, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	size = ft_min(img.height, img.width);
	ratio = (size / state->square_size);
	j = size;
	while (--j >= 0)
	{
		i = -1;
		while (++i < size)
		{
			if (img.addr[j * img.line_len / 4 + i] > 0)
				state->img.addr[(y + j / ratio) * state->img.line_len / 4 + (x + i / ratio)] = img.addr[j * img.line_len / 4 + i];
		}
	}
}


int	img_coord_adjusted(t_state *state, int i, int j, int size, char mode)
{
	if (mode == 'j')
	{
		if (state->player_dir == 'N')
			return (i);
		if (state->player_dir == 'S')
			return (size - i);
		return (j);
	}
	else if (mode == 'i')
	{
		if (state->player_dir == 'N')
			return (j);
		if (state->player_dir == 'S')
			return (size - j);
		if (state->player_dir == 'W')
			return (size - i);
		return (i);
	}
	return (0);
}

void	render_square_pic_rotation(t_state *state, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	ratio;
	int	size;

	size = ft_min(img.height, img.width);
	ratio = (size / state->square_size);
	j = size;
	while (--j >= 0)
	{
		i = -1;
		while (++i < size)
		{
			if (img.addr[j * img.line_len / 4 + i] > 0)
				state->img.addr[(y + img_coord_adjusted(state, i, j, size, 'j') / ratio) * state->img.line_len / 4 + (x + img_coord_adjusted(state, i, j, size, 'i') / ratio)] = img.addr[j * img.line_len / 4 + i];
		}
	}
}


void	draw_floor_map(t_state *state, t_img img)
{
	int x;
	int y;

	y = 0;
	(void)img;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			draw_square(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, RED);
			//render_square_pic(state, img, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN);
			x++;
		}
		y++;
	}
}

int adj(int pos, t_state *state)
{
	return (pos * state->square_size + MAP_MARGIN) ;
}

void	draw_map(t_state *state)
{
	int			x;
	int			y;
	t_img 		pic;

	//static int	color_arr[6] = {BLUE, RED, GREEN, VIOLET, WHITE, BLACK};
	t_img	img_arr[6] = {state->player, state->foe, state->collectible, state->exit, state->wall, state->praticable};
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
	state->img.mlx_img = mlx_new_image(state->mlx, state->win_width, state->win_height);
	state->img.addr = (int*)mlx_get_data_addr(state->img.mlx_img, &state->img.bpp, &state->img.line_len, &state->img.endian);
	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			render_square_pic_evolved(state, state->praticable, adj(x, state) ,adj(y ,state));
			pic = img_arr[ft_find_index(item, state->map[y][x])];
			if (state->map[y][x] == 'c')
				render_animated_sprite(state, pic, adj(x, state) ,adj(y ,state));
			else
				render_square_pic_evolved(state, pic, adj(x, state) ,adj(y ,state));
			x++;
		}
		y++;
	}
	render_square_pic_evolved(state, state->foe, adj(state->foe_coord.x, state) ,adj(state->foe_coord.y ,state));
	render_square_pic_rotation(state, state->player, adj(state->player_coord.x, state) ,adj(state->player_coord.y ,state));
	score_displayer(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
}

void	draw_map_end(t_state *state)
{
	int			x;
	int			y;
	t_img 		pic;

	//static int	color_arr[6] = {BLUE, RED, GREEN, VIOLET, WHITE, BLACK};
	t_img	img_arr[6] = {state->player, state->foe, state->collectible, state->exit, state->wall, state->praticable};
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
	state->img.mlx_img = mlx_new_image(state->mlx, state->win_width, state->win_height);
	state->img.addr = (int*)mlx_get_data_addr(state->img.mlx_img, &state->img.bpp, &state->img.line_len, &state->img.endian);
	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			render_square_pic_evolved(state, state->praticable, adj(x, state) ,adj(y ,state));
			pic = img_arr[ft_find_index(item, state->map[y][x])];
			if (state->map[y][x] == '1' || state->map[y][x] == 'e')
				render_square_pic_evolved(state, pic, adj(x, state) ,adj(y ,state));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
	//mlx_destroy_image(state->mlx, state->img.mlx_img);
}


void	draw_map_init(t_state *state)
{
	int			x;
	int			y;
	int 		color;
	static int	color_arr[6] = {BLUE, RED, GREEN, VIOLET, WHITE, BLACK};
	static char	item[6] = {'P', 'f', 'c', 'e', '1', 'x'};

	y = 0;
	while (state->map[y])
	{
		x = 0;
		while (state->map[y][x])
		{
			color = color_arr[ft_find_index(item, state->map[y][x])];
			if (state->map[y][x] != '1')
			{
				draw_square(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, color);
				draw_square_outline(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, BLACK);
			}
			else
			{
				draw_square(state, x * state->square_size + MAP_MARGIN, y * state->square_size + MAP_MARGIN, state->square_size, WHITE);	
			}
			x++;
		}
		y++;
	}
	draw_circle(state, (state->player_coord.x + 0.5) * state->square_size + MAP_MARGIN, (state->player_coord.y + 0.5) * state->square_size + MAP_MARGIN, state->square_size / 4, AZUR);
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img, 0, 0);
}