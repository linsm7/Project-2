#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main(){
    char nome[1000][40], nomeback[1000][40], email[1000][40], emailback[1000][40], sex[1000], sexback[1000], endereco[1000][40], enderecoback[1000][40], buscaremail[1000][50];
    int vacina[1000], vacinaback[1000], id[1000], idback[1000], i, k, qnt;
    double altura[1000], alturaback[1000];
    srand (time(NULL));
    
struct endereco_completo
{
	int cep;
	char rua[40];
	char estado[40];
	char cidade[40];
};
    

    //SOLICITAÇÃO DE USUÁRIOS

    printf("Digite quantos usuarios voce deseja cadastrar (maximo de 1000 cadastros): ");
    fflush(stdin);
    scanf("%d", &qnt);
    
    //DADOS DOS USUÁRIOS

    for(i=0; i<qnt; i++){

        //REQUISIÇÃO DO NOME

        printf("\nDigite o nome: ");
        fflush(stdin);
        fgets(nome[i],50,stdin);
        
        //REQUISIÇÃO DO EMAIL

        printf("\nDigite o email: ");
        fflush(stdin);
        scanf("%s",&email[i]);
        
        if(strchr(email[i], '@') == 0){
		printf("\n!!! Email invalido !!!\n");
							
		printf("E-mail Invalido (Nao apresenta o caracter '@')\n\nDigite o Email novamente:");
		fflush(stdin);
		scanf("%s", email[i]);
	    }
	    else{
		printf("Email cadastrado com sucesso!\n");
	    }

        //REQUISIÇÃO DO SEXO

        printf("\nDigite o sexo ('m' para masculino ou 'f' para feminino): ");
        fflush(stdin);
        scanf("%c",&sex[i]);
        if (sex[i] == 'm'){
        printf("Sexo confirmado como masculino\n");
        }
        else if (sex[i] == 'f'){
        printf("Sexo confirmado como feminino\n");
        } 
        else{
        printf("Sexo nao declarado\n");
        }

        //REQUISIÇÃO DO ENDEREÇO
        
        struct endereco_completo endereco1;
        printf("\n------Cadastro de endereco------\n\n");
        
    	printf("\nDigite o estado onde mora: ");
        fflush(stdin);
        fgets(endereco1.estado, 40, stdin);
        
        printf("\nDigite a cidade onde mora: ");
        fflush(stdin);
        fgets(endereco1.cidade, 40, stdin);
        
        printf("\nDigite a rua onde mora: ");
        fflush(stdin);
        fgets(endereco1.rua, 40, stdin);
        
        printf("\nInforme o cep do seu endereco: ");
        fflush(stdin);
        scanf("%d", &endereco1.cep);

        //REQUISIÇÃO DA ALTURA

        printf("\nDigite a altura: ");
        fflush(stdin);
        scanf("%lf", &altura[i]);

        //REQUISIÇÃO DE VACINAÇÃO CONTRA A COVID

        printf("\nJa se vacinou contra a covid 19?\n(Digite 1 se for sim ou qualquer numero se nao) \n");
        fflush(stdin);
        scanf("%d",&vacina[i]);
        if (vacina[i] == 1){
        printf("Ok, o cadastrado foi vacinado!.\n");
        }
        else{
        printf("O cadastrado ainda nao se vacinou, peca para que ele se vacine!!!\n");
        }
        printf("\n");
        
        //GERADOR DO ID

        id[i] = rand();
        
        printf("ID gerado(anote o id, ele nao pode ser alterado): %d\n ",id[i]); 
    }

    //MENU 


    int acao;
    printf("\nDeseja editar algum usuario? (Se sim digite 1)");
    printf("\nDeseja excluir algum usuario? (Se sim digite 2)");
    printf("\nDeseja buscar algum usuario por email? (Se sim digite 3)");
    printf("\nDeseja imprimir todos os usuarios cadastrados? (Se sim digite 4)");
    printf("\nDeseja fazer o backup? (Se sim digite 5)");
    printf("\nDeseja fazer a restauracao dos dados? (Se sim digite 6)\n");
    fflush(stdin);
    scanf("%d", &acao);

    //EDITAR


    if (acao == 1){
    	int infor;
    	printf("Qual informacao voce deseja alterar? \n1: Nome\n2: Email\n3: Sexo\n4: Endereco\n5: Altura\n6: Vacina\n\nDigite o numero: ");
    	fflush(stdin);
		scanf("%d", &infor);
			
		switch (infor){
			case 1:
				printf("Informe o nome: ");
				fflush(stdin);
				scanf("%s", &nome[i]);
			break;
			case 2:
				printf("Informe o email: ");
				fflush(stdin);
				scanf("%s", &email[i]);
			break;
			case 3:
				printf("Informe o sexo do usuario: ");
				fflush(stdin);
				scanf("%c", &sex[i]);
			break;
			case 4:
				printf("Informe o endereco: ");
				fflush(stdin);
				fgets(endereco[i],50,stdin);
			break;
			case 5:
				printf("Informe a altura: ");
    			fflush(stdin);
    			scanf("%lf", &altura[i]);
    		break;
    		case 6:
    			printf("\nO cadastrado ja se vacinou contra a covid 19?\n(Digite 1 se for sim ou digite 0 se for nao) \n");
    			fflush(stdin);
   				scanf("%d",&vacina[i]);
    			if (vacina[i] == 1)
    			{
        			printf("Ok, o cadastrado foi vacinado!.\n");
    			}
    			else
    			{
        			printf("O cadastrado ainda nao se vacinou!\n");
    			}
		}

	}

    //EXCLUAR UM USUÁRIO


    else if (acao == 2)
    {
        printf("\nVolte Mais Tarde Minha Linda Professora :)");
    }
    
    //BUSCAR POR EMAIL


    else if(acao == 3){
        printf("Qual o e-mail:");
        fflush(stdin);
        fgets(buscaremail, 50, stdin);
                    
        printf("\n%s", buscaremail[i]);

        for(i = 0; i < qnt; i++){
        if(strcmp(buscaremail[i], email[i]) == 1){
        printf("Nome do Usuario: %s Email do Usuario: %s\n Sexo do Usuario: %c\n Endereco do Usuario: %s Altura do Usuario: %.2lf\n Situacao de vacina contra covid(1=sim, qualquer outro numero=nao): %d\n", nome[i], email[i], sex[i], endereco[i], altura[i], vacina[i]);
    }
        else
    {
        printf("email nao encontrado!");
    }
    }

    }

    //IMPRIMIR


    else if(acao == 4){
        for (i = 0; i < qnt; i++)
        {
        printf("\n");
        printf("Nome do Usuario: %s Email do Usuario: %s\n Sexo do Usuario: %c\n Endereco do Usuario: %s Altura do Usuario: %.2lf\n Situacao de vacina contra covid(1=sim, qualquer outro numero=nao): %d\n", nome[i], email[i], sex[i], endereco[i], altura[i], vacina[i]);
        }
	}

    //BACKUP


    else if (acao == 5)
    {
        for(i=0; i < qnt; i++){
            strcpy(nome[i], nomeback[i]);
            strcpy(email[i],emailback[i]);
            strcpy(endereco[i], enderecoback[i]);
            vacinaback[i] = vacina[i];
            idback[i] = id[i];
            sexback[i] = sex[i];
        }
    	printf("\nBackup Feito com Sucesso!");
    }

    //RESTAURAR DADOS


    else if (acao == 6)
    {
        for(i=0; i < qnt; i++){
            strcpy(nome[i], nomeback[i]);
            strcpy(email[i],emailback[i]);
            strcpy(endereco[i], enderecoback[i]);
            vacinaback[i] = vacina[i];
            idback[i] = id[i];
            sexback[i] = sex[i];
        }
    	printf("\nDados Restaurados com Sucesso!");
    }



    
    return 0;
}



    



