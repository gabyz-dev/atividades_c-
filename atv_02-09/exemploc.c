#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include <string.h>


int i=0;
int cont=0; 


typedef struct {
                char nome[30];
                }cliente;      


cliente cadastrarcliente()  
{    
   cliente c;
    printf ("\n Sistema Cadastrar Clientes ");
    printf ("\n Informe o nome:");
    scanf(" %30[^\n]", c.nome); 
    cont++;

    return c;
}


void exibircliente (cliente cad[])
{
  printf("\n Exibição de Cadastro Cliente   \n");
    for (int j=0;j<cont;j++){
          printf("\n     CODIGO:   %d", j+1);
          printf("\nNome ...........: %s", cad[j].nome);

    }
}


int main()
{
    setlocale(LC_ALL,"portuguese");
      int opc;
      cliente cad[50];

     do{
        printf ("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE      **** 3 p/ SAIR");
        printf ("\n\n Digite a opção:     ");
        scanf ("%d", &opc);
         switch(opc){
                case 1 : cad [i]=cadastrarcliente();
                         i++;
                         break;
                case 2 :  exibircliente(cad);
                         break;
               printf ("\n SISTEMA CADASTRO \n\n 1 - CADASTRAR CLIENTE\n 2 - EXIBIR CLIENTE     **** 3 p/ SAIR");
          }
    }
 while(opc != 3);
}