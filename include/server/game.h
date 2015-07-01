/*
** game.h for game in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:12:11 2015 Antoine Plaskowski
** Last update Wed Jul  1 04:41:33 2015 Antoine Plaskowski
*/

#ifndef		GAME_H_
# define	GAME_H_

typedef	struct	s_team	t_team;
typedef	struct	s_game	t_game;

# include	<stddef.h>
# include	"player.h"
# include	"map.h"
# include	"opt.h"

struct		s_team
{
  size_t	connect;
  size_t	connect_max;
  size_t	len_team;
  char		*team;
};

struct		s_game
{
  size_t	size_team;
  t_team	*team;
  t_player	*player;
  t_map		map;
  t_opt		opt;
};

t_game		*init_game(t_game * const game, char **argv, int const argc);

#endif		/* !GAME_H_ */
