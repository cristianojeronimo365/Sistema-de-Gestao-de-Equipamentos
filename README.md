# 📦 Sistema de Gestão de Equipamentos (XPTO Solutions)

## 👥 Equipa

Projeto desenvolvido por um grupo de 5 estudantes no âmbito da disciplina de Programação I.

---

## 📚 Índice

* [Sobre o Projeto](#-sobre-o-projeto)
* [Funcionalidades](#-funcionalidades)
* [Arquitetura](#-arquitetura)
* [Estrutura do Projeto](#-estrutura-do-projeto)
* [Compilação e Execução](#-compilação-e-execução)
* [Uso de Ficheiros](#-uso-de-ficheiros)
* [Git & Colaboração](#-git--colaboração)
* [Boas Práticas](#-boas-práticas)
* [Roadmap](#-roadmap)
* [Relatório](#-relatório)

---

## 🎯 Sobre o Projeto

Sistema em C para gestão de equipamentos numa empresa (XPTO Solutions), permitindo controlar componentes, funcionários, postos de trabalho, empresas e operações (entradas/saídas).

---

## ⚙️ Funcionalidades

### ✅ Requisitos Base

* CRUD: Inserir, Listar, Alterar, Apagar
* Pesquisa por ID e nome
* Gestão de operações (entrada/saída)
* Persistência em ficheiros binários

### 🚀 Requisitos Avançados

* Consistência entre entidades (IDs válidos)
* Substituição de componentes entre postos
* Estatísticas
* Pesquisa com wildcards (* e ?)

---

## 🧠 Arquitetura

Fluxo do sistema:

```
Início → Carregar ficheiros → Arrays em memória → CRUD → Guardar ficheiros → Fim
```

* Todos os dados são carregados para arrays de structs
* Operações são feitas em memória
* Dados são persistidos em ficheiros binários (.dat)

---

## 🏗️ Estrutura do Projeto

```
project/
│
├── src/
│   ├── main.c
│   ├── componentes.c
│   ├── funcionarios.c
│   ├── empresas.c
│   ├── postos.c
│   ├── operacoes.c
│   └── ficheiros.c
│
├── include/
│   └── sistema_gestao.h
│
├── data/
│   ├── componentes.dat
│   ├── funcionarios.dat
│   ├── empresas.dat
│   ├── postos.dat
│   └── operacoes.dat
│
├── Makefile
└── README.md
```

---

## ▶️ Compilação e Execução

### 🔹 Compilar

```
make
```

### 🔹 Executar

```
./sistema_gestao
```

---

## 💾 Uso de Ficheiros

### Abrir ficheiro

```c
FILE *f = fopen("data/componentes.dat", "rb");
```

### Ler

```c
fread(&componentes[i], sizeof(Componente), 1, f);
```

### Escrever

```c
fwrite(&componentes[i], sizeof(Componente), 1, f);
```

---

## 🔀 Git & Colaboração

### 🔹 Clonar o repositório

```
git clone <url-do-repo>
cd nome-do-repo
```

### 🔹 Criar uma branch

```
git checkout -b feature/nome-da-feature
```

### 🔹 Ver estado

```
git status
```

### 🔹 Adicionar alterações

```
git add .
```

### 🔹 Commit

```
git commit -m "descrição da alteração"
```

### 🔹 Enviar (push)

```
git push origin nome-da-branch
```

### 🔹 Atualizar (pull)

```
git pull origin main
```

### 🔹 Mudar de branch

```
git checkout main
```

### 🔹 Atualizar antes de trabalhar (IMPORTANTE)

```
git pull origin main
```

---

## 📌 Boas Práticas

* Usar IDs para relacionamentos
* Validar dados antes de inserir
* Fechar ficheiros (`fclose`)
* Código modular (.c e .h)
* Commits pequenos e descritivos

---

## 🗺️ Roadmap (2 semanas)

### Semana 1

* Estruturas de dados
* CRUD completo
* Operações
* Persistência

### Semana 2

* Consistência
* Pesquisa avançada
* Estatísticas
* Refinamento

---

## 📝 Relatório

Deve conter:

* Estruturas de dados
* Algoritmos principais
* Organização do código
* Decisões técnicas
* Fluxogramas

---

## 🔥 Nota Final

Este projeto utiliza ficheiros binários para garantir eficiência e integridade dos dados.

---

💻 "May The Code Be With You"
