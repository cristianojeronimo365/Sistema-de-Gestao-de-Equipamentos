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
    printf(GREEN"\t\t\t------------------------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |            NOME            |        FUNCÃO           |         DESCRIÇÃO        |\n" RESET);
    printf(GREEN"\t\t\t------------------------------------------------------------------------------------------\n"RESET);
    while (i < total_funcionarios)
    {
        printf(GREEN "\t\t\t| " RESET);
        printf("%d", funcionarios[i].id);
        printf(GREEN "  |   " RESET);
        format_printf(funcionarios[i].nome);
        printf(GREEN "  | " RESET);
        format_printf(funcionarios[i].funcao);
        printf(GREEN " | " RESET);
        format_printf(funcionarios[i].descricao);
        printf(GREEN "  |\n" RESET);
        printf(GREEN"\t\t\t------------------------------------------------------------------------------------------\n"RESET);
        i++;
    }
	return (1);
}