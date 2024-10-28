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
	printf("V1.3\n");

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
            printf("1. Cadatrar novos itens\n"); //printf(" modificar dados do estoque\n"); ==> dentro de estoque ----> 1. Visualizar ou 2. modificar (2 opçoes)
            printf("2. Estoque\n");
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
                /*
                itens faltantes: 
                    comparação de nomes (para nao cadastrar 2 itens iguais)
                    soma no quantidade (se cadastrar um item igual ele soma na quantidade)
                */
                cadastroItem_ADM();
                printf("\n");
                system("pause");

            }
            else if (seleciona1 == 2)
            {
                /*
                itens faltantes:
                    excluir item do estoque e enviar para lixeira
                    tirar valores da quantidade (diminuir o estoque)
                    (EM ANALISE) editar itens no estoque 
                */
                Estoque_ADM();
                printf("\n");
                system("pause");

            }
            else if (seleciona1 == 4)
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

// VARIAVEIS GLOBAIS ==> CADASTROS DE ITENS E ESTOQUE
struct Produto {
    // registros
    int id;
    char nome[20];
    int quantidade;
    float valor;
    char selecaoItem;
};

struct Produto* produtos = NULL; // Ponteiro para produtos
int tamanho = 0; // Número de produtos inseridos
int capacidade = 0;
int opcao = 0;

int tamanhoL = 0; // Número de produtos inseridos
int capacidadeL = 0;
int frutaLegume;

