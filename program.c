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
    int id;
    char usuario[20];
    char senha[20];
};

// Função para validar login e retornar o ID do usuário
int validar_login(const char* usuario_input, const char* senha_input) {
    FILE* arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return 0;
    }

    char linha[60];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0; // Remove o '\n' da string lida
        char* id_str = strtok(linha, ":");
        char* usuario = strtok(NULL, ":");
        char* senha = strtok(NULL, ":");

        if (id_str && usuario && senha && strcmp(usuario_input, usuario) == 0 && strcmp(senha_input, senha) == 0) {
            fclose(arquivo);
            return atoi(id_str); // Retorna o ID do usuário
        }
    }

    fclose(arquivo);
    return 0; // Retorna 0 se não encontrar o usuário
}


// Função para cadastro de usuários
void cadastro() {
    struct Pessoas cadastro;
    int selecao;
    limparTela();

    printf("___________CADASTRO DE USUARIO___________\n\n");
    printf("escolha o tipo de cadastro:\n\n");

    printf("1. Administrador\n");
    printf("2. Cliente\n");
    printf("==> ");
    scanf("%d", &selecao);

    if (selecao == 1 || selecao == 2) {
        limparTela();
        if (selecao == 1) {
            printf("___________CADASTRO ADMINISTRATIVO___________\n\n\n");
        }
        else {
            printf("___________CADASTRO CLIENTE___________\n\n\n");
        }
        cadastro.id = selecao;
        printf("Login: ");
        scanf("%s", cadastro.usuario);
        printf("Senha: ");
        scanf("%s", cadastro.senha);

        FILE* arquivo = fopen("cadastro.txt", "a");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return;
        }

        // Salvar os dados no arquivo
        fprintf(arquivo, "%d:%s:%s\n", cadastro.id, cadastro.usuario, cadastro.senha);
        fclose(arquivo);

        printf("Cadastro realizado com sucesso!\n");
    }
    else {
        printf("Opcao invalida! Cadastro nao realizado.\n");
    }
}



