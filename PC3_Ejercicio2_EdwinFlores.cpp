#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<limits>


using namespace std;

//se crea la estructura 
struct Nodo {
    int dato;
    Nodo *siguiente;
};

Nodo *pila = NULL; // Declaración de la variable pila

// Prototipos de funciones
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void generarNumerosAleatorios(int, int, int);
void ingresarNumerosPositivos();
void calcularMaximoMinimo();
void calcularMedia();
void mostrarPila(Nodo *pila);

int main() {
    setlocale(LC_ALL, ""); // Establecer la configuración regional para habilitar los acentos

    int opcion;
    
    do { //menú de opciones
    	cout << "--------------------------------" << endl;
    	cout << "--------------------------------" << endl;
        cout << "--------MENU DE OPCIONES--------" << endl;
        cout << "--------------------------------" << endl;
        cout << "--------------------------------" << endl;
        
        cout << "1. Ingresar números enteros de forma aleatoria, y obtener máximo y mínimo." << endl;
        cout << "2. Ingresar números enteros positivos y devolver la media aritmética(promedio)." << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
    
        if (cin.fail()) {
            cout << "Opción inválida. Ingrese un número válido por favor 1-3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
            continue;
        }

        if (opcion < 1 || opcion > 4) {
            cout << "Opción inválida. Ingrese un número válido entre 1 y 3." << endl;
            system("pause");
            system("cls");
        }
        
        switch (opcion) {
            case 1:
                calcularMaximoMinimo();
                break;
            case 2:
                calcularMedia();
                break;
            case 3:
            	cout<<"Gracias por usar nuestro programa!!!";
            	exit(0);
                break;
            default:
                cout << "Opción inválida. Ingrese un número válido entre 1 y 3.\n";
                break;
        }
        
        system("pause");
        system("cls");
    } while (opcion != 'c' && opcion != 'C');
    
    return 0;
}

void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila,int& n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

void generarNumerosAleatorios(int cantidad) {
    srand(time(0));
    
    int maximo = INT_MIN;
    int minimo = INT_MAX;
    cout << "-------------------------------------------------";
    cout << endl << endl;
    cout << "Números aleatorios entre el 1 y el  10000" << endl;
    cout << "-------------------------------------------------" << endl;
    
    
    for (int i = 0; i < cantidad; i++) {
        //Genera números aleatorios entre 1 y 10000
		int numero = (rand() % 10000) + 1;
        //Se agrega al struct llamado pila al inicio
        agregarPila(pila, numero);
        
        //Si el número es mayor que el máximo, se reemplaza
        if (numero > maximo) {
            maximo = numero;
        }
        
        //Si el número es menor que el mínimo, se reemplaza
        
        if (numero < minimo) {
            minimo = numero;
        }
        //Una forma de sencilla de hallar máximos y mínimos
    }
    mostrarPila(pila);
    
    cout << "El número máximo es: " << maximo << endl;
    cout << "El número mínimo es: " << minimo << endl;
    
	int num;
    while (pila != NULL) {
        sacarPila(pila, num);
    }
    
}
//En esta función se ingresa la cantidad de números aleatorios
//para luego hallar si son maximos o mínimos
void calcularMaximoMinimo() {
    int cantidad_numeros, rango_min, rango_max;
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "Ingrese la cantidad de números aleatorios que desea generar: ";
    cin >> cantidad_numeros;
    //Filtro para que no se ingrese otro tipo de valor incorrecto
    if (cantidad_numeros <= 0) {
        cout << "No se ingresaron números válidos!!! Deben ser POSITIVOS! +++" << endl;
        return;
    }
    
    generarNumerosAleatorios(cantidad_numeros);
    
}
//Función para hallar el promedio
void calcularMedia() {
    int numero;
    int contador = 0;
    int suma = 0;
    cout << "------------------------------------------------------------------------------------"<< endl ;
    cout << "Ingresar números enteros positivos, y para finalizar, ingresar un número negativo o 0" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    
    do {
        cout << "Ingrese un número: ";
        cin >> numero;
        
        if (numero > 0) {
            agregarPila(pila, numero);
        } else {
            break;
        }
    } while (true);
    
    Nodo* temp = pila;
    
    while (temp != NULL) {
        int dato = temp->dato;
        suma += dato;
        contador++;
        temp = temp->siguiente;
    }
    
    if (contador > 0) {
        double media = static_cast<double>(suma) / contador;
        cout << "La media aritmética o promedio es: " << media << endl;
    } else {
        cout << "No se ingresaron números positivos.\n";
    }
    int num;
    while (pila != NULL) {
        sacarPila(pila, num);
    }
}
//Función para recorrer la pila
void mostrarPila(Nodo *pila) {
    
    Nodo *temp = pila;
    
    while (temp != NULL) {
        cout << temp->dato << endl;
        temp = temp->siguiente;
    }
    
    cout << endl;
}

