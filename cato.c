#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define limpiar "cls"
#define parar "pause"

// Grupo: 160501
// Jesus Angel de la luz Hernandez
// Francisco Said Campuzano Torres

int opc = 0;

int total = -1;
char nombre[50][30];
float precio[50];
float peso[50];
int calidad[50];
int almacen[50];
int vendidos[50];
float ganancias = 0;
void CrearDocumento();

char nombreCliente[50][100];
char ciudad[50][100];
int codigoPostal[50];
float pagar[50];
int lista[20][2];
int total2 = -1;
int total3 = -1;
bool envio = false;

const int MOSTRAR_TODO = 0;
const int MOSTRAR_MAS_VENDIDO = 1;
const int MOSTRAR_PRECIO_MAYOR = 2;
const int MOSTRAR_MAYOR_CALIDAD = 3;
const int MOSTRAR_LISTA_CLIENTE = 4;

void vendedor();
void cliente();
void mostrarLista(int filtro);
void ordenar(int *vector,int p[50], int n);
void ordenarFlotantes(int *vector,float p[50], int n);
void agregar();
void modificar();
void comprar(int id,int cantidad,bool envio);
void eliminarLista(int id);
void eliminarModelo(int id);
void cotizar();
float calcular(bool envio);
void compra(float total, bool envio);
void registro();
void escribir();

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}

int main(){ 
    do{
        system(limpiar);
        printf("1.- Vendedor\n2.- Cliente\n3.- Salir\nOpcion: ");
        scanf("%d",&opc);
        if(opc == 4){
            CrearDocumento();
        }

        switch(opc){
            case 1:
                system(limpiar);
                vendedor();
                break;
            case 2:
                system(limpiar);
                cliente();
                break;
            case 3: break;

            case 4:
                CrearDocumento();
                break;

            default: printf("Opcion no valida.");
        }
    }while(opc != 3);
    escribir();
    return 0;
}

void vendedor(){
    int pass;
    printf("Contraseña: ");
    scanf("%d", &pass);
    system(limpiar);
    if(pass == 12345){
        do{
            if(total == -1){
                printf("1.- Agregar modelo.\n");
                printf("2.- Salir\n");
            }else if(total >= 0){
                printf("1.- Agregar modelo.\n");
                printf("2.- Modificar modelo.\n");
                printf("3.- Eliminar modelo.\n");
                printf("4.- Mostrar modelos.\n");
                printf("5.- Registro de ventas\n");
                printf("6.- Salir\n");
            }
            printf("Opcion: ");
            scanf("%d",&opc);
            if(opc == 2 && total == -1){
                opc = 100;
            }else if(opc == 6 && total >= 0){
                opc = 100;
            }else if(opc == 1){
                system(limpiar);
                agregar();
                system(limpiar);
            }else if(opc == 2 && total >= 0){
                system(limpiar);
                modificar();
                opc =0;
                system(limpiar);
            }else if(opc == 3 && total >= 0){
                system(limpiar);
                mostrarLista(MOSTRAR_TODO);
                printf("------------------------------\n");
                printf("Numero del modelo a eliminar: ");
                scanf("%d",&opc);
                eliminarModelo(opc);
                opc = 0;
                system(limpiar);
            }else if(opc == 4 && total >= 0){
                system(limpiar);
                mostrarLista(MOSTRAR_TODO);
                printf("\n");
                system(parar);
                system(limpiar);
            }else if(opc == 5 && total >= 0){
                registro();
                system(limpiar);
            }else{
                system(limpiar);
                printf("-----Opcion no valida.----\n");
            }
        }while(opc != 100);
        opc = 0;
    }else{
        system(limpiar);
        printf("-- No se logro acceder --\n");
    }
}

