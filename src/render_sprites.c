#include "solong.h"

int	img_period_adjusted(t_state *state, int i, int size)
{
	if (state->timer >= state->sprite_period / 2)
		return (size - i);
	return (i);
}

void	render_animated_sprite(t_state *state, t_img img, int x, int y)
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
				state->img.addr[(y + j / ratio) * state->img.line_len / 4 + (x + img_period_adjusted(state, i, size) / ratio)] = img.addr[j * img.line_len / 4 + i];
		}
	}
}