// CADASTRO DE ALIMENTOS
int cadastroItem_ADM()
{
    printf("______CADASTRO DE ITENS______\n");

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
        printf("\n");
        printf("Qual e o tipo do produto?\n");
        printf("\n");
        printf("1. Fruta\n");
        printf("2. Legume\n");
        printf("3. Voltar\n");
        printf("==> ");
        scanf("%d", &frutaLegume);


        if (frutaLegume == 1)
        {
            //FRUTAS
            novoProduto.id = tamanho + 1;  // Define o ID automaticamente
            novoProduto.selecaoItem = 'F';

            printf("Nome do produto: ");
            scanf(" %49[^\n]", novoProduto.nome);  // Lê o nome com espaços, até 49 caracteres

            printf("Quantidade: ");
            scanf("%d", &novoProduto.quantidade);

            printf("Valor: ");
            scanf("%f", &novoProduto.valor);

            // Adiciona o novo produto ao array
            produtos[tamanho] = novoProduto;  // Copia os dados para o array
            tamanho++;  // Incrementa o número de produtos
            printf("\n");



            /* Abrindo o arquivo no modo "append" para adicionar dados sem
            sobrescrever os existentes*/
            FILE* arquivoF = fopen("estoque.txt", "a");

            if (arquivoF == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
            // Escrevendo os dados no arquivo
            fprintf(arquivoF, " %d \t %-10s \t %d \t R$%.2f \t%c\n",
                produtos[tamanho - 1].id,
                produtos[tamanho - 1].nome,
                produtos[tamanho - 1].quantidade,
                produtos[tamanho - 1].valor,
                produtos[tamanho - 1].selecaoItem);


            // Fechando o arquivo
            fclose(arquivoF);

        }
        else if (frutaLegume == 2)
        {
            //LEGUMES
            novoProduto.id = tamanhoL + 1;  // Define o ID automaticamente
            novoProduto.selecaoItem = 'L';

            printf("Nome do produto: ");
            scanf(" %20[^\n]", novoProduto.nome);  // Lê o nome com espaços, até 49 caracteres

            printf("Quantidade: ");
            scanf("%d", &novoProduto.quantidade);

            printf("Valor: ");
            scanf("%f", &novoProduto.valor);

            // Adiciona o novo produto ao array
            produtos[tamanhoL] = novoProduto;  // Copia os dados para o array
            tamanhoL++;  // Incrementa o número de produtos
            printf("\n");




            /* Abrindo o arquivo no modo "append" para adicionar dados sem
        sobrescrever os existentes*/
            FILE* arquivoL = fopen("estoque.txt", "a");

            if (arquivoL == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }

            // Escrevendo os dados no arquivo
            fprintf(arquivoL, " %d \t %-10s \t %d \t R$%.2f \t%c\n",
                produtos[tamanho - 1].id,
                produtos[tamanho - 1].nome,
                produtos[tamanho - 1].quantidade,
                produtos[tamanho - 1].valor,
                produtos[tamanho - 1].selecaoItem);

            // Fechando o arquivo
            fclose(arquivoL);
        }
        else if (frutaLegume == 3)
        {
            printf("\n");
            printf("Voltando a pagina inicial...\n");
            printf("\n");
            system("cls");
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


// GERENCIAMENTO DE ESTOQUE

int Estoque_ADM()
{   
    // **** ADICIONAR OPÇAO PARA EXCLUIUR ITEM *****


    while (1) 
    {
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
                //ESTOQUE FRUTAS ==> opção 1
                printf("FRUTAS:\n");
                printf("\n");
                printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                printf("________________________________________\n");

                // Abrindo o arquivo no modo de leitura
                FILE* arquivoF = fopen("estoque.txt", "r");

                if (arquivoF == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                char linhaF[100];

                // Lendo e exibindo cada linha do arquivo
                while (fgets(linhaF, sizeof(linhaF), arquivoF) != NULL) {
                    // Se a linha contém o nome procurado, exibe a linha
                    if (strstr(linhaF, "\tF") != NULL)
                    {
                        printf("%s", linhaF);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoF);
                printf("\n");
                printf("\n");
                system("pause");
            }
            else if (frutaLegume == 2)
            {
                //ESTOQUE LEGUMES ==> opçao 2
                printf("LEGUMES:\n");
                printf("\n");
                printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                printf("________________________________________\n");
                // Abrindo o arquivo no modo de leitura
                FILE* arquivoL = fopen("estoque.txt", "r");

                if (arquivoL == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                char linhaL[100];

                // Lendo e exibindo cada linha do arquivo
                while (fgets(linhaL, sizeof(linhaL), arquivoL) != NULL) {
                    if (strstr(linhaL, "\tL") != NULL)
                    {
                        printf("%s", linhaL);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoL);
                printf("\n");
                printf("\n");
                system("pause");
            }
            else if (frutaLegume == 3)
            {

                // ESTOQUE FRUTAS ==> opção 3
                printf("FRUTAS:\n");
                printf("\n");
                printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                printf("________________________________________\n");

                // Abrindo o arquivo no modo de leitura
                FILE* arquivoF = fopen("estoque.txt", "r");

                if (arquivoF == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                char linhaF[100];

                // Lendo e exibindo cada linha do arquivo
                while (fgets(linhaF, sizeof(linhaF), arquivoF) != NULL) {
                    // Se a linha contém o nome procurado, exibe a linha
                    if (strstr(linhaF, "\tF") != NULL)
                    {
                        printf("%s", linhaF);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoF);
                printf("\n");
                printf("\n");


                //ESTOQUE LEGUMES ==>opção 3
                printf("LEGUMES:\n");
                printf("\n");
                printf(" ID \t PRODUTO \t QTD \t VALOR \n");
                printf("________________________________________\n");
                // Abrindo o arquivo no modo de leitura
                FILE* arquivoL = fopen("estoque.txt", "r");

                if (arquivoL == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                char linhaL[100];

                // Lendo e exibindo cada linha do arquivo
                while (fgets(linhaL, sizeof(linhaL), arquivoL) != NULL) {
                    // Se a linha contém o nome procurado, exibe a linha
                    if (strstr(linhaL, "\tL") != NULL)
                    {
                        printf("%s", linhaL);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoL);
                printf("\n");
                printf("\n");
                system("pause");
            }
            else if (frutaLegume == 4)
            {

                printf("Voltando a pagina inicial...\n");
                printf("\n");
                return 1; // sair do loop do estoque
            }
            else
            {
                printf("Opção inválida! Tente novamente.\n");
                printf("\n");
                system("pause");
            }

            printf("\n");

        }

        free(produtos); // Libera a memória alocada
    }
}

