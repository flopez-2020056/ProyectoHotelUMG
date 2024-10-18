
#include<iostream>
#include<fstream>
#include<sstream>

#include <string>
using namespace std;


void createReservation(){
    ofstream archive("reservation.txt", ios::app);
    if (!archive)
    {
        cout<<"Error al crear el archivo reservation.txt revisa tu código.";
    } else {
        string userName, entryDate, departureDate, description;
        double priceRoom, roomCode;
        char continueR;

        cout<<"Datos del cliente"<<endl<<endl;

        cout<<"Nombre del cliente"<<endl;
        cin.ignore();
        //cin>>userName;
        getline(cin, userName);
        cout<<"Ingresa la fecha de ingreso"<<endl;
        //cin>>entryDate;
        getline(cin, entryDate);
        cout<<"Ingresa la fecha de salida"<<endl;
        //cin>>departureDate;
        getline(cin, departureDate);
        do
        {
            cout<<"Datos de la habitacion a reservar"<<endl<<endl;

            cout<<"Ingrese el código de la habitacion"<<endl;
            cin>>roomCode;
            cin.ignore();
            cout<<"Ingrese la descripcion de la habitacion"<<endl;
            //cin>>description;
            getline(cin, description);
            cout<<"Ingrese el precio de la habitacion"<<endl;
            cin>>priceRoom;

            archive<<userName<<";"<<entryDate<<";"<<departureDate<<";"<<roomCode<<";"<<description<<";"<<priceRoom<<";"<<endl;
             
            cout<<"Desea seguir agregando reservaciones? (S/N)";
            cin>>continueR;


           
        } while (continueR == 'S' || continueR == 's');

        archive.close();

        cout<<"Se ingreso de manera correta la habitacion";
        
    }
    
}


void listUser(){
ifstream archive("user.txt", ios::in);
     if (!archive)
     {
        cout<<"No se encontro el archivo deseado (user.csv)"<<endl;

     }else{
        string dataUser;
        string name, city, email,id_user, telephoneNumber;
        while (getline(archive,dataUser))
        {
            //cout<<dataUser<<endl;
            stringstream token(dataUser);

            getline(token, id_user, ';');
            getline(token, telephoneNumber, ';');
            getline(token, name, ';');
            getline(token, city, ';');
            getline(token, email, ';');

            cout<<id_user<<endl;
            cout<<telephoneNumber<<endl;
            cout<<name<<endl;
            cout<<city<<endl;

        }
        
        archive.close();
     }
     

}
     



void createUser(){
        ofstream archive("user.txt", ios::app);
        if (!archive)
        {
            cout<<"error al crear el archivo user.csv"<<endl;
        }else{
            long id_user, telephoneNumber;
            string name, city, email;

            cout<<"Ingrese el id de usuarion:  "<<endl;
            cin>>id_user;
            
            cout<<"Ingrese el nombre del usuario: "<<endl;
            cin>>name;

            cout<<"Ingrese la ciudad del usuario: "<<endl;
            cin>>city;

            cout<<"Ingrese el telefono del usuario:  "<<endl;
            cin>>telephoneNumber;
            
            cout <<"Ingrese el correo del usuario: "<<endl;
            cin>>email;

            archive<<id_user<<";"<<name<<";"<<city<<";"<<telephoneNumber<<";"<<email<<endl;

            archive.close();

            cout<<"Se ingreso correctamente el cliente del hotel."<<endl<<endl;


        }
    
}

void menu(){
    int option;
    do{
        cout<<"Menu de opciones"<<endl;
        cout<<"1. Crear cliente"<<endl;
        cout<<"2. Listado de clientes"<<endl;
        cout<<"3. crear una reservacion en el hotel"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: "<<endl;
        cin>>option;
        cout<<"   "<<endl;
        switch (option)
        {
        case 1:
            createUser(); break;
        case 2:
            listUser(); break;
        case 3:
            createReservation(); break;
        case 0:
            cout<<"Esta saliendo de la aplicación, vuelva pronto";       
        default:
            cout<<"La opcion que se esta usando no existe en el listado del hotel";
            break;
        }
    }while(option != 0);
}

int main(){
    menu();
    return 0;
}


