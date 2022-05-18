#include <iostream>
#include <fstream>
#include "login.h"
#include "impuestos.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

int escribirOpcion();
void crearArchivoCredito();
void nuevoRegistro( fstream& );
void consultarRegistro( fstream& );
void buscarRegistro(fstream&);
int obtenerId( const char * const );
void mostrarLineaPantalla( const impuestos &);
void actualizarRegistro( fstream& );
void mostrarLinea( ostream&, const impuestos & );
void eliminarRegistro( fstream& );
void calcularSueldo(fstream&);
void obtenerSueldo( const char * const);
void conceptosS();


void menuGeneral();
void mantenimientos();


int main()
{
    bool accesoUsuarios;
    login usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
    if (accesoUsuarios){
        menuGeneral();
    }




    system("cls");
    cout<<"\n\t\t\t          ** Hasta la proxima **"<<endl;

   return 0;


}

void menuGeneral(){
    system("cls");
    int choice;
	//char x;
	do
    {
	system("cls");
	cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t    | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t  1. Manteniminetos"<<endl;
    cout << "\t\t\t  2. Generacion de Nomina"<<endl;
    cout << "\t\t\t  3. Informes de Nomina"<<endl;
    cout << "\t\t\t  4. Transferencia bancaria"<<endl;
    cout << "\t\t\t  5. Generación de Poliza"<<endl;
    cout << "\t\t\t  6. Impuestos"<<endl;
    cout << "\t\t\t  7. Salir"<<endl;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Selecciona tu opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	/*do
    	{*/
    		mantenimientos();
    		/*cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;
	case 2:
		//display();
		break;
	case 3:
		//modify();
		break;
	case 4:
		//search();
		break;
    case 5:
        //XD();
        break;
    case 6:
        //();
        break;
	case 7:
	    exit(0);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 7);
}
void mantenimientos(){
    int choice;
    char s;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t      | Menu Mantenimientos - Grupo 6 |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Mantenimiento de Empleados"<<endl;
        cout << "\t\t\t  2. Mantenimiento de Puestos"<<endl;
        cout << "\t\t\t  3. Mantenimiento de Departamentos"<<endl;
        cout << "\t\t\t  4. Mantenimiento de Impuestos"<<endl;
        cout << "\t\t\t  5. Mantenimiento de Bancos"<<endl;
        cout << "\t\t\t  6. Mantenimiento de Empresas"<<endl;
        cout << "\t\t\t  7. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: ";
        cin>>choice;

        switch(choice)
        {
    case 1:
    	/*do
    	{

    		menu2();
    		cout << "\t\t\t ¿Quieres seguir en el apartado de empleados? (S/N)";
    		cin>>s;
		}while(s=='s'||s=='S');*/
		break;
    case 2:
		//menuprincipal();
		break;
	case 3:
		//menu3();
		break;
	case 4:
		escribirOpcion();
		break;
	case 5:
		//menu5();
		break;
    case 6:
        //menu6();
        break;
	case 7:
		menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 7);

}

//enum Opciones { Ingresar = 1, Consultar = 2, Buscar = 3, Borrar = 4, Conceptos = 5};

int escribirOpcion()
{
    fstream creditoEntradaSalida( "Informacion.dat", ios::in | ios::out | ios::binary);

    if ( !creditoEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      crearArchivoCredito();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );
    }

    int opcionMenu;
    do{
    system("cls");
    cout << "\t\t\t *********************************************" << endl
         << "\t\t\t           | Menu de Conceptos |" << endl
         << "\t\t\t *********************************************" << endl
         << "\t\t\t 1 - Ingresar informacion salarial" << endl
         << "\t\t\t 2 - Desplegar informacion salarial" << endl
         << "\t\t\t 3 - Buscar inforacion salarial" << endl
         << "\t\t\t 4 - Borrar informacion salarial "<< endl
         << "\t\t\t 5 - Conceptos "<< endl
         << "\t\t\t 6 - Salir "<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Ingresa tu opcion [1/2/3/4/5/6]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\n\t\t\t Opcion: ";


   int opcion;
   cin >> opcionMenu;


      switch ( opcionMenu ) {

         case 1:
            nuevoRegistro( creditoEntradaSalida );
            break;

         case 2:
            consultarRegistro( creditoEntradaSalida );
            break;

         case 3:
            buscarRegistro(creditoEntradaSalida);
            break;

         case 4:
            eliminarRegistro( creditoEntradaSalida );
            break;

         case 5:
            conceptosS();
            break;
         case 6:


         default:
            cerr << "Opcion incorrecta" << endl;
            break;

      }

      creditoEntradaSalida.clear();



   return opcion;
    }while ( ( opcionMenu = escribirOpcion() ) != 6 );
}

