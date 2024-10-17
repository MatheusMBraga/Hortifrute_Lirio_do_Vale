#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{

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

    // encurtador ==> excluir esse bloco depois
    /*int i;
    printf("adm: ");
    scanf("%d", &i);*/

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
            printf("1. Estoque \n"); //printf(" modificar dados do estoque\n"); ==> dentro de estoque ----> 1. Visualizar ou 2. modificar (2 opçoes)
            printf("2. Cadatrar novos itens\n");
            printf("3. Lixeira\n");
            printf("4. SAIR DA CONTA\n");

            int seleciona1;
            printf("==> ");
            scanf("%d", &seleciona1);
            printf("\n");
            printf("\n");


            if (seleciona1 == 1)
            {
                soma();
                printf("\n");
                system("pause");
                
            }
            if (seleciona1 == 4)
            {
                printf("Saindo...\n");
                printf("\n");
                system("pause");
                goto inicio;
            }
           
        }

        printf("\n");

        printf("Saiu do loop");
        printf("\n");
        system("pause");


        printf("\n");
        printf("\n");





    }
    
	return 0;
}


int soma()
{   

    printf("\n");
    printf("________ESTOQUE________\n");
    printf("\n");
    printf("Itens do meu estoque: \n");
    printf("\n");
    printf("PRODUTOS:\tFRUTAS\tLEGUMES\n");
    char a[2][2] = { { 10,15 },{20,30}};

    int i;
    int j;

    for (i = 0; i < 2; i++)
    {
        printf("COLUNA %d\t", i+1);

        for (j = 0; j < 2; j++)
        {
            printf("%d \t", a[i][j]);
            
        }
        printf("\n");
    }
}

