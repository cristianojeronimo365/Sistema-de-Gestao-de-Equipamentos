# CRONOGRAMA COMPLETO DE IMPLEMENTAÇÃO
## Sistema de Gestão de Componentes

---

# 1. OBJETIVO DO DOCUMENTO

Este documento define:

- A ordem correta de implementação do sistema
- As dependências entre módulos
- As responsabilidades da equipa
- O fluxo de funcionamento de cada menu
- O que deve ser pedido ao utilizador
- O que deve ser validado
- O que deve ser salvo
- O comportamento esperado do sistema

O objetivo é evitar:

- dúvidas durante o desenvolvimento
- conflitos entre membros
- funcionalidades incoerentes
- erros de integração
- repetição de código

---

# 2. ARQUITETURA GERAL DO SISTEMA

## O sistema será dividido em:

1. Gestão de Empresas
2. Gestão de Funcionários
3. Gestão de Postos de Trabalho
4. Gestão de Componentes
5. Gestão de Operações
6. Consultas e Estatísticas
7. Persistência em Ficheiros

---

# 3. ORGANIZAÇÃO DOS FICHEIROS

## Estrutura sugerida

```text
src/
│
├── main.c
├── menu.c
├── menu.h
│
├── empresas.c
├── empresas.h
│
├── funcionarios.c
├── funcionarios.h
│
├── postos.c
├── postos.h
│
├── componentes.c
├── componentes.h
│
├── operacoes.c
├── operacoes.h
│
├── ficheiros.c
├── ficheiros.h
│
├── estatisticas.c
├── estatisticas.h
│
├── utils.c
├── utils.h
│
└── sistema_gestao.h
```

---

# 4. DIVISÃO DA EQUIPA

| Membro | Responsabilidade |
|---|---|
| Dev 1 | Arquitetura geral + integração |
| Dev 2 | Empresas + Funcionários |
| Dev 3 | Postos + Componentes |
| Dev 4 | Operações |
| Dev 5 | Ficheiros + Estatísticas + testes |

---

# 5. ORDEM CORRETA DE IMPLEMENTAÇÃO

A implementação deve seguir esta ordem obrigatoriamente:

1. Estruturas base
2. Menus
3. Empresas
4. Funcionários
5. Postos de Trabalho
6. Componentes
7. Operações
8. Ficheiros
9. Estatísticas
10. Testes finais

Motivo:

- Postos dependem de funcionários
- Componentes dependem de empresas e postos
- Operações dependem de todos os módulos

---

# 6. ETAPA 1 — ESTRUTURAS BASE

## Objetivo

Criar a base do sistema.

---

## Deve ser feito

- Criar enums
- Criar structs
- Criar arrays globais
- Criar contadores
- Criar header principal

---

## Arrays globais sugeridos

```c
#define MAX_EMPRESAS 100
#define MAX_FUNCIONARIOS 100
#define MAX_POSTOS 100
#define MAX_COMPONENTES 100
#define MAX_OPERACOES 100
```

---

## Exemplo

```c
extern t_empresas empresas[MAX_EMPRESAS];
extern int total_empresas;
```

---

# 7. ETAPA 2 — MENUS

## Objetivo

Criar toda navegação do sistema.

---

# MENU PRINCIPAL

```text
1. Gestão de Empresas
2. Gestão de Funcionários
3. Gestão de Postos de Trabalho
4. Gestão de Componentes
5. Gestão de Operações
6. Consultas e Estatísticas
0. Sair
```

---

# MENU EMPRESAS

```text
1. Inserir Empresa
2. Listar Empresas
3. Alterar Empresa
4. Apagar Empresa
5. Pesquisar Empresa
0. Voltar
```

---

# MENU FUNCIONÁRIOS

```text
1. Inserir Funcionário
2. Listar Funcionários
3. Alterar Funcionário
4. Apagar Funcionário
5. Pesquisar Funcionário
0. Voltar
```

---

# MENU POSTOS

```text
1. Inserir Posto
2. Listar Postos
3. Alterar Posto
4. Apagar Posto
5. Pesquisar Posto
0. Voltar
```

---

# MENU COMPONENTES

