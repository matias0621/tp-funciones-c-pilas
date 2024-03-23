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

    ordenarNuevaPila(&dada);
    */

    ///Ejercicio 6
    Pila dada;
    inicpila(&dada);

    acumularPilas(&dada);
    ponerEnPilaOrdenada(&dada);


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

void ordenarNuevaPila(Pila *p){
    int num = -1;
    Pila AUX1;
    Pila AUX2;
    Pila nuevaPila;
    inicpila(&AUX1);
    inicpila(&AUX2);
    inicpila(&nuevaPila);

    while(!pilavacia(p)){
        if (num < 0){
            num = desapilar(p);
        }

        if (tope(p) > num){
            apilar(&AUX1, desapilar(p));
        }
        else{
            apilar(&AUX1, num);
            num = -1;
        }
    }

    if (pilavacia(p) && num != -1){
        apilar(&AUX1, num);
    }

    mostrar(&AUX1);

    /*
    while(!pilavacia(p)){
        if (tope(p) < num){
            num = tope(p);
            apilar(&AUX1, desapilar(p));
        }
        else{
            apilar(&AUX2, desapilar(p));
        }
    }
    printf("Pila AUX1:");
    mostrar(&AUX1);
    printf("Pila AUX2:");
    mostrar(&AUX2);


    while(!pilavacia(&AUX1) && !pilavacia(&AUX2)){
            if (tope(&AUX1) < tope(&AUX2)){
                if (!pilavacia(&nuevaPila)){
                    if (tope(&nuevaPila) > tope(&AUX1)){
                        int numAxuliar = desapilar(&nuevaPila);
                        apilar(&nuevaPila, desapilar(&AUX1));
                        apilar(&nuevaPila, numAxuliar);
                    }
                }
                apilar(&nuevaPila, desapilar(&AUX1));
            }
            else{
                if (!pilavacia(&nuevaPila)){
                    if (tope(&nuevaPila) > tope(&AUX1)){
                        int numAxuliar = desapilar(&nuevaPila);
                        apilar(&nuevaPila, desapilar(&AUX1));
                        apilar(&nuevaPila, numAxuliar);
                    }
                }
                apilar(&nuevaPila, desapilar(&AUX1));
            }
    }
    printf("Pila nuevaPila: ");
    mostrar(&nuevaPila);
    */

}
///---------------------------------------Ejercicio6---------------------------------------------------------------------------------------///
void ponerEnLaPila(Pila *p){
    Pila AUX1;
    inicpila(&AUX1);
    int aux = -1;

    while(!pilavacia(p)){
        if (aux == -1){
            apilar(&AUX1, desapilar(p));
            aux = 10;
        }

        if (tope(p) >)
    }
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
