#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4


typedef struct{


int id;
char procesador[20];
char marca[20];
float precio;


}eNotebook;

float descuento(float precio);
int contarCaracter(char cadena[] , char caracter);
void ordenamientoBurbuja(eNotebook notebooks[], int tam);


int main()
{

    char nombre[20] = "CRISTIAN";
    char caracter = 'I';
    float precio;
    float descuentoPrecio;
    int i;
    int contador;
    eNotebook notebooks[4] = {  {20,"INTEL","SONY",500},
                                {30,"RAZOR","ACER",800},
                                {40,"OMEGA","SONY",300},
                                {50,"GAMA","DELL",100}

                            };

    printf("ingrese precio del producto: ");
    scanf("%f",&precio);

    descuentoPrecio = descuento(precio);

    precio -= descuentoPrecio;

    printf("el precio final es %.2f\n",precio);

    system("pause");
    system("cls");


    contador = contarCaracter(nombre,caracter);

    printf("LA CANTIDAD DE %c QUE TIENE LA PALABRA %s SON %d\n",caracter,nombre,contador);

    system("pause");
    system("cls");


    for(i=0;i<TAM;i++)
    {
       printf("%d  %s     %s     %.2f\n",notebooks[i].id,notebooks[i].procesador,notebooks[i].marca,notebooks[i].precio);

    }
    printf("\n\n");
    printf("ORDENADO POR MARCA Y PRECIO\n");

    for(i=0;i<TAM;i++)
    {
    ordenamientoBurbuja(notebooks,TAM);
    printf("%d  %s     %s     %.2f\n",notebooks[i].id,notebooks[i].procesador,notebooks[i].marca,notebooks[i].precio);
    }



    return 0;
}



int contarCaracter(char cadena[] , char caracter)
{

    int i;
    int contador = 0;

    for(i=0;i<strlen(cadena);i++)
    {
       if(cadena[i]==caracter)
       {
          contador++;
       }

    }


   return contador;



}








void ordenamientoBurbuja(eNotebook notebooks[], int tam)
{

    int i;
    int flagSwap;
    eNotebook auxNotebook;

    do
    {

        flagSwap=0;

        for(i=0; i<tam-1; i++)
        {

            if(strcmp(notebooks[i].marca,notebooks[i+1].marca)>0)
            {

                flagSwap = 1;
                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[i+1];
                notebooks[i+1] = auxNotebook;

            }

            else if((strcmp(notebooks[i].marca,notebooks[i+1].marca)==0 )&& notebooks[i].precio<notebooks[i+1].precio)
            {

                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[i+1];
                notebooks[i+1] = auxNotebook;
            }
        }

    }
    while(flagSwap);
}






float descuento(float precio)
{
    float descuento = (precio*5)/100;
    printf("descuento aplicado del 5 porciento realizado con exito\n");

    return descuento;
}
