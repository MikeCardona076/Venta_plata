#include <stdio.h>
#include <string.h>
//En este punto se van a usar condicionales, entradas, ciclos para entrar de lleno

int main(){
    int numero1;
    int numero2;
    int salida;
    int eleccion;
    int resultado;
    do {
        printf("Mike's calculator 1:Empezar 2:Salir alv  ");
        scanf("%d",&salida);
        if(salida==2){
            exit (-1);
        }
    }
    while(salida != 1);
    printf("Calculadora Mike 1:Sumar 2:Restar 3:Dividir 4:Multiplicar");
        printf("Ingrese primer numero: ");
        scanf("%d",&numero1);
        printf("Ingrese segundo numero: ");
        scanf("%d",&numero2);
        printf("Ingrese eleccion: ");
        scanf("%d",&eleccion);
        switch(eleccion){
            case 1:
                resultado = numero1 + numero2;
                printf("Resultado: %i\n" ,resultado);
            break;
            case 2:
                resultado = numero1 - numero2;
                printf("Resultado: %i\n",resultado);
            break;
            case 3:
                resultado = numero1 / numero2;
                printf("Resultado: %i\n",resultado);
            break;
            case 4:
                resultado = numero1 * numero2;
                printf("Resultado: %i\n",resultado);
            break;
        }
    


}