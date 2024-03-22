#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void acumularPilas(Pila *pila);
void pasarPilaAOtra(Pila *p, Pila *au);
void pasarPilaAOtraEnMismoOrden(Pila *p, Pila *au);
int eliminarAlMenor(Pila *p);
void sumaTopeYAnterior(Pila p);
void promedio(Pila p);
int sumaDeValoresEnUna(Pila p);
int cuantoDividir(Pila p);
float resultadoDelPromedio(int suma, int dividendo);
void decimalDesdePila(Pila p);

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
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);

    decimalFromStack(dada);

    return 0;
}

void acumularPilas(Pila *p){
    char control = 's';

    do{
        leer(p);
        printf("Quieres agregar mas valores a la pila?\n");
        fflush(stdin);
        scanf("%c", &control);
    }while(control == 's');
}

void pasarPilaAOtra(Pila *p, Pila *au){
    while(!pilavacia(p)){
        apilar(au, desapilar(p));
    }
}

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

void sumaTopeYAnterior(Pila p){
    Pila aux;
    inicpila(&aux);
    int suma = 0;

    suma += desapilar(&p);
    suma += desapilar(&p);
    printf("El resultado de la suma es de: %d", suma);
}

/*
void promedio(Pila p){
    int suma = sumaDeValoresEnUna(p);
    int dividendo = cuantoDividir(p);
    float resultado = resultadoDelPromedio(suma, dividendo);

    printf("El promedio es de: %.2f", resultado);
}

int sumaDeValoresEnUna(Pila p){
    int suma = 0;

    while(!pilavacia(&p)){
        suma += desapilar(&p);
    }
    return suma;
}

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

float resultadoDelPromedio(int suma, int dividendo){
    float resulta = suma / dividendo;

    return resulta;
}

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
