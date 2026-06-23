#ifndef COMPONENTES_H
# define COMPONENTES_H

#include "globals.h"
#include "ficheiros.h"

void    adicionar_componente(void);
int     listar_componente(void);
void    pesquisar_componente(void);
void    actualizar_componente(void);
void    remover_componente(void);
void    mover_componente(void);
t_componentes   *buscarComponentePorId(int id);

#endif