/*
** manage_select.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 18:38:07 2015 zwertv_e
** Last update Wed Jul  1 06:15:55 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"client.h"
#include	"manage_select.h"
#include	"fd_set.h"
#include	"int_handler.h"

static t_client	*read_client(fd_set const * const fd_read, t_client *client)
{
  t_client	*tmp;
  t_client	*tmp2;

  tmp = first_node(&client->node);
  while (tmp != NULL)
    {
      tmp2 = tmp->node.next;
      if (FD_ISSET(tmp->ca.cfd, fd_read))
	if (write_cbuf(&tmp->cbuf, tmp->ca.cfd) <= 0)
	  {
	    if (client->player != NULL)
	      client->player->client = NULL;
	    client = sup_node(&tmp->node);
	  }
      tmp = tmp2;
    }
  return (client);
}

static t_string	*write_to_write(t_string *to_write, int const cfd)
{
  to_write = first_node(&to_write->node);
  if (to_write == NULL)
    return (NULL);
  if (to_write->str != NULL)
    write(cfd, to_write->str, strlen(to_write->str));
  free(to_write->str);
  return (sup_node(&to_write->node));
}

static t_client	*write_client(fd_set const * const fd_write, t_client *client)
{
  t_client	*tmp;
  t_client	*tmp2;

  tmp = first_node(&client->node);
  while (tmp != NULL)
    {
      tmp2 = tmp->node.next;
      if (FD_ISSET(tmp->ca.cfd, fd_write))
	tmp->to_write = write_to_write(tmp->to_write, tmp->ca.cfd);
      tmp = tmp2;
    }
  return (client);
}

t_client	*manage_select(t_client *client, int const sfd)
{
  fd_set	fd_read;
  fd_set	fd_write;
  int		fd_max;

  fd_max = fd_set_client(&fd_read, &fd_write, client, sfd);
  if (pselect(fd_max + 1, &fd_read, &fd_write, NULL, NULL, NULL) == -1)
    {
      perror("select()");
      g_keep_running = false;
      return (client);
    }
  if (FD_ISSET(sfd, &fd_read) && (client = add_client(client, sfd)) == NULL)
    {
      g_keep_running = false;
      return (client);
    }
  return (write_client(&fd_write, read_client(&fd_read, client)));
}
