#include "../includes/postos.h"
#include "../includes/sistema_gestao.h"
#include "../includes/funcionarios.h"

void adicionar_posto(void)
{
    t_posto_trabalhos novo;

    if (total_postos >= MAX_POSTOS)
    {
        printf("Limite de postos atingido.\n");
        return ;
    }

    novo.id = total_postos + 100;

    getchar();

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Local: ");
    fgets(novo.local, sizeof(novo.local), stdin);
    novo.local[strcspn(novo.local, "\n")] = '\0';

    printf("Seccao: ");
    fgets(novo.seccao, sizeof(novo.seccao), stdin);
    novo.seccao[strcspn(novo.seccao, "\n")] = '\0';

    printf("Descricao: ");
    fgets(novo.descricao,
            sizeof(novo.descricao), stdin);

    novo.descricao[
        strcspn(novo.descricao, "\n")] = '\0';

    if (!listar_funcionario())
	{
		printf("FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("\nID do funcionario responsavel: ");
    scanf("%d", &novo.id_funcionario);

    postos[total_postos] = novo;

    total_postos++;

    salvarDados();

    printf("\nPosto criado com sucesso.\n");
}

int listar_posto(void)
{
    int i;

    if (total_postos == 0)
    {
        printf("\nNenhum posto cadastrado.\n");
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