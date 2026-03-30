#include "../includes/sistema_gestao.h"

int main();

void    menu_principal()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES GERIR? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - COMPONETES                                                                " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - EMPRESAS                                                                  " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - FUNCIONÁRIOS                                                              " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - OPERAÇÕES                                                                 " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - POSTOS DE TRABALHO                                                        " RESET "|\n");
    printf("\t\t|" RED "          6 - SAIR                                                                      " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_componentes()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR COMPONENTE                                                      " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR COMPONENTES                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR COMPONENTE POR ID                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR COMPONENTE POR ID                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER COMPONENTE POR ID                                                 " RESET "|\n");
    printf("\t\t|" RED "          6 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_empresas()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR EMPRESA                                                         " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR EMPRESAS                                                           " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR EMPRESA POR ID                                                  " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR EMPRESA POR ID                                                  " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER EMPRESA POR ID                                                    " RESET "|\n");
    printf("\t\t|" RED "          6 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_funcionarios()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR FUNCIONÁRIO                                                     " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR FUNCIONÁRIOS                                                       " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR FUNCIONÁRIO POR ID                                              " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR FUNCIONÁRIO POR ID                                              " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER FUNCIONÁRIO POR ID                                                " RESET "|\n");
    printf("\t\t|" RED "          6 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_operacoes()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR OPERAÇÃO                                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR OPERAÇÕES                                                          " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR OPERAÇÃO POR ID                                                 " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR OPERAÇÃO POR ID                                                 " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER OPERAÇÃO POR ID                                                   " RESET "|\n");
    printf("\t\t|" RED "          6 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

    printf("\t\t------------------------------------------------------------------------------------------\n");
}

void menu_postos()

{
    printf("\t\t------------------------------------------------------------------------------------------\n");

    printf("\t\t|" CYAN BOLD "                           O QUE PRETENDES FAZER? ESCOLHA UMA DAS OPÇÕES:               " RESET "|\n");
    printf("\t\t|" YELLOW "          1 - ADICIONAR POSTO DE TRABALHO                                               " RESET "|\n");
    printf("\t\t|" YELLOW "          2 - LISTAR POSTOS DE TRABALHO                                                 " RESET "|\n");
    printf("\t\t|" YELLOW "          3 - PESQUISAR POSTO DE TRABALHO POR ID                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          4 - ATUALIZAR POSTO DE TRABALHO POR ID                                        " RESET "|\n");
    printf("\t\t|" YELLOW "          5 - REMOVER POSTO DE TRABALHO POR ID                                          " RESET "|\n");
    printf("\t\t|" RED "          6 - VOLTAR AO MENU PRINCIPAL                                                  " RESET "|\n");

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
            listar__componente();*/
            break;
        case 3:
            /*system("clear");
            pesquisar__componente();*/
            break;
        case 4:
            /*system("clear");
            actualizar__componente();*/
            break;
        case 5:
            /*system("clear");
            remover__componente();*/
            break;
        case 6:
            printf("\t\t" RED "A VOLTAR AO MENU PRINCIPAL...\n" RESET);
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
            listar__empresa();*/
            break;
        case 3:
            /*system("clear");
            pesquisar__empresa();*/
            break;
        case 4:
            /*system("clear");
            actualizar__empresa();*/
            break;
        case 5:
            /*system("clear");
            remover__empresa();*/
            break;
        case 6:
            printf("\t\t" RED "A VOLTAR AO MENU PRINCIPAL...\n" RESET);
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
            listar__funcionario();*/
            break;
        case 3:
            /*system("clear");
            pesquisar__funcionario();*/
            break;
        case 4:
            /*system("clear");
            actualizar__funcionario();*/
            break;
        case 5:
            /*system("clear");
            remover__funcionario();*/
            break;
        case 6:
            printf("\t\t" RED "A VOLTAR AO MENU PRINCIPAL...\n" RESET);
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
            adicionar_operacao();*/
            break;
        case 2:
            /*system("clear");
            listar__operacao();*/
            break;
        case 3:
            /*system("clear");
            pesquisar__operacao();*/
            break;
        case 4:
            /*system("clear");
            actualizar__operacao();*/
            break;
        case 5:
            /*system("clear");
            remover__operacao();*/
            break;
        case 6:
            printf("\t\t" RED "A VOLTAR AO MENU PRINCIPAL...\n" RESET);
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
            listar__posto();*/
            break;
        case 3:
            /*system("clear");
            pesquisar__posto();*/
            break;
        case 4:
            /*system("clear");
            actualizar__posto();*/
            break;
        case 5:
            /*system("clear");
            remover__posto();*/
            break;
        case 6:
            printf("\t\t" RED "A VOLTAR AO MENU PRINCIPAL...\n" RESET);
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

    system("clear");
    menu_principal();
    printf("\t\t" GREEN "ESCOLHA UMA OPÇÃO: " RESET);
    sleep(1);
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            system("clear");
            run_options_componentes();
            break;
        case 2:
            system("clear");
            run_options_empresas();
            break;
        case 3:
            system("clear");
            run_options_funcionarios();
            break;
        case 4:
            system("clear");
            run_options_operacoes();
            break;
        case 5:
            system("clear");
            run_options_postos();
            break;
        case 6:
            printf("\t\t" RED "A SAIR DO SISTEMA...\n" RESET);
            sleep(1);
            exit(0);
        default:
            printf("\t\t" RED "OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" RESET);
    }
    return (0);
}