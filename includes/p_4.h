/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_4.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:46:51 by kyazdani          #+#    #+#             */
/*   Updated: 2017/12/27 14:50:02 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_4_H
# define P_4_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include "../libft/includes/libft.h"

typedef struct	s_map
{
	char		**tab;
	char		c;
	int			x;
	int			y;
	int			xmax;
	int			ymax;
}				t_map;

char			**create_tab(int x, int y);
int				placer_piece(t_map *map, int x);
void			putmap(t_map map);
int				victory(t_map map);
int				horizontal(t_map map, int m, char c);
int				vertical(t_map map, int m, char c);
int				diagonal(t_map map, int m, char c);
int				adiagonal(t_map map, int m, char c);
int				play_u(t_map *map);
int				check(t_map *map, int force, char c);
int				p_easy(t_map *map);
int				p_med(t_map *map);
int				p_med2(t_map *map);
int				p_hard2(t_map *map);
int				strong_proximity(t_map *map, int x, int y);
int				weak_proximity(t_map *map, int x, int y);

#endif
