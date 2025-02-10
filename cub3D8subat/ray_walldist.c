#include "cubthreed.h"

double	calc_perpdis(t_map *cub) // ışının duvara dik uzaklığı hesaplanır, hareket olmadan bir anda yollanan her ışının duvara dik uzaklığı
{
	if (cub->raycast->wall_hit_dir == 0 || cub->raycast->wall_hit_dir == 1) // çarpan duvarın yonu batı veya dogu ise
	{
		cub->raycast->perpend_dist = (cub->loc_px_index - cub->player->loc_x \
		+ (1 - cub->raycast->step_x) / 2) / cub->raycast->raydir_x; // 
		if (cub->raycast->perpend_dist <= 0.000001)
			cub->raycast->perpend_dist = 0.00001;
		return (cub->player->loc_y + cub->raycast->perpend_dist \
				* cub->raycast->raydir_y);
	}
	cub->raycast->perpend_dist = (cub->loc_py_index - cub->player->loc_y \
		+ (1 - cub->raycast->step_y) / 2) / cub->raycast->raydir_y;
	if (cub->raycast->perpend_dist <= 0.000001)
		cub->raycast->perpend_dist = 0.00001;
	return (cub->player->loc_x + cub->raycast->perpend_dist \
			* cub->raycast->raydir_x);
}

void	calc_wall(t_map *cub) // çizilecek duvarın uzunluk hesabı
{
	double	wall_x;
	wall_x = calc_perpdis(cub); // kesişim noktası koordinatı döndü
	wall_x -= floor(wall_x); // konumun tam kısmını çıkarıp kesirli kısmını tutuyor sadece
	cub->raycast->height = (SCREENHEIGHT / cub->raycast->perpend_dist); // ekran boyutuna dik uzaklığı bölerek duvar uzunluğunu aldı
	cub->raycast->tex_x = (int)(wall_x * (double)TILE); // ışının çizim yapacağı kısmın duvar dokusunun kaç pikseli olduğunu hesaplıyor
	if (cub->raycast->wall_hit_dir == 0 || cub->raycast->wall_hit_dir == 1)
		cub->raycast->tex_x = TILE - cub->raycast->tex_x - 1;
	else if (cub->raycast->wall_hit_dir == 2 || cub->raycast->wall_hit_dir == 3)
		cub->raycast->tex_x = TILE - cub->raycast->tex_x - 1;
	cub->raycast->start_y = -cub->raycast->height / 2 + SCREENHEIGHT / 2;
	if (cub->raycast->start_y < 0) // duvarın mapin ortasından yukarıya kdar olan uzunluğu ve alt uzunluğu hesaplanır
		cub->raycast->start_y = 0; // eğer bu değer ekrandan taşıyor ise 0 ve SCREENHEIGHT yapılır
	cub->raycast->end_y = cub->raycast->height / 2 + SCREENHEIGHT / 2;
	if (cub->raycast->end_y >= SCREENHEIGHT)
		cub->raycast->end_y = SCREENHEIGHT - 1;
}

void	map_liner(t_map *cub, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TILE / cub->raycast->height; // yukarıdan aşağı doğru çizimde her seferinde ne kadar çizileceğini hesaplar
	tex_pos = (cub->raycast->start_y - SCREENHEIGHT \
				/ 2 + cub->raycast->height / 2) * step; // duvarın üst kısmını başlangıç belirler
	i = cub->raycast->start_y;
	while (i <= cub->raycast->end_y)
	{
		tex_y = (int)tex_pos & 63; // burada textureda olan pozisyonu hesaplar 63 ile 0 arasında
		tex_pos += step;
		color = cub->walls[cub->raycast->wall_hit_dir]->addr[(TILE * tex_y) \
			+ cub->raycast->tex_x]; // gerekli duvarın çizilecek konumdaki rengini alır
		cub->mlx_data[i * SCREENWIDTH + x] = color; // ve bunu ekrana çizilecek yere koyar
		i++;
	}
}
