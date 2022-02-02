/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:11:48 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/02 18:52:18 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_image(t_mlx *mlx, char c, int j, int i)
{
	if (c == '1' && (i == 0 || i == mlx->height - 1))
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/wall.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
	else if (c == '1' && (j == 0 || j == mlx->width - 1))
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/wall.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
	else if (c == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/tree.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
	else if (c == '0')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/ground.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
	else if (c == 'C')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/collectibles.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
	else if (c == 'P')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/player.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
	else if (c == 'E')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/door_closed.xpm",
				&mlx->sprites.width, &mlx->sprites.height);
}

void	init_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			get_image(mlx, mlx->map[i][j], j, i);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
				j * 64, i * 64);
			mlx_destroy_image(mlx->ptr, mlx->img);
			j++;
		}
		i++;
	}
}

void	player_position(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->vector.x = j * 64;
				mlx->vector.y = i * 64;
			}
			j++;
		}
		i++;
	}
}

int	init_window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->width * 64, mlx->height * 64,
			"so_long");
	player_position(mlx);
	init_map(mlx);
	return (1);
}