void nuevoRegistro( fstream &insertarEnArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el ID que desea asignar: " );

   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   impuestos persona;
   insertarEnArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   if ( persona.obtenerNumeroId() == 0 ) {

      char usuario[ 10 ];
      double sueldo;

      cout << "Escriba el nombre de usuario: " << endl;
      cin >> setw( 10 ) >> usuario;
      cout << "Escriba el sueldo: " << endl;
      cin >> sueldo;

      persona.establecerUsuario( usuario );
      persona.establecerSueldo( sueldo );
      persona.establecerNumeroId( numeroId );

      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( impuestos ) );

      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &persona ),
         sizeof( impuestos ) );

   }

   else
      cerr << "La cuenta # " << numeroId
           << " ya contiene informacion." << endl;

char ctrl;
    cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        escribirOpcion();
    }


}

void consultarRegistro( fstream &leerDeArchivo )
{
    system("cls");
   cout << left << setw( 10 ) << "ID" << setw( 14 ) << "Usuario" << right<< setw( 10 ) << "Sueldo" << endl;

   leerDeArchivo.seekg( 0 );

   impuestos persona;
   leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   while ( !leerDeArchivo.eof() ) {

      if ( persona.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(persona);

      leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
         sizeof( impuestos ) );

   }
   char ctrl;
    cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        escribirOpcion();
    }
}

void buscarRegistro( fstream &buscarArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el Id de la persona a buscar: " );

    buscarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

    impuestos persona;
   buscarArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   if ( persona.obtenerNumeroId() != 0 ) {
      mostrarLinea( cout, persona );
   }

   else
      cerr << "La cuenta #" << numeroId
         << " no tiene informacion." << endl;

    char ctrl;
    cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        escribirOpcion();
    }

}

void eliminarRegistro( fstream &eliminarDeArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el Id de la persona a eliminar: " );

   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   impuestos persona;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   if ( persona.obtenerNumeroId() != 0 ) {
      impuestos clienteEnBlanco;

      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( impuestos ) );

      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( impuestos ) );

      cout << "Informacion #" << numeroId << " eliminada.\n";

   }

   else
      cerr << "La posicion #" << numeroId << " esta vacia.\n";


char ctrl;
    cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        escribirOpcion();
    }

}

void conceptosS()
{
    system("cls");

    cout<<" Cantidades a calcular: "<<endl;
    cout<<" Mensual: "<<endl;
    cout<<" - 4.83% IGSS "<<endl;
    cout<<" + Q250  Bono Incentivo "<<endl;
    cout<<" Anual: "<<endl;
    cout<<" + 100% Bono 14 "<<endl;
    cout<<" + 100% Aguinaldo "<<endl;

    char ctrl;
    cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        escribirOpcion();
    }

}

int obtenerId( const char * const indicador )
{
   int numeroId;

   do {
      cout << indicador << " (1 - 100): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 100 );

   return numeroId;

}

void mostrarLinea( ostream &salida, const impuestos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

}

void mostrarLineaPantalla( const impuestos &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

}

void crearArchivoCredito()
{
    ofstream creditoSalida( "Informacion.dat", ios::out | ios::binary );
   if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   impuestos clienteEnBlanco;

   for ( int i = 0; i < 100; i++ )
      creditoSalida.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( impuestos ) );
}
