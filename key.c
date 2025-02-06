#include "cubthreed.h"

int key_pressed(int keycode, t_map *cub)
{
    if (keycode == 65307) // Escape tuşu
        exit_game(cub);
    if (keycode == 119)  // W tuşu
        cub->key->w = 1;
    if (keycode == 97)   // A tuşu
        cub->key->a = 1;
    if (keycode == 115)  // S tuşu
        cub->key->s = 1;
    if (keycode == 100)  // D tuşu
        cub->key->d = 1;
    if (keycode == 65361) // Sol ok tuşu
        cub->key->left = 1;
    if (keycode == 65363) // Sağ ok tuşu
        cub->key->right = 1;
    return (0);
}

int key_released(int keycode, t_map *cub)
{
    if (keycode == 119)  // W tuşu
        cub->key->w = 0;
    if (keycode == 97)   // A tuşu
        cub->key->a = 0;
    if (keycode == 115)  // S tuşu
        cub->key->s = 0;
    if (keycode == 100)  // D tuşu
        cub->key->d = 0;
    if (keycode == 65361) // Sol ok tuşu
        cub->key->left = 0;
    if (keycode == 65363) // Sağ ok tuşu
        cub->key->right = 0;
    return (0);
}


