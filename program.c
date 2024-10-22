#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    /*
	// apresentação
	printf("Programa Lirio do vale");
    printf("\n");
	printf("V1.0\n");

	// Login 
	printf("Bem vindo ao login");
    printf("\n");
    printf("Escolha uma das opcoes abaixo:\n");
    printf("\n");

    inicio: // ponto de retorno GOTO;
    printf("\n");
    printf("1. Login\n");
    printf("2. Cadastrar\n");
    printf("3. Esqueci minha senha\n");
    printf("4. FECHAR\n");


    // variavel para login
    char login[10];
    char senha[10];
    int i; // VARIAVEM PARA ENTRAR NO IF DE ADM

    // opcoes do switch case
    int seleciona;
    printf("==> ");
    scanf("%d", &seleciona);

    if (seleciona == 4) // finalizar programa
    {
        printf("\n");
        printf("Finalizando programa...\n");
        exit(0);
    }
    switch (seleciona) {
    case 1:
        printf("Opcao 1 selecionada\n");
        printf("Login: ");
        scanf("%s", login); 
        printf("Senha: ");
        scanf("%s", senha);

        // TEMPORARIO => PARA ENTRAR NO IF DE ADM
        printf("adm: ");
        scanf("%d", &i);


        printf("\n");

        // Comparar strings ==> TROCAR POR BCO DE DADOS
        if (strcmp(login, "admin") == 0 && strcmp(senha, "admin") == 0) {
            printf("-------------------------------------------\n");
            printf("Bem-vindo usuario %s\n", login);
            printf("-------------------------------------------\n");
            system("pause");
            break;
        }
        else {
            printf("Login ou senha invalida, tente novamente.\n\n");
            goto inicio;
        }
        

    case 2:
        printf("Funcao de cadastro nao implementada ainda.\n");
        goto inicio;

    case 3:
        printf("Função de recuperação de senha não implementada ainda.\n");
        break;

    default:
        printf("\n");
        printf("Numero de selecao invalido!\n");
        printf("\n");
        system("pause");
        goto inicio;
    }
    */
    // encurtador ==> excluir esse bloco depois
    int i;
    printf("adm: ");
    scanf("%d", &i);

    // Inicio sistema ADM
    if (i == 1)
    {
      
        while (1)
        {
            printf("\n");
            printf("-------------------------------------------\n");
            printf("HORTIFRUTI LIRIO DO VALE\n");
            printf("PERFIL: ADM\n");
            printf("\n");
            printf("\n");

            printf("Escolha uma das opcoes abaixo: \n");
            printf("\n");
            printf("1. Estoque \n"); //printf(" modificar dados do estoque\n"); ==> dentro de estoque ----> 1. Visualizar ou 2. modificar (2 opçoes)
            printf("2. Cadatrar novos itens\n");
            printf("3. Lixeira\n");
            printf("4. SAIR DA CONTA\n");

            int seleciona1;
            printf("==> ");
            scanf("%d", &seleciona1);
            printf("\n");
            printf("\n");

            //ESTOQUE
            if (seleciona1 == 1)
            {
                Estoque_ADM();
                printf("\n");
                system("pause");
                
            }
            if (seleciona1 == 4)
            {
                printf("Saindo...\n");
                printf("\n");
                system("pause");
                return 0; // TEMPORARIO
                //goto inicio;
            }
           
        }

        printf("\n");

        printf("Saiu do loop"); //TEMPORARIO
        printf("\n");
        system("pause");


        printf("\n");
        printf("\n");





    }
    
	return 0;
}




