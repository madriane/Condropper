/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 23:06:56 by kyazdani          #+#    #+#             */
/*   Updated: 2017/12/19 20:27:26 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_4.h"

int	p_easy(t_map *map)
{
	int		x;
	int		y;
	char	c;

	c = (map->c == 'O' ? 'X' : 'O');
	if (check(map, 4, map->c) || check(map, 4, c) || check(map, 3, map->c) ||
			check(map, 3, c) || check(map, 2, map->c) || check(map, 2, c))
		return (1);
	srand((unsigned)time(NULL));
	x = rand() % (map->xmax + 1);
	while ((y = placer_piece(map, x)) < 0)
		x = rand() % (map->xmax - 1);
	return (y);
}

int	check(t_map *map, int force, char c)
{
	int		x;
	int		y;

	x = 0;
	while (x < map->xmax)
	{
		y = 0;
		while (map->tab[y + 1] && map->tab[y + 1][x] == '.')
			y++;
		map->x = x;
		map->y = y;
		if (horizontal(*map, force, c) || diagonal(*map, force, c) ||
				vertical(*map, force, c) || adiagonal(*map, force, c))
			if ((placer_piece(map, x)) >= 0)
				return (1);
		x++;
	}
	return (0);
}

int	p_hard2(t_map *map)
{
	int		x;
	int		y;
	char	c;

	c = (map->c == 'O' ? 'X' : 'O');
	x = 0;
	while (x < map->xmax)
	{
		y = 0;
		while (map->tab[y + 1] && map->tab[y + 1][x] == '.')
			y++;
		map->x = x;
		map->y = y;
		if (horizontal(*map, 3, c) || diagonal(*map, 3, c) ||
				vertical(*map, 3, c) || adiagonal(*map, 3, c))
			if ((placer_piece(map, x)) >= 0)
				return (1);
		x++;
	}
	return (p_hard2(map));
}

int	p_med(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (x < map->xmax)
	{
		y = 0;
		while (map->tab[y + 1] && map->tab[y + 1][x] == '.')
			y++;
		map->x = x;
		map->y = y;
		if (horizontal(*map, 2, map->c) || diagonal(*map, 2, map->c) ||
				vertical(*map, 2, map->c) || adiagonal(*map, 2, map->c))
			if ((placer_piece(map, x)) >= 0)
				return (1);
		x++;
	}
	return (p_easy(map));
}

int	p_med2(t_map *map)
{
	int		x;
	int		y;
	char	c;

	c = (map->c == 'O' ? 'X' : 'O');
	x = 0;
	while (x < map->xmax)
	{
		y = 0;
		while (map->tab[y + 1] && map->tab[y + 1][x] == '.')
			y++;
		map->x = x;
		map->y = y;
		if (horizontal(*map, 2, c) || diagonal(*map, 2, c) ||
				vertical(*map, 2, c) || adiagonal(*map, 2, c))
			if ((placer_piece(map, x)) >= 0)
				return (1);
		x++;
	}
	return (p_med(map));
}
