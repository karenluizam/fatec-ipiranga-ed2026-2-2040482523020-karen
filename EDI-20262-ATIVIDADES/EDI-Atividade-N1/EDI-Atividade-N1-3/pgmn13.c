/* - - - - - - - - -- - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - -- - - - - -*
* Disciplina : Estrutura de Dados *
* Prof . Verissimo *
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*
* Objetivo do Programa : Sistema de Atendimento – Lava-Rápido Brilho Total *
* Data - 27/08/2026 *
* Autor : Karen Luiza Marques *
* - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - -- - - - -*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
char placa [8];
float valor ;
} Veiculo ;

#define VALOR_PREMIUM 100.0

void exibirCabecalho(void){
    printf("=================================\nLAVA - RAPIDO BRILHO TOTAL - FILA DE ATENDIMENTO\n=================================");
}
 
void preencherFrota(Veiculo *frota, int quantidade){
    for(int i=0; i<quantidade; i++){
        printf("Placa do veiculo %d: ", i+1);
        scanf("%s", (frota + i)->placa);
        printf("Valor do servico ( R$ ) : ");
        scanf("%f", &((frota + i)->valor));
    }
}

void exibirFrotaRecursivo(Veiculo *frota, int indice, int quantidade){
    
    if(indice == quantidade){
    //se o indice for igual a quantidade, nada é exibido    
    }else{
           
        printf("\n%i) Placa : %s | Valor : R$ %.2f ", indice+1, frota[indice].placa, frota[indice].valor);
        exibirFrotaRecursivo(frota, indice + 1, quantidade);
        
    }
}

float calcularValorTotalRecursivo(Veiculo *frota, int indice, int quantidade){
    
    if(indice==quantidade){
        return 0.0f; //caso base: se indice for igual a quatidade, retorna 0, pois os valores já foram todos somados
    }else{
        return frota[indice].valor + calcularValorTotalRecursivo(frota, indice + 1, quantidade);
        //se o indice for diferente da quantidade, ainda há valores a se somar, então pegamos o valor atual da frota e somamos ao valor do próximo.
    }
    
}

int buscarVeiculoRecursivo(Veiculo *frota, int indice, int quantidade, char placa[8]){
    int resultado;
    
    if(indice == quantidade){
        printf("Veiculo nao encontrado na frota.");
        return -1;
    }
    if(strcmp(frota[indice].placa, placa) == 0){
        printf("Veiculo encontrado na posicao %i! Placa : %s | Valor : R$ %.2f", indice+1, frota[indice].placa, frota[indice].valor);
        return indice;
    }
    
    return buscarVeiculoRecursivo(frota, indice+1, quantidade, placa);
}

int contarPremiumRecursivo(Veiculo *frota, int indice, int quantidade){
    if(indice == quantidade){
        return 0;
    }
    
    int premium=0;
    
    if(frota[indice].valor >= VALOR_PREMIUM){
        premium=1;
    }
    
    return premium + contarPremiumRecursivo(frota, indice+1, quantidade);
}

int main()
{
    int quantidade=0;
    float valor=0;
    exibirCabecalho();
    char placaProcurada[8];
    
    printf("\nQuantos veiculos serao atendidos hoje? ");
    scanf("%d", &quantidade);
    Veiculo *frota = (Veiculo*)malloc(quantidade*sizeof(Veiculo));
    //Inicializando o ponteiro frota do tipo Veiculo depois de atribuir a quantidade
    if(frota==NULL){
        exit(1);
        //Verificação de NULL depois de alocar a memória
    }
    
    preencherFrota(frota, quantidade);
    
    printf("\n--- Veiculos atendidos hoje ---");
    exibirFrotaRecursivo(frota, 0, quantidade);
    
    //valor = calcularValorTotalRecursivo(frota, 0, quantidade);
    
    printf("\n\n--- Busca recursiva por placa ---");
    printf("\nPlaca a ser pesquisada : ");
    scanf("%8s", &placaProcurada);
    
    buscarVeiculoRecursivo(frota, 0, quantidade, placaProcurada);
    
    printf("\n\n--- Resumo do dia ---");
    printf("\nTotal de veiculos atendidos : %i", quantidade);
    printf("\nServicos premium ( >= R$ 100.00) : %i", contarPremiumRecursivo(frota, 0, quantidade));
    printf("\nValor total arrecadado : R$ %.2f", calcularValorTotalRecursivo(frota, 0, quantidade));
    
    free(frota);
    frota = NULL;
    
    printf("\n\nMemoria da frota liberada com sucesso . Sistema encerrado .");
    return 0;
}
