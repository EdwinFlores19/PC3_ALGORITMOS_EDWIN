#include <iostream>
#include <string.h>
#include <limits>
#include <locale.h>

using namespace std;
//Se crea el struct con los punteros dentro
struct arbol_binario {
    int numero;
    struct arbol_binario* l;   // l de left
    struct arbol_binario* r;   // r de right
};

struct arbol_binario* arbol = NULL;
//Prototipos de funciones
void llamandoMenuArbol();
void mostrarArbolRDI(struct arbol_binario* aux);
void mostrarArbolDRI(struct arbol_binario* aux);
void mostrarArbolDIR(struct arbol_binario* aux);
void mostrarArbol();
void mostrarNodo(struct arbol_binario* nodo);
void listarNodosInternos(struct arbol_binario* arbol);
void listarNodosHojas(struct arbol_binario* arbol);
int calcularAltura(struct arbol_binario* arbol);
void insertarNodoArbol(int numero);
void resultadoAltura();
void nodosHojas(arbol_binario* arbol);

//Funciones de los 3 tipos de recorridos
void mostrarArbolRDI(struct arbol_binario* aux) {
    if (aux) {
        mostrarArbolRDI(aux->l);
        cout << aux->numero << " ";
        mostrarArbolRDI(aux->r);
    }
}

void mostrarArbolDRI(struct arbol_binario* aux) {
    if (aux) {
        mostrarArbolDRI(aux->r);
        cout << aux->numero << " ";
        mostrarArbolDRI(aux->l);
    }
}

void mostrarArbolDIR(struct arbol_binario* aux) {
    if (aux) {
        mostrarArbolDIR(aux->r);
        mostrarArbolDIR(aux->l);
        cout << aux->numero << " ";
    }
}

//aqu� se llaman a las funciones de recorridos, y se muestran en consola
void mostrarArbol() {
        cout << endl  << "Los tres tipos de recorridos: " << endl;
            cout << endl  << "Mostrando �rbol RDI: " << endl;
            mostrarArbolRDI(arbol);
            
            cout << endl << "\nMostrando �rbol DRI: " << endl;
            mostrarArbolDRI(arbol);
        
            cout << endl << "\nMostrando �rbol DIR: " << endl;
            mostrarArbolDIR(arbol);
			    
    llamandoMenuArbol();
}

//aqu� se inserta el nuevo nodo ingresado dentro del arbol binario 
void insertarNodoArbol(int numero) {
    struct arbol_binario* nodo = new arbol_binario;
    nodo->numero = numero;
    nodo->l = NULL;
    nodo->r = NULL;

    if (arbol == NULL)
        arbol = nodo;
    else {
        struct arbol_binario* aux = arbol;
        struct arbol_binario* prev = aux;

        while (aux) {
            prev = aux;
            if (numero < aux->numero)
                aux = aux->l;
            else
                aux = aux->r;
        }

        if (numero < prev->numero)
            prev->l = nodo;
        else
            prev->r = nodo;
    }
}


void nodosInternos(arbol_binario* arbol)
{
    listarNodosInternos(arbol);
    llamandoMenuArbol();
}
//Aqu� se llaman todos los nodos internos, todos los que tienen hijos 
void listarNodosInternos(arbol_binario* arbol) {
    if (arbol == NULL || (arbol->l == NULL && arbol->r == NULL))
        return;

    cout << arbol->numero << endl;

    listarNodosInternos(arbol->l);
    listarNodosInternos(arbol->r);
}


void nodosHojas(arbol_binario* arbol)
{
    listarNodosHojas(arbol);
    llamandoMenuArbol();
}

//aqu� se llaman a todas las hojas
// O los �ltimos hijos del �rbol, que ya no tienen otros hijos
void listarNodosHojas(arbol_binario* arbol) {

    if (arbol == NULL)
        return;

    if (arbol->l == NULL && arbol->r == NULL)
        cout << arbol->numero << endl;

    listarNodosHojas(arbol->l);
    listarNodosHojas(arbol->r);
}

//Aqu� se llama la atura del arbol
void resultadoAltura() {
    int altura;
    altura = calcularAltura(arbol);
    cout << "La altura del �rbol es: " << altura << endl;
    cout << endl << endl;
    llamandoMenuArbol();
}
//Aqu� se calcula la atura del arbol
int calcularAltura(arbol_binario* arbol) {
    int altura;
    if (arbol == NULL)
        return 0;

    int alturaIzquierda = calcularAltura(arbol->l);
    int alturaDerecha = calcularAltura(arbol->r);

    altura = max(alturaIzquierda, alturaDerecha) + 1;

    return altura;
}

//Este es el men� del arbol, despu�s de que se ingresaron los valores
void llamandoMenuArbol() {
    system("pause");
    system("cls");

    int opcion;
    do {
        cout << endl << endl << "Administrando el �rbol: " << endl;
        cout << "1 - Cu�l es la altura" << endl;
        cout << "2 - Listar todos los nodos internos" << endl;
        cout << "3 - Listar los nodos hojas" << endl;
        cout << "4 - Establecer los siguientes recorridos RDI, DRI, DIR" << endl;
        cout << "5 - Salir" << endl;

        cout << "Escoge una opci�n: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Error: Opci�n inv�lida. Ingrese un n�mero v�lido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
            continue;
        }

        if (opcion < 1 || opcion > 4) {
            cout << "Error: Opci�n inv�lida. Ingrese un n�mero v�lido entre 1 y 4." << endl;
            system("pause");
            system("cls");
        }

    } while (opcion < 1 || opcion > 6);

    switch (opcion) {
        case 1:
            resultadoAltura();
            break;

        case 2:
            cout << endl << endl;
            cout << "LISTA DE NODOS INTERNOS" << endl;
            cout << "=======================" << endl;
            nodosInternos(arbol);
            cout << endl << endl;
            system("pause");
            system("cls");
            break;

        case 3:
            cout << endl << endl;
            cout << "LISTA DE NODOS HOJAS" << endl;
            cout << "====================" << endl;
            nodosHojas(arbol);
            cout << endl << endl;
            break;

        case 4:
            mostrarArbol();
            break;

        case 5:
            break;
    }
}

int main() {
	//Para que se permitan acentos dentro del programa 
    setlocale(LC_ALL, "spanish");

    int num;
    char rpt;
    do {
        cout << "Ingresa un n�mero a agregar al �rbol: " << endl;
        cin >> num;

        if (cin.fail()) {
        cout << "Error: Opci�n inv�lida. Ingrese un n�mero v�lido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        rpt = 'S';
    }
    else {
        insertarNodoArbol(num);  // Corregir el nombre de la funci�n aqu�
        cout << "Desea agregar m�s n�meros (s/n): ";
        cin >> rpt;
        cout << endl;
    }

} while (rpt == 'S' || rpt == 's');

    llamandoMenuArbol();
    cout << "\n\n";

    return 0;
}


