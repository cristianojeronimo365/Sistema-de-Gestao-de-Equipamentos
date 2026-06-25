#include "../includes/operacoes.h"
#include "../includes/sistema_gestao.h"
#include "../includes/componentes.h"
#include "../includes/empresas.h"
#include "../includes/postos.h"
#include "../includes/funcionarios.h"

char *obterTipoProcesso(
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

static char *obterStatus(
        StatusOperacao status)
{
    if (status == PENDENTE)
        return ("PENDENTE");

    else if (status == EM_ANDAMENTO)
        return ("EM_ANDAMENTO");

    else if (status == CONCLUIDO)
        return ("CONCLUIDO");
    else if (status == CANCELADO)
        return ("CANCELADO");
    return (NULL);
}

t_operacoes *buscarOperacaoPorId(int id)
{
    int i;

    i = 0;
    while (i < total_operacoes)
    {
        if (operacoes[i].id == id)
            return (&operacoes[i]);
        i++;
    }
    return (NULL);
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
    if (!listar_funcionario())
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
    //getchar();
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

int listar_operacao(void)
{
    int i;

    if (total_operacoes == 0)
    {
        printf(RED "\nNENHUMA OPERAÇÃO CADASTRADA.\n" RESET);
        return (0);
    }

    i = 0;
    printf(GREEN"\t\t\t---------------------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |          TIPO          |         ESTADO         |       COMPONENTE       |         EMPRESA        |       FUNCIONÁRIO      |      DATA DE SAÍDA      |\n" RESET);
    printf(GREEN"\t\t\t---------------------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);
    while (i < total_operacoes)
    {
        printf(GREEN "\t\t\t| " RESET);
        printf("%d", operacoes[i].id);
        printf(GREEN "  | " RESET);
        format_printf(obterTipoProcesso(
                    operacoes[i].tipo_processo));
        printf(GREEN "| " RESET);
        format_printf(obterStatus(
                    operacoes[i].status));
        printf(GREEN "| " RESET);
        format_printf(buscarComponentePorId(
                   operacoes[i].id_componente)->designacao);
        printf(GREEN "| " RESET);
        format_printf(buscarEmpresaPorId(
                   operacoes[i].id_empresa)->nome);
        printf(GREEN "| " RESET);
        format_printf(buscarFuncionarioPorId(
                   operacoes[i].id_funcionario)->nome);
        printf(GREEN "|  " RESET);
        format_printf(operacoes[i].data_saida);
        printf(GREEN "|\n" RESET);
        printf(GREEN"\t\t\t---------------------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);

        i++;
    }
    return (1);
}
void atualizar_operacao(void)
{
    int id;
    int opcao;
    t_operacoes *op;

    if (!listar_operacao())
	{
		printf(RED "OPERAÇÕES PRECISAM SER CADASTRADAS...\n" RESET);
        return ;
	}

    printf(GREEN "ID DA OPERAÇÃO: " RESET);
    scanf("%d", &id);

    op = buscarOperacaoPorId(id);

    if (!op)
    {
        printf(RED "OPERAÇÃO NÃO ENCONTRADA.\n" RESET);
        return ;
    }
    printf("\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "ACTUALIZAR STATUS DA OPERAÇÃO:\n" RESET);
    printf(YELLOW "0 - CONCLUIR OPERAÇÃO\n" RESET);
    printf(YELLOW "1 - CANCELAR OPERAÇÃO\n" RESET);
    do{
        printf(GREEN "ESCOLHA UMA ACÇÃO CORRESPONDENTE: " RESET);
        scanf("%d", &opcao);
    }while(!obterStatus(opcao));

    getchar();

    if (opcao == 0)
    {
        op->status = CONCLUIDO;
        printf("------------------------------------------------------------------------------------------\n");
        printf(GREEN "DATA DE CONCLUSÃO: " RESET);

        fgets(op->data_conclusao,
                sizeof(op->data_conclusao),
                stdin);

        op->data_conclusao[
            strcspn(op->data_conclusao, "\n")] = '\0';
    }

    else if (opcao == 1)
        op->status = CANCELADO;

    salvarDados();

    printf(GREEN "OPERAÇÃO ACTUALIZADA COM SUCESSO...\n" RESET);
}

void pesquisar_operacao(void)
{
    int id;
    t_operacoes *op;

    if (!listar_operacao())
	{
		printf(RED "OPERAÇÕES PRECISAM SER CADASTRADAS...\n" RESET);
        return ;
	}

    printf(GREEN "ID DA OPERACAO: " RESET);
    scanf("%d", &id);

    op = buscarOperacaoPorId(id);

    if (!op)
    {
        printf(RED "OPERAÇÃO NÃO ENCONTRADA.\n" RESET);
        return ;
    }

    system("clear");
    printf(YELLOW "\nDADOS DA OPERAÇÃO PESQUISADA\n" RESET);
    printf(GREEN "ID: " RESET "%d\n", op->id);

    printf(GREEN "TIPO DO PROCESSO: " RESET "%s\n",
            obterTipoProcesso(
                op->tipo_processo));

    printf(GREEN "STATUS: " RESET "%s\n",
            obterStatus(
                op->status));

    printf(GREEN "COMPONENTE: " RESET "%s\n",
        buscarComponentePorId(
            op->id_componente)->designacao);

    printf(GREEN "EMPRESA: " RESET "%s\n",
        buscarEmpresaPorId(
            op->id_empresa)->nome);

    printf(GREEN "FUNCIONARIO: " RESET "%s\n",
        buscarFuncionarioPorId(
            op->id_funcionario)->nome);

    printf(GREEN "POSTO DE TRABALHO: " RESET "%s\n",
        buscarPostoPorId(
            op->id_posto_trabalho)->nome);

    printf(GREEN "DATA DE SAIDA: " RESET "%s\n",
            op->data_saida);

    printf(GREEN "DATA PREVISTA DE CHEGADA: " RESET "%s\n",
            op->data_prevista);

    printf(GREEN "DATA DE CONCLUSÃO: " RESET "%s\n",
            op->data_conclusao);

    printf(GREEN "MONTANTE: " RESET "%.2lf\n",
            op->montante);

    printf(GREEN "OBSERVAÇÃO: " RESET "%s\n",
            op->observacao);
}

void operacoes_pendentes(void)
{
    int i;

    i = 0;
    printf(GREEN"\t\t\t--------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |          STATUS          |        COMPONENTE        |\n" RESET);
    printf(GREEN"\t\t\t--------------------------------------------------------------\n"RESET);
    while (i < total_operacoes)
    {
        if (operacoes[i].status == PENDENTE
            || operacoes[i].status == EM_ANDAMENTO)
        {
            printf(GREEN "\t\t\t| " RESET);
            printf("%d", operacoes[i].id);
            printf(GREEN "  | " RESET);
            format_printf(obterStatus(
                    operacoes[i].status));
            printf(GREEN "  | " RESET);
            format_printf(buscarComponentePorId(
                    operacoes[i].id_componente)->designacao);
            printf(GREEN "  |\n" RESET);
            printf(GREEN"\t\t\t--------------------------------------------------------------\n"RESET);
        }

        i++;
    }
}

void operacoes_concluidas(void)
{
    int i;

    i = 0;
    printf(GREEN"\t\t\t-----------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |      DATA DE CONCLUSÃO      |        COMPONENTE        |\n" RESET);
    printf(GREEN"\t\t\t-----------------------------------------------------------------\n"RESET);
    while (i < total_operacoes)
    {
        if (operacoes[i].status == CONCLUIDO)
        {
            printf(GREEN "\t\t\t| " RESET);
            printf("%d", operacoes[i].id);
            printf(GREEN "  |   " RESET);
            format_printf(operacoes[i].data_conclusao);
            printf(GREEN "   | " RESET);
            format_printf(buscarComponentePorId(
                    operacoes[i].id_componente)->designacao);
            printf(GREEN "  |\n" RESET);
             printf(GREEN"\t\t\t-----------------------------------------------------------------\n"RESET);
        }

        i++;
    }
}