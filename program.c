#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float totalVenda = 0.0;
// faz a função do System("cls");
void limparTela() {
    printf("\033[H\033[J");  // Move o cursor para o início e limpa a tela
}

// faz a função do System("pause");
void pause()
{
    printf("Pressione qualquer tecla para continuar...");
    getchar();
    getchar();
}

struct Pessoas {
    char id;
    char usuario[20];
    char senha[20];
};

// FUNÇÃO VALIDAR LOGIN
int validar_login(const char* usuario_input, const char* senha_input) {
    FILE* arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return 0;
    }

    char linha[50];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0; // Remove o '\n' da string lida
        char* usuario = strtok(linha, ":");
        char* senha = strtok(linha, ":");
        

        if (usuario && senha && strcmp(usuario_input, usuario) == 0 && strcmp(senha_input, senha) == 0 ) {
            fclose(arquivo); // fechar o arquivo
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

// função para cadastro de usuarios
int cadastro() {
    limparTela();
    struct Pessoas cadastro;
    int selecao;
    printf("___________CADASTRO DE USUARIOS___________\n\n");
    printf("1. Administrador\n2. Cliente\n0. Voltar\n==> ");
    scanf("%d", &selecao);

    if (selecao == 1) {
        system("cls");
        printf("___________CADASTRO ADMINISTRATIVO___________\n\n");

        cadastro.id = 'A'; // ID para admin definido como A
        printf("Login (Admin): ");
        scanf("%s", cadastro.usuario);

        printf("Senha (Admin): ");
        scanf("%s", cadastro.senha);

        FILE* arquivo = fopen("cadastro.txt", "a");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return 1;
        }

        // Salvando os dados no arquivo
        fprintf(arquivo, "%s:%s:%d\n", cadastro.usuario, cadastro.senha, cadastro.id);
        fclose(arquivo);
        printf("\n");
        printf("Cadastro realizado com sucesso para ADMIN!\n\n");
        system("pause");
    }
    else if (selecao == 2) {
        system("cls");
        printf("___________CADASTRO CLIENTE___________\n\n");
       
        cadastro.id = 'C';
        printf("Login (Cliente): ");
        scanf("%s", cadastro.usuario);
        printf("Senha (Cliente): ");
        scanf("%s", cadastro.senha);

        FILE* arquivo = fopen("cadastro.txt", "a");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return 1;
        }

        fprintf(arquivo, "%s:%s:%d\n", cadastro.usuario, cadastro.senha, cadastro.id);;
        fclose(arquivo);
        printf("\n");
        printf("Cadastro realizado com sucesso para CLIENTE!\n\n");
        system("pause");
    }
    else if (selecao == 0)
    {
        system("cls");
        printf("\n");
        printf("Voltando...\n\n");
        system("pause");
        return 1;

    }

    return 1;
}


