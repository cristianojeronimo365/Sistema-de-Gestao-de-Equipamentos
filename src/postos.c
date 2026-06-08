#include "../includes/postos.h"
#include "../includes/sistema_gestao.h"
#include "../includes/funcionarios.h"

char *buscarPostoPorId(int id)
{
    int i;

    i = 0;
    while (i < total_postos)
    {
        if (postos[i].id == id)
            return (postos[i].nome);
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
        format_printf(buscarFuncionarioPorId(postos[i].id_funcionario));
        printf(GREEN "      |\n" RESET);
        printf(GREEN"\t--------------------------------------------------------------------------------------------------------------------------------------------------\n"RESET);

        i++;
    }
	return (1);
}