void mostrarLista(int filtro){
    int aux = 1;
    int temp[50];
    if(filtro == 1){
        ordenar(&temp[0], vendidos,1);
    }else if(filtro == 2){
        ordenarFlotantes(&temp[0], precio, 1);
    }else if(filtro == 3){
        ordenar(&temp[0], calidad, 1);
    }
    
    if(filtro == 0){
        printf("Numero<");
        gotoxy(10,0);
        printf("Nombre");
        gotoxy(25,0);
        printf("Calidad");
        gotoxy(40,0);
        printf("peso");
        gotoxy(50,0);
        printf("Precio");
        gotoxy(60,0);
        printf("Cantidad");
        for(int i = 0; i <= total; i++){
            gotoxy(0,i+1);
            printf("%d",i);
            gotoxy(10,i+1);
            printf("%s",nombre[i]);
            gotoxy(25,i+1);
            printf("%d",calidad[i]);
            gotoxy(40,i+1);
            printf("%.1fg",peso[i]);
            gotoxy(50,i+1);
            printf("$%.1f",precio[i]);
            gotoxy(60,i+1);
            printf("%d",almacen[i]);
        }
        printf("\n");
    }else if(filtro == 1){
        printf("Numero");
        gotoxy(10,0);
        printf("Nombre");
        gotoxy(25,0);
        printf("Calidad");
        gotoxy(40,0);
        printf("peso");
        gotoxy(50,0);
        printf("Precio");
        gotoxy(60,0);
        printf("Cantidad");
        gotoxy(70,0);
        printf("Vendidos<");
        for(int i = 0; i <= total; i++){
            if(almacen[temp[i]] > 0){
                gotoxy(0,aux);
                printf("%d",temp[i]);
                gotoxy(10,aux);
                printf("%s",nombre[temp[i]]);
                gotoxy(25,aux);
                printf("%d",calidad[temp[i]]);
                gotoxy(40,aux);
                printf("%.1fg",peso[temp[i]]);
                gotoxy(50,aux);
                printf("$%.1f",precio[temp[i]]);
                gotoxy(60,aux);
                printf("%d",almacen[temp[i]]);
                gotoxy(70,aux);
                printf("%d",vendidos[temp[i]]);
                aux++;
            }
        }
        printf("\n");
    }else if(filtro == 4){
        printf("Numero");
        gotoxy(10,0);
        printf("Nombre");
        gotoxy(25,0);
        printf("Calidad");
        gotoxy(40,0);
        printf("peso");
        gotoxy(50,0);
        printf("Precio");
        gotoxy(60,0);
        printf("Cantidad");
        for(int i = 0; i <= total2; i++){
            gotoxy(0,i+1);
            printf("%d",lista[i][0]);
            gotoxy(10,i+1);
            printf("%s",nombre[lista[i][0]]);
            gotoxy(25,i+1);
            printf("%d",calidad[lista[i][0]]);
            gotoxy(40,i+1);
            printf("%.1fg",peso[lista[i][0]]);
            gotoxy(50,i+1);
            printf("$%.1f",precio[lista[i][0]]);
            gotoxy(60,i+1);
            printf("%d",lista[i][1]);
        }
        printf("\n");
    }else{
        printf("Numero");
        gotoxy(10,0);
        printf("Nombre");
        gotoxy(25,0);
        if(filtro == 3){
            printf("Calidad<");
        }else{
            printf("Calidad");
        }
        gotoxy(40,0);
        printf("peso");
        gotoxy(50,0);
        if(filtro == 2){
            printf("Precio<");
        }else{
            printf("Precio");
        }
        gotoxy(60,0);
        printf("Cantidad");
        for(int i = 0; i <= total; i++){
            if(almacen[temp[i]] > 0){
                gotoxy(0,aux);
                printf("%d",temp[i]);
                gotoxy(10,aux);
                printf("%s",nombre[temp[i]]);
                gotoxy(25,aux);
                printf("%d",calidad[temp[i]]);
                gotoxy(40,aux);
                printf("%.1fg",peso[temp[i]]);
                gotoxy(50,aux);
                printf("$%.1f",precio[temp[i]]);
                gotoxy(60,aux);
                printf("%d",almacen[temp[i]]);
                aux++;
            }
        }
        printf("\n");
    }
}

