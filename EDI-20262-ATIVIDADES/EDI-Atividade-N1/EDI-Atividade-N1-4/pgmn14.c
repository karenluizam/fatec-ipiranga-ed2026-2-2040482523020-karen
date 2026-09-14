/*----------------------------------------------------------------------------------*/
/*                                FATEC-Ipiranga                                    */        
/*                            ADS - Estrutura de Dados                              */
/*                             Id da Atividade: N1-4                                */
/*    Objetivo: Utilizar estrutura de dados do tipo Fila Dinâmica Encadeada em C    */
/*                                                                                  */
/*                                  Autor: Karen Luiza Marques                      */
/*                                                                   Data:14/09/2026*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int id;
    char nome[50];
    struct no *prox;
} No;

typedef No* NoPtr;

typedef struct {
    NoPtr ini;
    NoPtr fim;
} Cabecalho;

typedef Cabecalho* Fila;

Fila Criar() {
    Fila f = (Fila) malloc(sizeof(Cabecalho));
    if (f != NULL) {
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int inserir(Fila f, int id, const char *nome) {
    NoPtr novo = (NoPtr) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->prox = NULL;

    if (f->ini == NULL) {
        f->ini = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return 1;
}

int filaVazia(Fila f){
    if (f == NULL || f->ini == NULL) {
        return 1;
    }
    return 0;
}

void listarFila(Fila f) {
    if(filaVazia(f)){
        printf("\n[AVISO] A fila já esta vazia .\n");
        return;
    }
    NoPtr atual = f->ini;
    printf("\n=== FILA DE PACIENTES ===\n");
    while (atual != NULL) {
        printf("ID: %d - Nome: %s\n", atual->id, atual->nome);
        atual = atual->prox;
    }
    printf("=========================\n");
}

void desenfileirar(Fila f) {
    if (filaVazia(f)) {
        printf("\n[AVISO] A fila esta vazia. Nenhum paciente para atender.\n");
        return;
    }
    NoPtr aux = f->ini;

    //Imprime os dados do paciente que está sendo atendido
    printf("\n====================================");
    printf("\n=== PACIENTE EM ATENDIMENTO ===\n");
    printf(">> ID: %d\n", aux->id);
    printf(">> Nome: %s\n", aux->nome);
    printf("====================================\n");
    f->ini = f->ini->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(aux);
}

void consultarProximo(Fila f){
    if(filaVazia(f)){
        printf("\n[AVISO] A fila já esta vazia .\n");
        return;
    }
    
    NoPtr atual = f->ini;
    printf("\n=== PRÓXIMO PACIENTE ===\n");
    printf("ID: %d - Nome: %s\n", atual->id, atual->nome);
    printf("=========================\n");
}

void tamanhoFila(Fila f){
    if(filaVazia(f)){
        printf("\n[AVISO] A fila já esta vazia .\n");
        return;
    }
    NoPtr atual = f->ini;
    int quantidade=0;
    printf("\n=== TAMANHO DA FILA ===\n");
    while (atual != NULL) {
        quantidade++;
        atual = atual->prox;
    }
    printf(">> %d pacientes aguardando atendimento.\n", quantidade);
    printf("=========================\n");
}


void esvaziaFila(Fila f){
    if(filaVazia(f)){
        printf("\n[AVISO] A fila já esta vazia .\n");
        return;
    }
    
    NoPtr atual = f->ini;
    NoPtr aux;


    while (atual != NULL) {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }

    // Atualiza o cabeçalho para indicar que a fila está vazia
    f->ini = NULL;
    f->fim = NULL;

    printf("\n>> Todos os pacientes foram removidos, e a fila foi esvaziada com sucesso!\n");
}


int main() {
    Fila filaAtendimento = Criar();
    int opcao, id;
    char nome[50];

    do {
        printf("\n--- SISTEMA HOSPITALAR (FATEC IPIRANGA) ---\n");
        printf("1. Chegada de Paciente (Inserir na Fila)\n");
        printf("2. Listar Fila de Pacientes\n");
        printf("3. Atendimento de paciente (Remover da Fila)\n");
        printf("4. Consultar próximo paciente da Fila\n");
        printf("5. Consultar tamanho da Fila\n");
        printf("6. Esvaziar Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Informe o ID do paciente: \n");
                scanf("%d", &id);
                getchar(); // Limpar buffer do teclado
                printf("Informe o Nome do paciente: \n");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remover quebra de linha

                if (inserir(filaAtendimento, id, nome)) {
                    printf(">> Paciente inserido com sucesso !\n");
                } else {
                    printf(">> Erro ao inserir paciente .\n");
                }
                break;
            case 2:
                listarFila(filaAtendimento);
                break;
            case 3:
                desenfileirar(filaAtendimento);
                break;
            case 4:
                consultarProximo(filaAtendimento);
                break;
            case 5:
                tamanhoFila(filaAtendimento);
                break;
            case 6:
                esvaziaFila(filaAtendimento);
                break;
            case 0:
                printf("Encerrando o sistema ...\n");
                break;
            default:
                printf("Opcao invalida !\n");
        }
    } while (opcao != 0);

    return 0;
}