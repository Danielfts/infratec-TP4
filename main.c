// Paulina Arrazola
// 202020631
// p.arrazola@uniandes.edu.co

#include <stdio.h>
#include <stdlib.h>

// Funcion para cambiar multiples bits en un vector de enteros en posiciones especificas
void cambiarVector(int *vctr, int num, int indice, int salto, int value);

// Funcion para cambiar un bit en un numero entero contenido en un vector
void cambiarBit(int *v, int index, int valor);

int main() {

    // Variables necesaias para la transformacion, las define el usuario
    int n;          // Tamaño del vector
    int *vector;    // Apuntador al vector
    int i;          // Posicion de inicio de la transformacion
    int k;          // Numero de posiciones de salto
    int v;          // Valor a asignar

    // Se solicita al usuario el tamaño del vector, verifica que sea mayor a 0 y de lo contrario no continua
    while (1) {
        printf("Por favor, ingrese el tamano del vector: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("El numero ingresado es menor que 0. Intente de nuevo.\n");
        } else {
            break;
        }
    }

    // Se crea el vector de forma dinamica
    vector = (int *)calloc(n, sizeof(int));

    // Se solicita al usuario ingresar los valores para el vector
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor para la posicion %d: ", i);
        scanf("%d", &vector[i]);
    }

    // Se solicita al usuario la posicion de inicio (i)
    printf("Por favor, ingrese la posicion de inicio (i): ");
    scanf("%d", &i);

    // Se solicita al usuario el numero de posiciones de salto (k)
    printf("Por favor, ingrese el numero de posiciones de salto (k): ");
    scanf("%d", &k);

    // Se solicita al usuario el valor a asignar (v). No continua hasta que el valor es 1 o 0
    while (1) {
        printf("Por favor, ingrese el valor que se va a asignar (v): ");
        scanf("%d", &v);
        if (v != 0 && v != 1) {
            printf("v tiene que ser 0 o 1. Intente de nuevo.\n");
        } else {
            break;
        }
    }

    // Se llama a la función para realizar la transformacion en el vector
    cambiarVector(vector, n, i, k, v);

    // Se imprime el resultado de la transformacion
    printf("Los numeros en el vector despues de la transformacion son: \n");

    for (int s = 0; s < n; s++) {
        printf("0x%08X\n", vector[s]);
    }

    return 0;
}


// Funcion para cambiar multiples bits en un vector de enteros en posiciones especificas
void cambiarVector(int *vctr, int num, int indice, int salto, int value) {
    //ciclo que pasa los parametros necesarios a cambiarBit
    //se verifica que la posicion que se va a modificar este en el rango
    for (int j = 0; indice + j * salto < num * 32; j++) {
        cambiarBit(vctr, indice + j * salto, value);
    }
}

// Funcion para cambiar un bit en un numero entero contenido en un vector
void cambiarBit(int *v, int index, int valor) {

    int numero= index/32;    // Calcular el indice del número en el vector que se va a modificar
    int pos= index%32;       // Calcular la posición del bit en ese numero

    // Se crea un valor binario que se pueda utilizar para hacer operaciones de bits sobre el numero que queremos cambiar
    int comodin = 1 << (sizeof(int) * 8 - pos - 1);  // se tiene en cuenta que los bits estan numerados de mas a menos significativo
    if (valor == 1) {
        v[numero] |= comodin;   // Se establece el bit de esa posicion en 1
    } else if (valor == 0) {
        v[numero] &= (~comodin); // Se establece el bit de esa posicion en 0
    }
}
