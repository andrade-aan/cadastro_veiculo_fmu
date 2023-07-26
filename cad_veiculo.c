/*
CURSO: Bacharelado em Ci�ncia da Computa��o (110059)
DISCIPLINA: (222RGR3342A) T�cnicas de Programa��o

RA:
E-MAIL:
TURMA: BLOCO_01
PER�ODO LETIVO: 2022-2
DATA: NOVEMBRO/2022

C�digo em Linguagem C desenvolvido para a ATIVIDADE 1

Sistema Operacional Windows

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <locale.h>

#define TAM_MAXIMO 10 // defini��o de constante como m�ximo

// Cria�ao da Struct para agrupar e armazenar os dados

typedef struct{
    int codigoUnicoRenavam;
    char marcaVeiculo[20];
    char modeloVeiculo[20];
    int anoVeiculo;
    int controle;
}Veiculos;

// Cria��o do vetor para struct e vari�veis globais

Veiculos veiculos[TAM_MAXIMO];
int opcao;

//veiculos[0].anoVeiculo = '2023';
//veiculos[0].marcaModelo "HONDA";
//veiculos[0].codigoUnicoRenavam = 2602;
//veiculos[0].modeloVeiculo = "CIVIC TYPE-R";

// Declara��o dos prot�tipos dos procedimentos e fun��es

void cadastroVeiculos();
void listarVeiculos();
void consultarAno();
void consultarModelo();
void excluirVeiculo();
void limpa_linha();

//  -------------------------------------
//              INICIO MAIN
//  -------------------------------------

int main(){

    setlocale(LC_ALL,"Portuguese"); // defini��o caracteres especiais
    system("cls");
    do {

        //system("cls");
        opcao=0;
        printf("========== Cadastro de Ve�culos ===============\n");
        printf("1 - Cadastrar Novo Ve�culo\n");
        printf("2 - Listar Ve�culos Cadastrados\n");
        printf("3 - Consultar Ve�culos por Ano\n");
        printf("4 - Consultar Ve�culos por Modelo\n");
        printf("5 - Exluir Ve�culos do Cadastro\n");
        printf("999 - Sair\n");
        printf("===============================================\n");
        scanf("%d",&opcao);
        getchar();

        switch (opcao){

        case 1:
            system("cls");
            printf("=======================\n");
            printf("   CADASTRAR VE�CULO\n");
            printf("=======================\n");
            cadastroVeiculos();// CHAMADA DO PROCEDIMENTO CADASTRO
            break;

        case 2:
            system("cls");
            listarVeiculos(); // PROCEDIMENTO LISTAR VEICULOS
            break;

        case 3:
            system("cls");
            printf("==========================\n");
            printf("CONSULTAR Ve�culos por Ano\n");
            printf("==========================\n");
            consultarAno();
            break;

        case 4:
            system("cls");
            printf("=============================\n");
            printf("PESQUISAR Ve�culos por Modelo\n");
            printf("=============================\n");
            consultarModelo();
            break;

        case 5:
            system("cls");
            excluirVeiculo();
            break;

        default:
            system("cls"); // limpa a tela no Windows
            //printf("Opcao Invalida!!!\n");
        }
    }
    while (opcao!=999);


    return 0;

} //fechamento main


//  ------------------------------------
//              FIM MAIN
//  ------------------------------------


//  ------------------------------------
//     IN�CIO FUN�OES E PROCEDIMENTOS
//  ------------------------------------


//  -- Procedimento para CADASTRAR Ve�culos --


void cadastroVeiculos(){

    system("cls");

    int codigoUnicoRenavam;
    char marcaVeiculo[20];
    char modeloVeiculo[20];
    int anoVeiculo;
    int maximo;

    do{

        printf("Entre com o C�digo RENAVAM do Ve�culo:\n");
        scanf("%d", &codigoUnicoRenavam);
        fflush(stdin);//getchar();

        printf("Entre com os dados MARCA do Ve�culo:\n");
        fgets(marcaVeiculo,sizeof(marcaVeiculo),stdin);//scanf("%s",marcaModelo[linha]);//scanf("%15[^\n]s",marcaModelo[linha]);
        fflush(stdin);

        printf("Entre com os dados Modelo do Ve�culo:\n");
        fgets(modeloVeiculo,sizeof(modeloVeiculo),stdin);//scanf("%s",marcaModelo[linha]);//scanf("%15[^\n]s",marcaModelo[linha]);
        fflush(stdin);

        printf("Entre com o ano de fabrica��o do Ve�culo - 4 d�gitos:\n");
        scanf("%d", &anoVeiculo);
        fflush(stdin);

        printf("Digite 1 para realizar um novo cadastro ou qualquer outro valor para sair\n");
        scanf("%d", &opcao);
        fflush(stdin);

        system("cls");

        maximo = 0;

        for (int j = 0; j < TAM_MAXIMO; j++){
            maximo = maximo + veiculos[j].controle;
            if (maximo == TAM_MAXIMO){
                    printf("LIMITE DO BANCO DE DADOS ATINGIDO!!!\n\nCADASTRO N�O REALIZADO!!\n\nEXCLUA ALGUM CADASTRO!!\n\n");
                    opcao=2;
                    break;
                }
        } // for de controle do tamanho m�ximo de cadastros

        for(int i = 0; i < TAM_MAXIMO; i++){

            if (veiculos[i].controle == 0){

                veiculos[i].codigoUnicoRenavam = codigoUnicoRenavam;
                veiculos[i].anoVeiculo = anoVeiculo;
                veiculos[i].controle = 1;
                strcpy(veiculos[i].marcaVeiculo, marcaVeiculo);
                strcpy(veiculos[i].modeloVeiculo, modeloVeiculo);

                break;
                }

        }

    }while (opcao==1);

}; //FIM void cadastrarVeiculos();


//  -- Procedimento para LISTAR Ve�culos --

void listarVeiculos(){

    int verificacao = TAM_MAXIMO;
    int i = 0;
    int maximo;

    do {
        for(i = 0; i < TAM_MAXIMO; i++){
                maximo = maximo + veiculos[i].controle;
            if (veiculos[i].controle != 0 ){ //CONDI��O PARA EXCLUIR DA LISTAGEM
                //verificacao = 0;      //ITENS NULOS - LISTAR S� CADASTRADOS
           // }else{
                printf("=================================\n");
                printf("CADASTRO:\t%d\n", (i+1));
                printf("RENAVAN:\t%d\n", veiculos[i].codigoUnicoRenavam);
                printf("MARCA:\t\t%s\n", strtok(veiculos[i].marcaVeiculo,"\n"));
                printf("MODELO:\t\t%s\n", strtok(veiculos[i].modeloVeiculo,"\n"));
                printf("ANO:\t\t%d\n", veiculos[i].anoVeiculo);
                printf("=================================\n\n");

                verificacao --;


            }else{
                if (maximo == TAM_MAXIMO){
                    printf("LIMITE DO BANCO DE DADOS ATINGIDO!!! N�O � POSSIVEL CADASTRAR!!");
                    verificacao=0;
                }else{
                    verificacao --;
                }

            }
        }
       // }
    }while(verificacao != 0);

}; // FIM void listarVeiculos();


//  -- Procedimento para EXCLUIR Ve�culos --

void excluirVeiculo(){

    system("cls");

    int cadastroNumero;
    char vazio[20];

    listarVeiculos();

    printf("Digite o NUMERO DO CADASTRO do Ve�culo a ser REMOVIDO:\n");
    scanf("%d", &cadastroNumero);
    getchar();
    cadastroNumero--;

    printf("Digite novamente o NUMERO DO CADASTRO para confirmar a EXCLUS�O do VE�CULO de RENAVAM %d\n",veiculos[(cadastroNumero)].codigoUnicoRenavam);
    scanf("%d", &opcao);
    getchar;


    if (opcao - 1 == cadastroNumero){

        veiculos[cadastroNumero].anoVeiculo = 0;
        veiculos[cadastroNumero].codigoUnicoRenavam = 0;
        veiculos[cadastroNumero].controle = 0;
        strcpy(veiculos[cadastroNumero].marcaVeiculo, vazio);
        strcpy(veiculos[cadastroNumero].modeloVeiculo, vazio);

        printf("CADASTRO %d EXCLUIDO COM SUCESSO!!\n\n", cadastroNumero+1);
        opcao = 0;

    }else{
        printf("EXCLUS�O CANCELADA!!\n\n");
        opcao = 0;
    }

};


//  -- Procedimento para CONSULTAR Ve�culos ANO --

void consultarAno(){

    int ano;
    system("cls");
    int controle = 999; // variavel de controle para ano inexistente

    do{
        printf("Digite o ano com 4 d�gitos para a pesquisa\n");
        scanf("%d", &ano);
        fflush(stdin);

        for (int i = 0; i<TAM_MAXIMO; i++){
            if (ano == veiculos[i].anoVeiculo){
                printf("======= CADASTRO %d =========\n",(i+1));
                printf("RENAVAM:\t%d\n", veiculos[i].codigoUnicoRenavam);
                printf("MARCA:\t\t%s\n",strtok(veiculos[i].marcaVeiculo,"\n"));
                printf("MODELO:\t\t%s\n",strtok(veiculos[i].modeloVeiculo,"\n"));
                printf("ANO:\t\t%d\n",veiculos[i].anoVeiculo);
                printf("=============================\n");
                controle = 777; // caso ano cadastrado a vari�vel troca de valor
            }
        }
        if (controle == 999){ //caso a variavel se mantenha = ano inexistente
            printf("Ano n�o encontrado!!!");
            printf("Digite 1 para realizar uma nova consulta ou outro valor para sair\n");
            scanf("%d", &opcao);
            fflush(stdin);
            system("cls");
        }else{ // variavel assume valor 777 e entra nessa condi��o de escolha
            printf("Digite 1 para realizar uma nova consulta ou outro valor para sair\n");
            scanf("%d", &opcao);
            fflush(stdin);
            system("cls");
        }

    }while(opcao == 1);
};

void consultarModelo(){

    char pesquisaMinusculo[20], pesquisaMaiusculo[20], pesquisa[20]={NULL}, vazio[20]={NULL};
    int i = 0, j = 0, h = 0, x = 0, tamanhoPesquisa, aM, bM;


    printf("Digite a MARCA ou MODELO para a consulta:\n");
    scanf("%19s%*[^\n]",pesquisa);// fgets(pesquisa,20,stdin); n�o funcionou
    fflush(stdin);

//----------- transformar em Min�sculo/Ma�sculo
    do{
        pesquisaMinusculo[i] = tolower(pesquisa[i]);
        i++;
    }while (pesquisa[i]!= '\0');

    do{
        pesquisaMaiusculo[j] = toupper(pesquisa[j]);
        j++;
    }while (pesquisa[j]!= '\0');
//------------

//------------ for usando do...while para MARCA
    do{

        tamanhoPesquisa = strlen(pesquisa);
        x = strncmp(pesquisa,veiculos[h].marcaVeiculo,tamanhoPesquisa);
        aM = strncmp(pesquisaMinusculo,veiculos[h].marcaVeiculo,tamanhoPesquisa);//Minusculo
        bM = strncmp(pesquisaMaiusculo,veiculos[h].marcaVeiculo,tamanhoPesquisa);//Maiusculo


        if ((x == 0) || (aM == 0) || (bM == 0)){

            printf("======= CADASTRO %d =========\n",(h+1));
            printf("RENAVAM:\t%d\n", veiculos[h].codigoUnicoRenavam);
            printf("MARCA:\t\t%s\n",strtok(veiculos[h].marcaVeiculo,"\n"));
            printf("MODELO:\t\t%s\n",strtok(veiculos[h].modeloVeiculo,"\n"));
            printf("ANO:\t\t%d\n",veiculos[h].anoVeiculo);
            printf("=============================\n");
            h++;

        }else{h++;}

    }while (h < 10);

    x = 0, aM = 0, bM = 0;

//--------------- for para pesquisa MODELO

    for (int y = 0; y < TAM_MAXIMO; y++){

        tamanhoPesquisa = strlen(pesquisa);
        x = strncmp(pesquisa,veiculos[y].modeloVeiculo,tamanhoPesquisa);
        aM = strncmp(pesquisaMinusculo,veiculos[y].modeloVeiculo,tamanhoPesquisa);//Minusculo
        bM = strncmp(pesquisaMaiusculo,veiculos[y].modeloVeiculo,tamanhoPesquisa);//Maiusculo

        if ((x == 0) || (aM == 0) || (bM == 0)){

            printf("======= CADASTRO %d =========\n",(y+1));
            printf("RENAVAM:\t%d\n", veiculos[y].codigoUnicoRenavam);
            printf("MARCA:\t\t%s\n",strtok(veiculos[y].marcaVeiculo,"\n"));
            printf("MODELO:\t\t%s\n",strtok(veiculos[y].modeloVeiculo,"\n"));
            printf("ANO:\t\t%d\n",veiculos[y].anoVeiculo);
            printf("=============================\n");
        }

    }


};

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}
