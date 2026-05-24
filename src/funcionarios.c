#include "../includes/funcionarios.h"
#include "../includes/sistema_gestao.h"

void adicionar_funcionario(void)
{
    t_funcionarios novo;

    if (total_funcionarios >= MAX_FUNCIONARIOS)
    {
        printf(RED "LIMITE DE FUNCIONÁRIOS ATINGIDO.\n" RESET);
        return ;
    }

    novo.id = total_funcionarios + 100;

    getchar();

    printf(GREEN "NOME DO FUNCIONÁRIO: " RESET);
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "FUNCÃO: " RESET);
    fgets(novo.funcao, sizeof(novo.funcao), stdin);
    novo.funcao[strcspn(novo.funcao, "\n")] = '\0';
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "DESIGNAÇÃO: " RESET);
    fgets(novo.descricao, sizeof(novo.descricao), stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    funcionarios[total_funcionarios] = novo;

    total_funcionarios++;
    printf("------------------------------------------------------------------------------------------\n");
    salvarDados();

    printf(GREEN "\nFUNCIONÁRIO CADASTRADO COM SUCESSO.\n" RESET);
}


int listar_funcionario(void)
{
    int i;

    if (total_funcionarios == 0)
    {
        printf(RED "\nNENHUM FUNCIONÁRIO CADASTRADO.\n" RESET);
        return (0);
    }

    i = 0;
    /*printf(GREEN"\t\t\t-------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |          NOME          |        FUNCÃO        |         DESIGNAÇÃO         |\n" RESET);
    printf(GREEN"\t\t\t-------------------------------------------------------------------------\n"RESET);*/
    while (i < total_funcionarios)
    {
        printf("\n%d\n", funcionarios[i].id);
        printf("%s\n", funcionarios[i].nome);
        printf("%s\n", funcionarios[i].funcao);
        printf("%s\n",
                funcionarios[i].descricao);

        printf("--------------------------\n");

        i++;
    }
	return (1);
}