#ifndef EMPRESAS_H
# define EMPRESAS_H

#include "globals.h"
#include "ficheiros.h"

void    adicionar_empresa();
int     listar_empresa();
void    pesquisar_empresa();
void    actualizar_empresa();
void    remover_empresa();
t_empresas    *buscarEmpresaPorId(int id);

#endif
