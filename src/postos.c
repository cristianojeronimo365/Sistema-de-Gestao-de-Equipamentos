#include "../includes/postos.h"
#include "../includes/sistema_gestao.h"
#include "../includes/funcionarios.h"

static int postoEstaEmUso(int id_posto)
{
    int i;

    i = 0;
    while (i < total_componentes)
    {
        if (componentes[i].id_posto_trabalho == id_posto)
            return (1);

        i++;
    }

    i = 0;
    while (i < total_operacoes)
    {
        if (operacoes[i].id_posto_trabalho == id_posto)
            return (1);

        i++;
    }

    return (0);
}

t_posto_trabalhos *buscarPostoPorId(int id)
{
    int i;

    i = 0;
    while (i < total_postos)
    {
        if (postos[i].id == id)
            return (&postos[i]);
        i++;
    }
    return (NULL);
}

void adicionar_posto(void)
{
    t_posto_trabalhos novo;

    if (total_postos >= MAX_POSTOS)
    {
        printf(RED "LIMITE DE POSTO ATINGIDO.\n" RESET);
        return ;
    }

    novo.id = total_postos + 100;

    getchar();

    printf(GREEN "NOME DO POSTO: " RESET);
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");

    printf(GREEN "LOCAL: " RESET);
    fgets(novo.local, sizeof(novo.local), stdin);
    novo.local[strcspn(novo.local, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");

    printf(GREEN "SECÇÃO: " RESET);
    fgets(novo.seccao, sizeof(novo.seccao), stdin);
    novo.seccao[strcspn(novo.seccao, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");

    printf(GREEN "DESCRIÇÃO: " RESET);
    fgets(novo.descricao,
            sizeof(novo.descricao), stdin);

    novo.descricao[
        strcspn(novo.descricao, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    if (!listar_funcionario())
	{
		printf(RED "FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO FUNCIONÁRIO RESPONSÁVEL: " RESET);
    scanf("%d", &novo.id_funcionario);

    postos[total_postos] = novo;

    total_postos++;
    printf("------------------------------------------------------------------------------------------\n");
    salvarDados();

    printf(GREEN "\nPOSTO CADASTRADO COM SUCESSO.\n" RESET);
}

int listar_posto(void)
{
    int i;

    if (total_postos == 0)
    {
        printf(RED "\nNENHUM POSTO CADASTRADO.\n" RESET);
        return (0);
    }

    i = 0;
    printf(GREEN"\t--------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t|  ID  |            NOME            |        LOCAL            |        SECÇÃO           |         DESCRIÇÃO       |         RESPONSÁVEL          |\n" RESET);
    printf(GREEN"\t--------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);
    while (i < total_postos)
    {

        printf(GREEN "\t| " RESET);
        printf("%d", postos[i].id);
        printf(GREEN "  |   " RESET);

        format_printf(postos[i].nome);
        printf(GREEN "  | " RESET);
        format_printf(postos[i].local);
        printf(GREEN " | " RESET);
        format_printf(postos[i].seccao);
        printf(GREEN " | " RESET);
        format_printf(postos[i].descricao);
        printf(GREEN " | " RESET);
        format_printf(buscarFuncionarioPorId(postos[i].id_funcionario)->nome);
        printf(GREEN "      |\n" RESET);
        printf(GREEN"\t--------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);

        i++;
    }
	return (1);
}

void pesquisar_posto(void)
{
    int id;
    t_posto_trabalhos *posto;

    if (!listar_posto())
	{
		printf(RED "POSTOS DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO POSTO: " RESET);
    scanf("%d", &id);

    posto = buscarPostoPorId(id);

    if (!posto)
    {
        printf(RED "\nPOSTO NÃO ENCONTRADO.\n" RESET);
        return ;
    }
    system("clear");
    printf(YELLOW "\nDADOS DO POSTO PESQUISADO\n" RESET);

    printf(GREEN "ID: " RESET "%d\n", posto->id);
    printf(GREEN "NOME: " RESET "%s\n", posto->nome);
    printf(GREEN "LOCAL: " RESET "%s\n", posto->local);
    printf(GREEN "SECÇÃO: " RESET "%s\n", posto->seccao);
    printf(GREEN "DESCRIÇÃO: " RESET "%s\n", posto->descricao);
    printf(GREEN "FUNCIONÁRIO RESPONSÁVEL: " RESET "%s\n",
            buscarFuncionarioPorId(posto->id_funcionario)->nome);
}

void actualizar_posto(void)
{
    int id;
    t_posto_trabalhos *posto;

    if (!listar_posto())
	{
		printf(RED "POSTOS DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO POSTO: " RESET);
    scanf("%d", &id);

    posto = buscarPostoPorId(id);

    if (!posto)
    {
        printf(RED "\nPOSTO NÃO ENCONTRADO.\n" RESET);
        return ;
    }

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "NOVO NOME DO POSTO: " RESET);
    fgets(posto->nome,
        sizeof(posto->nome),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    posto->nome[
        strcspn(posto->nome, "\n")] = '\0';

    printf(GREEN "NOVO LOCAL DO POSTO: " RESET);
    fgets(posto->local,
        sizeof(posto->local),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    posto->local[
        strcspn(posto->local, "\n")] = '\0';

    printf(GREEN "NOVA SECÇÃO DO POSTO: " RESET);
    fgets(posto->seccao,
        sizeof(posto->seccao),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    posto->seccao[
        strcspn(posto->seccao, "\n")] = '\0';

    printf(GREEN "NOVA DESCRIÇÃO DO POSTO: " RESET);
    fgets(posto->descricao,
        sizeof(posto->descricao),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    posto->descricao[
        strcspn(posto->descricao, "\n")] = '\0';

    if (!listar_funcionario())
	{
		printf(RED "FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "NOVO ID DO FUNCIONÁRIO RESPONSÁVEL: " RESET);
    scanf("%d", &posto->id_funcionario);

    salvarDados();

    printf(GREEN "POSTO ACTUALIZADO COM SUCESSO...\n" RESET);
}
void remover_posto(void)
{
    int id;
    int i;

    if (!listar_posto())
	{
		printf(RED "POSTOS DE TRABALHO PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO POSTO: " RESET);
    scanf("%d", &id);

    if (postoEstaEmUso(id))
    {
        printf(RED
            "\nNÃO É POSSÍVEL REMOVER."
            "\nPOSTO ASSOCIADO A COMPONENTES "
            "OU OPERAÇÕES.\n" RESET);

        return ;
    }

    i = 0;

    while (i < total_postos)
    {
        if (postos[i].id == id)
        {
            while (i < total_postos - 1)
            {
                postos[i] = postos[i + 1];
                i++;
            }

            total_postos--;

            salvarDados();

            printf(GREEN "POSTO REMOVIDO COM SUCESSO...\n" RESET);

            return ;
        }

        i++;
    }

    printf(RED "\nPOSTO NÃO ENCONTRADO.\n" RESET);
}
