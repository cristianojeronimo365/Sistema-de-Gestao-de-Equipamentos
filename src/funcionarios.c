#include "../includes/funcionarios.h"
#include "../includes/sistema_gestao.h"

void adicionar_funcionario(void)
{
    t_funcionarios novo;

    if (total_funcionarios >= MAX_FUNCIONARIOS)
    {
        printf("Limite de funcionarios atingido.\n");
        return ;
    }

    novo.id = total_funcionarios + 100;

    getchar();

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Funcao: ");
    fgets(novo.funcao, sizeof(novo.funcao), stdin);
    novo.funcao[strcspn(novo.funcao, "\n")] = '\0';

    printf("Descricao: ");
    fgets(novo.descricao, sizeof(novo.descricao), stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    funcionarios[total_funcionarios] = novo;

    total_funcionarios++;

    salvarDados();

    printf("\nFuncionario cadastrado com sucesso.\n");
}


int listar_funcionario(void)
{
    int i;

    if (total_funcionarios == 0)
    {
        printf("\nNenhum funcionario cadastrado.\n");
        return (0);
    }

    i = 0;

    while (i < total_funcionarios)
    {
        printf("\nID: %d\n", funcionarios[i].id);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Funcao: %s\n", funcionarios[i].funcao);
        printf("Descricao: %s\n",
                funcionarios[i].descricao);

        printf("--------------------------\n");

        i++;
    }
	return (1);
}