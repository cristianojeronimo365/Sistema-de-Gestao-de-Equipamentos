#include "../includes/empresas.h"
#include "../includes/sistema_gestao.h"


static char *obterTipoEmpresa(TipoEmpresa tipo)
{
    if (tipo == FORNECEDOR)
        return ("FORNECEDOR");

    else if (tipo == FABRICANTE)
        return ("FABRICANTE");

    else if (tipo == RECICLAGEM)
        return ("RECICLAGEM");

    else if (tipo == AGENCIA)
        return ("AGENCIA");

    return (NULL);
}

static int empresaEstaEmUso(int id_empresa)
{
    int i;

    i = 0;
    while (i < total_componentes)
    {
        if (componentes[i].id_fornecedor == id_empresa
            || componentes[i].id_fabricante == id_empresa)
            return (1);

        i++;
    }

    i = 0;
    while (i < total_operacoes)
    {
        if (operacoes[i].id_empresa == id_empresa)
            return (1);

        i++;
    }

    return (0);
}
t_empresas *buscarEmpresaPorId(int id)
{
    int i;

    i = 0;
    while (i < total_empresas)
    {
        if (empresas[i].id == id)
            return (&empresas[i]);
        i++;
    }
    return (NULL);
}
void adicionar_empresa(void)
{
    t_empresas nova_empresa;

    if (total_empresas >= MAX_EMPRESAS)
    {
        printf(RED "LIMITE DE EMPRESAS ATINGIDO.\n" RESET);
        return ;
    }

    nova_empresa.id = total_empresas + 100;

    getchar();

    printf(GREEN "NOME DA EMPRESA: " RESET);
    fgets(nova_empresa.nome,
            sizeof(nova_empresa.nome), stdin);
    printf("------------------------------------------------------------------------------------------\n");
    nova_empresa.nome[strcspn(nova_empresa.nome, "\n")] = '\0';

    printf(GREEN "TIPO DA EMPRESA:\n" RESET);
    printf(YELLOW "0 - FORNECEDOR\n"RESET);
    printf(YELLOW "1 - FABRICANTE\n"RESET);
    printf(YELLOW "2 - RECICLAGEM\n"RESET);
    printf(YELLOW "3 - AGENCIA\n"RESET);
    printf("------------------------------------------------------------------------------------------\n");
    do{
        printf(GREEN "ESCOLHA UM TIPO CORRESPONDENTE: " RESET);
        scanf("%d", (int *)&nova_empresa.tipo);
    }while(!obterTipoEmpresa(nova_empresa.tipo));

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    do{
        printf(GREEN "CONTACTO: " RESET);
        fgets(nova_empresa.contacto, sizeof(nova_empresa.contacto), stdin);
    }while((strlen(nova_empresa.contacto) - 1) != 9);

    nova_empresa.contacto[strcspn(nova_empresa.contacto, "\n")] = '\0';

    empresas[total_empresas] = nova_empresa;

    total_empresas++;

    salvarDados();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "EMPRESA ADICIONADA COM SUCESSO...\n" RESET);
}

int listar_empresa(void)
{
    int i;

    if (total_empresas == 0)
    {
        printf(RED "\nNENHUMA EMPRESA CADASTRADA.\n" RESET);
        return (0);
    }

    i = 0;

    printf(GREEN"\t\t\t--------------------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |          NOME           |           TIPO          |        CONTACTO         |\n" RESET);
    printf(GREEN"\t\t\t--------------------------------------------------------------------------------------\n"RESET);

    while (i < total_empresas)
    {
        printf(GREEN "\t\t\t| " RESET);
        printf("%d", empresas[i].id);
        printf(GREEN "  | " RESET);
        format_printf(empresas[i].nome);
        printf(GREEN " | " RESET);
        format_printf(obterTipoEmpresa(empresas[i].tipo));
        printf(GREEN " | " RESET);
        format_printf(empresas[i].contacto);
        printf(GREEN " |\n" RESET);
        printf(GREEN"\t\t\t--------------------------------------------------------------------------------------\n"RESET);
        i++;
    }
	return (1);
}