int main()
{
    while (1) {
        /*

         //login
         int selecao;
         int id_input;

         FILE* arquivo = fopen("cadastro.txt", "r");
         char l[50];

         while (fgets(l, sizeof(l), arquivo) != NULL) {
             if (strstr(l, "65") != NULL)
             {
                 id_input = 1;
             }
             else if (strstr(l, "67") != NULL)
             {
                 id_input = 2;
             };
         }
         while (1) {
             system("cls");
             //apresentação
             printf("Programa Lirio do Vale\n");
             printf("V1.3\n\n");
             printf("\nEscolha uma das opcoes abaixo:\n");
             printf("1. Login\n");
             printf("2. Cadastrar\n");
             printf("0. Fechar\n");
             printf("==> ");
             scanf("%d", &selecao);


             if (selecao == 1) {
                 char usuario_input[50], senha_input[50];

                 printf("Digite seu usuario: ");
                 scanf("%49s", usuario_input);
                 printf("Digite sua senha: ");
                 scanf("%49s", senha_input);


                 if (validar_login(usuario_input, senha_input)) { // Verifica se o ID retornado é válido (maior que zero)
                     printf("\nLogin bem-sucedido!\n\n");

                     printf("____________________________________________\n\n");
                     printf("Bem vindo %s\n\n", usuario_input);
                     if (id_input == 1)
                     {
                         printf("Tipo de Login: ADMINISTRATIVO\n");
                         printf("Seu ID e: %d\n", id_input);
                     }
                     else
                     {
                         printf("Tipo de Login: CLIENTE\n");
                         printf("Seu ID e: %d\n", id_input);
                     }
                     printf("____________________________________________\n");
                     system("pause");
                     break;
                 }
                 else {
                     printf("Usuario ou senha incorreta.\n");
                 }

                 system("pause");
             }
             else if (selecao == 2) {
                 cadastro();
             }
             else if (selecao == 0)
             {
                 printf("Finalizando programa...\n");
                 exit(0);
             }
             else {
                 printf("Selecao invalida! Tente novamente.\n");
             }
         }

         */

         // encurtador ==> excluir esse bloco depois
        int i;
        printf("adm: ");
        scanf("%d", &i);
        int seleciona1;
        // Inicio sistema ADM
        if (i == 1)
        {
            while (1)
            {

                limparTela();
                printf("-------------------------------------------\nHORTIFRUTI LIRIO DO VALE\nPERFIL: ADMINISTRATIVO\n\n\n");

                printf("Escolha uma das opcoes abaixo:\n\n1. Cadatrar novos itens\n2. Estoque\n3. Registro de vendas\n0. SAIR DA CONTA\n==> ");
                scanf("%d", &seleciona1);
                printf("\n\n");


                if (seleciona1 == 1) // CADASTRO DE NOVOS ITENS
                {
                    cadastroItem_ADM();
                    printf("\n");
                }
                else if (seleciona1 == 2) // ESTOQUE
                {
                    /*
                    itens faltantes:
                        excluir item do estoque e enviar para lixeira
                        tirar valores da quantidade (diminuir o estoque)
                        (EM ANALISE) editar itens no estoque
                    */
                    estoque_ADM();
                    printf("\n");



                }
                else if (seleciona1 == 3)
                {
                    // Registro da venda
                    FILE* arquivoVenda = fopen("vendas.txt", "a");
                    if (arquivoVenda == NULL) {
                        printf("Erro ao abrir o arquivo de vendas.\n");
                        return;
                    }
                    fprintf(arquivoVenda, "Venda total: %.2f\n", totalVenda);
                    fclose(arquivoVenda);
                    printf("Venda registrada com sucesso!\n");
                }
                else if (seleciona1 == 0)
                {
                    printf("Saindo...\n\n");
                    pause();
                    break; 
                    
                }
            }
        }

        //CLIENTE
        if (i == 2)
        {
            while (1)
            {
                limparTela();
                printf("-------------------------------------------\nHORTIFRUTI LIRIO DO VALE\nPERFIL: CLIENTE\n\n\n");

                printf("Escolha uma das opcoes abaixo:\n\n1. Produtos\n2. Adicionar ao carrinho\n3. Carrinho\n0. SAIR DA CONTA\n==> ");
                scanf("%d", &seleciona1);
                printf("\n\n");

                if (seleciona1 == 1) // CADASTRO DE NOVOS ITENS
                {
                    estoque_CLIENTE();

                }
                else if (seleciona1 == 2)
                {
                    venda_CLIENTE(); // venda do produto
                }
                else if (seleciona1 == 3)
                {
                    carrinho_CLIENTE();
                }
                else if (seleciona1 == 0)
                {
                    printf("Saindo...\n\n");
                    pause();
                    break;
                    
                }
            }

        }
    }
    
	return 0;
}



// VARIAVEIS GLOBAIS ==> CADASTROS DE ALIMENTOS E ESTOQUE
typedef struct Produto {
    // registros
    int id;
    char nome[20];
    int quantidade;
    float valor;
    char selecaoItem;
}Produto;

struct Produto* produtos = NULL; // Ponteiro para produtos
struct Produto novoProduto;
struct Produto tempProduto;

int tamanho = 0; // Número de produtos inseridos frutas
int capacidade = 0;
char addItem = 'n'; // escolhas com caractere
int frutaLegume; // escolhas com numeros
int produtoEncontrado = 0; // Verifica se o novo produto já existe no array


// reinicia o array de produtos
int zerandoProduto() {
    
    memset(produtos, 0, capacidade * sizeof(struct Produto));  // Limpa o array de produtos
    tamanho = 0;  // Redefine o contador de produtos
    
}

//GERADOR DE ID ALEATORIO
int gerarIdAleatorio() {
    return 1000 + rand() % 9000;  // Gera um número entre 1000 e 9999
}



