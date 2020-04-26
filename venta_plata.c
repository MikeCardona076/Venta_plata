#include <stdio.h> //MACC CODES-MIKE CARDONA 
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 


/*Cotizador de venta de plata 
El presente proyecto pretende facilitar la cotizacion de plata en una tienda
que ofrece este bien, con el mismo darla a la venta guardando un registro de las actividades
econimicas en general y capturar el destino y precio de envio, en caso de ser necesario
*/

//Variables 
int precio_plata = 300;
double peso_plata; //El comprador establecera el valor que desea de plata
char nombre_comprador[30];
char nombre_vendedor[30] = "Miguel Cardona";
int Producto_precio(int tipo_trabajo);
int Descuento_comprador(int precio_descuento);
int Envio_no_local(int precio_total);
int precio_pedido;
int opcion;
int envio;
int eleccion_trabajo;
int costo_envio = 700;
//Fin de variables 

//Funcion principal en donde se llaman todas las funciones del programa
int main(){
    do{
        // system("clear");
        printf("1 = Hacer nuevo pedido\n");
        printf(" 2 = Salir ");
        scanf("%d",&opcion);
        system("clear");
        
        printf("Cual es su nombre?  ");
        scanf("%s",nombre_comprador);
        system("clear");

        printf("El envio es local? Si = 1 No = 2  ");
        scanf("%d",&envio);
        system("clear");

        printf("Elige el tipo de trabajo");
        printf(" 1 = Redondo 2 = Cruzado 3 = Diamantado 4 = Sencillo ");
        scanf("%d",&eleccion_trabajo);
        system("clear");

        if(envio == 1 ){
            Producto_precio(eleccion_trabajo);
            Descuento_comprador(precio_pedido);
            

        }
        if(envio==2){
            Producto_precio(eleccion_trabajo);
            Envio_no_local(precio_pedido);
            Descuento_comprador(precio_pedido);
        }
    }
    while(opcion != 2);
    exit(-1);
    


}


//Inicio de funcion
//Funcion que establece el precio de las piezas a pedir y el tipo de plata
int Producto_precio(int tipo_trabajo){
    system("clear");
    /// O.72 0.925 0.999
    int redondo[3] = {200,300,400};
    int cruzado[3] = {200,300,400};
    int diamantado[3] ={200,300,400};
    int sencillo[3] = {200,300,400};
    int tipo_plata;
    int cantidad_piezas;
    switch (tipo_trabajo)
    {
    case 1: 
        ///Lista de precios del tipo de trabajo redondo
        printf("Precios O.72: 200  0.925:300  0.999:400");
        printf(" Seleccione el tipo de plata 0 = O.72  1 = 0.925  2 = 0.999 ");
        scanf("%d",&tipo_plata);
        printf("Ingrese el numero de piezas ");
        scanf("%d",&cantidad_piezas);
        precio_pedido = cantidad_piezas * redondo[tipo_plata];
        printf("Total: %i\n" ,precio_pedido);
        break;

    case 2:
        ///Lista de precios del tipo de trabajo Cruzado
        printf("Precios O.72: 200  0.925:300  0.999:400");
        printf(" Seleccione el tipo de plata 0 = O.72  1 = 0.925  2 = 0.999 ");
        scanf("%d",&tipo_plata);
        printf("Ingrese el numero de piezas ");
        scanf("%d",&cantidad_piezas);
        precio_pedido = cantidad_piezas * cruzado[tipo_plata];
        printf("Total: %i\n" ,precio_pedido);
        break;
    case 3:
        ///Lista de precios del tipo de trabajo Cruzado
        printf("Precios O.72: 200  0.925:300  0.999:400");
        printf(" Seleccione el tipo de plata 0 = O.72  1 = 0.925  2 = 0.999 ");
        scanf("%d",&tipo_plata);
        printf("Ingrese el numero de piezas ");
        scanf("%d",&cantidad_piezas);
        precio_pedido = cantidad_piezas * diamantado[tipo_plata];
        printf("Total: %i\n" ,precio_pedido);
        break;   
    case 4:
        ///Lista de precios del tipo de trabajo Cruzado
        printf(" Precios O.72: 200  0.925:300  0.999:400");
        printf(" Seleccione el tipo de plata 0 = O.72  1 = 0.925  2 = 0.999 ");
        scanf("%d",&tipo_plata);
        printf("Ingrese el numero de piezas ");
        scanf("%d",&cantidad_piezas);
        precio_pedido = cantidad_piezas * sencillo[tipo_plata];
        printf("Total: %i\n" ,precio_pedido);
        break;
       
    }
    return precio_pedido;
    
}
//Fin de funcion



//Inicio de funcion 
int Descuento_comprador(int precio_descuento){
    system("clear");
    //Cambiar el descuento por el que quiran SOLO ES UN EJEMPLO
    printf("Es un cliente frecuente? Si = 1 Nel = 2  ");
    scanf("%d",&precio_descuento);

    if(precio_descuento == 1){
        precio_pedido = precio_pedido - 20;
        printf("Atendido por: %s\n" ,nombre_vendedor);
        printf(" Cliente : %s\n" ,nombre_vendedor);
        printf(" Total a pagar : %i\n" ,precio_pedido);
    }
    if(precio_descuento ==2){
        precio_pedido = precio_pedido - 20;
        printf("Atendido por: %s\n" ,nombre_vendedor);
        printf(" Cliente: %s\n" ,nombre_comprador);
        printf(" Total a pagar : %i\n" ,precio_pedido);
    }
    return precio_pedido;
}
//Fin de funcion



//Inicio de funcion
int Envio_no_local(int precio_total){
    system("clear");
    int confirmacion_envio;
    char lugar_envio[30];
    printf("Lugar a enviar: ");
    scanf("%s",&lugar_envio);
    system("clear");
    printf("CADA ENVIO FUERA DE TAXCO SE LE AUMENTA $700:");
    printf("Quiere seguir Si = 1 No = 2: ");
    scanf("%s",&confirmacion_envio);
    if(confirmacion_envio == 1){
        system("clear");
        precio_pedido = precio_pedido + costo_envio;
        printf("Atendido por: %s\n" ,nombre_vendedor);
        printf("Cliente : %s\n" ,nombre_comprador);
        printf("Lugar de envio: %s\n" ,lugar_envio);
        printf("Total a pagar : %i\n" ,precio_pedido);
    }
    return precio_pedido;

}
//Fin de funcion