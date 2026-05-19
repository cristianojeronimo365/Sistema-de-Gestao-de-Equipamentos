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
        printf("Limite de operacoes atingido.\n");
        return ;
    }

    nova.id = total_operacoes + 100;

    printf("Tipo Processo:\n");
    printf("0 - GARANTIA\n");
    printf("1 - REPARACAO\n");
    printf("2 - ABATIMENTO\n");
    printf("3 - TRANSFERENCIA\n");

	do{
    	scanf("%d", (int *)&nova.tipo_processo);
	}while(!(nova.tipo_processo >= 0 && nova.tipo_processo <= 3));

    if (!listar_componente())
	{
		printf("COMPONENTES PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("\nID componente: ");
    scanf("%d", &nova.id_componente);

    if (!listar_empresa())
	{
		printf("EMPRESAS PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("ID empresa: ");
    scanf("%d", &nova.id_empresa);

    if (!listar_posto())
	{
		printf("POSTOS PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("ID posto: ");
    scanf("%d", &nova.id_posto_trabalho);

    if (listar_funcionario())
	{
		printf("FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("ID funcionario: ");
    scanf("%d", &nova.id_funcionario);

    printf("Documento interno: ");
    scanf("%d",
            &nova.numero_documento_interno);

    printf("Documento externo: ");
    scanf("%d",
            &nova.numero_documento_externo);

    getchar();

    printf("Data saida: ");
    fgets(nova.data_saida,
            sizeof(nova.data_saida), stdin);

    nova.data_saida[
        strcspn(nova.data_saida, "\n")] = '\0';

    printf("Data prevista: ");
    fgets(nova.data_prevista,
            sizeof(nova.data_prevista), stdin);

    nova.data_prevista[
        strcspn(nova.data_prevista, "\n")] = '\0';

    printf("Montante: ");
    scanf("%lf", &nova.montante);

    getchar();

    printf("Observacao: ");
    fgets(nova.observacao,
            sizeof(nova.observacao), stdin);

    nova.observacao[
        strcspn(nova.observacao, "\n")] = '\0';

    nova.status = EM_ANDAMENTO;

    strcpy(nova.data_conclusao, "");

    operacoes[total_operacoes] = nova;

    total_operacoes++;

    salvarDados();

    printf("\nOperacao criada com sucesso.\n");
}

void listar_operacao(void)
{
    int i;

    if (total_operacoes == 0)
    {
        printf("\nNenhuma operacao cadastrada.\n");
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