void pesquisar_empresa(void)
{
    int id;
    t_empresas *empresa;

    if (!listar_empresa())
	{
		printf(RED "EMPRESAS PRECISAM SER CADASTRADAS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DA EMPRESA: " RESET);
    scanf("%d", &id);

    empresa = buscarEmpresaPorId(id);

    if (!empresa)
    {
        printf(RED "\nEMPRESA NÃO ENCONTRADA.\n" RESET);
        return ;
    }
    system("clear");
    printf(YELLOW "\nDADOS DA EMPRESA PESQUISADA\n" RESET);

    printf(GREEN "ID: " RESET "%d\n", empresa->id);
    printf(GREEN "NOME: " RESET "%s\n", empresa->nome);
    printf(GREEN "TIPO: " RESET "%s\n", obterTipoEmpresa(empresa->tipo));
    printf(GREEN "CONTACTO: " RESET "%s\n", empresa->contacto);
}

void actualizar_empresa(void)
{
    int id;
    t_empresas *empresa;

    if (!listar_empresa())
	{
		printf(RED "EMPRESAS PRECISAM SER CADASTRADAS...\n" RESET);
        return ;
	}

    printf(GREEN "\nID DA EMPRESA: " RESET);
    scanf("%d", &id);

    empresa = buscarEmpresaPorId(id);

    if (!empresa)
    {
        printf(RED "\nEMPRESA NÃO ENCONTRADA.\n" RESET);
        return ;
    }

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "NOVO NOME DA EMPRESA: " RESET);
    fgets(empresa->nome,
        sizeof(empresa->nome),
        stdin);
    printf("------------------------------------------------------------------------------------------\n");
    empresa->nome[
        strcspn(empresa->nome, "\n")] = '\0';

    printf(GREEN "TIPO DA EMPRESA:\n" RESET);
    printf(YELLOW "0 - FORNECEDOR\n"RESET);
    printf(YELLOW "1 - FABRICANTE\n"RESET);
    printf(YELLOW "2 - RECICLAGEM\n"RESET);
    printf(YELLOW "3 - AGENCIA\n"RESET);
    printf("------------------------------------------------------------------------------------------\n");
    do{
        printf(GREEN "ESCOLHA UM TIPO CORRESPONDENTE: " RESET);
        scanf("%d", (int *)&empresa->tipo);
    }while(!obterTipoEmpresa(empresa->tipo));

    getchar();
    printf("------------------------------------------------------------------------------------------\n");
    do{
        printf(GREEN "NOVO CONTACTO: " RESET);

        fgets(empresa->contacto,
            sizeof(empresa->contacto),
            stdin);
    }while((strlen(empresa->contacto) - 1) != 9);

    empresa->contacto[
        strcspn(empresa->contacto, "\n")] = '\0';

    salvarDados();

    printf("------------------------------------------------------------------------------------------\n");
    printf(GREEN "EMPRESA ACTUALIZADA COM SUCESSO...\n" RESET);
}
void remover_empresa(void)
{
    int id;
    int i;

    if (!listar_empresa())
	{
		printf(RED "EMPRESAS PRECISAM SER CADASTRADAS...\n" RESET);
        return ;
	}
    printf(GREEN "\nID DA EMPRESA: " RESET);
    scanf("%d", &id);

    if (empresaEstaEmUso(id))
    {
        printf(RED
            "\nNÃO É POSSÍVEL REMOVER."
            "\nEMPRESA ASSOCIADA A COMPONENTES "
            "OU OPERAÇÕES.\n"RESET);

        return ;
    }

    i = 0;

    while (i < total_empresas)
    {
        if (empresas[i].id == id)
        {
            while (i < total_empresas - 1)
            {
                empresas[i] = empresas[i + 1];
                i++;
            }

            total_empresas--;

            salvarDados();

            printf(GREEN "EMPRESA REMOVIDA COM SUCESSO...\n" RESET);

            return ;
        }

        i++;
    }

    printf(RED "\nEMPRESA NÃO ENCONTRADA.\n" RESET);
}
