#include<iostream>
#include<limits>
#include <cstring>
#include<locale.h> // Incluir locale.h para habilitar los acentos en consola

using namespace std;

void mostrarCola(int& cantidadCarros);
void mostrarListaEspCar(int& cantidadCarros);
void ingresoCliente(int& cantidadCarros);
bool esNumero(const string& str);
void Menu(int& cantidadCarros);
void anadirElementoCola(int& cantidadCarros);
void removerElementoCola(int& cantidadCarros);
void insertarListaCliente(char nombre[40],bool carroOcupado);
void mostrarListaEspCli();


struct Cola
{
	char name[40];
	
	struct Cola* prev;
};


struct Cliente {
   char name[40];
   bool carroOcupado;
   
   Cliente *sgte;
};

struct Cola* cajaDeCobros[6] = {NULL};
Cliente *listaClientes = NULL;





int main()
{	
	setlocale(LC_ALL, ""); // Establecer la configuración regional para habilitar los acentos
	int cantidadCarros = 50; //se coloca la cantidad de carritos disponibles en el supermercado
	Menu(cantidadCarros);
	return 0;
}


void Menu(int& cantidadCarros) {
	
    int option;
    string input;

    do {
    	//MENÚ DEL SUPERMERCADO
        cout << endl << endl << "COLAS EN UN SUPERMERCADO:" << endl;
        cout << endl << endl << "Iniciando simulacion:" << endl;
        
        cout << "1 - Ingreso de cliente."<<endl;
        cout << "2 - Mostrar Lista de Clientes con carrito de compras."<<endl;
        cout << "3 - Mostrar Cola." << endl;
        cout << "4 - Agregar cliente a cola." << endl;
        cout << "5 - Atender a cliente." << endl;
        cout << "6 - Salir." << endl;
        cout << "Ingrese la opción: ";

        cin >> option;
        
		if (cin.fail()) {
            cout << "Opcion invalida. Ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
            continue;
        }

        if (option < 1 || option > 7) {
            cout << "Opcion invalida. Ingrese un numero valido entre 1 y 4." << endl;
            system("pause");
            system("cls");
        }
        
	}
	while (option < 1 || option > 5);
	
	switch (option) {
	//SE LLAMA A CADA RESPECTIVA FUNCIÓN PARA REALIZAR CADA OPERACIÓN 
		case 1: ingresoCliente(cantidadCarros); break;
	    case 2: mostrarListaEspCar(cantidadCarros); break;
	    case 3: mostrarCola(cantidadCarros); break;
	    case 4: anadirElementoCola(cantidadCarros); break;
	    case 5: removerElementoCola(cantidadCarros); break;
	    case 6: break;
		default: cout << "Opcion invalida. Intente nuevamente. "<<endl;
	}
		

}

void ingresoCliente(int& cantidadCarros)
{
	char nombre[40];
	bool carroOcupado;
	//Se pide el nombre del cliente para registrarlo
    cout << "Ingrese el nombre del nuevo cliente: ";
    cin >> nombre;
    if(cantidadCarros == 0)
    {
    	carroOcupado = true;
    	//En caso no hayan carritos disponibles
    	cout << "Espere su turno. No hay carros disponibles :("<<endl;
	}
	else
	{
		carroOcupado = false;
	//Si los carros no están ocupados, se ingresa correctamente
        cout << "El elemento se ingreso con exito .... ;D\n"<< endl;
	    
	    cantidadCarros = cantidadCarros - 1;
	}
	
	insertarListaCliente(nombre, carroOcupado);
	
	mostrarListaEspCli();
	
    Menu(cantidadCarros);
}



void insertarListaCliente(char nombre[40],bool carroOcupado)
{
	struct Cliente *nuevoCliente = new Cliente[1];
	strcpy(nuevoCliente->name, nombre);
	//nuevoCliente->name = nombre;
	nuevoCliente->carroOcupado = carroOcupado;
	
	nuevoCliente->sgte = NULL;
	
	struct Cliente* aux = new Cliente[1];
	
	if(listaClientes == NULL) listaClientes = nuevoCliente;
	else
	{
		aux = listaClientes;
		bool agregar = false;
		while(agregar == false)
		{
			if(aux->sgte == NULL)
			{
				aux->sgte = nuevoCliente;
				agregar = true;
			}	
			else
			{
				aux = aux->sgte;
			}
		}
	}
		
	
	
	nuevoCliente = NULL;
	delete[] nuevoCliente;
	aux = NULL;
	delete[] aux;
}

void mostrarListaEspCli()
{
	struct Cliente *aux = listaClientes;
	bool hayClientesEnEspera = false;
	
	cout << endl;
	cout << "Lista de los clientes en espera: "<<endl << endl;
	
		for(int i=1; aux != NULL; i++)
		{
			if(aux->carroOcupado == true)
			{
				cout << "Cliente " << i << ": " << aux->name << endl;
				aux = aux->sgte;
				hayClientesEnEspera = true;	
			}
			else
			{
				aux = aux->sgte;
			}
		}
		
	if (!hayClientesEnEspera)
    {
        cout << "No hay clientes en espera en este momento." << endl;
        system("pause");
		system("cls");	
    }
}	



void mostrarCola(int& cantidadCarros)
{
	
	for(int i=0;i < 6; i++)
	{
		if(cajaDeCobros[i])
		{	
			cout << "CAJA " << i+1 << endl;
		
			struct Cola* aux = cajaDeCobros[i];
			for(int posicion=1; aux; posicion++)
			{
				cout << "Cliente " << posicion << " en la caja "<<i+1<<" : " << aux->name<<endl;
				aux = aux->prev; 
			}
			
		}
		else
		{
			cout << "No hay clientes en la caja"<<i+1<<"."<<endl;
		}
		cout <<"-------------------------------------"<<endl;
		system("pause");
		system("cls");	
	}	
	

	Menu(cantidadCarros);
}

