// =====================================================
// ficheiro: globals.h
// =====================================================

#ifndef GLOBALS_H
# define GLOBALS_H

# include "sistema_gestao.h"

// arrays globais
extern t_empresas          empresas[MAX_EMPRESAS];
extern t_funcionarios      funcionarios[MAX_FUNCIONARIOS];
extern t_posto_trabalhos   postos[MAX_POSTOS];
extern t_componentes       componentes[MAX_COMPONENTES];
extern t_operacoes         operacoes[MAX_OPERACOES];

// contadores
extern int total_empresas;
extern int total_funcionarios;
extern int total_postos;
extern int total_componentes;
extern int total_operacoes;

#endif