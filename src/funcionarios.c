#include "../includes/funcionarios.h"
#include "../includes/sistema_gestao.h"

static int funcionarioEstaEmUso(int id_funcionario)
{
    int i;

    i = 0;
    while (i < total_postos)
    {
        if (postos[i].id_funcionario == id_funcionario)
            return (1);

        i++;
    }

    i = 0;
    while (i < total_operacoes)
    {
        if (operacoes[i].id_funcionario == id_funcionario)
            return (1);

        i++;
    }

    return (0);
}

t_funcionarios *buscarFuncionarioPorId(int id)
{
    int i;

    i = 0;
    while (i < total_funcionarios)
    {
        if (funcionarios[i].id == id)
            return (&funcionarios[i]);
        i++;
    }
    return (NULL);
}

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

void pesquisar_funcionario(void)
{
    int id;
    t_funcionarios *funcionario;

    if (!listar_funcionario())
	{
		printf(RED "FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO FUNCIONÁRIO: " RESET);
    scanf("%d", &id);

    funcionario = buscarFuncionarioPorId(id);

    if (!funcionario)
    {
        printf(RED "\nFUNCIONÁRIO NÃO ENCONTRADO.\n" RESET);
        return ;
    }
    system("clear");
    printf(YELLOW "\nDADOS DO FUNCIONÁRIO PESQUISADO\n" RESET);

    printf(GREEN "ID: " RESET "%d\n", funcionario->id);
    printf(GREEN "NOME: " RESET "%s\n", funcionario->nome);
    printf(GREEN "FUNÇÃO: " RESET "%s\n", funcionario->funcao);
    printf(GREEN "DESCRIÇÃO: " RESET "%s\n", funcionario->descricao);
}

void actualizar_funcionario(void)
{
    int id;
    t_funcionarios *funcionario;

    if (!listar_funcionario())
	{
		printf(RED "FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DO FUNCIONÁRIO: " RESET);
    scanf("%d", &id);

    funcionario = buscarFuncionarioPorId(id);

    if (!funcionario)
    {
        printf(RED "\nFUNCIONÁRIO NÃO ENCONTRADA.\n" RESET);
        return ;
    }

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "NOVO NOME DO FUNCIONÁRIO: " RESET);
    fgets(funcionario->nome,
        sizeof(funcionario->nome),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    funcionario->nome[
        strcspn(funcionario->nome, "\n")] = '\0';

    printf(GREEN "NOVA FUNÇÃO DO FUNCIONÁRIO: " RESET);
    fgets(funcionario->funcao,
        sizeof(funcionario->funcao),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    funcionario->funcao[
        strcspn(funcionario->funcao, "\n")] = '\0';

    printf(GREEN "NOVA DESCRIÇÃO DO FUNCIONÁRIO: " RESET);
    fgets(funcionario->descricao,
        sizeof(funcionario->descricao),
        stdin);
    
    funcionario->descricao[
        strcspn(funcionario->descricao, "\n")] = '\0';

    salvarDados();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "FUNCIONÁRIO ACTUALIZADO COM SUCESSO...\n" RESET);
}

void remover_funcionario(void)
{
    int id;
    int i;

    if (!listar_funcionario())
	{
		printf(RED "FUNCIONÁRIOS PRECISAM SER CADASTRADOS...\n" RESET);
        return ;
	}
    printf(GREEN "\nID DO FUNCIONÁRIO: " RESET);
    scanf("%d", &id);

    if (funcionarioEstaEmUso(id))
    {
        printf(RED
            "\nNÃO É POSSÍVEL REMOVER."
            "\nFUNCIONÁRIO ASSOCIADO A POSTOS "
            "OU OPERAÇÕES.\n"RESET);

        return ;
    }

    i = 0;

    while (i < total_funcionarios)
    {
        if (funcionarios[i].id == id)
        {
            while (i < total_funcionarios - 1)
            {
                funcionarios[i] = funcionarios[i + 1];
                i++;
            }

            total_funcionarios--;

            salvarDados();

             printf(GREEN "FUNCIONÁRIO REMOVIDO COM SUCESSO...\n" RESET);

            return ;
        }

        i++;
    }

    printf(RED "\nFUNCIONÁRIO NÃO ENCONTRADO.\n" RESET);
}