// ADMINISTRATIVO

// otimizar cadastro de item
int cadItemSimpli_ADM() {
    
   

    printf("\nNome do produto: ");
    scanf(" %49[^\n]s", novoProduto.nome);

    printf("Quantidade: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Valor: ");
    scanf("%f", &novoProduto.valor);

    char linha[9000];
    

    // Abrindo o arquivo no modo leitura para carregar todos os produtos no array
    FILE* arquivoF = fopen("estoque.txt", "r");
    if (arquivoF == NULL) {
        printf("Erro ao abrir o arquivo para leitura. Criando novo arquivo...\n");
    }
    else {

        while (fscanf(arquivoF, "%d %49s %d %f %c",
            &tempProduto.id,
            tempProduto.nome,
            &tempProduto.quantidade,
            &tempProduto.valor,
            &tempProduto.selecaoItem) == 5) {



            if (tamanho < 100) {
                produtos[tamanho++] = tempProduto;
            }
            else {
                printf("Erro: Limite de produtos no array atingido.\n");
                break;
            }
        }
        fclose(arquivoF);
    }

    

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(produtos[i].nome, novoProduto.nome) == 0) {
            produtoEncontrado = 1;
            printf("\nItem ja cadastrado. Deseja adiciona a quantidade no estoque? (S/N): ");
            scanf(" %c", &addItem);

            if (addItem == 'S' || addItem == 's')
            {
                produtos[i].quantidade += novoProduto.quantidade;  // Atualiza a quantidade
                printf("\nQuantidade atualizada.\n\n");
            }
            else
            {
                printf("\n");
                break;
            }
        }
    }

    // Caso o produto não exista, adiciona-o ao array
    if (!produtoEncontrado)
    {
        if (tamanho < 100)
        {
            produtos[tamanho++] = novoProduto;
            printf("\nProduto cadastrado com sucesso!\n\n");

        }
        else
        {
            printf("Erro: Limite de produtos no array atingido.\n");
        }
    }

    // Reescreve o arquivo com todos os produtos do array, evitando duplicação
    arquivoF = fopen("estoque.txt", "w");
    if (arquivoF == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivoF, " %d \t %-10s \t %d \t %.2f \t  %c\n",
            produtos[i].id,
            produtos[i].nome,
            produtos[i].quantidade,
            produtos[i].valor,
            produtos[i].selecaoItem);
    }

    fclose(arquivoF);
    tamanho = 0;
    zerandoProduto();
}

// CADASTRO DE ALIMENTOS
int cadastroItem_ADM()
{
    limparTela();
    printf("___________CADASTRO DE ITENS___________\n");
    
    
    do {
        srand(time(NULL));

        // Ajuste de capacidade para o array de produtos
       if (tamanho == capacidade) {
    capacidade = (capacidade == 0) ? 1 : capacidade * 2;
    struct Produto* temp = realloc(produtos, capacidade * sizeof(struct Produto));
    if (temp == NULL) {
        printf("Erro ao alocar memória!\n");
        free(produtos);
        return 1;
    }
    produtos = temp;
}

        printf("\nQual e o tipo do produto?\n\n1. Fruta\n2. Legume\n0. Voltar\n==> ");
        scanf("%d", &frutaLegume);

        if (frutaLegume == 1) 
        {
            limparTela();
            printf("___________CADASTRO FRUTA___________\n\n");
            //gerador ID
            novoProduto.id = gerarIdAleatorio();
            //ID tipo de produto
            novoProduto.selecaoItem = 'F';
            //cadastro otimizado
            cadItemSimpli_ADM();
            // zerando variaveis
            zerandoProduto();
            
        }
        else if (frutaLegume == 2)
        {
            limparTela();
            printf("___________CADASTRO LEGUME___________\n\n");
            //gerador ID
            novoProduto.id = gerarIdAleatorio();
            //ID tipo de produto
            novoProduto.selecaoItem = 'L';
            //cadastro otimizado
            cadItemSimpli_ADM();
            // zerando variaveis
            zerandoProduto();
            
        }
        else if (frutaLegume == 0) {
            printf("\nVoltando a pagina inicial...\n\n");
            pause();
            break;
        }
        else {
            printf("\nDígito invalido!\n\n");
            pause();
            break;
        }

        printf("Gostaria de adicionar outro produto? (S/N): ");
        scanf(" %c", &addItem);
        addItem = toupper(addItem);

    } while (addItem == 'S');
    
}

