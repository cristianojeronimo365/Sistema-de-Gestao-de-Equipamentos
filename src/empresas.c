#include "../includes/empresas.h"
#include "../includes/sistema_gestao.h"


static const char *obterTipoEmpresa(TipoEmpresa tipo)
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
    int len;

    if (total_empresas == 0)
    {
        printf(RED "\nNENHUMA EMPRESA CADASTRADA.\n" RESET);
        return (0);
    }

    i = 0;
    len = 0;

    printf(GREEN"\t\t\t-------------------------------------------------------------------------\n"RESET);
    printf(GREEN "\t\t\t|  ID  |          NOME          |        TIPO        |     CONTACTO     |\n" RESET);
    printf(GREEN"\t\t\t-------------------------------------------------------------------------\n"RESET);

    while (i < total_empresas)
    {
        printf(GREEN "\t\t\t| " RESET);
        printf("%d", empresas[i].id);
        printf(GREEN "  |     " RESET);
        len = strlen(empresas[i].nome);
        if (len <= 14)
        {
            printf("%s", empresas[i].nome);
            while (len++ < 17)
                printf(" ");
        }
        else
        {
            len = 0;
            while (len < 14)
            {
                printf("%c", empresas[i].nome[len]);
                len++;
            }
            printf("...");
        }
        printf(GREEN "  |      " RESET);
        printf("%s", obterTipoEmpresa(empresas[i].tipo));
        len = strlen(obterTipoEmpresa(empresas[i].tipo));
        while (len++ < 14)
            printf(" ");
        printf(GREEN "|     " RESET);
        printf("%s", empresas[i].contacto);
        printf(GREEN "    |\n" RESET);
        printf(GREEN"\t\t\t-------------------------------------------------------------------------\n"RESET);
        i++;
    }
	return (1);
}