```text
1. Inserir Componente
2. Listar Componentes
3. Alterar Componente
4. Apagar Componente
5. Pesquisar Componente
6. Mover Componente
0. Voltar
```

---

# MENU OPERAÇÕES

```text
1. Criar Operação
2. Atualizar Operação
3. Listar Operações
4. Pesquisar Operações
5. Operações Pendentes
6. Operações Concluídas
0. Voltar
```

---

# MENU CONSULTAS E ESTATÍSTICAS

```text
1. Componentes por Posto
2. Componentes em Garantia
3. Operações Pendentes
4. Operações Concluídas
5. Empresas Mais Utilizadas
6. Operações por Empresa
7. Operações por Funcionário
0. Voltar
```

---

# 8. ETAPA 3 — GESTÃO DE EMPRESAS

## Dependências

Nenhuma.

---

## Funções obrigatórias

```c
inserirEmpresa();
listarEmpresas();
pesquisarEmpresa();
alterarEmpresa();
apagarEmpresa();
buscarEmpresaPorId();
```

---

# FLUXO — INSERIR EMPRESA

## O sistema deve pedir

- Nome
- Tipo da empresa
- Contacto

---

## Validações

- Nome não vazio
- Contacto válido
- Tipo válido

---

## Depois

- Adicionar no array
- Incrementar contador
- Salvar no ficheiro

---

# RESULTADO ESPERADO

```text
Empresa criada com sucesso.
```

---

# 9. ETAPA 4 — GESTÃO DE FUNCIONÁRIOS

## Dependências

Nenhuma.

---

## Funções obrigatórias

```c
inserirFuncionario();
listarFuncionarios();
pesquisarFuncionario();
alterarFuncionario();
apagarFuncionario();
buscarFuncionarioPorId();
```

---

# FLUXO — INSERIR FUNCIONÁRIO

## O sistema deve pedir

- Nome
- Função
- Descrição

---

## Validações

- Nome não vazio
- Função não vazia

---

## Depois

- Adicionar no array
- Incrementar contador
- Salvar no ficheiro

---

# 10. ETAPA 5 — GESTÃO DE POSTOS

## Dependências

- Funcionários

---

## Funções obrigatórias

```c
inserirPosto();
listarPostos();
pesquisarPosto();
alterarPosto();
apagarPosto();
buscarPostoPorId();
```

---

# FLUXO — INSERIR POSTO

## O sistema deve pedir

- Nome
- Local
- Secção
- Descrição

---

## Depois

O sistema deve:

- listar funcionários
- pedir ID do funcionário responsável

---

## Validações

- Funcionário existe
- Campos não vazios

---

## Depois

- Adicionar no array
- Incrementar contador
- Salvar no ficheiro

---

# 11. ETAPA 6 — GESTÃO DE COMPONENTES

## Dependências

- Empresas
- Postos

---

## Funções obrigatórias

```c
inserirComponente();
listarComponentes();
pesquisarComponente();
alterarComponente();
apagarComponente();
moverComponente();
buscarComponentePorId();
```

---

# FLUXO — INSERIR COMPONENTE

## O sistema deve pedir

- Designação
- Número de série
- Data de aquisição
- Data da garantia
- Tipo do componente
- Condição
- Observação

---

## Depois

O sistema deve:

- listar empresas
- pedir ID do fornecedor
- pedir ID do fabricante

---

## Depois

O sistema deve:

- listar postos
- pedir ID do posto

---

## Validações

- Número de série não duplicado
- Fornecedor existe
- Fabricante existe
- Posto existe
- Campos obrigatórios preenchidos

---

## Depois

- Adicionar no array
- Incrementar contador
- Salvar no ficheiro

---

# FLUXO — MOVER COMPONENTE

## O sistema deve pedir

- ID do componente

---

## Depois

O sistema deve:

- listar postos
- pedir novo posto

---

## Validações

- Componente existe
- Posto existe

---

## Depois

```c
componentes[i].id_posto_trabalho = novo_id;
```

---

# 12. ETAPA 7 — GESTÃO DE OPERAÇÕES

## Dependências

- Empresas
- Funcionários
- Postos
- Componentes

---

## Objetivo

Gerir processos completos:

- garantia
- reparação
- abatimento
- transferência

