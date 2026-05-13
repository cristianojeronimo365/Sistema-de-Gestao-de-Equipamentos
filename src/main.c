#include "../includes/sistema_gestao.h"

int main();

void    menu_principal()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES GERIR? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - EMPRESAS                                                                  " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - FUNCIONÁRIOS                                                              " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - POSTOS DE TRABALHO                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - COMPONENTES                                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - OPERAÇÕES                                                                 " RESET "|\n");
    printf("\t\t|" YELLOW "          6 - CONSULTAS E ESTATÍSTICAS                                                  " RESET "|\n");
    printf("\t\t|" RED "          0 - SAIR                                                                      " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_componentes()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR COMPONENTE                                                      " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR COMPONENTES                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR COMPONENTE                                                      " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR COMPONENTE                                                      " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER COMPONENTE                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          6 - MOVER COMPONENTE                                                          " RESET "|\n");
    printf("\t\t|" RED "          0 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_empresas()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR EMPRESA                                                         " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR EMPRESAS                                                           " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR EMPRESA                                                         " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR EMPRESA                                                         " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER EMPRESA                                                           " RESET "|\n");
    printf("\t\t|" RED "          0 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_funcionarios()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR FUNCIONÁRIO                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR FUNCIONÁRIOS                                                       " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR FUNCIONÁRIO                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR FUNCIONÁRIO                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER FUNCIONÁRIO                                                       " RESET "|\n");
    printf("\t\t|" RED "          0 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_operacoes()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - CRIAR OPERAÇÃO                                                            " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - ATUALIZAR OPERAÇÃO                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - LISTAR OPERAÇÕES                                                          " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - PESQUISAR OPERAÇÃO                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - OPERAÇÕES PENDENTES                                                       " RESET "|\n");
    printf("\t\t|" YELLOW "          6 - OPERAÇÕES CONCLUÍDAS                                                      " RESET "|\n");
    printf("\t\t|" RED "          0 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_postos()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR POSTO DE TRABALHO                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR POSTOS DE TRABALHO                                                 " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR POSTO DE TRABALHO                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR POSTO DE TRABALHO                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER POSTO DE TRABALHO                                                 " RESET "|\n");
    printf("\t\t|" RED "          0 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_avancados()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES CONSULTAR? ESCOLHA UMA DAS OPÇÕES:           " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - COMPONENTES POR POSTO                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - COMPONENTES EM GARANTIA                                                   " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - COMPONENTES ATRASADOS                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - EMPRESAS MAIS UTILIZADAS                                                  " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - OPERAÇÕES POR EMPRESA                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          6 - OPERAÇÕES POR FUNCIONÁRIO                                                 " RESET "|\n");
    printf("\t\t|" RED "          0 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void    run_options_componentes()

{
    int opcao;

    menu_componentes();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            /*system("clear");
            adicionar_componente();*/
            break;
        case 2:
            /*system("clear");
            listar_componente();*/
            break;
        case 3:
            /*system("clear");
            pesquisar_componente();*/
            break;
        case 4:
            /*system("clear");
            actualizar_componente();*/
            break;
        case 5:
            /*system("clear");
            remover_componente();*/
            break;
        case 6:
            /*system("clear");
            mover_componente();*/
            break;
        case 0:
            printf("\t\t" RED "VOLTANDO PARA O MENU PRINCIPAL...\n" RESET);
            sleep(1);
            main();
            break;
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
}

void    run_options_empresas()

{
    int opcao;

    menu_empresas();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            /*system("clear");
            adicionar_empresa();*/
            break;
        case 2:
            /*system("clear");
            listar_empresa();*/
            break;
        case 3:
            /*system("clear");
            pesquisar_empresa();*/
            break;
        case 4:
            /*system("clear");
            actualizar_empresa();*/
            break;
        case 5:
            /*system("clear");
            remover_empresa();*/
            break;
        case 0:
            printf("\t\t" RED "VOLTANDO PARA O MENU PRINCIPAL...\n" RESET);
            sleep(1);
            main();
            break;
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
}


void    run_options_funcionarios()

{
    int opcao;

    menu_funcionarios();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            /*system("clear");
            adicionar_funcionario();*/
            break;
        case 2:
            /*system("clear");
            listar_funcionario();*/
            break;
        case 3:
            /*system("clear");
            pesquisar_funcionario();*/
            break;
        case 4:
            /*system("clear");
            actualizar_funcionario();*/
            break;
        case 5:
            /*system("clear");
            remover_funcionario();*/
            break;
        case 0:
            printf("\t\t" RED "VOLTANDO PARA O MENU PRINCIPAL...\n" RESET);
            sleep(1);
            main();
            break;
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
}

void    run_options_operacoes()

{
    int opcao;

    menu_operacoes();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            /*system("clear");
            criar_operacao();*/
            break;
        case 2:
            /*system("clear");
            atualizar_operacao();*/
            break;
        case 3:
            /*system("clear");
            listar_operacao();*/
            break;
        case 4:
            /*system("clear");
            pesquisar_operacao();*/
            break;
        case 5:
            /*system("clear");
            operacoes_pendentes();*/
            break;
        case 6:
            /*system("clear");
            operacoes_concluidas();*/
            break;
        case 0:
            printf("\t\t" RED "VOLTANDO PARA O MENU PRINCIPAL...\n" RESET);
            sleep(1);
            main();
            break;
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
}

void    run_options_postos()

{
    int opcao;

    menu_postos();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            /*system("clear");
            adicionar_posto();*/
            break;
        case 2:
            /*system("clear");
            listar_posto();*/
            break;
        case 3:
            /*system("clear");
            pesquisar_posto();*/
            break;
        case 4:
            /*system("clear");
            actualizar_posto();*/
            break;
        case 5:
            /*system("clear");
            remover_posto();*/
            break;
        case 0:
            printf("\t\t" RED "VOLTANDO PARA O MENU PRINCIPAL...\n" RESET);
            sleep(1);
            main();
            break;
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
}

void    run_options_avancadas()

{
    int opcao;

    menu_avancados();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            /*system("clear");
            componentes_posto();*/
            break;
        case 2:
            /*system("clear");
            componentes_garantia();*/
            break;
        case 3:
            /*system("clear");
            componentes_atrasados();*/
            break;
        case 4:
            /*system("clear");
            empresas_utilizadas();*/
            break;
        case 5:
            /*system("clear");
            operacoes_empresa();*/
            break;
        case 6:
            /*system("clear");
            operacoes_funcionario();*/
            break;
        case 0:
            printf("\t\t" RED "VOLTANDO PARA O MENU PRINCIPAL...\n" RESET);
            sleep(1);
            main();
            break;
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
}

int main()

{
    int opcao;

    setlocale(LC_ALL, "PORTUGUESE");
    system("clear");
    menu_principal();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            system("clear");
            run_options_empresas();
            break;
        case 2:
            system("clear");
            run_options_funcionarios();
            break;
        case 3:
            system("clear");
            run_options_postos();
            break;
        case 4:
            system("clear");
            run_options_componentes();
            break;
        case 5:
            system("clear");
            run_options_operacoes();
            break;
        case 6:
            system("clear");
            run_options_avancadas();
            break;
        case 0:
            printf("\t\t" RED "SAINDO DO SISTEMA...\n" RESET);
            sleep(1);
            exit(0);
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
    return (0);
}