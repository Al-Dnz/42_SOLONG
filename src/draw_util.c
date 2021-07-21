#include "solong.h"

void	draw_pix(t_img *img, int x, int y, int color)
{
	img->addr[y * img->line_len / 4 + x] = color;
}
