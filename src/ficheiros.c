// =====================================================
// ficheiro: ficheiros.c
// =====================================================

#include "../includes/globals.h"
#include "../includes/ficheiros.h"

// =====================================================
// EMPRESAS
// =====================================================

static void carregarEmpresas(void)
{
    FILE *fp;

    fp = fopen("../data/empresas.dat", "rb");
    if (!fp)
        return ;

    fread(&total_empresas, sizeof(int), 1, fp);
    fread(empresas, sizeof(t_empresas), total_empresas, fp);

    fclose(fp);
}

static void salvarEmpresas(void)
{
    FILE *fp;

    fp = fopen("../data/empresas.dat", "wb");
    if (!fp)
        return ;

    fwrite(&total_empresas, sizeof(int), 1, fp);
    fwrite(empresas, sizeof(t_empresas), total_empresas, fp);

    fclose(fp);
}

// =====================================================
// FUNCIONÁRIOS
// =====================================================

static void carregarFuncionarios(void)
{
    FILE *fp;

    fp = fopen("../data/funcionarios.dat", "rb");
    if (!fp)
        return ;

    fread(&total_funcionarios, sizeof(int), 1, fp);
    fread(funcionarios, sizeof(t_funcionarios),
            total_funcionarios, fp);

    fclose(fp);
}

static void salvarFuncionarios(void)
{
    FILE *fp;

    fp = fopen("../data/funcionarios.dat", "wb");
    if (!fp)
        return ;

    fwrite(&total_funcionarios, sizeof(int), 1, fp);
    fwrite(funcionarios, sizeof(t_funcionarios),
            total_funcionarios, fp);

    fclose(fp);
}

// =====================================================
// POSTOS
// =====================================================

static void carregarPostos(void)
{
    FILE *fp;

    fp = fopen("../data/postos.dat", "rb");
    if (!fp)
        return ;

    fread(&total_postos, sizeof(int), 1, fp);
    fread(postos, sizeof(t_posto_trabalhos),
            total_postos, fp);

    fclose(fp);
}

static void salvarPostos(void)
{
    FILE *fp;

    fp = fopen("../data/postos.dat", "wb");
    if (!fp)
        return ;

    fwrite(&total_postos, sizeof(int), 1, fp);
    fwrite(postos, sizeof(t_posto_trabalhos),
            total_postos, fp);

    fclose(fp);
}

// =====================================================
// COMPONENTES
// =====================================================

static void carregarComponentes(void)
{
    FILE *fp;

    fp = fopen("../data/componentes.dat", "rb");
    if (!fp)
        return ;

    fread(&total_componentes, sizeof(int), 1, fp);
    fread(componentes, sizeof(t_componentes),
            total_componentes, fp);

    fclose(fp);
}

static void salvarComponentes(void)
{
    FILE *fp;

    fp = fopen("../data/componentes.dat", "wb");
    if (!fp)
        return ;

    fwrite(&total_componentes, sizeof(int), 1, fp);
    fwrite(componentes, sizeof(t_componentes),
            total_componentes, fp);

    fclose(fp);
}

// =====================================================
// OPERAÇÕES
// =====================================================

static void carregarOperacoes(void)
{
    FILE *fp;

    fp = fopen("../data/operacoes.dat", "rb");
    if (!fp)
        return ;

    fread(&total_operacoes, sizeof(int), 1, fp);
    fread(operacoes, sizeof(t_operacoes),
            total_operacoes, fp);

    fclose(fp);
}

static void salvarOperacoes(void)
{
    FILE *fp;

    fp = fopen("../data/operacoes.dat", "wb");
    if (!fp)
        return ;

    fwrite(&total_operacoes, sizeof(int), 1, fp);
    fwrite(operacoes, sizeof(t_operacoes),
            total_operacoes, fp);

    fclose(fp);
}

// =====================================================
// FUNÇÕES GERAIS
// =====================================================

void carregarDados(void)
{
    carregarEmpresas();
    carregarFuncionarios();
    carregarPostos();
    carregarComponentes();
    carregarOperacoes();
}

void salvarDados(void)
{
    salvarEmpresas();
    salvarFuncionarios();
    salvarPostos();
    salvarComponentes();
    salvarOperacoes();
}