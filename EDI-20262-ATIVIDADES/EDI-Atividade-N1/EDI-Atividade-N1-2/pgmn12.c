#include <stdio.h>
#define TAMANHO_ESTOQUE 5
#define ESTOQUE_MINIMO 10

int estoque[TAMANHO_ESTOQUE];

void exibirCabecalho(){
    printf("=================================\nSISTEMA DE ESTOQUE - LOJA CONSTRUMAIS\n=================================\n");
}

void preencherEstoque(){
    int *p = estoque;
    //ponteiro recebe endereço do começo do array estoque;
    
    for(int i=0; i<TAMANHO_ESTOQUE; i++){
        printf("Quantidade do produto %d:   ", i+1);
        scanf("%p",  &*(p+i));
        //o valor recebido por meio de digitação é atribuido a variável
        //para qual o ponteiro está apontando: estoque.
        //como estoque é um array, ele atribui o valor ao seu primeiro elemento
        //e vai incrementando o i para atribuir aos elementos subsequentes.
    }
}

void exibirEstoque(int momento){
    int *p = estoque;
    
    if(momento == 0){
        printf("\n-- Estoque atual (antes da reposição) --");
    }else{
        printf("\n\n-- Estoque final (apos reposição) --");
    }
    
    for(int i=0; i<TAMANHO_ESTOQUE; i++){
            printf("\nProduto %d:   %d unidades", i+1, *(p+i));
    }
}

float calcularMediaEstoque(){
    int *p = estoque;
    float mediaEstoque=0;
    
    for(int i=0; i<TAMANHO_ESTOQUE; i++){
        mediaEstoque += *(p+i);
    }
    //a diferença entre o p+i e o *(p+i) é que o p+i apenas pega o endereço da variável
    //e adiciona o tamanho de i, para ir para o próximo endereço do vetor.
    //Já *(p+i) também faz isso, mas o uso de * significa
    //que ele está acessando o valor implementado nesse endereço.
    
    return (mediaEstoque/TAMANHO_ESTOQUE);
}

void simularReposicao(int quantidadeAtual, int reposicao){
    int simulacao=0;
    
    simulacao = quantidadeAtual+reposicao;
    printf("\n\n–- Simulacao de reposicao (passagem por valor) –-");
    printf("\nSimulacao para o produto 1: %d + %d = %d (nao aplicado ainda)\n", quantidadeAtual, reposicao, simulacao);
}

void aplicarReposicaoGeral(int reposicao){
    int *p = estoque;
    printf("\n–- Aplicacao real da reposicao (ponteiro interno ao vetor global) –-\n");
    printf("Reposicao de %d unidades aplicada a todos os produtos do estoque.", reposicao);
    for(int i=0; i<TAMANHO_ESTOQUE; i++){
        *(p + i) += reposicao;
        //valor para o qual o ponteiro aponta recebe ele mesmo + valor de reposição
    }
}

void identificarEstoqueCritico(int minimo){
    int *p = estoque;
    int produtosCriticos=0;
    printf("\n\n–- Analise de estoque critico (minimo = %d unidades) –-\n", minimo);
    
    for(int i=0; i<TAMANHO_ESTOQUE; i++){
        if(*(p+i)<minimo){
            //se o valor apontado pelo ponteiro +i for menor que o minimo,
            printf("Produto %d esta em nivel critico:    %d unidades (abaixo do minimo)\n", i+1, *(p+i));
            produtosCriticos++;
            //o estoque é apontado como crítico e a variável produtosCriticos é incrementada.
        }
    }
    if(produtosCriticos==0){
        //caso a variável produtosCriticos não tenha sido incrementada,
        printf("Estoque regularizado");
        //o estoque está regular
    }  
        
}


int main()
{
    int i;
    int momento = 0;
    //momento recebe 0 pois é o momento inicial do estoque
    int reposicao;
    float media;
    
    
    exibirCabecalho();
    preencherEstoque();
    
    printf("Quantidade de reposicao a aplicar:  ");
    scanf("%d", &reposicao);
    
    exibirEstoque(momento);
    int quantidade=estoque[0];
    //variável recebe valor do primeiro elemento do array estoque
    simularReposicao(quantidade, reposicao);
    printf("Quantidade do produto 1 apos a simulacao (inalterada):  %d\n", estoque[0]);
    
    aplicarReposicaoGeral(reposicao);
    momento = 1;
    //momento recebe 1 pois chegamos ao momento final do estoque.
    exibirEstoque(momento);
    
    media = calcularMediaEstoque();
    printf("\n\n–- Media geral do estoque –-");
    printf("\nMedia final:   %.2f unidades", media);
    
    identificarEstoqueCritico(ESTOQUE_MINIMO);
    
    

    return 0;
}
