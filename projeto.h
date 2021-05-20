#ifndef PROJETO_INCLUDED
#define PROJETO_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INDICADOR_CASES
#define INDICADOR_DEATHS

typedef struct info_var_node
{
    char indicador[6];
    int contagem_semanal;
    char ano_semana[8];
    double racio_14_dias;
    int conta_cumulativa;
    struct info_var_node *next_info_var;

} info_var_node;


typedef struct pais_node
{
    char nome_pais[100];
    char codigo_pais[3];
    char continente[7];
    int populacao;
    struct pais_node *next;
    struct info_var_node *head_info_var;

} pais_node;



void leFicheiro_Paises(char ficheiro_a_Ler[50]);
pais_node* adiciona_no_Fim_Pais(pais_node *head, pais_node *tail, char* nome[100], char* codigo[4], char* continente[7], int* populacao);
void adiciona_no_Fim_Info_Var(info_var_node *tail, info_var_node *head);
#endif //PROJETO INCLUDED