void cliente(){
    if(total == -1){
        printf("No hay productos en la plateria.\n\n");
        system(parar);
    }else{
        opc = 0;
        while(opc != 100){
            system(limpiar);
            printf("------Cotizar------\n");
            printf("1.- Mostrar plata por precios\n");
            printf("2.- Mostrar lo mas vendido\n");
            printf("3.- Mostrar plata por calidad\n");
            if(total2 == -1){
                printf("4.- Salir\n");
            }else{
                printf("4.- Mostrar lista\n");
                printf("5.- Cotizar\n");
                printf("6.- Salir\n");
            }
            printf("Opcion: ");
            scanf("%d", &opc);
            if(opc == 4 && total2 == -1){
                opc = 100;
                for(int i = 0; i <= total2; i++){
                    lista[i][0] = 0;
                    lista[i][1] = 0;
                }
                total2 = -1;
                envio = false;
            }else if(opc == 6 && total2 > -1){
                opc = 100;
                for(int i = 0; i <= total2; i++){
                    lista[i][0] = 0;
                    lista[i][1] = 0;
                }
                total2 = -1;
                envio = false;
            }else if(opc == 1 || opc == 2 || opc == 3){
                int aux = opc;
                int aux2 = 0;
                opc = 0;
                system(limpiar);
                do{
                    system(limpiar);
                    if(aux == 1){
                        mostrarLista(MOSTRAR_PRECIO_MAYOR);
                    }else if(aux == 2){
                        mostrarLista(MOSTRAR_MAS_VENDIDO);
                    }else if(aux == 3){
                        mostrarLista(MOSTRAR_MAYOR_CALIDAD);
                    }
                    if(opc == 0){
                        printf("---------------------------------\n");
                        printf("1.- Agregar a lista\n2.- regresar\n");
                        printf("opcion: ");
                        scanf("%d", &opc);
                        if(opc == 1){
                            opc = 1;
                        }else if(opc == 2){
                            opc = 100;
                        }else{
                            system(limpiar);
                            printf("opcion no valida\n\n");
                            system(parar);
                            opc = 0;
                        }
                    }else if(opc == 1){
                        printf("---------------------------------\n");
                        printf("Selecciones numero de producto: ");
                        scanf("%d",&opc);
                        if(opc > total || opc < 0){
                            opc = 2;
                        }else{
                            if(almacen[opc] == 0){
                                opc = 2;
                            }else if(total2 >= 0){
                                aux2 = 0;
                                for(int i=0; i<=total2;i++){
                                    if(lista[i][0] == opc){
                                        aux2 = 1;
                                        break;
                                    }else{
                                        aux2 = 0;
                                    }
                                }
                                if(aux2 == 0){
                                    aux2 = opc;
                                    opc = 4;
                                }else if(aux2 == 1){
                                    opc = 3;
                                }
                            }else{
                                aux2=opc;
                                opc = 4;
                            }
                        }
                    }else if(opc == 2){
                        printf("---------------------------------\n");
                        printf("El producto no existe.\n\n");
                        system(parar);
                        opc = 0;
                    }else if(opc == 3){
                        printf("---------------------------------\n");
                        printf("El producto ya existe en tu lista.\n\n");
                        system(parar);
                        opc = 0;
                    }else if(opc == 4){
                        printf("---------------------------------\n");
                        printf("¿Cuantas piezas decea? ");
                        scanf("%d",&opc);
                        if(opc > 0 && opc <= almacen[aux2]){
                            total2++;
                            lista[total2][0] = aux2;
                            lista[total2][1] = opc;
                            opc = 6;
                        }else{
                            opc = 5;
                        }
                    }else if(opc == 5){
                        printf("---------------------------------\n");
                        printf("La cantidad no es valida.\n\n");
                        system(parar);
                        opc = 4;
                    }else if(opc == 6){
                        printf("---------------------------------\n");
                        printf("Se agrego a lista correctamente.\n\n");
                        system(parar);
                        opc = 0;
                    }
                }while(opc != 100);
                opc = 0;
            }else if(opc == 4 && total2 >= 0){
                system(limpiar);
                mostrarLista(MOSTRAR_LISTA_CLIENTE);
                printf("\n");
                system(parar);
            }else if(opc == 5 && total2 >= 0){
                cotizar();
            }else{
                system(limpiar);
                printf("Opcion no valida.\n\n");
                system(parar);
            }
        }
    }
    opc = 0;
}

void ordenar(int *vector,int p[50], int n){
    int ordentemp[50];
    int min = 0,i,j;
    int aux = 0,aux2=0;
    for(int i = 0; i <= total; i++){
        ordentemp[i] = p[i];
        *(vector + i) = i;
    }
    if(n == 0){ 
        for(i = 0; i < total; i++){
            min = i;
            for(j=i; j <= total; j++){
                if(ordentemp[j] < ordentemp[min]){
                    min = j;
                }
            }
            aux = ordentemp[i];
            aux2 = *(vector+i);
            ordentemp[i] = ordentemp[min];
            *(vector+i)=*(vector+min);
            ordentemp[min] = aux;
            *(vector+min)=aux2;
        }
    }else if(n==1){ 
        for(i = 0; i < total; i++){
            min = i;
            for(j=i; j <= total; j++){
                if(ordentemp[j] > ordentemp[min]){
                    min = j;
                }
            }
            aux = ordentemp[i];
            aux2 = *(vector+i);
            ordentemp[i] = ordentemp[min];
            *(vector+i)=*(vector+min);
            ordentemp[min] = aux;
            *(vector+min)=aux2;
        }
    }
}

