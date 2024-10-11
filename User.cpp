
#include<iostream>
#include<fstream>
#include<sstream>

#include <string>
using namespace std;

void listUser(){
ifstream archive("user.csv", ios::in);
     if (!archive)
     {
        cout<<"No se encontro el archivo deseado (user.csv)"<<endl;

     }else{
        string dataUser;
        while (getline(archive,dataUser))
        {
            cout<<dataUser<<endl;
        }
        
        archive.close();
     }
     

}
     



void createUser(){
        ofstream archive("user.csv");
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

            cout<<"Ingrese el número de telefono: "<<endl;
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
        cout<<"2. Listado de usuarios"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>option;
        switch (option)
        {
        case 1:
            createUser(); break;
        case 2:
            listUser(); break;
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

