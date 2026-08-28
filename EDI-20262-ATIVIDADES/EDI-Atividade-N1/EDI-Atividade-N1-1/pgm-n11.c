/* - - - - - - - - -- - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - -- - - - - -*
* Disciplina : Estrutura de Dados *
* Prof . Verissimo *
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*
* Objetivo do Programa : Sistema de notas *
* Data - 20/08/2026 *
* Autor : Karen Luiza Marques *
* - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - -- - - - -*/

#include <stdio.h>
#define TAMANHO_TURMA 5
//define o tamanho da variavel

void exibirCabecalho(){
    printf("=================================\n");
    printf("SISTEMA DE NOTAS - TURMA ADS\n");
    printf("=================================\n");
}

float calcularMedia(float vetor[], int tamanho){
    float media=0;
    for(int i=0; i<tamanho; i++){
        media += vetor[i];
    }
    media = media/tamanho;
    //soma todas as notas dentro de um loop for
    //e divide pelo numero de alunos (tamanho)
    return media;
    //Não é necessário o uso de ponteiro pois em C um vetor já representa
    //o endereço do seu primeiro elemento.
}

float simularAjuste(float notaOriginal, float bonus){
    float notaSimulada = notaOriginal + bonus;
    printf("\nSimulação para o aluno 1: %.2f + %.2f = %.2f (nao aplicado ainda)", notaOriginal, bonus, notaSimulada);
    //usa a variavel nota simulada para receber a original mais o bonus
}

void aplicarBonus(float *nota, float bonus){
    //nota como ponteiro para acessar seu endereço e fazer mudanças lá
    *nota = *nota + bonus;
    //Conteudo de nota recebe o conteudo de nota mais o bonus
}

int main()
{
    float notas[TAMANHO_TURMA], bonus, mediaInicial, mediaFinal;
    int i;
    exibirCabecalho();
    
    for(i=0; i<TAMANHO_TURMA; i++){
        printf("\nNOTA DO ALUNO %d: ", i+1);
        scanf("%f", &notas[i]);
        //pega via teclado as notas dos alunos em um loop for
    }
    
    printf("Informe o valor do bonus a aplicar: ");
	scanf("%f", &bonus);
	//pega o valor do bonus
	
	printf("\n\n--- Media da turma antes do ajuste ---");
	mediaInicial = calcularMedia(notas, TAMANHO_TURMA);
	//chama a função e atribui o resultado a variavel mediaInicial
	printf("\nMedia inicial: %.2f\n", mediaInicial);
	
	
	printf("\n\n--- Simulação do ajuste (ajuste por valor) ---");
	simularAjuste(notas[0], bonus);
	//chama a função e usa a nota do primeiro aluno como parametro para a simulação
	printf("\nNota do aluno 1 apos a simulacao (inalterada): %.2f", notas[0]);
	
	printf("\n\n--- Aplicacao real do bonus (passagem por referencia) ---");
	for(i=0; i<TAMANHO_TURMA; i++){
	    aplicarBonus(&notas[i], bonus);
	}
	//aplica o bonus em um for, atribuindo o valor do bonus no endereço da variável usando &
	//no parametro da função, pois na construção da função foi usado ponteiro
	printf("\nBonus de %.2f aplicado a todas as notas da turma.", bonus);
	
	printf("\n\n--- Notas finais da turma ---");
	for (i=0; i<TAMANHO_TURMA; i++){
		printf("\nAluno %d: %.2f", i+1, notas[i]);
	}
	//imprime notas
    
    printf("\n\n--- Media da turma apos o ajuste ---");
	mediaFinal = calcularMedia(notas, TAMANHO_TURMA);
	printf("\nMedia final: %.2f", mediaFinal);
    //imprime media   

    return 0;
}