---

## Funções obrigatórias

```c
criarOperacao();
atualizarOperacao();
listarOperacoes();
pesquisarOperacoes();
listarPendentes();
listarConcluidas();
buscarOperacaoPorId();
```

---

# FLUXO — CRIAR OPERAÇÃO

## O sistema deve pedir

- Tipo do processo
- ID do componente
- ID da empresa
- ID do posto
- ID do funcionário
- Número do documento interno
- Número do documento externo
- Data de saída
- Data prevista
- Montante
- Observação

---

## O sistema deve listar

- Componentes
- Empresas
- Funcionários
- Postos

---

## Estado inicial

```text
Status = EM_ANDAMENTO
```

---

## Validações

- Componente existe
- Empresa existe
- Funcionário existe
- Posto existe
- Datas válidas

---

## Depois

- Adicionar operação
- Salvar no ficheiro

---

# FLUXO — ATUALIZAR OPERAÇÃO

## O sistema deve pedir

- ID da operação

---

## O sistema deve permitir

- Atualizar status
- Adicionar data de conclusão
- Atualizar observação

---

## Regras importantes

### Reparação/Garantia

Pode:

- ter data prevista
- ter data conclusão

---

### Abatimento

Não precisa:

- data prevista
- data conclusão

---

## Quando concluir operação

```text
Status = CONCLUIDO
```

---

# 13. ETAPA 8 — PERSISTÊNCIA EM FICHEIROS

## Objetivo

Guardar e carregar dados automaticamente.

---

## Ficheiros sugeridos

```text
empresas.dat
funcionarios.dat
postos.dat
componentes.dat
operacoes.dat
```

---

## Funções obrigatórias

```c
salvarEmpresas();
carregarEmpresas();

salvarFuncionarios();
carregarFuncionarios();

salvarPostos();
carregarPostos();

salvarComponentes();
carregarComponentes();

salvarOperacoes();
carregarOperacoes();
```

---

# Regras importantes

## Ao iniciar o programa

Deve:

```text
Carregar todos os ficheiros.
```

---

## Ao alterar dados

Deve:

```text
Salvar imediatamente.
```

---

# 14. ETAPA 9 — CONSULTAS E ESTATÍSTICAS

## Funções obrigatórias

```c
componentesPorPosto();
operacoesPendentes();
operacoesConcluidas();
empresasMaisUtilizadas();
operacoesPorFuncionario();
operacoesPorEmpresa();
```

---

# EMPRESAS MAIS UTILIZADAS

## Lógica

- Percorrer operações
- Contar quantas vezes cada empresa aparece
- Mostrar ranking

---

# COMPONENTES POR POSTO

## Lógica

- Listar componentes agrupados por posto

---

# OPERAÇÕES PENDENTES

## Lógica

Mostrar:

```text
Status != CONCLUIDO
```

---

# 15. ETAPA 10 — TESTES E INTEGRAÇÃO

## Objetivo

Garantir estabilidade do sistema.

---

## Deve ser testado

### Empresas

- Inserção
- Alteração
- Remoção
- Pesquisa

---

### Funcionários

- Inserção
- Alteração
- Remoção
- Pesquisa

---

### Postos

- Relação com funcionário

---

### Componentes

- Relação com empresas
- Relação com postos
- Movimentação

---

### Operações

- Criação
- Atualização
- Conclusão
- Pesquisa

---

### Ficheiros

- Salvar corretamente
- Carregar corretamente
- Persistência após fechar programa

---

# 16. BOAS PRÁTICAS DA EQUIPA

## Antes de começar

```bash
git pull origin main
```

---

## Depois de terminar

```bash
git add .
git commit -m "mensagem"
git push origin branch
```

---

# REGRAS IMPORTANTES

- Não alterar código de outro membro sem avisar
- Testar antes de fazer push
- Manter nomes padronizados
- Não duplicar funções
- Fazer commits pequenos e organizados

---

# 17. CONCLUSÃO

A implementação correta do sistema depende:

- da ordem correta das etapas
- da comunicação da equipa
- da consistência dos menus
- da validação dos relacionamentos
- da persistência correta dos dados

Este documento deve servir como guia principal do desenvolvimento do projeto.

