#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_USUARIOS 20000

struct Usuario 
{
	char arquivo[200];
    char cpf[15];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
};

struct Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

void registrarUsuario() 
{
	setlocale(LC_ALL, "portuguese");
    if (numUsuarios >= MAX_USUARIOS) 
	{
        printf("Número máximo de usuários atingido.\n");
        return;
    }
	struct Usuario* novoUsuario = new Usuario;
	
   	char arquivo[600];
	char cpf[200];
	char nome[200];
	char sobrenome[200];
	char cargo[100];
	
	printf("Digite o CPF: ");
	fgets(novoUsuario->cpf, sizeof(novoUsuario->cpf), stdin);
    novoUsuario->cpf[strcspn(novoUsuario->cpf, "\n")] = 0;  // remove a nova linha do final
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das "string"
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variï¿½vel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");

	fgets(novoUsuario->nome, sizeof(novoUsuario->nome), stdin);
    novoUsuario->nome[strcspn(novoUsuario->nome, "\n")] = 0;  // remove a nova linha do final
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(novoUsuario->sobrenome, sizeof(novoUsuario->sobrenome), stdin);
    novoUsuario->sobrenome[strcspn(novoUsuario->sobrenome, "\n")] = 0;  // remove a nova linha do final
    scanf("%s",sobrenome);
    
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	fgets(novoUsuario->cargo, sizeof(novoUsuario->cargo), stdin);
    novoUsuario->cargo[strcspn(novoUsuario->cargo, "\n")] = 0;  // remove a nova linha do final
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

    numUsuarios++;
    
    system("pause");
	system("cls");
}

void consultarUsuario() 
{
	setlocale(LC_ALL, "portuguese");
	
    char cpf[15];
    printf("Digite o CPF do usuário que deseja consultar: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) 
    {
        printf("Usuário com CPF %s não encontrado.\n", cpf);
		system("pause");
		return;
    }
	setlocale(LC_ALL, "portuguese");
    char linha[200];
    fgets(linha, sizeof(linha), file);
    printf("CPF: %s\n", linha);

    fgets(linha, sizeof(linha), file);
    printf("Nome Completo: %s\n", linha);

    fgets(linha, sizeof(linha), file);
    printf("Cargo: %s\n", linha);

    fclose(file);
    system("pause");
    system("cls");
}

void deletarUsuario()
{
   char cpf[15];
    printf("Digite o CPF do usuário que deseja deletar: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
        printf("Usuário com CPF %s deletado.\n", cpf);
    	else
        	printf("Usuário com CPF %s não encontrado.\n", cpf);
        	system("pause");
        	system("cls");
}

int main() 
{
	setlocale(LC_ALL, "portuguese");
	

	
	
    	int opcao=0;
    	int laco=1;
    	
		for(laco=1; laco==1;)
		
		{
	system("cls");
			setlocale(LC_ALL, "portuguese");
    	
    		printf("\t\tCARTÓRIO DA EBAC.\n\n");
    		printf("Selecione a opção desejada:\n\n ");
			printf("\t\t1- Registrar nomes\n");
			printf("\t\t2- Consultar nomes\n");
			printf("\t\t3- Deletar nomes\n\n");
			printf("opção: ");
        	scanf(" %s", &opcao);
        	system("cls");

        	switch (opcao) 
			{
        	    case '1':
            	    registrarUsuario();
            	    break;
            	case '2':
            	    consultarUsuario();
            	    break;
            	case '3':
            		deletarUsuario();
            		break;
          	default:
            	    printf("Opção inválida.\n");
            	    system("pause");
        		    break;
			system("cls");
        	}
    	}
	}

