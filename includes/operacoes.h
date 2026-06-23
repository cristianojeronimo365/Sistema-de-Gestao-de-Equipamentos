#ifndef OPERACOES_H
# define OPERACOES_H

#include "globals.h"
#include "ficheiros.h"

void    criar_operacao(void);
int     listar_operacao(void);
void    atualizar_operacao(void);
void    pesquisar_operacao(void);
void    operacoes_pendentes(void);
void    operacoes_concluidas(void);

t_operacoes *buscarOperacaoPorId(int id);

#endif