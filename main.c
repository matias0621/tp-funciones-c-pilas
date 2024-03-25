#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void acumularPilas(Pila *pila);
void pasarPilaAOtra(Pila *p, Pila *au);
void pasarPilaAOtraEnMismoOrden(Pila *p, Pila *au);
int eliminarAlMenor(Pila *p);
void ordenarNuevaPila(Pila *p);
void ponerEnLaPila(Pila *p);
void sumaTopeYAnterior(Pila p);
void promedio(Pila p);
int sumaDeValoresEnUna(Pila p);
int cuantoDividir(Pila p);
float resultadoDelPromedio(int suma, int dividendo);
void decimalDesdePila(Pila p);
void ponerEnLaPila(Pila *p);
void mostrarPila(Pila p);
void ordenarPilaConPunto4(Pila p);
void pilaOrdenadaconPunto6(Pila p);

int main()
{
    ///Ejercicio 1
    /*
    Pila dada;
    inicpila(&dada);
    acumularPilas(&dada);
    mostrar(&dada);
    */

    ///Ejercicio 2
    /*
    Pila dada;
    Pila aux1;
    inicpila(&dada);
    inicpila(&aux1);

    acumularPilas(&dada);

    pasarPilaAOtra(&dada, &aux1);

    printf("Pila dada:");
    mostrar(&dada);
    printf("Pila aux:");
    mostrar(&aux1);
    */

    ///Ejercicio 3
    /*
    Pila dada;
    Pila aux1;
    inicpila(&dada);
    inicpila(&aux1);

    acumularPilas(&dada);

    mostrar(&dada);
    pasarPilaAOtraEnMismoOrden(&dada, &aux1);

    printf("Pila dada:");
    mostrar(&dada);
    printf("Pila aux:");
    mostrar(&aux1);
    */
    ///Ejercicio 4
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    eliminarAlMenor(&dada);
    */

    ///Ejercicio 5
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    ordenarPilaConPunto4(dada);
    */

    ///Ejercicio 6
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);
    mostrar(&dada);

    ordenarNuevaPila(&dada);
    mostrar(&dada);
    */

    ///Ejercicio 7
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    pilaOrdenadaconPunto6(dada);

    ///Ejercicio 8
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    sumaTopeYAnterior(dada);
    */

    ///Ejercicio 9
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    promedio(dada);
    */

    ///Ejercicio 10
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    decimalFromStack(dada);
    */

    ///Ejercicio extra 1
    /*
    Pila DADA;
    inicpila(&DADA);

    ponerEnLaPila(&DADA);
    mostrar(&DADA);
    */

    ///Ejerciio extra 2
    /*
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    mostrarPila(dada);
    */


    return 0;
}

///---------------------------------------Ejercicio1---------------------------------------------------------------------------------------///
void acumularPilas(Pila *p){
    char control = 's';

    do{
        leer(p);
        printf("Quieres agregar mas valores a la pila?\n");
        fflush(stdin);
        scanf("%c", &control);
    }while(control == 's');
}

///---------------------------------------Ejercicio2---------------------------------------------------------------------------------------///
void pasarPilaAOtra(Pila *p, Pila *au){
    while(!pilavacia(p)){
        apilar(au, desapilar(p));
    }
}
///---------------------------------------Ejercicio3---------------------------------------------------------------------------------------///
void pasarPilaAOtraEnMismoOrden(Pila *p, Pila *au){
    Pila AUXFuncion;
    inicpila(&AUXFuncion);

    while(!pilavacia(p)){
        apilar(&AUXFuncion, desapilar(p));
    }

    while(!pilavacia(&AUXFuncion)){
        apilar(au, desapilar(&AUXFuncion));
    }
}
///---------------------------------------Ejercicio4---------------------------------------------------------------------------------------///
 int eliminarAlMenor(Pila *p){
    Pila AUXFuncion;
    inicpila(&AUXFuncion);
    int numMenor = 9999999;

    while(!pilavacia(p)){
        if (numMenor > tope(p)){
            numMenor = tope(p);
            apilar(&AUXFuncion, desapilar(p));
        }
        else{
            apilar(&AUXFuncion, desapilar(p));
        }
    }

    while(!pilavacia(&AUXFuncion)){
        if (tope(&AUXFuncion) == numMenor){
            desapilar(&AUXFuncion);
        }
        else{
            apilar(p, desapilar(&AUXFuncion));
        }
    }

    mostrar(p);
    return numMenor;
}
///---------------------------------------Ejercicio5---------------------------------------------------------------------------------------///