void ordenarFlotantes(int *vector,float p[50], int n){
    int ordentemp[50];
    int min = 0,i,j;
    int aux = 0,aux2=0;
    for(int i = 0; i <= total; i++){
        ordentemp[i] = p[i];
        *(vector + i) = i;
    }
    if(n == 0){ 
        for(i = 0; i < total; i++){
            min = i;
            for(j=i; j <= total; j++){
                if(ordentemp[j] < ordentemp[min]){
                    min = j;
                }
            }
            aux = ordentemp[i];
            aux2 = *(vector+i);
            ordentemp[i] = ordentemp[min];
            *(vector+i)=*(vector+min);
            ordentemp[min] = aux;
            *(vector+min)=aux2;
        }
    }else if(n==1){ 
        for(i = 0; i < total; i++){
            min = i;
            for(j=i; j <= total; j++){
                if(ordentemp[j] > ordentemp[min]){
                    min = j;
                }
            }
            aux = ordentemp[i];
            aux2 = *(vector+i);
            ordentemp[i] = ordentemp[min];
            *(vector+i)=*(vector+min);
            ordentemp[min] = aux;
            *(vector+min)=aux2;
        }
    }
}

void agregar(){
    printf("Nombre: ");
    scanf("%s",&nombre[total+1]);
    printf("peso: ");
    scanf("%f",&peso[total+1]);
    printf("Precio: ");
    scanf("%f",&precio[total+1]);
    do{
        printf("--------Calidad-------\n");
        printf("1. 720\n2. 925\n3. 999\nOpcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                calidad[total+1] = 720;
                opc = 100;
                break;
            case 2:
                calidad[total+1] = 925;
                opc = 100;
                break;
            case 3:
                calidad[total+1] = 999;
                opc = 100;
                break;
            default: printf("Opcion no valida.");
        }
    }while(opc != 100);
    opc = 0;
    printf("--------------------\n");
    printf("Total en almacen: ");
    scanf("%d",&almacen[total+1]);
    vendidos[total+1] = 0;
    total = total + 1;
}

void modificar(){
    int temp=0;
    mostrarLista(MOSTRAR_TODO);
    opc = 0;
    while(opc != 100){
        printf("Numero del producto a modificar: ");
        scanf("%d", &opc);
        temp = opc;
        if(opc <= total && opc >= 0){
            printf("--Seleccione que decea modificar-----\n");
            printf("1. Nombre\n2. precio\n3. preso\n4. calidad\n5. cantidad\n");
            printf("opcion: ");
            scanf("%d",&opc);
            do{
                switch(opc){
                    case 1:
                        printf("Nuevo nombre: ");
                        scanf("%s",&nombre[temp]);
                        opc = 100;
                        break;
                    case 2:
                        printf("Nuevo precio: ");
                        scanf("%f",&precio[temp]);
                        opc = 100;
                        break;
                    case 3:
                        printf("Nuevo peso: ");
                        scanf("%f",&peso[temp]);
                        opc = 100;
                        break;
                    case 4:
                        do{
                            printf("--------Calidad-------\n");
                            printf("1. 720\n2. 925\n3. 999\nOpcion: ");
                            scanf("%d",&opc);
                            switch(opc){
                                case 1:
                                    calidad[temp] = 720;
                                    opc = 100;
                                    break;
                                case 2:
                                    calidad[temp] = 925;
                                    opc = 100;
                                    break;
                                case 3:
                                    calidad[temp] = 999;
                                    opc = 100;
                                    break;
                                default: printf("Opcion no valida.");
                            }
                        }while(opc != 100);
                        break;
                    case 5:
                        printf("Nueva cantidad: ");
                        scanf("%d",&almacen[temp]);
                        opc = 100;
                        break;
                    default: printf("Opcion no valida.");
                }
            }while(opc != 100);
        }else{
            printf("El producto no se encuentra.\n");
        }
    }
    
}

void comprar(int id,int cantidad,bool envio){
    if(envio){
        ganancias = ganancias + (precio[id] * cantidad);
        almacen[id] = almacen[id] - cantidad;
        vendidos[id] = vendidos[id] + cantidad;
    }else{

    }
}

void eliminarLista(int id){
    if(id == total){
        lista[id][0] = 0;
    }else{
        int aux = 0;
        aux = lista[id][0];
        for(int i = id; i <= total; i++){
            lista[i][0] = lista[i+1][0];
        }
    }
    total = total-1;
}

