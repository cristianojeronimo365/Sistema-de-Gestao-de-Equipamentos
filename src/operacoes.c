#include "../includes/operacoes.h"
#include "../includes/sistema_gestao.h"
#include "../includes/componentes.h"
#include "../includes/empresas.h"
#include "../includes/postos.h"
#include "../includes/funcionarios.h"

static const char *obterTipoProcesso(
        TipoProcesso tipo)
{
    if (tipo == GARANTIA)
        return ("GARANTIA");

    else if (tipo == REPARACAO)
        return ("REPARACAO");

    else if (tipo == ABATIMENTO)
        return ("ABATIMENTO");

    return ("TRANSFERENCIA");
}

static const char *obterStatus(
        StatusOperacao status)
{
    if (status == PENDENTE)
        return ("PENDENTE");

    else if (status == EM_ANDAMENTO)
        return ("EM_ANDAMENTO");

    else if (status == CONCLUIDO)
        return ("CONCLUIDO");

    return ("CANCELADO");
}

void criar_operacao(void)
{
    t_operacoes nova;

    if (total_operacoes >= MAX_OPERACOES)
    {
        printf(RED "LIMITE DE OPERAÇÕES ATINGIDO.\n" RESET);
        return ;
    }

    nova.id = total_operacoes + 100;

    printf(GREEN "TIPO DO PROCESSO:\n" RESET);
    printf(YELLOW "0 - GARANTIA\n" RESET);
    printf(YELLOW "1 - REPARACAO\n" RESET);
    printf(YELLOW "2 - ABATIMENTO\n" RESET);
    printf(YELLOW "3 - TRANSFERENCIA\n" RESET);

	do{
    	scanf("%d", (int *)&nova.tipo_processo);
	}while(!(nova.tipo_processo >= 0 && nova.tipo_processo <= 3));
    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_componente())
	{
		printf(RED "COMPONENTES PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO COMPONENTE: " RESET);
    scanf("%d", &nova.id_componente);
    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_empresa())
	{
		printf(RED "EMPRESAS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "ID DA EMPRESA: " RESET);
    scanf("%d", &nova.id_empresa);
    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_posto())
	{
		printf(RED "POSTOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "ID DO POSTO: " RESET);
    scanf("%d", &nova.id_posto_trabalho);
    printf("------------------------------------------------------------------------------------------\n");
    if (listar_funcionario())
	{
		printf(RED "FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "ID DO FUNCIONÁRIO: " RESET);
    scanf("%d", &nova.id_funcionario);
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "Nº DE DOCUMENTO INTERNO: " RESET);
    scanf("%d",
            &nova.numero_documento_interno);
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "Nº DE DOCUMENTO EXTERNO: " RESET);
    scanf("%d",
            &nova.numero_documento_externo);

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "DATA DE SAÍDA: " RESET);
    fgets(nova.data_saida,
            sizeof(nova.data_saida), stdin);

    nova.data_saida[
        strcspn(nova.data_saida, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "DATA PREVISTA DE CHEGADA: " RESET);
    fgets(nova.data_prevista,
            sizeof(nova.data_prevista), stdin);

    nova.data_prevista[
        strcspn(nova.data_prevista, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "MONTANTE: " RESET);
    scanf("%lf", &nova.montante);

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "OBSERVAÇÃO: " RESET);
    fgets(nova.observacao,
            sizeof(nova.observacao), stdin);

    nova.observacao[
        strcspn(nova.observacao, "\n")] = '\0';

    nova.status = EM_ANDAMENTO;

    strcpy(nova.data_conclusao, "");

    operacoes[total_operacoes] = nova;

    total_operacoes++;
    printf("------------------------------------------------------------------------------------------\n");
    salvarDados();

    printf(GREEN "\nOPERAÇÃO CADASTRADA COM SUCESSO.\n" RESET);
}

void listar_operacao(void)
{
    int i;

    if (total_operacoes == 0)
    {
        printf(RED "\nNENHUMA OPERAÇÃO CADASTRADA.\n" RESET);
        return ;
    }

    i = 0;

    while (i < total_operacoes)
    {
        printf("\nID: %d\n",
                operacoes[i].id);

        printf("Tipo Processo: %s\n",
                obterTipoProcesso(
                    operacoes[i].tipo_processo));

        printf("Status: %s\n",
                obterStatus(
                    operacoes[i].status));

        printf("Componente: %d\n",
                operacoes[i].id_componente);

        printf("Empresa: %d\n",
                operacoes[i].id_empresa);

        printf("Funcionario: %d\n",
                operacoes[i].id_funcionario);

        printf("Data Saida: %s\n",
                operacoes[i].data_saida);

        printf("--------------------------\n");

        i++;
    }
}