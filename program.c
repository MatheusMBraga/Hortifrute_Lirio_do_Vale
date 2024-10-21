#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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

            inicio_adm:
            printf("Escolha uma das opcoes abaixo: \n");
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
                exit(); // TEMPORARIO
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
        int id;
        char nome[20];
        int quantidade;
        float valor;
    };

    struct Produto* produtos = NULL; // Ponteiro para produtos
    int capacidade = 0; // Capacidade atual do array
    int tamanho = 0; // Número de produtos inseridos
    int opcao = 0;

    while (1) {
        
        printf("\n");
        printf("________ESTOQUE________\n");
        printf("\n");
        printf("Itens do meu estoque: \n");
        printf("\n");

        printf("1. Adicionar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Voltar\n");
        printf("==> ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Verifica se é necessário aumentar a capacidade
            if (tamanho == capacidade) {
                capacidade = (capacidade == 0) ? 1 : capacidade * 2; // Dobra a capacidade
                produtos = realloc(produtos, capacidade * sizeof(struct Produto));
                if (produtos == NULL) {
                    printf("Erro ao alocar memória!\n");
                    return 1; // Sai em caso de erro
                }
            }

            // Adiciona um novo produto
            struct Produto novoProduto;
            novoProduto.id = tamanho + 1; // Define o ID
            printf("Nome do produto: ");
            scanf("%s", novoProduto.nome);
            printf("Quantidade: ");
            scanf("%d", &novoProduto.quantidade);
            printf("Valor: ");
            scanf("%f", &novoProduto.valor);

            produtos[tamanho] = novoProduto; // Adiciona o produto ao array
            tamanho++; // Aumenta o número de produtos
            
        }
        else if (opcao == 2) {
            // Listar produtos
            printf(" ID \t PRODUTO \t QTD \t VALOR \n");
            printf("________________________________________\n");

            for (int i = 0; i < tamanho; i++) { // Lista todos os produtos
                printf(" %d \t %-10s \t %d \t R$%.2f\n",
                    produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].valor);
            }
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
    
    
    /*
    printf("\n");
    printf("________ESTOQUE________\n");
    printf("\n");
    printf("Itens do meu estoque: \n");
    printf("\n");
    
    struct Produto {
        int id;
        char nome[20];
        int quantidade;
        float valor;
    };

    struct Produto produtos[20] = {
       {1,"manga", 10, 4.00},
       {2,"banana", 5, 2.50},
       {3,"abacaxi", 8, 3.00},
       {4,"laranja", 12, 1.80},
       {4,"laranja", 12, 1.80},
       { 4,"laranja", 12, 1.80 },
       { 4,"laranja", 12, 1.80 },
       { 4,"laranja", 12, 1.80 }
    };
    
    printf(" ID \t PRODUTO \t QTD \t VALOR \n");
    printf("________________________________________\n");

    for (int i = 0; i < 8; i++) {
        printf("| %d \t| %s \t| %d \t| R$%.2f \n", produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].valor);
    }
        printf("\n");
        */
    
}