int main()
{
    while (1) {
        int selecao;
        limparTela();
        printf("Programa Lirio do Vale\n");
        printf("V1.3\n");

         //login
        printf("\nEscolha uma das opcoes abaixo:\n");
        printf("1. Login\n");
        printf("2. Cadastrar\n");
        printf("0. Fechar programa\n");
        printf("==> ");
        scanf("%d", &selecao);

        if (selecao == 0) {
            printf("Finalizando programa...\n");
            exit(0);
        }
        else if (selecao == 1) {
            limparTela();
            printf("___________LOGIN___________\n\n\n");
            char usuario_input[50], senha_input[50];
            int seleciona1 = 0;
            printf("Digite seu usuario: ");
            scanf("%49s", usuario_input);
            printf("Digite sua senha: ");
            scanf("%49s", senha_input);

            int id = validar_login(usuario_input, senha_input);
            if (id == 1) {

                // CÓDIGO ADM
                printf("\n______________________________\nBem-vindo, Administrador.\n______________________________\n\n"); // ADMINISTRADOR ID = 1
                pause();
                while (1)
                {

                    limparTela();
                    printf("-------------------------------------------\nHORTIFRUTI LIRIO DO VALE\nPERFIL: ADMINISTRATIVO\n\n\n");

                    printf("Escolha uma das opcoes abaixo:\n\n1. Cadatrar novos itens\n2. Estoque\n3. Remover produto \n4. Registro de vendas \n0. SAIR DA CONTA\n==> ");
                    scanf("%d", &seleciona1);
                    printf("\n\n");


                    if (seleciona1 == 1) // CADASTRO DE NOVOS ITENS
                    {
                        cadastroItem_ADM();
                        printf("\n");
                    }
                    else if (seleciona1 == 2) // ESTOQUE
                    {
                        estoque_ADM();
                        printf("\n");
                    }
                    else if (seleciona1 == 3) // REMOVE PRODUTOS DO ESTOQUE
                    {
                        removerEstoque_ADM();
                        printf("\n");
                    }
                    else if (seleciona1 == 4)
                    {
                        limparTela();
                        printf("\n___________RELATORIO DE VENDAS___________\n\n\n");
                        // Registro da venda
                        FILE* arquivoF = fopen("relatorioVendas.txt", "r");

                        if (arquivoF == NULL) {
                            printf("Erro ao abrir o arquivo.\n");
                            return 1;
                        }

                        char linhaF[1000];

                        // Lendo e exibindo cada linha do arquivo
                        while (fgets(linhaF, sizeof(linhaF), arquivoF) != NULL) {
                            printf("%s", linhaF);
                        }
                        pause();
                    }
                    else if (seleciona1 == 0)
                    {
                        printf("Saindo...\n\n");
                        pause();
                        break;

                    }
                }
            }
            else if (id == 2) {
                printf("\n______________________________\nBem-vindo, Cliente.\n______________________________\n\n"); //CLIENTE ID = 2
                pause();
                //CLIENTE
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
            else {
                printf("\n\nUsuario ou senha incorreta.\n\n");
                pause();
            }
        }
        else if (selecao == 2) {
            cadastro();
        }
        else {
            printf("Selecao invalida! Tente novamente.\n\n");
            pause();
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

int totalQuantidade = 0;
float totalValor = 0.0;


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
        
    }
}

// REMOVE PRODUTO DO ESTOQUE
int removerEstoque_ADM() {
    limparTela();
    printf("\n___________REMOVER PRODUTO ESTOQUE___________\n\n");

    printf("\n*ATENCAO* isso removera o produto inteiro\n\nDeseja continuar? (S/N): ");
    scanf(" %c", &addItem);
    addItem = toupper(addItem);

    if (addItem == 'S')
    {
        FILE*  arquivoEstoque;
        struct Produto produtos[1000];
        int idExcluir, encontrado = 0;

        // Abre o arquivo do carrinho
        arquivoEstoque = fopen("estoque.txt", "r");
        if (arquivoEstoque == NULL) {
            printf("Erro ao abrir o arquivo do carrinho.\n");
            return;
        }

        // Lê os itens do estoque para um array
        while (fscanf(arquivoEstoque, "%d %49s %d %f %c",
            &produtos[tamanho].id,
            produtos[tamanho].nome,
            &produtos[tamanho].quantidade,
            &produtos[tamanho].valor,
            &produtos[tamanho].selecaoItem) == 5) {
            tamanho++;
        }
        fclose(arquivoEstoque);

        // Abrindo o arquivo no modo de leitura
        FILE* arquivoEstoque1 = fopen("estoque.txt", "r");

        if (arquivoEstoque1 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        printf("______________________________________________\n\n");
        char linhaF[9000];
        printf("PRODUTOS:\n\n ID \t PRODUTO \t QTD \t VALOR \t TIPO \n______________________________________________\n");

        // Lendo e exibindo cada linha do arquivo
        while (fgets(linhaF, sizeof(linhaF), arquivoEstoque1) != NULL) {
            printf("%s", linhaF);
        }
        fclose(arquivoEstoque1);
        printf("______________________________________________\n");

        // Pergunta qual item excluir
        printf("\nInforme o ID do produto: ");
        scanf("%d", &idExcluir);

        
        // Abre o carrinho para reescrever os itens restantes
        arquivoEstoque = fopen("estoque.txt", "w");
        if (arquivoEstoque == NULL) {
            printf("Erro ao abrir o arquivo do carrinho para escrita.\n");
            return;
        }

        for (int i = 0; i < tamanho; i++) {
            if (produtos[i].id == idExcluir) {
                encontrado = 1; // Marca que o produto foi encontrado
                printf("\n\nProduto '%s' removido do carrinho.\n", produtos[i].nome);

            }
            else {
                // Mantém os produtos que não foram excluídos no carrinho
                fprintf(arquivoEstoque, " %d \t %-10s \t %d \t %.2f \t  %c\n",
                    produtos[i].id,
                    produtos[i].nome,
                    produtos[i].quantidade,
                    produtos[i].valor,
                    produtos[i].selecaoItem);
            }
        }
        fclose(arquivoEstoque);

        if (!encontrado) {
            printf("\nProduto com ID %d nao encontrado no carrinho.\n\n", idExcluir);
            pause();
            return;
        }

        printf("\n\nEstoque atualizado com sucesso.\n\n");
    }
    else {
        return;
    }

    zerandoProduto();
    totalQuantidade = 0;
    totalValor = 0.0;
    pause();

}



// CLIENTE


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
        totalQuantidade = 0;
        totalValor = 0.0;
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
            printf("\n\n");
            zerandoProduto;

            // zerar a quantidade e o valor para atualizarem nas modificaçoes
            totalQuantidade = 0;
            totalValor = 0.0;

            pause();
            return 1;
        }
        
    }
    
    
}

// REMOVE PRODUTOS DO CARRINHO DO CLIENTE
int removerCarrinho_CLIENTE() {

    printf("\n___________REMOVER PRODUTO CARRINHO___________\n\n");

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

// Limpa o carrinho de compras
int limparCarrinho() {
    FILE* arquivo = fopen("carrinho.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para limpar.\n");
        return;
    }
    fclose(arquivo); 
    printf("Arquivo limpo com sucesso.\n");
}

