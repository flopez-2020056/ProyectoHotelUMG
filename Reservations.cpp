
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void createReservation() {
    ofstream archive("reservation.txt", ios::app);
    if (!archive) {
        cout << "Error al crear el archivo reservation.txt revisa tu código." << endl;
    } else {
        string userName, entryDate, departureDate, description;
        double priceRoom = 0, roomCode, totalPrice = 0;
        char continueR;

        cout << "Datos del cliente" << endl << endl;

        cout << "Nombre del cliente" << endl;
        cin.ignore();
        getline(cin, userName);
        cout << "Ingresa la fecha de ingreso (dia/mes/año)" << endl;
        getline(cin, entryDate);
        cout << "Ingresa la fecha de salida (dia/mes/año)" << endl;
        getline(cin, departureDate);

        do {
            cout << endl << "Datos de la habitacion a reservar" << endl << endl;
            cout << "Tipos de habitaciones disponibles" << endl;
            cout << "codigo   Tipo de habitacion" << endl;
            cout << "1.       Habitacion grande   Q400" << endl;
            cout << "2.       Habitacion mediana  Q300" << endl;
            cout << "3.       Habitacion pequeña  Q500" << endl;
            cout << "4.       Habitacion doble    Q800" << endl;
            cout << endl;

            cout << "Ingrese el código de la habitacion" << endl;
            cin >> roomCode;

            switch (static_cast<int>(roomCode)) {
                case 1:
                    description = "Habitacion grande";
                    priceRoom = 400;
                    cout << "Escogiste la " << description << " con un precio de Q" << priceRoom << endl;

                    break;
                case 2:
                    description = "Habitacion mediana";
                    priceRoom = 300;
                    cout << "Escogiste la " << description << " con un precio de Q" << priceRoom << endl;
                    break;
                case 3:
                    description = "Habitacion pequeña";
                    priceRoom = 500;
                    cout << "Escogiste la " << description << " con un precio de Q" << priceRoom << endl;
                    break;
                case 4:
                    description = "Habitacion doble";
                    priceRoom = 800;
                    cout << "Escogiste la " << description << " con un precio de Q" << priceRoom << endl;
                    break;
                default:
                    cout << "Código de habitación no válido. Intente nuevamente." << endl;
                    continue;
            }

            totalPrice += priceRoom;

            archive << userName << ";" << entryDate << ";" << departureDate << ";" 
                    << roomCode << ";" << description << ";" << priceRoom << ";" << endl;
             
            cout << endl << "Desea seguir agregando reservaciones? (S/N): ";
            cin >> continueR;
            cout << endl;

        } while (continueR == 'S' || continueR == 's');

        archive.close();

        cout << "Se ingresó de manera correcta la reservación." << endl;
        cout << "Total a pagar por todas las reservaciones: " << totalPrice << endl;
        cout << endl;
    }
}


void findReservationByCode(){
    ifstream archive("reservation.txt", ios::in);
    if (!archive)
    {
        cout<<"No se encontro el archivo deseado (reservation.txt)"<<endl;
    }else {
        string dataReservation;
        string roomCode,userName, entryDate, departureDate, description, priceRoom;
        string numCodeFind;
        cout<<"Ingrese el codigo de la habitación que quiere buscar"<<endl;
        cin>>numCodeFind;
        
        bool exist = false;
        while (getline(archive,dataReservation))
        {
            stringstream token(dataReservation);

            getline(token, userName, ';');
            getline(token, entryDate, ';');
            getline(token, departureDate, ';');
            getline(token, roomCode, ';');
            getline(token, description, ';');
            getline(token, priceRoom, ';');


            


            if (numCodeFind.compare(roomCode) == 0)
            {
                exist = true;
                cout<<""<<endl;
                cout<<"La habitacion con el codigo "<<roomCode<<" es la siguiente: "<<endl;
                cout<<""<<endl;
                //cout<<roomCode<<endl;
                cout<<"Codigo de habitacion: "<<roomCode<<endl;
                //cout<<priceRoom<<endl;
                cout<<"Precio de habitacion: "<<priceRoom<<endl;
                //cout<<description<<endl;
                cout<<"Descripcion de habitacion: "<<description<<endl;
                //cout<<departureDate<<endl;
                cout<<"fecha de entrada de habitacion: "<<entryDate<<endl;
                //cout<<entryDate<<endl;
                cout<<"Fecha de salida de habitacion: "<<departureDate<<endl;
                cout<<""<<endl;
                //cout<<userName<<endl;
            }
            
            
        }
        archive.close();
        if (!exist)
        {
            cout<<"La habitacion con el codigo "<<numCodeFind<<" no existe"<<endl;
        }
        
    }
    

}


void getUser(){
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

            cout<<""<<endl;
            cout<<"Usuario del hotel"<<endl;
            cout<<""<<endl;
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

            cout<<"error al crear el archivo user.txt"<<endl;

        }else{

            long id_user, telephoneNumber;
            string name, city, email;

            cout<<"Ingrese el id de usuario:  "<<endl;
            cin>>id_user;
            cin.ignore();
            
            cout<<"Ingrese el nombre del usuario: "<<endl;
            //cin>>name;
            getline(cin,name);

            cout<<"Ingrese la ciudad del usuario: "<<endl;
            //cin>>city;
            getline(cin,city);

            cout<<"Ingrese el telefono del usuario:  "<<endl;
            cin>>telephoneNumber;
            cin.ignore();
            
            cout <<"Ingrese el correo del usuario: "<<endl;
            //cin>>email;
            getline(cin,email);

            archive<<id_user<<";"<<name<<";"<<city<<";"<<telephoneNumber<<";"<<email<<endl;

            archive.close();

            cout<<""<<endl;
            cout<<"Se ingreso correctamente el cliente del hotel."<<endl<<endl;


        }
    
}




void menu(){
    int option;
    do{
        cout<<"-Menu de opciones-"<<endl;
        cout<<""<<endl;
        cout<<"1. Crear cliente."<<endl;
        cout<<"2. Listado de clientes."<<endl;
        cout<<"3. Crear una reservacion en el hotel."<<endl;
        cout<<"4. Listar las reservaciones del hotel por codigo de habitación."<<endl;
        cout<<"0. Salir"<<endl;
        cout<<""<<endl;
        cout<<"Seleccione una opcion: "<<endl;
        cout<<""<<endl;
        cin>>option;
        cout<<"   "<<endl;
        switch (option)
        {
        case 1:
            createUser(); break;
        case 2:
            getUser(); break;
        case 3:
            createReservation(); break;
        case 4:
            findReservationByCode(); break;
        case 0:
            cout<<"Esta saliendo de la aplicación, vuelva pronto!!!"<<endl;; break;
        default:
            cout<<"La opcion que se esta usando no existe en el listado del hotel :("<<endl;
            break;
        }
    }while(option != 0);
}

int main(){
    menu();
    return 0;
}


