/*
** avance.c for avance in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 14:54:37 2015 Antoine Plaskowski
*/

#include	"game.h"
#include	"player.h"
#include	"avance.h"
#include	"message.h"

bool		avance(t_game *game, t_player *player, char *arg)
{
  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  move(&game->map, player);
  add_string(player->client, OK);
  return (false);
}