// Sessao de pagamento dentro do Carrinho do cliente
int finalizarCompra_CLIENTE() {

    while (1) {
        limparTela();
        printf("\n___________FINALIZAR COMPRA___________\n\n");

        printf("Valor total da compra: R$ %.2f\n\n", totalValor);
        printf("Insira a forma de pagamento:\n");
        printf("1. Debito\n2. Credito\n3. Pix\n4. Cartao Lirio do Vale\n0. Voltar\n==> ");
        scanf("%d", &frutaLegume);

        if (frutaLegume == 1) {
            printf("\n________________________________________\n\n ");
            printf("Pagamento com cartao de debito selecionado ");
            printf("\n\n________________________________________\n ");
            printf("\nPagamento autorizado!\nObrigado por comprar no Lirio do Vale.\n\n"); 
            pause();
            break;
        }
        else if (frutaLegume == 2) {
            printf("\n________________________________________\n\n ");
            printf("Pagamento com cartao de credito selecionado ");
            printf("\n\n________________________________________\n ");

            float t2 = totalValor / 2;
            float t3 = totalValor / 3;
            float t4 = totalValor / 4;
            float t5 = totalValor / 5;
            float t6 = totalValor / 6;

            printf("\nParcelas:\n");
            printf("1. 1x de R$ %.2f\n", totalValor);
            printf("2. 2x de R$ %.2f\n", t2);
            printf("3. 3x de R$ %.2f\n", t3);
            printf("4. 4x de R$ %.2f\n", t4);
            printf("5. 5x de R$ %.2f\n", t5);
            printf("6. 6x de R$ %.2f\n", t6);
            printf("0. Voltar\n==> ");
            scanf("%d", &frutaLegume);

            printf("_____________________________________\n");
            if (frutaLegume == 0) {
                continue;
            }
            else if (frutaLegume == 1) {
                printf("\nSelecionado 1x de R$ %.2f\n", totalValor);
            }
            else if (frutaLegume == 2) {
                printf("\nSelecionado 2x de R$ %.2f\n", t2);
            }
            else if (frutaLegume == 3) {
                printf("\nSelecionado 3x de R$ %.2f\n", t3);
            }
            else if (frutaLegume == 4) {
                printf("\nSelecionado 4x de R$ %.2f\n", t4);
            }
            else if (frutaLegume == 5) {
                printf("\nSelecionado 5x de R$ %.2f\n", t5);
            }
            else if (frutaLegume == 6) {
                printf("\nSelecionado 6x de R$ %.2f\n", t6);
            }
            else {
                printf("Digito invalido!");
            }
            printf("\n_____________________________________\n\n");
            pause();
            printf("\nPagamento autorizado!\nObrigado por comprar no Lirio do Vale.\n\n");
            pause();
            break;
        }
        else if (frutaLegume == 3) {

            printf("\n_____________________________________\n\n");
            printf("Pagamento via Pix selecionado ");
            printf("\n\n_____________________________________\n");
            printf("\nServico temporariamente indisponivel, favor selecionar outra forma de pagamento.\n\n");
            pause();
            continue;
        }
        else if (frutaLegume == 4) {
            printf("\n___________________________________________\n\n");
            printf("Pagamento com Cartao Lirio do Vale selecionado");
            printf("\n\n___________________________________________\n");
            pause();
            printf("\n\nPagamento com Cartao Lirio do Vale autorizado!\nObrigado por comprar no Lirio do Vale.\n\n");
            printf("\n_____________________________________________________\n\n");
            printf("PARABENS! voce ganhou 1 ficha da sorte para concorrer a um carro 0 KM.\n");
            printf("Quanto mais comprar com nossos cartoes, mais chances tem de ganham!");
            printf("\n\n_____________________________________________________\n");
            pause();
            break;
        }
        else if (frutaLegume == 0) {
            printf("\nOperacao cancelada. Retornando ao carrinho...\n\n");

            return 1; // Sai da função
        }
        else {
            printf("\nOpcao invalida. Tente novamente.\n\n");
        }
       
    }
    relatorioVendas();
}

// Registra todas as comprar que foram finalizadas
int relatorioVendas() {
    struct Produto carrinho[9000];
    int idVenda = gerarIdAleatorio();

    // Abre o arquivo do carrinho para leitura
    FILE* arquivoCarrinho = fopen("carrinho.txt", "r");
    if (arquivoCarrinho == NULL) {
        printf("Erro ao abrir o arquivo do carrinho.\n");
        return -1; // Retorna erro
    }

    // Lê os itens do carrinho para um array
    while (fscanf(arquivoCarrinho, "%d %49s %d %f %c",
        &carrinho[tamanho].id,
        carrinho[tamanho].nome,
        &carrinho[tamanho].quantidade,
        &carrinho[tamanho].valor,
        &carrinho[tamanho].selecaoItem) == 5) {
        tamanho++;
    }
    fclose(arquivoCarrinho);

    // Abre o arquivo de relatório de vendas para escrita
    FILE* arquivo = fopen("relatorioVendas.txt", "a"); // Modo append
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de relatorio de vendas.\n");
        return -1; // Retorna erro
    }

    fprintf(arquivo, "\n\n\n\n-----------------------------------VENDA-----------------------------------\n\n\n");
    
    fprintf(arquivo, "CODIGO DA VENDA: %d\n\n\n", idVenda);


    // Escreve os itens do carrinho no arquivo de relatório
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "ID: %d\tItem: %s\tQuantidade: %d\tPreco:__________ R$ %.2f\n\n",
            carrinho[i].id, carrinho[i].nome, carrinho[i].quantidade, carrinho[i].valor);
    }

    fprintf(arquivo, "---------------\n\n");
    fprintf(arquivo, "Total: R$ %.2f\n\n", totalValor);
    fprintf(arquivo, "---------------\n\n\n");
   

    fclose(arquivo);
    zerandoProduto();
    limparCarrinho();
    carrinho == NULL;
}














