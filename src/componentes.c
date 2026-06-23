#include "../includes/componentes.h"
#include "../includes/sistema_gestao.h"
#include "../includes/empresas.h"
#include "../includes/postos.h"
#include "../includes/funcionarios.h"

static char *obterTipoComponente(
        TipoComponente tipo)
{
    if (tipo == ELECTRONICO)
        return ("ELECTRONICO");

    return ("MECANICO");
}

static char *obterCondicao(
        TipoCondicao condicao)
{
    if (condicao == NOVO)
        return ("NOVO");

    return ("UTILIZADO");
}

static int componenteEstaEmUso(int id_componente)
{
    int i;

    i = 0;
    while (i < total_operacoes)
    {
        if (operacoes[i].id_componente == id_componente)
            return (1);

        i++;
    }

    return (0);
}

t_componentes *buscarComponentePorId(int id)
{
    int i;

    i = 0;
    while (i < total_componentes)
    {
        if (componentes[i].id == id)
            return (&componentes[i]);
        i++;
    }
    return (NULL);
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
    printf(GREEN"\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |        DESIGNAÇÃO       |    NÚMERO DE SÉRIE      |       TIPO              |     CONDIÇÃO            |           POSTO           |\n" RESET);
    printf(GREEN"\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);
    while (i < total_componentes)
    {

        printf(GREEN "\t\t\t| " RESET);
        printf("%d", componentes[i].id);
        printf(GREEN "  | " RESET);

        format_printf(componentes[i].designacao);
        printf(GREEN " | " RESET);
        format_printf(componentes[i].numero_serie);
        printf(GREEN " | " RESET);
        format_printf(obterTipoComponente(componentes[i].tipo));
        printf(GREEN " | " RESET);
        format_printf(obterCondicao(componentes[i].condicao));
        printf(GREEN " |  " RESET);
        format_printf(buscarPostoPorId(componentes[i].id_posto_trabalho)->nome);
        printf(GREEN "  |\n" RESET);
        printf(GREEN"\t\t\t--------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);

        i++;
    }
	return (1);
}

void pesquisar_componente(void)
{
    int id;
    t_componentes *componente;

    if (!listar_componente())
	{
		printf(RED "COMPONENTES DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO COMPONENTE: " RESET);
    scanf("%d", &id);

    componente = buscarComponentePorId(id);

    if (!componente)
    {
        printf(RED "\nCOMPONENTE NÃO ENCONTRADO.\n" RESET);
        return ;
    }
    system("clear");
    printf(YELLOW "\nDADOS DO COMPONENTE PESQUISADO\n" RESET);

    printf(GREEN "ID: " RESET "%d\n", componente->id);
    printf(GREEN "DESIGNAÇÃO: " RESET "%s\n", componente->designacao);
    printf(GREEN "NÚMERO DE SÉRIE: " RESET "%s\n", componente->numero_serie);
    printf(GREEN "DATA DE AQUISIÇÃO: " RESET "%s\n", componente->data_aquisicao);
    printf(GREEN "DATA DE GARANTIA: " RESET "%s\n", componente->data_garantia);
    printf(GREEN "FORNECEDOR: " RESET "%s\n", buscarFuncionarioPorId(componente->id_fornecedor)->nome);
    printf(GREEN "FABRICANTE: " RESET "%s\n", buscarFuncionarioPorId(componente->id_fabricante)->nome);
    printf(GREEN "POSTO DE TRABALHO: " RESET "%s\n", buscarPostoPorId(componente->id_posto_trabalho)->nome);
    printf(GREEN "OBSERVAÇÃO: " RESET "%s\n", componente->observacao);
}

void actualizar_componente(void)
{
    int id;
    t_componentes *componente;

    if (!listar_componente())
	{
		printf(RED "COMPONENTES DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO COMPONENTE: " RESET);
    scanf("%d", &id);

    componente = buscarComponentePorId(id);

    if (!componente)
    {
        printf(RED "\nCOMPONENTE NÃO ENCONTRADO.\n" RESET);
        return ;
    }

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "\nNOVA DESIGNAÇÃO: " RESET);
    fgets(componente->designacao,
        sizeof(componente->designacao),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    componente->designacao[
        strcspn(componente->designacao, "\n")] = '\0';

    printf(GREEN "NOVO NÚMERO DE SÉRIE: " RESET);
    fgets(componente->numero_serie,
        sizeof(componente->numero_serie),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    componente->numero_serie[
        strcspn(componente->numero_serie, "\n")] = '\0';

    printf(GREEN "NOVA DATA DE GARANTIA: " RESET);
    fgets(componente->data_garantia,
        sizeof(componente->data_garantia),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    componente->data_garantia[
        strcspn(componente->data_garantia, "\n")] = '\0';

    if (!listar_empresa())
	{
		printf(RED "EMPRESAS PRECISAM SER CADASTRADAS...\n" RESET);
        return ;
	}

    printf(GREEN "\nNOVO FORNECEDOR: " RESET);
    scanf("%d", &componente->id_fornecedor);

    printf(GREEN "NOVO FABRICANTE: " RESET);
    scanf("%d", &componente->id_fabricante);
    printf("------------------------------------------------------------------------------------------\n");
    
    if (!listar_posto())
	{
		printf(RED "POSTOS DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "NOVO POSTO: " RESET);
    scanf("%d", &componente->id_posto_trabalho);

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "NOVA OBSERVAÇÃO: " RESET);
    fgets(componente->observacao,
        sizeof(componente->observacao),
        stdin);

    componente->observacao[
        strcspn(componente->observacao, "\n")] = '\0';

    salvarDados();

    printf(GREEN "COMPONENTE ACTUALIZADO COM SUCESSO...\n" RESET);
}

void remover_componente(void)
{
    int id;
    int i;

    if (!listar_componente())
	{
		printf(RED "COMPONENTES DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO COMPONENTE: " RESET);
    scanf("%d", &id);

    if (componenteEstaEmUso(id))
    {
        printf(RED
            "\nNÃO É POSSÍVEL REMOVER."
            "\nCOMPONENTE ASSOCIADO A OPERAÇÕES\n" RESET);

        return ;
    }

    i = 0;

    while (i < total_componentes)
    {
        if (componentes[i].id == id)
        {
            while (i < total_componentes - 1)
            {
                componentes[i] =
                    componentes[i + 1];
                i++;
            }

            total_componentes--;

            salvarDados();

            printf(GREEN "COMPONENTE REMOVIDO COM SUCESSO...\n" RESET);

            return ;
        }

        i++;
    }

    printf(RED "\nCOMPONENTE NÃO ENCONTRADO.\n" RESET);
}

void mover_componente(void)
{
    int id_componente;
    int novo_posto;

    t_componentes *componente;

    if (!listar_componente())
	{
		printf(RED "COMPONENTES DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO COMPONENTE: " RESET);
    scanf("%d", &id_componente);

    componente =
        buscarComponentePorId(
            id_componente);

    if (!componente)
    {
        printf(RED "\nCOMPONENTE NÃO ENCONTRADO.\n" RESET);
        return ;
    }
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN
        "\nPOSTO ACTUAL: " RESET "%d\n",
        componente->id_posto_trabalho);
    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_posto())
	{
		printf(RED "POSTOS DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf("\nNOVO POSTO: ");
    scanf("%d", &novo_posto);

    componente->id_posto_trabalho =
        novo_posto;

    salvarDados();

    printf(GREEN "COMPONENTE MOVIDO COM SUCESSO...\n" RESET);
}