/*
** player.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:20:46 2015 zwertv_e
** Last update Wed Jul  1 01:40:03 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<string.h>
#include	"player.h"

void		rotate_left(t_player * const player)
{
  if (player != NULL)
    {
      switch(player->dir)
	{
	case NORTH:
	  player->dir = WEST;
	  break;
	case SOUTH:
	  player->dir = EAST;
	  break;
	case WEST:
	  player->dir = SOUTH;
	  break;
	case EAST:
	  player->dir = NORTH;
	  break;
	};
    }
}

void		rotate_right(t_player * const player)
{
  if (player != NULL)
    {
      switch(player->dir)
	{
	case NORTH:
	  player->dir = EAST;
	  break;
	case SOUTH:
	  player->dir = WEST;
	  break;
	case WEST:
	  player->dir = NORTH;
	  break;
	case EAST:
	  player->dir = SOUTH;
	  break;
	};
    }
}

void		move(t_map const * const map, t_player * const player)
{
  if (player != NULL)
    {
      switch(player->dir)
	{
	case NORTH:
	  player->y = prev_y(map, player->y);
	  break;
	case SOUTH:
	  player->y = next_y(map, player->y);
	  break;
	case WEST:
	  player->x = prev_x(map, player->x);
	  break;
	case EAST:
	  player->x = next_x(map, player->x);
	  break;
	};
      printf("Player has moved in [%lu - %lu]\n", player->x, player->y);
    }
}

t_player		*init_player(t_map *map, char * const team,
				     size_t const x, size_t const y)
{
  t_player		*player;

  if (team == NULL)
    return (NULL);
  player->x = x;
  player->y = y;
  player->dir = NORTH;
  player->range = 1;
  player->client = NULL;
  player->action = NULL;
  init_inv(&player->inv);
  player->team = team;
  printf("New player at pos [%lu - %lu] in '%s' team\n", player->x, player->y, player->team);
  return (player);
}
