#include <iostream>
using namespace std;

// Funcion para organizar el max-heap
void mover(int arr[], int n, int indicePadre) {
    int hijoMaximo = indicePadre; // Inicialmente, el padre es el mayor
    int hijoIzquierdo = 2 * indicePadre + 1; // Índice del hijo izquierdo
    int hijoDerecho = 2 * indicePadre + 2; // Índice del hijo derecho

    // Comprobar si el hijo izquierdo es mayor que el padre
    if (hijoIzquierdo < n && arr[hijoIzquierdo] > arr[hijoMaximo])
        hijoMaximo = hijoIzquierdo;

    // Comprobar si el hijo derecho es mayor que el padre o el hijo izquierdo
    if (hijoDerecho < n && arr[hijoDerecho] > arr[hijoMaximo])
        hijoMaximo = hijoDerecho; 

    //Comprobar si el padre cambio
    if (hijoMaximo != indicePadre) {
        swap(arr[indicePadre], arr[hijoMaximo]);
        mover(arr, n, hijoMaximo);
    }
}

void heapsort(int arr[], int n) {
    // Construir el max-heap (reorganizar el arreglo)
    for (int i = (n - 2) / 2; i >= 0; i--)
        mover(arr, n, i);

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i > 0; i--) {
        // Mover el elemento actual (raíz) al final del arreglo
        swap(arr[0], arr[i]);

        // Organizar heap reducido
        mover(arr, i, 0);
    }
}

int main() {
    int arr[] = { 8, 5, 6, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapsort(arr, n);

    cout << "Arreglo ordenado usando heapsort finalizado:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
