/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:51:03 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/17 23:09:44 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_4.h"

int		horizontal(t_map map, int m, char c)
{
	int	x;
	int	k;

	k = 1;
	x = map.x;
	while (x < map.xmax && map.tab[map.y][x + 1] == c)
	{
		x++;
		k++;
	}
	x = map.x;
	while (x > 0 && map.tab[map.y][x - 1] == c)
	{
		x--;
		k++;
	}
	return (k >= m ? 1 : 0);
}

int		vertical(t_map map, int m, char c)
{
	int	k;
	int	y;

	k = 1;
	y = map.y;
	while (y < map.ymax && map.tab[y + 1][map.x] == c)
	{
		y++;
		k++;
	}
	y = map.y;
	while (y > 0 && map.tab[y - 1][map.x] == c)
	{
		y--;
		k++;
	}
	return (k >= m ? 1 : 0);
}

int		diagonal(t_map map, int m, char c)
{
	int	k;
	int	x;
	int	y;

	k = 1;
	x = map.x;
	y = map.y;
	while (y < map.ymax && x > 0 && map.tab[y + 1][x - 1] == c)
	{
		y++;
		x--;
		k++;
	}
	x = map.x;
	y = map.y;
	while (y > 0 && x < map.xmax && map.tab[y - 1][x + 1] == c)
	{
		y--;
		x++;
		k++;
	}
	return (k >= m ? 1 : 0);
}

int		adiagonal(t_map map, int m, char c)
{
	int	k;
	int	x;
	int	y;

	k = 1;
	x = map.x;
	y = map.y;
	while (x < map.xmax && y < map.ymax
			&& map.tab[y + 1][x + 1] == c)
	{
		x++;
		y++;
		k++;
	}
	x = map.x;
	y = map.y;
	while (y > 0 && x > 0 && map.tab[y - 1][x - 1] == c)
	{
		y--;
		x--;
		k++;
	}
	return (k >= m ? 1 : 0);
}

int		victory(t_map map)
{
	int	x;

	putmap(map);
	if (horizontal(map, 4, map.c) || diagonal(map, 4, map.c)
			|| vertical(map, 4, map.c) || adiagonal(map, 4, map.c))
	{
		if (map.c == 'X')
			ft_putstr("You won the game!\nWell played!\n'");
		else
			ft_putstr("You have been defeated!\nGAME OVER!\n'");
		return (1);
	}
	x = 0;
	while (x <= map.xmax && map.tab[0][x] != '.')
		x++;
	if (x - 1 == map.xmax)
	{
		ft_putstr("The grid is full!\nGAME OVER!!!");
		return (1);
	}
	return (0);
}
