#include "solong.h"

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
			state->img.addr[(y + j / ratio) *state->img.line_len
				/ 4 + (x + i / ratio)] = img.addr[j * img.line_len / 4 + i];
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
				state->img.addr[(y + (j / ratio)) *state->img.line_len / 4
					+ (x + (i / ratio))] = img.addr[j * img.line_len / 4 + i];
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
				state->img.addr[(y + j / ratio) *state->img.line_len
					/ 4 + (x + i / ratio)] = img.addr[j * img.line_len / 4 + i];
		}
	}
}

int	img_coord_adjusted(t_state *state, t_pos pos, int size, char mode)
{
	int	i;
	int	j;

	i = pos.x;
	j = pos.y;
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
				state->img.addr[(y + img_coord_adjusted(state, (t_pos){i, j},
							size, 'j') / ratio) *state->img.line_len / 4
					+ (x + img_coord_adjusted(state, (t_pos){i, j}, size, 'i')
						/ ratio)] = img.addr[j * img.line_len / 4 + i];
		}
	}
}
