#include <stdio.h>
#include <stdlib.h>


char* getName () {

    return "Joao Fernando";
}

char* getMotherName () {

    return "Silvania";
}

char* getFatherName () {

    return "Luiz Fernando";
}

int main () {

    /*typedef struct st_Teste {
        char meu_nome[20]; // 20 bytes
        char nome_mae[20]; // 20 bytes
        char nome_pai[20]; // 20 bytes
        // int idade; // acrescenta 4 bytes no tamanho da struct

    } Teste; */

    // nao funciona pois o rvalue e const e na struct esta declarado um chat (e nao um const char)
    // t1.meu_nome = "Joao Fernando"; // aqui estamos declarando um array de char imutavel
    
    //printf("char[20]: %lu\n", sizeof(char[20]));
    //printf("t1 (3 char): %lu\n", sizeof(t1));

    typedef struct st_Teste {
        char nome[20];
        unsigned short int idade; 
        unsigned int cpf;
        unsigned int rg;
        // int idade; // acrescenta 4 bytes no tamanho da struct

    } Teste;

    typedef struct st_Teste_ints {
        double num1;
        double num2;
        double num3;
        double num4;

    } Teste_int;

    Teste t1;
    Teste *pTeste;
    pTeste = &t1;

    unsigned short int numGen = 12;
    void* pGen; // pode ser declarado um ponteiro generico, mas quando for acessado precisa ter typecast
    pGen = &numGen;

    printf("Digite seu nome: ");
    scanf("%s", t1.nome);

    printf("idade com ponteiro especifico: %d\n", pTeste->idade = 28);
    printf("idade (acesso direto a struct): %d\n", t1.idade);
    printf("numGen e (sem casting completo): %d\n", *((int*)pGen)); 
    // typecasting incompleto, pois esta sem os qualificadores. Imprimira um endereco ao inves do numero numGen
    printf("numGen e (com casting completo): %d\n", *((unsigned short int*)pGen)); 
    // pGen sera entendido como um endereco para um inteiro depois de (int*), entao sera necessario colocar *() no entorno para indicar o conteudo

    pGen = &t1;
    printf("nome (com casting usando struct) ponteiro generico: %s\n", ((Teste*)pGen)->nome);


    Teste_int Tint_1;
    Teste_int *pTeste_int;
    pTeste_int = &Tint_1;

    size_t size_T_int = sizeof(Tint_1)/sizeof(pTeste_int->num1);

    double* pInt = NULL;
    int cont = 0;

    for (pInt = &(pTeste_int->num1); pInt <= &(pTeste_int->num4); pInt++) {

        *pInt = cont;
        printf("Tint_1 num%d: %lf\n", cont+1, *(pInt));
        cont++;

    }

}