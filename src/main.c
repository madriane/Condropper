/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:51:41 by kyazdani          #+#    #+#             */
/*   Updated: 2017/12/19 20:33:08 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_4.h"

static int		error(int x)
{
	ft_putstr("usage : ./puissance_4 {ligne} {colonne} : line > 6, col > 7\n");
	if (!x)
		ft_putstr("\033[31mVeuillez entrer une valeur !\033[0m\n");
	else if (x == 1)
		ft_putstr("\033[31mLe nombre de lignes est incorrect !\033[0m\n");
	else if (x == 2)
		ft_putstr("\033[31mLe nombre de colonnes est incorrect !\033[0m\n");
	exit(0);
}

static t_map	start(int ac, char **av)
{
	t_map	map;

	srand((unsigned)time(NULL));
	if (ac < 3)
		error(0);
	if ((map.ymax = ft_atoi(av[1])) < 6 || map.ymax > 40)
		error(1);
	if ((map.xmax = ft_atoi(av[2])) < 7 || map.xmax > 40)
		error(2);
	map.tab = create_tab(map.xmax, map.ymax);
	map.x = 0;
	map.xmax--;
	map.y = 0;
	map.ymax--;
	map.c = ((rand() % 2) ? 'X' : 'O');
	return (map);
}

int				play_u(t_map *map)
{
	int		x;
	char	*buf;

	if (!(buf = ft_strnew(1)))
		return (-1);
	ft_putstr("Choisissez une colonne entre 1 et ");
	ft_putnbr(map->xmax + 1);
	ft_putchar('\n');
	if (read(0, buf, 5) < 0)
		return (-1);
	x = ft_atoi(buf) - 1;
	while ((placer_piece(map, x)) < 0)
	{
		ft_putstr("Mauvaise colonne !\n");
		if (read(0, buf, 5) < 0)
			return (-1);
		x = ft_atoi(buf) - 1;
	}
	ft_strdel(&buf);
	return (1);
}

static int		replay(t_map map, int (*play_ai)(t_map *))
{
	while (!(victory(map)))
	{
		if (map.c == 'O')
		{
			map.c = 'X';
			if (!play_u(&map))
				return (0);
		}
		else
		{
			map.c = 'O';
			play_ai(&map);
			ft_putstr("The AI played in the column number ");
			ft_putnbr(map.x + 1);
			ft_putchar('\n');
		}
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_map		map;
	char		buff[2];

	map = start(ac, av);
	while (!buff[0] || buff[0] > '3')
	{
		ft_putstr("Choose your destiny !\n1:easy\t\t2:medium\t3:hard\n");
		if (!read(0, buff, 2))
			return (1);
		if (buff[0] == '1')
			replay(map, p_easy);
		else if (buff[0] == '2')
			replay(map, p_med);
		else if (buff[0] == '3')
			replay(map, p_hard2);
		else
			ft_putstr("This difficulty does not exist. Try again please! ^^\n");
	}
	return (0);
}
