
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_gstrlen(const char *str);
int		finder(const char *str);
char	*strjoin(char *line, char *bf);
char	*getbefore(char *str);
char	*getafter(char *str);
#endif