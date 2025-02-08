
#include "cubthreed.h"

int ft_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

char *ft_whitetrim(char const *s)
{
    size_t start = 0;
    size_t end;
    size_t len;

    if (!s)
        return (NULL);
    while (s[start] && ft_whitespace(s[start]))
        start++;
    end = ft_strlen(s);
    while (end > start && ft_whitespace(s[end - 1]))
        end--;
    len = end - start;
    return (ft_substr(s, start, len));
}

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
void char_check(t_map *cub)
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
            if (is_invalid_char(cub->map_line[i][j]) && (cub->map_line[i][j] > 32 && cub->map_line[i][j] <= 126))
            {
                ft_error("Invalid character on the map file!");
                cub_free(cub);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void    map_control(t_map *cub)
{
    char_check(cub);
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
    control_sep(cub);
    check_x(cub);
    control_wall(cub);
}