void ordenarPilaConPunto4(Pila p){
    Pila AUX;
    inicpila(&AUX);
    int numPila = 0;

    while(!pilavacia(&p)){
        numPila++;
        apilar(&AUX, desapilar(&p));
    }
    while(!pilavacia(&AUX)){
        apilar(&p, desapilar(&AUX));
    }

    for(int i = 0; i < numPila; i++){
        apilar(&AUX, eliminarAlMenor(&p));
    }

    mostrar(&AUX);
}


///---------------------------------------Ejercicio6---------------------------------------------------------------------------------------///

void ordenarNuevaPila(Pila *p){
    Pila AUX;
    inicpila(&AUX);
    int ordenada = 0;
    int num = 0;

    printf("Ingrese que numero quiere ingresar\n");
    scanf("%d", &num);

    while(!pilavacia(p) && ordenada == 0){
        if (tope(p) < num){
            apilar(&AUX, desapilar(p));
        }
        else{
            apilar(p, num);
            ordenada = 1;
        }
    }

    while(!pilavacia(&AUX)){
        apilar(p, desapilar(&AUX));
    }

}
///---------------------------------------Ejercicio7---------------------------------------------------------------------------------------///

void pilaOrdenadaconPunto6(Pila p){
    Pila AUX;
    inicpila(&AUX);
    ordenarNuevaPila(&p);

    while(!pilavacia(&p)){
        apilar(&AUX, desapilar(&p));
    }

    printf("Pila AUX");
    mostrar(&AUX);

}

///---------------------------------------Ejercicio8---------------------------------------------------------------------------------------///
void sumaTopeYAnterior(Pila p){
    Pila aux;
    inicpila(&aux);
    int suma = 0;

    suma += desapilar(&p);
    suma += desapilar(&p);
    printf("El resultado de la suma es de: %d", suma);
}

///---------------------------------------Ejercicio9---------------------------------------------------------------------------------------///
/*
void promedio(Pila p){
    int suma = sumaDeValoresEnUna(p);
    int dividendo = cuantoDividir(p);
    float resultado = resultadoDelPromedio(suma, dividendo);

    printf("El promedio es de: %.2f", resultado);
}
*/
/*
int sumaDeValoresEnUna(Pila p){
    int suma = 0;

    while(!pilavacia(&p)){
        suma += desapilar(&p);
    }
    return suma;
}
*/

/*
int cuantoDividir(Pila p){
    int dividendo = 0;

    while(!pilavacia(p)){
        dividendo++;
        desapilar(p);
    }
    return dividendo;
}
*/

///---------------------------------------Ejercicio10---------------------------------------------------------------------------------------///
float resultadoDelPromedio(int suma, int dividendo){
    float resulta = suma / dividendo;

    return resulta;
}

/*
void decimalDesdePila(Pila p) {
    int numero_decimal = 0;
    int multiplicador = 1;

    while (!pilaVacia(p)) {
        int digito = desapilar(p);
        numero_decimal += digito * multiplicador;
        multiplicador *= 10;
    }
    printf("%d", numero_decimal);
}
*/


///---------------------------------------Ejercicio Extra 1---------------------------------------------------------------------------------------///
void ponerEnLaPila(Pila *p){
    int num = 0;
    char control = 's';

    while(control == 's'){
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &num);
        apilar(p, num);

        printf("Quieres agregar mas valores a la pila?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

///---------------------------------------Ejercicio Extra 2---------------------------------------------------------------------------------------///
void mostrarPila(Pila p){
    int num = 0;
    while(!pilavacia(&p)){
        num = desapilar(&p);
        printf("%d|", num);
    }
}