int Estoque_ADM()
{   
    /* 
        'ADICIONAR PRODUTO' ENCERRA DEPOIS DE REGISTRADO O PRODUTO => arrumar
    */

    struct Produto {
        // Fruta
        int idF;
        char nomeF[20];
        int quantidadeF;
        float valorF;

        //Legume
        int idL;
        char nomeL[20];
        int quantidadeL;
        float valorL;
       
    };

    struct Produto* produtos = NULL; // Ponteiro para produtos
    int tamanho = 0; // Número de produtos inseridos
    int capacidade = 0;
    int opcao = 0;

    int tamanhoL = 0; // Número de produtos inseridos
    int capacidadeL = 0;

    while (1) {
        
        printf("\n");
        printf("________ESTOQUE________\n");
        printf("\n");
        printf("1. Adicionar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Voltar\n");
        printf("==> ");
        scanf("%d", &opcao);
        int frutaLegume;
        printf("\n");

        // lista de opcoes
        if (opcao == 1) {
            //adicionar produtos
            printf("\n");
            printf("\n");
            printf("_____NOVO PRODUTO AO ESTOQUE______");
            printf("\n");
            printf("\n");

            char addItem;
            do
            {
                //FRUTA
                if (tamanho == capacidade) {
                    capacidade = (capacidade == 0) ? 1 : capacidade * 2;  // Dobra a capacidade
                    struct Produto* temp = realloc(produtos, capacidade * sizeof(struct Produto));
                    if (temp == NULL) {
                        printf("Erro ao alocar memória!\n");
                        free(produtos);  // Libera a memória previamente alocada
                        return 1;  // Sai em caso de erro
                    }
                    produtos = temp;  // Atualiza o ponteiro
                }

                //LEGUMES
                if (tamanhoL == capacidadeL) {
                    capacidadeL = (capacidadeL == 0) ? 1 : capacidadeL * 2;  // Dobra a capacidade
                    struct Produto* temp = realloc(produtos, capacidadeL * sizeof(struct Produto));
                    if (temp == NULL) {
                        printf("Erro ao alocar memória!\n");
                        free(produtos);  // Libera a memória previamente alocada
                        return 1;  // Sai em caso de erro
                    }
                    produtos = temp;  // Atualiza o ponteiro
                }

                // Adiciona um novo produto
                struct Produto novoProduto;
                printf("Qual e o tipo do produto?\n");
                printf("\n");
                printf("1. Fruta\n");
                printf("2. Legume\n");
                printf("3. Voltar\n");

                printf("==> ");
                scanf("%d", &frutaLegume);


                if (frutaLegume == 1)
                {
                    novoProduto.idF = tamanho + 1;  // Define o ID automaticamente

                    printf("Nome do produto: ");
                    scanf(" %49[^\n]", novoProduto.nomeF);  // Lê o nome com espaços, até 49 caracteres

                    printf("Quantidade: ");
                    scanf("%d", &novoProduto.quantidadeF);

                    printf("Valor: ");
                    scanf("%f", &novoProduto.valorF);

                    // Adiciona o novo produto ao array
                    produtos[tamanho] = novoProduto;  // Copia os dados para o array
                    tamanho++;  // Incrementa o número de produtos
                    printf("\n");
                }
                else if (frutaLegume == 2)
                {
                    novoProduto.idL = tamanhoL + 1;  // Define o ID automaticamente

                    printf("Nome do produto: ");
                    scanf(" %20[^\n]", novoProduto.nomeL);  // Lê o nome com espaços, até 49 caracteres

                    printf("Quantidade: ");
                    scanf("%d", &novoProduto.quantidadeL);

                    printf("Valor: ");
                    scanf("%f", &novoProduto.valorL);

                    // Adiciona o novo produto ao array
                    produtos[tamanhoL] = novoProduto;  // Copia os dados para o array
                    tamanhoL++;  // Incrementa o número de produtos
                    printf("\n");
                }
                else if (frutaLegume == 3)
                {
                    printf("\n");
                    printf("Voltando ao estoque...\n");
                    printf("\n");
                    break;
                }
                else
                {
                    printf("\n");
                    printf("Digito invalido!\n");
                    printf("\n");
                    system("pause");
                }

                

                printf("\n");
                printf("Produto adicionado com sucesso!\n");
                printf("\n");
                printf("\n");
                printf("Gostaria de adicionar outro produto? (S/N): ");
                getchar();
                scanf("%c", &addItem);
                printf("\n");
                
            } while (addItem == 'S' || addItem == 's');
            
        }
        else if (opcao == 2) {
            // Lista de produtos
            printf("\n");
            printf("\n");
            printf("___________PRODUTOS EM ESTOQUE__________\n");
            printf("\n");
            printf("\n");
            
            while (1)
            {
                printf("\n");
                printf("Qual produto deseja acessar? \n");
                printf("1. Frutas\n");
                printf("2. Legumes\n");
                printf("3. Todos\n");
                printf("4. Voltar\n");
                printf("==> ");
                scanf("%d", &frutaLegume);

                printf("\n");
            
                if (frutaLegume == 1)
                {
                    printf("FRUTAS:\n");
                    printf("\n");
                    printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                    printf("________________________________________\n");

                    for (int i = 0; i < tamanho; i++) { // Lista todos os produtos
                        printf(" %d \t %-10s \t %d \t R$%.2f\n",
                            produtos[i].idF, produtos[i].nomeF, produtos[i].quantidadeF, produtos[i].valorF);
                    }
                    printf("\n");
                    printf("\n");
                    system("pause");
                }
                else if (frutaLegume == 2)
                {
                    printf("LEGUMES:\n");
                    printf("\n");
                    printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                    printf("________________________________________\n");
                    for (int i = 0; i < tamanho; i++) { // Lista todos os produtos
                        printf(" %d \t %-10s \t %d \t R$%.2f\n",
                            produtos[i].idL, produtos[i].nomeL, produtos[i].quantidadeL, produtos[i].valorL);
                    }
                    printf("\n");
                    printf("\n");
                    system("pause");
                }
                else if (frutaLegume == 3) 
                {
                    printf("FRUTAS:\n");
                    printf("\n");
                    printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                    printf("________________________________________\n");

                    for (int i = 0; i < tamanho; i++) { // Lista todos os produtos
                        printf(" %d \t %-10s \t %d \t R$%.2f\n",
                            produtos[i].idF, produtos[i].nomeF, produtos[i].quantidadeF, produtos[i].valorF);
                    }
                    printf("\n");
                    printf("\n");

                    printf("LEGUMES:\n");
                    printf("\n");
                    printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                    printf("________________________________________\n");
                    for (int i = 0; i < tamanho; i++) { // Lista todos os produtos
                        printf(" %d \t %-10s \t %d \t R$%.2f\n",
                            produtos[i].idL, produtos[i].nomeL, produtos[i].quantidadeL, produtos[i].valorL);
                    }
                    printf("\n");
                    printf("\n");
                    system("pause");
                }
                else if (frutaLegume == 4)
                {
                   
                    printf("Voltando ao estoque...\n");
                    printf("\n");
                    break; // sair do loop do estoque
                }
                else
                {
                    printf("Digito invalido!\n");
                    printf("\n");
                    system("pause");
                }
            }
            printf("\n");
            system("pause");
        }
        else if (opcao == 3) {
            // Voltar para o main
            printf("\n");
            printf("Voltando pagina inicial...\n");
            printf("\n");
            break; // Sai do loop
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    
    }

    free(produtos); // Libera a memória alocada
    
}

