#include "../includes/componentes.h"
#include "../includes/sistema_gestao.h"
#include "../includes/empresas.h"
#include "../includes/postos.h"

static const char *obterTipoComponente(
        TipoComponente tipo)
{
    if (tipo == ELECTRONICO)
        return ("ELECTRONICO");

    return ("MECANICO");
}

static const char *obterCondicao(
        TipoCondicao condicao)
{
    if (condicao == NOVO)
        return ("NOVO");

    return ("UTILIZADO");
}

void adicionar_componente(void)
{
    t_componentes novo;

    if (total_componentes >= MAX_COMPONENTES)
    {
        printf("Limite de componentes atingido.\n");
        return ;
    }

    novo.id = total_componentes + 100;

    getchar();

    printf("Designacao: ");
    fgets(novo.designacao,
            sizeof(novo.designacao), stdin);

    novo.designacao[
        strcspn(novo.designacao, "\n")] = '\0';

    printf("Numero de serie: ");
    fgets(novo.numero_serie,
            sizeof(novo.numero_serie), stdin);

    novo.numero_serie[
        strcspn(novo.numero_serie, "\n")] = '\0';

    printf("Data aquisicao: ");
    fgets(novo.data_aquisicao,
            sizeof(novo.data_aquisicao), stdin);

    novo.data_aquisicao[
        strcspn(novo.data_aquisicao, "\n")] = '\0';

    printf("Data garantia: ");
    fgets(novo.data_garantia,
            sizeof(novo.data_garantia), stdin);

    novo.data_garantia[
        strcspn(novo.data_garantia, "\n")] = '\0';

    printf("Tipo:\n");
    printf("0 - ELECTRONICO\n");
    printf("1 - MECANICO\n");
	
	do {
    	scanf("%d", (int *)&novo.tipo);
	}while (novo.tipo != 0 && novo.tipo != 1);

    printf("Condicao:\n");
    printf("0 - NOVO\n");
    printf("1 - UTILIZADO\n");
	do {
    	scanf("%d", (int *)&novo.condicao);
	}while (novo.condicao != 0 && novo.condicao != 1);


    if (!listar_empresa())
	{
		printf("EMPRESAS PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("\nID fornecedor: ");
    scanf("%d", &novo.id_fornecedor);

    printf("ID fabricante: ");
    scanf("%d", &novo.id_fabricante);

    if (!listar_posto())
	{
		printf("POSTOS PRECISAM SER CADASTRADOS...\n");
        return ;
	}

    printf("ID posto: ");
    scanf("%d", &novo.id_posto_trabalho);

    getchar();

    printf("Observacao: ");
    fgets(novo.observacao,
            sizeof(novo.observacao), stdin);

    novo.observacao[
        strcspn(novo.observacao, "\n")] = '\0';

    componentes[total_componentes] = novo;

    total_componentes++;

    salvarDados();

    printf("\nComponente criado com sucesso.\n");
}

int listar_componente(void)
{
    int i;

    if (total_componentes == 0)
    {
        printf("\nNenhum componente cadastrado.\n");
        return (0);
    }

    i = 0;

    while (i < total_componentes)
    {
        printf("\nID: %d\n",
                componentes[i].id);

        printf("Designacao: %s\n",
                componentes[i].designacao);

        printf("Numero Serie: %s\n",
                componentes[i].numero_serie);

        printf("Tipo: %s\n",
                obterTipoComponente(
                    componentes[i].tipo));

        printf("Condicao: %s\n",
                obterCondicao(
                    componentes[i].condicao));

        printf("Posto: %d\n",
                componentes[i].id_posto_trabalho);

        printf("--------------------------\n");

        i++;
    }
	return (1);
}