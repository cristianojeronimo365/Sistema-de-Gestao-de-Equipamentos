#include "../includes/componentes.h"
#include "../includes/sistema_gestao.h"
#include "../includes/empresas.h"
#include "../includes/postos.h"

static const char *obterTipoComponente(
        TipoComponente tipo)
{
    if (tipo == ELECTRONICO)
        return ("ELECTRONICO");

    return ("MECANICO");
}

static const char *obterCondicao(
        TipoCondicao condicao)
{
    if (condicao == NOVO)
        return ("NOVO");

    return ("UTILIZADO");
}

void adicionar_componente(void)
{
    t_componentes novo;

    if (total_componentes >= MAX_COMPONENTES)
    {
        printf(RED "LIMITE DE COMPONENTES ATINGIDO.\n" RESET);
        return ;
    }

    novo.id = total_componentes + 100;

    getchar();

    printf(GREEN "DESIGNAÇÃO DO COMPONENTE: " RESET);
    fgets(novo.designacao,
            sizeof(novo.designacao), stdin);

    novo.designacao[
        strcspn(novo.designacao, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "NÚMERO DE SÉRIE: " RESET);
    fgets(novo.numero_serie,
            sizeof(novo.numero_serie), stdin);

    novo.numero_serie[
        strcspn(novo.numero_serie, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "DATA DE AQUISIÇÃO: " RESET);
    fgets(novo.data_aquisicao,
            sizeof(novo.data_aquisicao), stdin);

    novo.data_aquisicao[
        strcspn(novo.data_aquisicao, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "DATA DE GARANTIA: " RESET);
    fgets(novo.data_garantia,
            sizeof(novo.data_garantia), stdin);

    novo.data_garantia[
        strcspn(novo.data_garantia, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "TIPO DO COMPONENTE:\n" RESET);
    printf(YELLOW "0 - ELECTRÓNICO\n" RESET);
    printf(YELLOW "1 - MECÂNICO\n" RESET);
	do {
    	scanf("%d", (int *)&novo.tipo);
	}while (novo.tipo != 0 && novo.tipo != 1);
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "CONDIÇÃO:\n" RESET);
    printf(YELLOW "0 - NOVO\n" RESET);
    printf(YELLOW "1 - UTILIZADO\n" RESET);
	do {
    	scanf("%d", (int *)&novo.condicao);
	}while (novo.condicao != 0 && novo.condicao != 1);

    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_empresa())
	{
		printf(RED "EMPRESAS PRECISAM SER CADASTRADOS...\n"RESET);
        return ;
	}

    printf(GREEN "\nID DO FORNACEDOR: " RESET);
    scanf("%d", &novo.id_fornecedor);

    printf(GREEN "ID DO FABRICANTE: " RESET);
    scanf("%d", &novo.id_fabricante);
    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_posto())
	{
		printf(RED "POSTOS PRECISAM SER CADASTRADOS...\n"RESET);
        return ;
	}

    printf(GREEN "ID DO POSTO: " RESET);
    scanf("%d", &novo.id_posto_trabalho);

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "OBSERVAÇÃO: " RESET);
    fgets(novo.observacao,
            sizeof(novo.observacao), stdin);

    novo.observacao[
        strcspn(novo.observacao, "\n")] = '\0';

    componentes[total_componentes] = novo;

    total_componentes++;
    printf("------------------------------------------------------------------------------------------\n");
    salvarDados();

    printf(GREEN "\nCOMPONENTE CADASTRADO COM SUCESSO.\n" RESET);
}

int listar_componente(void)
{
    int i;

    if (total_componentes == 0)
    {
        printf(RED "\nNENHUM COMPONENTE CADASTRADO.\n" RESET);
        return (0);
    }

    i = 0;
    printf(GREEN"\t\t\t------------------------------------------------------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |        DESIGNAÇÃO       |    NÚMERO DE SÉRIE      |       TIPO              |     CONDIÇÃO            | POSTO |\n" RESET);
    printf(GREEN"\t\t\t------------------------------------------------------------------------------------------------------------------------\n"RESET);
    while (i < total_componentes)
    {

        printf(GREEN "\t\t\t| " RESET);
        printf("%d", componentes[i].id);
        printf(GREEN "  | " RESET);

        format_printf(componentes[i].designacao);
        printf(GREEN " | " RESET);
        format_printf(componentes[i].numero_serie);
        printf(GREEN " | " RESET);
        format_printf((char *)obterTipoComponente(componentes[i].tipo));
        printf(GREEN " | " RESET);
        format_printf((char *)obterCondicao(componentes[i].condicao));
        printf(GREEN " |  " RESET);
        printf("%d", componentes[i].id_posto_trabalho);
        printf(GREEN "  |\n" RESET);
        printf(GREEN"\t\t\t------------------------------------------------------------------------------------------------------------------------\n"RESET);

        i++;
    }
	return (1);
}