void anadirElementoCola(int& cantidadCarros)
{
	char cliente[40];
	struct Cola colaCliente;
	struct Cliente *aux = listaClientes;
	bool nombreExiste = false;
	
	cout << "Ingrese el nombre del nuevo cliente en la cola: ";
	cin >> cliente;
	
	int contador=0;
	cout << endl<<endl;
	
	for(contador; aux != NULL; contador++)
	{
		if(strcmp(cliente, aux->name) == 0)
		{
			cout << "Cliente "<<cliente<<" encontrado " << endl;
			nombreExiste = true;
			break;	
		}
		else
		{
			aux = aux->sgte;
		}
	}
	
	if (!nombreExiste)
    {
        cout << "No se encontro el cliente :(" << endl;
    }
    else if(aux->carroOcupado)
    {
    	cout << "El cliente esta en espera. No se puede agregar a la cola."<<endl;
	}
	else
	{
		//El dato que le sigue en una cola es NULL;
		colaCliente.prev = NULL;
		strcpy(colaCliente.name,cliente);
		
		int minClientes = INT_MAX;
		int contadorCaja = -1;
		
		for(int i=0; i<6; i++)
		{
			int cantidadClientes = 0;	
			
			struct Cola* auxCola = cajaDeCobros[i];
			
			while(auxCola)
			{
				cantidadClientes++;
				
				auxCola = auxCola->prev;
			}
			
			if(cantidadClientes < minClientes)
			{
				minClientes = cantidadClientes;
				contadorCaja = i;
			}
		}
	
		
		if(contadorCaja == -1)
		{
			cout << "Todas las cajas estan ocupadas!!!"<<endl;
			delete &cliente;
		}
		else
		{
			//AÃ±ade un nuevo dato a la cola cuando va a recibir su primer dato por primera vez en la cola
			if(cajaDeCobros[contadorCaja] == NULL) cajaDeCobros[contadorCaja] = &colaCliente;
			else{
				struct Cola* posicionCaja = cajaDeCobros[contadorCaja];
				//Recorre cuando tenga datos y el bucle terminara cuando este en el ultimo de la cola
				while(posicionCaja->prev != NULL) posicionCaja = posicionCaja->prev;
				
				//AÃ±ade el nuevo dato en la cola
				posicionCaja->prev = &colaCliente;
			}	
		}
			
	}
	
	Menu(cantidadCarros);
}

	
void removerElementoCola(int& cantidadCarros)
{
	int caja;
	cout << "En que caja desea atender al cliente? 1-6 "<<endl;
	cin >> caja;
	caja--;
	
	if(caja < 0 || caja >= 6 || cajaDeCobros[caja] == NULL)
	{
		cout << "No se puede atender a nadie en la caja seleccionada!" << endl;
	}
	else
	{
		
		struct Cola* cliente = cajaDeCobros[caja];
		struct Cliente* auxCliente = listaClientes;
		struct Cliente* clienteEncontrado = NULL;
		
		cout << "El cliente "<< cajaDeCobros[caja]->name << " fue atendido." <<endl;
		
		if (listaClientes == NULL) {
        	cout << "La lista de clientes está vacía." << endl;
        	
    	}

	    Cliente* anterior = NULL;
	    Cliente* actual = listaClientes;
	
	    while (actual != NULL) {
	        if (strcmp(actual->name, cajaDeCobros[caja]->name) == 0) {
	            // El cliente se encuentra en la lista, se procede a eliminarlo
	
	            // Si es el primer elemento de la lista
	            if (anterior == NULL) {
	                listaClientes = actual->sgte;
	            } else {
	                anterior->sgte = actual->sgte;
	            }
	
	            delete actual;
	            cout << "El cliente '" << cajaDeCobros[caja]->name << "' ha sido removido de la lista." << endl;
	            
	        }
	
	        anterior = actual;
	        actual = actual->sgte;
	    }
		
		for(int i=0; auxCliente != NULL; i++)
		{
			if(auxCliente->carroOcupado == true)
			{
				auxCliente->carroOcupado = false;
				break;
			}
			else
			{
				auxCliente = auxCliente->sgte;
			}
		}
		
		cliente = cajaDeCobros[caja];
		
		cajaDeCobros[caja] = cajaDeCobros[caja]->prev;		
		
		
		
		cantidadCarros = cantidadCarros + 1;
		cliente->prev = NULL;
		cliente = NULL;
		delete cliente;
	}
	
	Menu(cantidadCarros);		
}

void mostrarListaEspCar(int& cantidadCarros)
{
	struct Cliente *aux = listaClientes;
	struct Cliente *aux2 = listaClientes;
	bool bandera = false;
	bool bandera2 = false;
	
	cout << endl;
	cout << "Lista de cliente con carritos: "<<endl << endl;
	
	for(int i=1; aux != NULL; i++)
	{
		
		if(aux->carroOcupado == false)
		{
			cout << "- " << aux->name << endl;
			bandera = true;		
		}
		aux = aux->sgte;
	}
	
	if(bandera == false)
	{
		cout << "No hay ningun cliente."<<endl;		
	}
	
	cout << "Lista de espera de clientes sin carritos: "<<endl << endl;
	for(int i=1; aux2 != NULL; i++)
	{
		if(aux2->carroOcupado == true)
		{
			cout << "- " << aux2->name << endl;
			bandera2 = true;	
		}
		aux2 = aux2->sgte;
	}
	
			
	if(bandera2 == false)
	{
		cout << "No se encuentra ningun cliente en espera."<<endl;
		system("pause");
		system("cls");
	}
	
	Menu(cantidadCarros);
}

