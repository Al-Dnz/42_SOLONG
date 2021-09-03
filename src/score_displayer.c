#include "solong.h"

void	update_str_score(t_state *state)
{
	ft_strclr(&state->str_score);
	state->str_score = ft_itoa(state->score);
}

void	set_number_img(t_state *state)
{
	static char	*numbers_txt_arr[10] = {"./numbers_txt/0.xpm",
	"./numbers_txt/1.xpm", "./numbers_txt/2.xpm", "./numbers_txt/3.xpm",
	"./numbers_txt/4.xpm", "./numbers_txt/5.xpm", "./numbers_txt/6.xpm",
	"./numbers_txt/7.xpm", "./numbers_txt/8.xpm", "./numbers_txt/9.xpm"};
	int			i;

	i = 0;
	while (i < 10)
	{
		(state->number_img[i]).mlx_img = mlx_xpm_file_to_image(state->mlx,
				numbers_txt_arr[i], &(state->number_img[i].width),
				&(state->number_img[i].height));
		(state->number_img[i]).addr = (int *)mlx_get_data_addr(
				state->number_img[i].mlx_img,
				&(state->number_img[i].bpp), &(state->number_img[i].line_len),
				&(state->number_img[i].endian));
		i++;
	}
}

void	score_displayer(t_state *state)
{
	t_img	img;
	int		i;
	int		img_index;

	i = 0;
	while (state->str_score[i])
	{
		img_index = state->str_score[i] - 48;
		img = state->number_img[img_index];
		render_square_pic_evolved(state, img, adj(i, state), adj(0, state));
		i++;
	}
}
