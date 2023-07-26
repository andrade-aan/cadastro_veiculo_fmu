/*
CURSO: Bacharelado em Ciência da Computação (110059)
DISCIPLINA: (222RGR3342A) Técnicas de Programação

RA:
E-MAIL:
TURMA: BLOCO_01
PERÍODO LETIVO: 2022-2
DATA: NOVEMBRO/2022

Código em Linguagem C desenvolvido para a ATIVIDADE 1

Sistema Operacional Windows

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <locale.h>

#define TAM_MAXIMO 10 // definição de constante como máximo

// Criaçao da Struct para agrupar e armazenar os dados

typedef struct{
    int codigoUnicoRenavam;
    char marcaVeiculo[20];
    char modeloVeiculo[20];
    int anoVeiculo;
    int controle;
}Veiculos;

// Criação do vetor para struct e variáveis globais

Veiculos veiculos[TAM_MAXIMO];
int opcao;

//veiculos[0].anoVeiculo = '2023';
//veiculos[0].marcaModelo "HONDA";
//veiculos[0].codigoUnicoRenavam = 2602;
//veiculos[0].modeloVeiculo = "CIVIC TYPE-R";

// Declaração dos protótipos dos procedimentos e funções

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

    setlocale(LC_ALL,"Portuguese"); // definição caracteres especiais
    system("cls");
    do {

        //system("cls");
        opcao=0;
        printf("========== Cadastro de Veículos ===============\n");
        printf("1 - Cadastrar Novo Veículo\n");
        printf("2 - Listar Veículos Cadastrados\n");
        printf("3 - Consultar Veículos por Ano\n");
        printf("4 - Consultar Veículos por Modelo\n");
        printf("5 - Exluir Veículos do Cadastro\n");
        printf("999 - Sair\n");
        printf("===============================================\n");
        scanf("%d",&opcao);
        getchar();

        switch (opcao){

        case 1:
            system("cls");
            printf("=======================\n");
            printf("   CADASTRAR VEÍCULO\n");
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
            printf("CONSULTAR Veículos por Ano\n");
            printf("==========================\n");
            consultarAno();
            break;

        case 4:
            system("cls");
            printf("=============================\n");
            printf("PESQUISAR Veículos por Modelo\n");
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
//     INÍCIO FUNÇOES E PROCEDIMENTOS
//  ------------------------------------


//  -- Procedimento para CADASTRAR Veículos --


void cadastroVeiculos(){

    system("cls");

    int codigoUnicoRenavam;
    char marcaVeiculo[20];
    char modeloVeiculo[20];
    int anoVeiculo;
    int maximo;

    do{

        printf("Entre com o Código RENAVAM do Veículo:\n");
        scanf("%d", &codigoUnicoRenavam);
        fflush(stdin);//getchar();

        printf("Entre com os dados MARCA do Veículo:\n");
        fgets(marcaVeiculo,sizeof(marcaVeiculo),stdin);//scanf("%s",marcaModelo[linha]);//scanf("%15[^\n]s",marcaModelo[linha]);
        fflush(stdin);

        printf("Entre com os dados Modelo do Veículo:\n");
        fgets(modeloVeiculo,sizeof(modeloVeiculo),stdin);//scanf("%s",marcaModelo[linha]);//scanf("%15[^\n]s",marcaModelo[linha]);
        fflush(stdin);

        printf("Entre com o ano de fabricação do Veículo - 4 dígitos:\n");
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
                    printf("LIMITE DO BANCO DE DADOS ATINGIDO!!!\n\nCADASTRO NÃO REALIZADO!!\n\nEXCLUA ALGUM CADASTRO!!\n\n");
                    opcao=2;
                    break;
                }
        } // for de controle do tamanho máximo de cadastros

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


//  -- Procedimento para LISTAR Veículos --

void listarVeiculos(){

    int verificacao = TAM_MAXIMO;
    int i = 0;
    int maximo;

    do {
        for(i = 0; i < TAM_MAXIMO; i++){
                maximo = maximo + veiculos[i].controle;
            if (veiculos[i].controle != 0 ){ //CONDIÇÃO PARA EXCLUIR DA LISTAGEM
                //verificacao = 0;      //ITENS NULOS - LISTAR SÓ CADASTRADOS
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
                    printf("LIMITE DO BANCO DE DADOS ATINGIDO!!! NÃO É POSSIVEL CADASTRAR!!");
                    verificacao=0;
                }else{
                    verificacao --;
                }

            }
        }
       // }
    }while(verificacao != 0);

}; // FIM void listarVeiculos();


//  -- Procedimento para EXCLUIR Veículos --

void excluirVeiculo(){

    system("cls");

    int cadastroNumero;
    char vazio[20];

    listarVeiculos();

    printf("Digite o NUMERO DO CADASTRO do Veículo a ser REMOVIDO:\n");
    scanf("%d", &cadastroNumero);
    getchar();
    cadastroNumero--;

    printf("Digite novamente o NUMERO DO CADASTRO para confirmar a EXCLUSÃO do VEÍCULO de RENAVAM %d\n",veiculos[(cadastroNumero)].codigoUnicoRenavam);
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
        printf("EXCLUSÃO CANCELADA!!\n\n");
        opcao = 0;
    }

};


//  -- Procedimento para CONSULTAR Veículos ANO --

void consultarAno(){

    int ano;
    system("cls");
    int controle = 999; // variavel de controle para ano inexistente

    do{
        printf("Digite o ano com 4 dígitos para a pesquisa\n");
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
                controle = 777; // caso ano cadastrado a variável troca de valor
            }
        }
        if (controle == 999){ //caso a variavel se mantenha = ano inexistente
            printf("Ano não encontrado!!!");
            printf("Digite 1 para realizar uma nova consulta ou outro valor para sair\n");
            scanf("%d", &opcao);
            fflush(stdin);
            system("cls");
        }else{ // variavel assume valor 777 e entra nessa condição de escolha
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
    scanf("%19s%*[^\n]",pesquisa);// fgets(pesquisa,20,stdin); não funcionou
    fflush(stdin);

//----------- transformar em Minúsculo/Maísculo
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
