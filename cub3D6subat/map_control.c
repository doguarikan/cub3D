
#include "cubthreed.h"
/*
int ft_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

int seperate_char(int i, int j, t_map *cub)
{
    if (ft_whitespace(cub->map_line[i][j]))
    {
        while(cub->map_line[i][j])
        {
            while(!is_invalid_char(cub->map_line[i][j]) && cub->map_line[i][j] != "\n")
            {

            }
            j++;
        }
        if (i == 0 || !cub->map_line[i - 1] || ft_whitespace(cub->map_line[i - 1][j]))
            return 1;
        if (!cub->map_line[i + 1] || ft_whitespace(cub->map_line[i + 1][j]))
            return 1;
        if (j == 0 || ft_whitespace(cub->map_line[i][j - 1]))
            return 1;
        if (!cub->map_line[i][j + 1] || ft_whitespace(cub->map_line[i][j + 1]))
            return 1;
    }
    return 0;
}
*/

int is_invalid_char(char c)
{
    return (!(c == '0' || c == '1' || c == 'N' || c == 'W' || c == 'S' || c == 'E'));
}


int map_control_2(int i, int j, t_map *cub)
{
    if (cub->map_line[i][j] == '0')
    {
        if (i == 0 || !cub->map_line[i - 1] || is_invalid_char(cub->map_line[i - 1][j]))
            return 1;
        if (!cub->map_line[i + 1] || is_invalid_char(cub->map_line[i + 1][j]))
            return 1;
        if (j == 0 || is_invalid_char(cub->map_line[i][j - 1]))
            return 1;
        if (!cub->map_line[i][j + 1] || is_invalid_char(cub->map_line[i][j + 1]))
            return 1;
    }
    return 0;
}

void    map_control(t_map *cub)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (cub->map_line[i])
    {
        j = 0;
        while (cub->map_line[i][j])
        {
            if (map_control_2 (i, j, cub))
            {
                    ft_error("Map is not valid");
                    cub_free(cub);
                    exit (1);
            }     
            j++;
        }
        i++; 
    }

    control_wall(cub);  
}

