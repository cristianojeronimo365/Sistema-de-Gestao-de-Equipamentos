#ifndef EMPRESAS_H
# define EMPRESAS_H

#include "globals.h"
#include "ficheiros.h"

void    adicionar_empresa();
int listar_empresa(void);
char *buscarEmpresaPorId(int id);

#endif
