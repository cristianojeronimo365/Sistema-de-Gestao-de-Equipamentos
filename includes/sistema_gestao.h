
#ifndef SISTEMA_GESTAO_H

# define SISTEMA_GESTAO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

// definição de cores para o terminal
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

// =====================================================
// ENUMS
// =====================================================

typedef enum
{
    ELECTRONICO,
    MECANICO
} TipoComponente;

typedef enum
{
    NOVO,
    UTILIZADO
} TipoCondicao;

typedef enum
{
    FORNECEDOR,
    FABRICANTE,
    RECICLAGEM,
    AGENCIA
} TipoEmpresa;

// Tipo do processo/operação
typedef enum
{
    GARANTIA,
    REPARACAO,
    ABATIMENTO,
    TRANSFERENCIA
} TipoProcesso;

// Estado atual da operação
typedef enum
{
    PENDENTE,
    EM_ANDAMENTO,
    CONCLUIDO,
    CANCELADO
} StatusOperacao;


// =====================================================
// COMPONENTES
// =====================================================

typedef struct s_componentes
{
    int             id;
    char            designacao[50];
    char            numero_serie[30];

    char            data_aquisicao[11];
    char            data_garantia[11];

    int             id_fornecedor;
    int             id_fabricante;

    TipoComponente  tipo;
    TipoCondicao    condicao;

    int             id_posto_trabalho;

    char            observacao[100];

} t_componentes;


// =====================================================
// POSTOS DE TRABALHO
// =====================================================

typedef struct s_posto_trabalhos
{
    int     id;

    char    nome[50];
    char    local[50];
    char    seccao[50];

    char    descricao[100];

    int     id_funcionario;

} t_posto_trabalhos;


// =====================================================
// FUNCIONÁRIOS
// =====================================================

typedef struct s_funcionarios
{
    int     id;

    char    nome[50];
    char    funcao[50];

    char    descricao[100];

} t_funcionarios;


// =====================================================
// EMPRESAS
// =====================================================

typedef struct s_empresas
{
    int             id;

    char            nome[50];

    TipoEmpresa     tipo;

    char            contacto[20];

} t_empresas;


// =====================================================
// OPERAÇÕES / PROCESSOS
// =====================================================

typedef struct s_operacoes
{
    int                 id;

    int                 numero_documento_interno;
    int                 numero_documento_externo;

    int                 id_componente;
    int                 id_empresa;
    int                 id_posto_trabalho;
    int                 id_funcionario;

    TipoProcesso        tipo_processo;
    StatusOperacao      status;

    // quando o componente saiu
    char                data_saida[11];

    // previsão de retorno/conclusão
    char                data_prevista[11];

    // quando o processo foi concluído
    char                data_conclusao[11];

    double              montante;

    char                observacao[100];

} t_operacoes;


#endif