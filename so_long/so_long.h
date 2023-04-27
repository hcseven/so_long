/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:30:20 by hseven            #+#    #+#             */
/*   Updated: 2022/10/01 13:32:31 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11000
# endif

# define BG_FT "./img/background.xpm"
# define WL_FT "./img/wall.xpm"
# define CHDO_FT "./img/ch_down.xpm"
# define CHUP_FT "./img/ch_up.xpm"
# define CHRI_FT "./img/ch_right.xpm"
# define CHLE_FT "./img/ch_left.xpm"
# define CO_FT "./img/collectable.xpm"
# define DR_FT "./img/door.xpm"
# define DO_FT "./img/door_if_open.xpm"

# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data{
	char	**maptwo;
	char	*map;
	char	*vp_map;
	char	**vp_maptwo;
	char	**vp_fe_maptwo;
	int		coin;
	int		collect_coin;
	int		foot_step;
	int		fd;
	int		width;
	int		height;
	int		p_posx;
	int		p_posy;
	int		score;
	void	*adr;
	void	*pen;
	void	**img;
	int		imgx;
	int		imgy;
	int		s_posx;
	int		s_posy;
}	t_data;

void	free_all(t_data *data);
void	free_map(t_data *data);

int		check(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc_gnl(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t len);

char	*get_read(char *s, int fd);
char	*find_nl(char *str);
char	*get_next_line(int fd);
char	*last(char *str);

void	put_image(int y, int x, t_data *data);
void	add_image(t_data *data);
void	put_map(t_data *data);
void	put_background(t_data *data);
void	put_score(t_data *data);

int		split_array(char const*s, char c);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
int		ft_strchr(char	*str, char c);
int		wisp_strchr(char *str, char c);

int		map_length(char *s);
int		check_map(t_data *map);
void	read_map(int fd, t_data *map);
int		map_line(char *s, int mc_line, t_data *map);
int		map_name(char *s);

int		pec_check(t_data *data);
char	**validpath(char **str, int x, int y);
char	**validpath_for_exit(char **str, int y, int x);
int		validpath_x(char **str, int height, int width);
int		validpath_x_v2(char **str, int height, int width);

int		walk_up(t_data *data, int y, int x);
int		walk_down(t_data *data, int y, int x);
int		walk_right(t_data *data, int y, int x);
int		walk_left(t_data *data, int y, int x);
int		wisp(t_data *data);

int		key_control(int key, t_data	*data);
int		map_checker(t_data *data, char *s);
int		map_checker_two(t_data *data);
int		key_exit(t_data *data);

#endif
