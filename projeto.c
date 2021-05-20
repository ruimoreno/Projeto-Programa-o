#include "projeto.h"

int nLinhasFicheiro = 0;
pais_node *head_listaPaises = NULL; 
pais_node *tail_lista_paises = NULL;


void leFicheiro_Paises(char *ficheiro_a_Ler){

    FILE * ficheiro;
    ficheiro = fopen(ficheiro_a_Ler, "r");
    if (ficheiro == NULL) {
        printf("O ficheiro não foi aberto com sucesso, a terminar o programa...");
        exit(-1);
    }

    char linhaDados[200];
    pais_node *head = NULL;
    char pais_atual[100] ;
    pais_atual[0] = '\0';
    int n_linha = 0;
    
     

    while(fgets(linhaDados, 200, ficheiro) != NULL)
    {
        char *obtemNomePais = strtok(linhaDados, ",");

        if((strcmp(pais_atual, obtemNomePais) != 0) && (n_linha != 0)){

            //============================== PAIS ===================================================

            pais_node *pais_a_inserir = malloc(sizeof(pais_node));
            
            strcpy(pais_a_inserir -> nome_pais, obtemNomePais);
            strcpy(pais_atual, obtemNomePais);

            char *obtemCodigo = strtok(NULL, ",");
            strcpy(pais_a_inserir -> codigo_pais, obtemCodigo);

            char *obtemContinente = strtok(NULL, ",");
            strcpy(pais_a_inserir -> continente, obtemContinente);

            char *obtemPopulacao = strtok(NULL, ",");
            int populacao;
            sscanf(obtemPopulacao, "%d", &populacao);
            //sprintf(populacao, "%d", pais_a_inserir->populacao); //transforma int em char
            //strcpy(populacao, obtemPopulacao);

            //====================== VARIÁVEL ========================================================================================

            info_var_node * info_var_inserir = malloc(sizeof(info_var_node));

            char *obtemIndicador = strtok(NULL, ",");
            strcopy(info_var_inserir -> indicador, obtemIndicador);

            char *obtemContagemSemanal = strtok(NULL, ",");
            int contagem_semanal;
            sscanf(obtemContagemSemanal, "%d", &contagem_semanal);

            char *obtemAnoSemana = strtok(NULL, ",");
            strcopy(info_var_inserir -> ano_semana, obtemAnoSemana);

            

            
            

            

            double *obtemRacio = strtok(NULL, ",");
            strcopy(info_var_inserir -> ano_semana, obtemAnoSemana);

            char *obtemContaCumulativa = strtok(NULL, ",");
            strcopy(info_var_inserir -> conta_cumulativa, obtemContaCumulativa);



            tail_lista_paises = adiciona_no_Fim_Pais(head_listaPaises, tail_lista_paises, obtemNomePais, obtemCodigo, obtemContinente, populacao);

        }
        else{
            
        }
        n_linha++;
    }
    //fclose(ficheiro_a_Ler);
}

pais_node* adiciona_no_Fim_Pais(pais_node *head, pais_node *tail, char* nome, char*codigo, char* continente, int populacao){
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
    temp -> populacao = populacao;
    temp -> next = NULL;

    return temp;
}

void adiciona_no_Fim_Info_Var(info_var_node *head, info_var_node *tail, char* indicador , int *contagem_semanal, char *ano_semana, double *racio_14, int *conta_cumulativa){
    info_var_node *temp_var = (info_var_node*)malloc(sizeof(info_var_node));
    if(tail != NULL){
        tail->next_info_var = temp_var;
    }
    else{
        head = temp_var;
    }
    tail = temp_var;
}

int main(){

    pais_node *head_listaPaises = NULL; 
    pais_node *tail_lista_paises = head_listaPaises;
    

    
    leFicheiro_Paises("dadosCovid.csv");
}