void eliminarModelo(int id){
    if(id == total){
        for(int i = 0; i < 30; i++){
            nombre[id][i] = ' ';
        }
        precio[id] = 0;
        calidad[id] = 0;
        almacen[id] = 0;
        peso[id] = 0;
        vendidos[id] = 0;
    }else{
        for(int i = id; i <= total; i++){
            for(int j = 0; j < 30; j++){
                nombre[i][j] = nombre[i+1][j];
            }
            precio[i] = precio[i+1];
            calidad[i] = calidad[i+1];
            almacen[i] = almacen[i+1];
            peso[i] = peso[i+1];
            vendidos[i] = vendidos[i+1];
        }
        for(int i = 0; i < 30; i++){
            nombre[total][i] = ' ';
        }
        precio[total] = 0;
        calidad[total] = 0;
        almacen[total] = 0;
        peso[total] = 0;
        vendidos[total] = 0;
    }
    total = total-1;
}

void cotizar(){
    float cuenta=0;
    do{
        system(limpiar);
        mostrarLista(MOSTRAR_LISTA_CLIENTE);
        printf("-----------------------------\n");
        cuenta = calcular(envio);
        if(envio){
            printf("Total a pagar + 100 de envio: $%.1f\n",cuenta);
            printf("-----------------------------\n");
            printf("1.- Quitar costo de envio\n");
        }else{
            printf("Total a pagar: $%.1f\n",cuenta);
            printf("-----------------------------\n");
            printf("1.- Agregar costo de envio\n");
        }
        printf("2.- Realizar compra\n");
        printf("3.- regresar\n");
        printf("Opcion: ");
        scanf("%d",&opc);
        if(opc == 1){
            if(envio == false){
                envio=true;
            }else{
                envio=false;
            }
        }else if(opc == 2){
            system(limpiar);
            printf("¿Quiere realizar la compra?\n1.- Si\n2.- No\nOpcion:");
            scanf("%d",&opc);
            if(opc == 1){
                compra(cuenta,envio);
            }
            opc = 100;
        }else if(opc == 3){
            opc = 100;
        }else{
            system(limpiar);
            printf("opcion no valida.\n\n");
            system(parar);
        }
    }while(opc != 100);
    opc = 0;
}

float calcular(bool envio){
    float total = 0;
    if(envio){
        for(int i = 0; i <= total2; i++){
            total = total + (precio[lista[i][0]] * lista[i][1]);
        }
        total = total + 100;
    }else{
        for(int i = 0; i <= total2; i++){
            total = total + (precio[lista[i][0]] * lista[i][1]);
        }
    }
    return total;
}

void compra(float total, bool envio){
    if(envio){
        total3 = total3 + 1;
        system(limpiar);
        printf("Nombre: ");
        scanf("%s",&nombreCliente[total3]);
        printf("Ciudad: ");
        scanf("%s",&ciudad[total3]);
        printf("Codigo Postal: ");
        scanf("%d",&codigoPostal[total3]);
        pagar[total3] = total;
    }
    fflush(stdin);
    ganancias = ganancias + total;
    for(int i = 0; i <= total2; i++){
        almacen[lista[i][0]] = almacen[lista[i][0]] - lista[i][1];
    }
    system(limpiar);
    mostrarLista(MOSTRAR_LISTA_CLIENTE);
    for(int i = 0; i <= total2; i++){
        lista[i][0] = 0;
        lista[i][1] = 0;
    }
    total2 = -1;
    if(envio){
        printf("\nNombre: %s\n",nombreCliente[total3]);
        printf("Ciudad: %s\n",ciudad[total3]);
        printf("Codigo Postal: %d\n\n",codigoPostal[total3]);
        printf("Total + envio = $%.1f\n\n",total);
        printf("Su compra llegara en 3 dias habiles.\n");
    }else{
        printf("\nTotal = $%.1f\n\n",total);
    }
    printf("Gracias por su compra.\n\n");
    envio = false;
    system(parar);
}

void registro(){
    system(limpiar);
    printf("Ganancias: $%.1f\n",ganancias);
    printf("---------------Envios-------------------\n");
    if(total3 == -1){
        printf("No hay envios.\n");
    }else{
        gotoxy(0,3);
        printf("Nombre");
        gotoxy(15,3);
        printf("ciudad");
        gotoxy(30,3);
        printf("Codigo Postal");
        for(int i=0; i <= total3; i++){
            gotoxy(0,(4+i));
            printf("%s",nombreCliente[i]);
            gotoxy(15,(4+i));
            printf("%s",ciudad[i]);
            gotoxy(30,(4+i));
            printf("%d",codigoPostal[i]);
        }
    }
    printf("\n");
    system(parar);
}

private void CrearDocumento(){
    FILE* fichero;
    private char texto;
    fichero = fopen("MikePapi.txt", "wt");
    fputs("CATO ES PUTO", fichero);
    fclose(fichero);
    printf("Documento creado");
}