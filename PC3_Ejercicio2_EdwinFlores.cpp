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

Nodo *pila = NULL; // Declaraci�n de la variable pila

// Prototipos de funciones
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void generarNumerosAleatorios(int, int, int);
void ingresarNumerosPositivos();
void calcularMaximoMinimo();
void calcularMedia();
void mostrarPila(Nodo *pila);

int main() {
    setlocale(LC_ALL, ""); // Establecer la configuraci�n regional para habilitar los acentos

    int opcion;
    
    do { //men� de opciones
    	cout << "--------------------------------" << endl;
    	cout << "--------------------------------" << endl;
        cout << "--------MENU DE OPCIONES--------" << endl;
        cout << "--------------------------------" << endl;
        cout << "--------------------------------" << endl;
        
        cout << "1. Ingresar n�meros enteros de forma aleatoria, y obtener m�ximo y m�nimo." << endl;
        cout << "2. Ingresar n�meros enteros positivos y devolver la media aritm�tica(promedio)." << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Ingrese una opci�n: ";
        cin >> opcion;
    
        if (cin.fail()) {
            cout << "Opci�n inv�lida. Ingrese un n�mero v�lido por favor 1-3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
            continue;
        }

        if (opcion < 1 || opcion > 4) {
            cout << "Opci�n inv�lida. Ingrese un n�mero v�lido entre 1 y 3." << endl;
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
                cout << "Opci�n inv�lida. Ingrese un n�mero v�lido entre 1 y 3.\n";
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
    cout << "N�meros aleatorios entre el 1 y el  10000" << endl;
    cout << "-------------------------------------------------" << endl;
    
    
    for (int i = 0; i < cantidad; i++) {
        //Genera n�meros aleatorios entre 1 y 10000
		int numero = (rand() % 10000) + 1;
        //Se agrega al struct llamado pila al inicio
        agregarPila(pila, numero);
        
        //Si el n�mero es mayor que el m�ximo, se reemplaza
        if (numero > maximo) {
            maximo = numero;
        }
        
        //Si el n�mero es menor que el m�nimo, se reemplaza
        
        if (numero < minimo) {
            minimo = numero;
        }
        //Una forma de sencilla de hallar m�ximos y m�nimos
    }
    mostrarPila(pila);
    
    cout << "El n�mero m�ximo es: " << maximo << endl;
    cout << "El n�mero m�nimo es: " << minimo << endl;
    
	int num;
    while (pila != NULL) {
        sacarPila(pila, num);
    }
    
}
//En esta funci�n se ingresa la cantidad de n�meros aleatorios
//para luego hallar si son maximos o m�nimos
void calcularMaximoMinimo() {
    int cantidad_numeros, rango_min, rango_max;
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "Ingrese la cantidad de n�meros aleatorios que desea generar: ";
    cin >> cantidad_numeros;
    //Filtro para que no se ingrese otro tipo de valor incorrecto
    if (cantidad_numeros <= 0) {
        cout << "No se ingresaron n�meros v�lidos!!! Deben ser POSITIVOS! +++" << endl;
        return;
    }
    
    generarNumerosAleatorios(cantidad_numeros);
    
}
//Funci�n para hallar el promedio
void calcularMedia() {
    int numero;
    int contador = 0;
    int suma = 0;
    cout << "------------------------------------------------------------------------------------"<< endl ;
    cout << "Ingresar n�meros enteros positivos, y para finalizar, ingresar un n�mero negativo o 0" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    
    do {
        cout << "Ingrese un n�mero: ";
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
        cout << "La media aritm�tica o promedio es: " << media << endl;
    } else {
        cout << "No se ingresaron n�meros positivos.\n";
    }
    int num;
    while (pila != NULL) {
        sacarPila(pila, num);
    }
}
//Funci�n para recorrer la pila
void mostrarPila(Nodo *pila) {
    
    Nodo *temp = pila;
    
    while (temp != NULL) {
        cout << temp->dato << endl;
        temp = temp->siguiente;
    }
    
    cout << endl;
}

