void leFicheiro_Paises_Continente(char *ficheiro_a_Ler){

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
    char nome_do_continente[] = "Europe";
    printf("\nNome do Continente: %s\n", nome_do_continente);
    while(fgets(linhaDados, 200, ficheiro) != NULL)
    {
        char *obtemNomePais = strtok(linhaDados, ",");

        if((strcmp(pais_atual, obtemNomePais) != 0) && (n_linha != 0)){

            //============================== PAIS ===================================================

            pais_node *pais_a_inserir = malloc(sizeof(pais_node));
            
            char *obtemCodigo = strtok(NULL, ",");
            
            char *obtemContinente = strtok(NULL, ",");
            
            
            if(!strcmp(obtemContinente, nome_do_continente)){
                strcpy(pais_a_inserir -> nome_pais, obtemNomePais);
                strcpy(pais_atual, obtemNomePais);
                strcpy(pais_a_inserir -> codigo_pais, obtemCodigo);
                strcpy(pais_a_inserir -> continente, obtemContinente);
                char *obtemPopulacao = strtok(NULL, ",");
                int populacao;
                sscanf(obtemPopulacao, "%d", &populacao);
                printf("\nNome do País:%s \nCódigo:%s\n", pais_a_inserir->nome_pais, pais_a_inserir->codigo_pais);
            }
        }
        else{
            
        }
        n_linha++;
    }
    //fclose(ficheiro_a_Ler);
}