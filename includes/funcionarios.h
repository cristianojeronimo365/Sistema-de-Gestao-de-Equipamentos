#ifndef FUNCIONARIOS_H
# define FUNCIONARIOS_H


#include "globals.h"
#include "ficheiros.h"

void    adicionar_funcionario(void);
int     listar_funcionario(void);
void    pesquisar_funcionario(void);
void    actualizar_funcionario(void);
void    remover_funcionario(void);
t_funcionarios    *buscarFuncionarioPorId(int id);

#endif