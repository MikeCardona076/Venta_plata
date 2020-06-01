#include <stdio.h>
#include <stdlib.h>
#define private static

private void CrearDocumento();
int opc = 0;

int main(){ 
    do{
        printf("1.- Vendedor\n2.- Cliente\n3.- Salir\nOpcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                system(limpiar);
                vendedor();
                break;
            case 2:
                system(limpiar);
                cliente();
                break;
            case 3: 
                CrearDocumento();
                break;

            case 4:
                break;

            default: printf("Opcion no valida.");
        }
    }while(opc != 4);

}


private void CrearDocumento(){
    FILE* fichero;
    private char texto;
    fichero = fopen("MikePapi.txt", "wt");
    fputs("CATO ES PUTO", fichero);
    fclose(fichero);
    printf("Documento creado");
}