// GERENCIAMENTO DE ESTOQUE
int estoque_ADM()
{   
    
    while (1) 
    {
       
        
        while (1)
        {
            // Lista de produtos
            limparTela();
            printf("___________PRODUTOS EM ESTOQUE___________\n\n\n");
            
            printf("Qual produto deseja acessar? \n\n1. Frutas\n2. Legumes\n3. Todos\n0. Voltar\n==> ");
            scanf("%d", &frutaLegume);
            printf("\n");

            if (frutaLegume == 1)
            {
                //ESTOQUE FRUTAS ==> opção 1
                limparTela();
                printf("FRUTAS:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");
                
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
                    if (strstr(linhaF, "\t  F") != NULL)
                    {
                        printf("%s", linhaF);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoF);
                printf("\n\n");
                pause();
            }
            else if (frutaLegume == 2)
            {
                limparTela();
                //ESTOQUE LEGUMES ==> opçao 2
                printf("LEGUMES:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

                // Abrindo o arquivo no modo de leitura
                FILE* arquivoL = fopen("estoque.txt", "r");

                if (arquivoL == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                char linhaL[100];

                // Lendo e exibindo cada linha do arquivo
                while (fgets(linhaL, sizeof(linhaL), arquivoL) != NULL) {
                    if (strstr(linhaL, "\t  L") != NULL)
                    {
                        printf("%s", linhaL);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoL);
                
                pause();
            }
            else if (frutaLegume == 3)
            {
                limparTela();
                // ESTOQUE FRUTAS ==> opção 3
                printf("FRUTAS:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

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
                    if (strstr(linhaF, "\t  F") != NULL)
                    {
                        printf("%s", linhaF);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoF);
                printf("\n\n");
               


                //ESTOQUE LEGUMES ==>opção 3
                printf("LEGUMES:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

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
                    if (strstr(linhaL, "\t  L") != NULL)
                    {
                        printf("%s", linhaL);
                    };
                }

                // Fechando o arquivo
                fclose(arquivoL);
                printf("\n\n");
                pause();
            }
            else if (frutaLegume == 0)
            {

                printf("Voltando a pagina inicial...\n\n");
                pause();
                return 1; // sair do loop do estoque
            }
            else
            {
                printf("Opção invalida! Tente novamente.\n");
                printf("\n");
                pause();
            }
            printf("\n");
        }
        free(produtos); // Libera a memória alocada
    }
}



// CLIENTE

int totalQuantidade = 0;
float totalValor = 0.0;

// ESTOQUE PARA O CLIENTE
int estoque_CLIENTE() {
    limparTela();
    // ESTOQUE FRUTAS 
    printf("FRUTAS:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

    // Abrindo o arquivo no modo de leitura
    FILE* arquivoF = fopen("estoque.txt", "r");

    if (arquivoF == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linhaF[1000];

    // Lendo e exibindo cada linha do arquivo
    while (fgets(linhaF, sizeof(linhaF), arquivoF) != NULL) {
        // Se a linha contém o nome procurado, exibe a linha
        if (strstr(linhaF, "\t  F") != NULL)
        {
            printf("%s", linhaF);
        };
    }

    // Fechando o arquivo
    fclose(arquivoF);
    printf("\n\n");



    //ESTOQUE LEGUMES 
    printf("LEGUMES:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

    // Abrindo o arquivo no modo de leitura
    FILE* arquivoL = fopen("estoque.txt", "r");

    if (arquivoL == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linhaL[1000];

    // Lendo e exibindo cada linha do arquivo
    while (fgets(linhaL, sizeof(linhaL), arquivoL) != NULL) {
        // Se a linha contém o nome procurado, exibe a linha
        if (strstr(linhaL, "\t  L") != NULL)
        {
            printf("%s", linhaL);
        };
    }

    // Fechando o arquivo
    fclose(arquivoL);
    printf("\n\n");
    pause();
}

// SISTEMA DE VENDA DE PRODUTOS
int venda_CLIENTE() {
    limparTela();
    printf("\n___________ADICIONAR PRODUTOS AO CARRINHO___________\n\n\n");


    printf("PRODUTOS:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

    // Abrindo o arquivo no modo de leitura
    FILE* arquivo = fopen("estoque.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linhaF[300];

    // Lendo e exibindo cada linha do arquivo
    while (fgets(linhaF, sizeof(linhaF), arquivo) != NULL) {
        
        printf("%s", linhaF);
    }


    // Fechando o arquivo
    fclose(arquivo);
    printf("\n\n");

    printf("Gostaria de adicionar algum produto ao carrinho? (S/N): ");
    scanf(" %c", &addItem);
    addItem = toupper(addItem);

    if (addItem == 'S')
    {
        do
        {
            struct Produto produtos[1000];
            printf("\n_____________________________________________________\n\n*ATENCAO* informe os dados do produto que gostaria de colocar no carrinho.\n\n");

            printf("ID: ");
            scanf("%d", &novoProduto.id);

            printf("Quantidade que deseja: ");
            scanf("%d", &novoProduto.quantidade);


            FILE* arquivo = fopen("estoque.txt", "r");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return 0; // Falha ao abrir o arquivo
            }

            // Lê os produtos do arquivo e armazena no array 'produtos'
            while (fscanf(arquivo, "%d %49s %d %f %c",
                &tempProduto.id,
                tempProduto.nome,
                &tempProduto.quantidade,
                &tempProduto.valor,
                &tempProduto.selecaoItem) == 5) {
                if (tamanho < 1000) {
                    produtos[tamanho++] = tempProduto;
                }
                else {
                    printf("Erro: Limite de produtos no array atingido.\n");
                    break;
                }
            }

            fclose(arquivo); 

            // Procura pelo produto no array
            for (int i = 0; i < tamanho; i++) {
                if (produtos[i].id == novoProduto.id) {
                    produtoEncontrado = 1;

                    printf("\nGostaria de adicionar esse produto ao seu carrinho? (S/N): ");
                    scanf(" %c", &addItem);
                    addItem = toupper(addItem);

                    if (addItem == 'S') {
                        // Verifica se há estoque suficiente
                        if (produtos[i].quantidade >= novoProduto.quantidade) {
                            produtos[i].quantidade -= novoProduto.quantidade; // Atualiza o estoque local

                            // Adiciona o produto ao carrinho
                            FILE* arquivoCarrinho = fopen("carrinho.txt", "r");
                            if (arquivoCarrinho == NULL) {
                                // Se o arquivo não existir, criaremos um novo
                                arquivoCarrinho = fopen("carrinho.txt", "w");
                                if (arquivoCarrinho == NULL) {
                                    printf("Erro ao criar o arquivo do carrinho.\n");
                                    return 1;
                                }
                                fclose(arquivoCarrinho);
                                arquivoCarrinho = fopen("carrinho.txt", "r");
                            }

                            // Estrutura temporária para armazenar produtos do carrinho
                            struct Produto carrinho[1000];
                            int tamanhoCarrinho = 0;

                            // Lê os produtos do carrinho existente
                            while (fscanf(arquivoCarrinho, "%d %49s %d %f %c",
                                &carrinho[tamanhoCarrinho].id,
                                carrinho[tamanhoCarrinho].nome,
                                &carrinho[tamanhoCarrinho].quantidade,
                                &carrinho[tamanhoCarrinho].valor,
                                &carrinho[tamanhoCarrinho].selecaoItem) == 5) {
                                tamanhoCarrinho++;
                            }

                            fclose(arquivoCarrinho);

                            // Verifica se o produto já está no carrinho
                            int produtoJaNoCarrinho = 0;
                            for (int j = 0; j < tamanhoCarrinho; j++) {
                                if (carrinho[j].id == produtos[i].id) {
                                    // Produto encontrado no carrinho, atualiza a quantidade
                                    carrinho[j].quantidade += novoProduto.quantidade;
                                    produtoJaNoCarrinho = 1;
                                    break;
                                }
                            }

                            // Se o produto não estiver no carrinho, adiciona como novo
                            if (!produtoJaNoCarrinho) {
                                carrinho[tamanhoCarrinho++] = (struct Produto){
                                    .id = produtos[i].id,
                                    .quantidade = novoProduto.quantidade,
                                    .valor = produtos[i].valor,
                                    .selecaoItem = produtos[i].selecaoItem
                                };
                                strcpy(carrinho[tamanhoCarrinho - 1].nome, produtos[i].nome);
                            }

                            // Reescreve o arquivo do carrinho com os produtos atualizados
                            arquivoCarrinho = fopen("carrinho.txt", "w");
                            if (arquivoCarrinho == NULL) {
                                printf("Erro ao abrir o arquivo do carrinho para atualização.\n");
                                return 1;
                            }

                            for (int j = 0; j < tamanhoCarrinho; j++) {
                                fprintf(arquivoCarrinho, " %d \t %-10s \t %d \t %.2f \t %c\n",
                                    carrinho[j].id,
                                    carrinho[j].nome,
                                    carrinho[j].quantidade,
                                    carrinho[j].valor,
                                    carrinho[j].selecaoItem);
                            }

                            fclose(arquivoCarrinho);

                            // Atualiza o arquivo de estoque
                            FILE* arquivoEstoque = fopen("estoque.txt", "w");
                            if (arquivoEstoque == NULL) {
                                printf("Erro ao atualizar o estoque.\n");
                                return 1;
                            }

                            for (int j = 0; j < tamanho; j++) {
                                fprintf(arquivoEstoque, " %d \t %-10s \t %d \t %.2f \t  %c\n",
                                    produtos[j].id,
                                    produtos[j].nome,
                                    produtos[j].quantidade,
                                    produtos[j].valor,
                                    produtos[j].selecaoItem);
                            }

                            fclose(arquivoEstoque); // Fecha o arquivo de estoque

                            printf("\nProduto atualizado no carrinho.\n\n");
                        }
                        else {
                            printf("\nQuantidade insuficiente em estoque.\n");
                        }
                    }
                    else {
                        printf("\nProduto não adicionado ao carrinho.\n");
                    }
                    break; 
                }
            }

            // Se o produto não foi encontrado
            if (!produtoEncontrado) {
                printf("\nProduto não encontrado no estoque.\n");
            }

            
            zerandoProduto();

            printf("Gostaria de adicionar outro produto? (S/N): ");
            scanf(" %c", &addItem);
            addItem = toupper(addItem);

        } while (addItem == 'S');
    }
    printf("\n");
    pause();
}

// CARRINHO DO CLIENTE
int carrinho_CLIENTE() {
    while (1) {

        limparTela();
        printf("\n___________CARRINHO___________\n\n\n");

        printf("PRODUTOS:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

        // Abrindo o arquivo no modo de leitura
        FILE* arquivoCarrinho = fopen("carrinho.txt", "r");

        if (arquivoCarrinho == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        char linhaF[100];

        // Lendo e exibindo cada linha do arquivo
        while (fgets(linhaF, sizeof(linhaF), arquivoCarrinho) != NULL) {
            printf("%s", linhaF);
        }

        // Fechando o arquivo
        fclose(arquivoCarrinho);

        printf("\n______________________________________________\n\n");



        FILE* arquivoVenda = fopen("carrinho.txt", "r");

        while (fscanf(arquivoVenda, "%d %49s %d %f %c",
            &tempProduto.id,
            tempProduto.nome,
            &tempProduto.quantidade,
            &tempProduto.valor,
            &tempProduto.selecaoItem) == 5) {

            // Soma a quantidade total
            totalQuantidade += tempProduto.quantidade;

            // Calcula o valor total
            totalValor += tempProduto.quantidade * tempProduto.valor;

        }
        fclose(arquivoVenda);


        printf("total de itens: %d\n", totalQuantidade);
        printf("total a pagar: R$ %.2f\n", totalValor);

        printf("\n\n1. Finalizar compra\n2. Remover produto\n0. Voltar\n==> ");
        scanf("%d", &frutaLegume);


        if (frutaLegume == 1) {

            finalizarCompra_CLIENTE();
        }
        else if (frutaLegume == 2) {
           
            removerCarrinho_CLIENTE();
        }
        else if (frutaLegume == 0) {
            return 1;
        }
    }

    printf("\n\n");
    zerandoProduto;

    // zerar a quantidade e o valor para atualizarem nas modificaçoes
    totalQuantidade = 0;
    totalValor = 0.0;

    pause();
}

// REMOVE PRODUTOS DO CARRINHO DO CLIENTE
int removerCarrinho_CLIENTE() {

    printf("\n___________REMOVER PRODUTO___________\n\n");

    printf("\n*ATENCAO* isso removera o produto e sua quantidade\n");

    printf("\n\nDeseja continuar? (S/N): ");
    scanf(" %c", &addItem);
    addItem = toupper(addItem);

    if (addItem == 'S')
    {
        FILE* arquivoCarrinho, * arquivoEstoque;
        struct Produto produtosCarrinho[1000];
        struct Produto estoque[1000];
        int tamanhoCarrinho = 0, tamanhoEstoque = 0;
        int idExcluir, encontrado = 0;

        // Abre o arquivo do carrinho
        arquivoCarrinho = fopen("carrinho.txt", "r");
        if (arquivoCarrinho == NULL) {
            printf("Erro ao abrir o arquivo do carrinho.\n");
            return;
        }

        // Lê os itens do carrinho para um array
        while (fscanf(arquivoCarrinho, "%d %49s %d %f %c",
            &produtosCarrinho[tamanhoCarrinho].id,
            produtosCarrinho[tamanhoCarrinho].nome,
            &produtosCarrinho[tamanhoCarrinho].quantidade,
            &produtosCarrinho[tamanhoCarrinho].valor,
            &produtosCarrinho[tamanhoCarrinho].selecaoItem) == 5) {
            tamanhoCarrinho++;
        }
        fclose(arquivoCarrinho);

        // Pergunta qual item excluir
        printf("\nInforme o ID do produto: ");
        scanf("%d", &idExcluir);

        // Lê o estoque
        arquivoEstoque = fopen("estoque.txt", "r");
        if (arquivoEstoque == NULL) {
            printf("Erro ao abrir o arquivo de estoque.\n");
            return;
        }

        while (fscanf(arquivoEstoque, "%d %49s %d %f %c",
            &estoque[tamanhoEstoque].id,
            estoque[tamanhoEstoque].nome,
            &estoque[tamanhoEstoque].quantidade,
            &estoque[tamanhoEstoque].valor,
            &estoque[tamanhoEstoque].selecaoItem) == 5) {
            tamanhoEstoque++;
        }
        fclose(arquivoEstoque);

        // Abre o carrinho para reescrever os itens restantes
        arquivoCarrinho = fopen("carrinho.txt", "w");
        if (arquivoCarrinho == NULL) {
            printf("Erro ao abrir o arquivo do carrinho para escrita.\n");
            return;
        }

        for (int i = 0; i < tamanhoCarrinho; i++) {
            if (produtosCarrinho[i].id == idExcluir) {
                encontrado = 1; // Marca que o produto foi encontrado
                printf("\n\nProduto '%s' removido do carrinho.\n", produtosCarrinho[i].nome);

                // Atualiza o estoque
                for (int j = 0; j < tamanhoEstoque; j++) {
                    if (estoque[j].id == produtosCarrinho[i].id) {
                        estoque[j].quantidade += produtosCarrinho[i].quantidade; // Retorna ao estoque
                        break;
                    }
                }
            }
            else {
                // Mantém os produtos que não foram excluídos no carrinho
                fprintf(arquivoCarrinho, " %d \t %-10s \t %d \t %.2f \t  %c\n",
                    produtosCarrinho[i].id,
                    produtosCarrinho[i].nome,
                    produtosCarrinho[i].quantidade,
                    produtosCarrinho[i].valor,
                    produtosCarrinho[i].selecaoItem);
            }
        }
        fclose(arquivoCarrinho);

        if (!encontrado) {
            printf("\nProduto com ID %d nao encontrado no carrinho.\n\n", idExcluir);
            pause();
            return;
        }

        // Atualiza o arquivo de estoque
        arquivoEstoque = fopen("estoque.txt", "w");
        if (arquivoEstoque == NULL) {
            printf("Erro ao abrir o arquivo de estoque para escrita.\n");
            return;
        }

        for (int i = 0; i < tamanhoEstoque; i++) {
            fprintf(arquivoEstoque, " %d \t %-10s \t %d \t %.2f \t  %c\n",
                estoque[i].id,
                estoque[i].nome,
                estoque[i].quantidade,
                estoque[i].valor,
                estoque[i].selecaoItem);
        }
        fclose(arquivoEstoque);

        printf("\n\nEstoque atualizado com sucesso.\n\n");
    }
    else {
        return;
    }

    totalQuantidade = 0;
    totalValor = 0.0;
    pause();
}


int finalizarCompra_CLIENTE() {


}

