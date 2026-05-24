#include "../includes/postos.h"
#include "../includes/sistema_gestao.h"
#include "../includes/funcionarios.h"

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
        printf(RED "\nNENHUM POSTO CADASTRADO.\n" REST);
        return (0);
    }

    i = 0;

    while (i < total_postos)
    {
        printf("\nID: %d\n", postos[i].id);
        printf("Nome: %s\n", postos[i].nome);
        printf("Local: %s\n", postos[i].local);
        printf("Seccao: %s\n", postos[i].seccao);

        printf("Funcionario Responsavel: %d\n",
                postos[i].id_funcionario);

        printf("--------------------------\n");

        i++;
    }
	return (1);
}