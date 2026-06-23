#ifndef POSTOS_H
# define POSTOS_H

#include "globals.h"
#include "ficheiros.h"

void    adicionar_posto(void);
int     listar_posto(void);
void    pesquisar_posto(void);
void    actualizar_posto(void);
void    remover_posto(void);
t_posto_trabalhos   *buscarPostoPorId(int id);

#endif