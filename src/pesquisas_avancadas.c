#include "../includes/pesquisas_avancadas.h"
#include "../includes/componentes.h"
#include "../includes/empresas.h"
#include "../includes/funcionarios.h"
#include "../includes/postos.h"
#include "../includes/operacoes.h"
#include "../includes/sistema_gestao.h"

void componentes_posto(void)
{
    int id_posto;
    int i;
    int encontrou;

    encontrou = 0;

    listar_posto();

    printf("ID DO POSTO: ");
    scanf("%d", &id_posto);

    printf(YELLOW "\nCOMPONENTES DO POSTO: %s\n" RESET, buscarPostoPorId(id_posto)->nome);
    printf("------------------------------------------------------------------------------------------\n");
    i = 0;
    while (i < total_componentes)
    {
        if (componentes[i].id_posto_trabalho == id_posto)
        {
            printf(GREEN "- %s\n" RESET,
                    componentes[i].designacao);
            printf("------------------------------------------------------------------------------------------\n");
            encontrou = 1;
        }
        i++;
    }

    if (!encontrou)
        printf("NENHUM COMPONENTE ENCONTRADO.\n");
}

void componentes_garantia(void)
{
    int i;

    printf(YELLOW "\nCOMPONENTES EM GARANTIA\n" RESET);
    printf("------------------------------------------------------------------------------------------\n");
    i = 0;
    while (i < total_operacoes)
    {
        if (operacoes[i].tipo_processo == GARANTIA
            && operacoes[i].status != CONCLUIDO)
        {
            printf(GREEN "COMPONENTE: %s\n" RESET,
                buscarComponentePorId(
                    operacoes[i].id_componente)->designacao);

            printf(GREEN "EMPRESA: %s\n" RESET,
                buscarEmpresaPorId(
                    operacoes[i].id_empresa)->nome);

            printf("------------------------------------------------------------------------------------------\n");
        }
        i++;
    }
}

void componentes_atrasados(void)
{
    char hoje[11];

    printf("DATA ATUAL (AAAA-MM-DD): ");
    scanf("%10s", hoje);
    printf("------------------------------------------------------------------------------------------\n");
    int i = 0;

    while (i < total_operacoes)
    {
        if (operacoes[i].status != CONCLUIDO
            && strcmp(
                operacoes[i].data_prevista,
                hoje) < 0)
        {
            printf(GREEN "%s\n" RESET,
                buscarComponentePorId(
                    operacoes[i].id_componente)->designacao);
            printf("------------------------------------------------------------------------------------------\n");
        }
        i++;
    }
}

void empresas_utilizadas(void)
{
    int i;
    int j;
    int contador;

    printf(YELLOW "\nEMPRESAS MAIS UTILIZADAS\n" RESET);
    printf("------------------------------------------------------------------------------------------\n");
    i = 0;
    while (i < total_empresas)
    {
        contador = 0;

        j = 0;
        while (j < total_operacoes)
        {
            if (operacoes[j].id_empresa
                == empresas[i].id)
                contador++;

            j++;
        }

        printf(GREEN "%s -> %d Operações\n" RESET,
                empresas[i].nome,
                contador);
        printf("------------------------------------------------------------------------------------------\n");
        i++;
    }
}

void operacoes_empresa(void)
{
    int id_empresa;
    int i;

    listar_empresa();

    printf("\nID DA EMPRESA: ");
    scanf("%d", &id_empresa);
    printf("------------------------------------------------------------------------------------------\n");
    i = 0;

    while (i < total_operacoes)
    {
        if (operacoes[i].id_empresa
                == id_empresa)
        {
            printf(GREEN "OPERACAO %d\n" RESET,
                    operacoes[i].id);

            printf(GREEN "COMPONENTE: %s\n" RESET,
                buscarComponentePorId(
                    operacoes[i].id_componente)->designacao);

            printf("------------------------------------------------------------------------------------------\n");
        }

        i++;
    }
}

void operacoes_funcionario(void)
{
    int id_funcionario;
    int i;

    listar_funcionario();

    printf("ID DO FUNCIONARIO: ");
    scanf("%d", &id_funcionario);
    printf("------------------------------------------------------------------------------------------\n");
    i = 0;

    while (i < total_operacoes)
    {
        if (operacoes[i].id_funcionario
                == id_funcionario)
        {
            printf(GREEN "OPERACAO: %d\n" RESET,
                operacoes[i].id);

            printf(GREEN "PROCESSO: %s\n" RESET,
                obterTipoProcesso(
                    operacoes[i].tipo_processo));

            printf("------------------------------------------------------------------------------------------\n");
        }

        i++;
    }
}

