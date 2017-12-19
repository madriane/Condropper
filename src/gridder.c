/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:58:55 by kyazdani          #+#    #+#             */
/*   Updated: 2017/12/17 23:42:15 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_4.h"

void	putmap(t_map map)
{
	int	t[2];

	ft_putstr("\t");
	t[0] = 0;
	while (++(t[0]) <= (map.xmax + 1))
	{
		ft_putnbr(t[0]);
		ft_putchar('\t');
	}
	t[1] = -1;
	while (++(t[1]) <= map.ymax)
	{
		ft_putstr("\n    |\t");
		t[0] = -1;
		while (++(t[0]) <= map.xmax)
		{
			if (map.tab[t[1]][t[0]] == 'O')
				ft_putstr("\033[1m\033[36mO\033[0m   |\t");
			else if (map.tab[t[1]][t[0]] == 'X')
				ft_putstr("\033[1m\033[31mX\033[0m   |\t");
			else
				ft_putstr(".   |\t");
		}
		ft_putchar('\t');
	}
}

int		placer_piece(t_map *map, int x)
{
	int		y;

	y = 0;
	if (x < 0 || x > map->xmax || map->tab[y][x] != '.')
		return (-1);
	while (map->tab[y + 1] && map->tab[y + 1][x] == '.')
		y++;
	map->tab[y][x] = map->c;
	map->x = x;
	map->y = y;
	return (y);
}

char	**create_tab(int xmax, int ymax)
{
	int		x;
	int		y;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (ymax + 1))))
		return (NULL);
	y = 0;
	while (y < ymax)
	{
		x = 0;
		if (!(tab[y] = ft_strnew(xmax + 1)))
			return (NULL);
		while (x < xmax)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}
