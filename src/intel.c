/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 23:06:56 by kyazdani          #+#    #+#             */
/*   Updated: 2017/12/17 22:09:29 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_4.h"

int		strong_proximity(t_map *map, int y, int x)
{
	if (y < map->xmax && map->tab[y + 1][x] == map->c
			&& y > 0 && map->tab[y - 1][x] == map->c)
		return (1);
	if (x < map->xmax && y < map->ymax && map->tab[y + 1][x + 1] == map->c
			&& x > 0 && y > 0 && map->tab[y - 1][x - 1] == map->c)
		return (1);
	if (y < map->ymax && x > 0 && map->tab[y + 1][x - 1] == map->c
			&& y > 0 && x < map->xmax && map->tab[y - 1][x + 1] == map->c)
		return (1);
	if (x < map->xmax && map->tab[y][x + 1] == map->c
			&& x > 0 && map->tab[y][x - 1] == map->c)
		return (1);
	return (0);
}

int		weak_proximity(t_map *map, int y, int x)
{
	if (x < map->xmax && map->tab[y + 1][x] == map->c)
		return (1);
	if (x > 0 && map->tab[y - 1][x] == map->c)
		return (1);
	if (y < map->ymax && x < map->xmax && map->tab[y + 1][x + 1] == map->c)
		return (1);
	if (y > 0 && x > 0 && map->tab[y - 1][x - 1] == map->c)
		return (1);
	if (y < map->ymax && x > 0 && map->tab[y + 1][x - 1] == map->c)
		return (1);
	if (y > 0 && x < map->xmax && map->tab[y - 1][x + 1] == map->c)
		return (1);
	if (x < map->xmax && map->tab[y][x + 1] == map->c)
		return (1);
	if (x > 0 && map->tab[y][x - 1] == map->c)
		return (1);
	return (0);
}
