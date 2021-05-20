#include "projeto.h"

int nLinhasFicheiro = 0;
pais_node *head_listaPaises = NULL; 
pais_node *tail_lista_paises = NULL;


void leFicheiro_Paises(char ficheiro_a_Ler[50]){

    FILE * ficheiro;
    ficheiro = fopen(ficheiro_a_Ler, "r");
    if (ficheiro == NULL) {
        printf("O ficheiro não foi aberto com sucesso, a terminar o programa...");
        exit(-1);
    }

    char linhaDados[200];
    pais_node *head = NULL;
    char pais_atual[100] = "";

    while(fgets(linhaDados, 200, ficheiro) != NULL)
    {
        char *obtemNomePais = strtok(linhaDados, ",");

        if(pais_atual[0] == '0' || strcmp(pais_atual, obtemNomePais) != 0){

            pais_node *pais_a_inserir = malloc(sizeof(pais_node));

            char *obtemNomePais = strtok(linhaDados, ",");
            
            strcpy(pais_a_inserir -> nome_pais, obtemNomePais);
            pais_atual[100] = *obtemNomePais;

            char *obtemCodigo = strtok(NULL, ",");
            strcpy(pais_a_inserir -> codigo_pais, obtemCodigo);

            char *obtemContinente = strtok(NULL, ",");
            strcpy(pais_a_inserir -> continente, obtemContinente);

            char *obtemPopulacao = strtok(NULL, ",");
            char populacao[15];
            sprintf(populacao, "%d", pais_a_inserir->populacao); //transforma int em char
            strcpy(populacao, obtemPopulacao);

            tail_lista_paises = adiciona_no_Fim_Pais(head_listaPaises, tail_lista_paises, obtemNomePais, obtemCodigo, obtemContinente, obtemPopulacao);
            


        }
        else{
            //adicionar apenas informação variável
        }
    }
}

pais_node* adiciona_no_Fim_Pais(pais_node *head, pais_node *tail, char* nome[100], char* codigo[4], char* continente[7], int* populacao){
    pais_node *temp = (pais_node*)malloc(sizeof(pais_node));
    if(tail != NULL){
        tail->next = temp;
    }
    else{
        head = temp;

    }
    tail = temp;
    strcpy(temp -> nome_pais, nome);
    strcpy(temp -> codigo_pais, codigo);
    strcpy(temp -> continente, continente);
    strcpy(temp -> populacao, populacao);
    temp -> next = NULL;
    return temp;
}

void adiciona_no_Fim_Info_Var(info_var_node *tail, info_var_node *head){
    pais_node *temp = (info_var_node*)malloc(sizeof(info_var_node));
    if(tail != NULL){
        tail->next_info_var = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
}

int main(){

    pais_node *head_listaPaises = NULL; 
    pais_node *tail_lista_paises = head_listaPaises;
    leFicheiro_Paises("dadosCovid.csv");
}