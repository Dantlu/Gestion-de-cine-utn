#ifndef SUBMENUCLIENTES_H_INCLUDED
#define SUBMENUCLIENTES_H_INCLUDED

#include "clsCliente.h"
int subMenuClientes();
void agregarCliente();
void listarCliente();
bool bajaLogicaCliente();

void submenuclientes(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::color::GREEN);
        rlutil::locate(posx-3, posy);
        std::cout << " " << (char)175 << " " << texto << " " << (char)174 << " " << std::endl;
    }
    else {
        rlutil::setBackgroundColor(rlutil::color::BLACK);
        rlutil::locate(posx - 3, posy);
        std::cout << "   " << texto << "   " << std::endl;
    }
    rlutil::setBackgroundColor(rlutil::color::BLACK);
}


int subMenuClientes(){
       int y = 0;
    bool salir = false;
    rlutil::cls();

    rlutil::hidecursor();
   while (salir==false) {

        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        submenuclientes("GESTION DE CLIENTES",47, 5,y==-1);
        submenuclientes("-------------------", 47, 6, y==-2);
        submenuclientes("AGREGAR CLIENTE", 50, 7, y == 0);
        submenuclientes("LISTAR CLIENTES", 50, 8, y == 1);
        submenuclientes("ELIMINAR CLIENTE", 50, 9, y == 2);
        submenuclientes(" VOLVER AL MENU PRINCIPAL ", 45, 10, y == 3);
        rlutil::locate(70, 15);
        switch (rlutil::getkey()) {
        case 119: //arriba
        case 14:
            rlutil::locate(38, 8 + y);
            std::cout << " " << std::endl;
            y--;
            if (y < 0) {
                y = 0;
            }
            break;
        case 115: // abajo
        case 15:
            rlutil::locate(38, 8 + y);
            std::cout << " " << std::endl;
            y++;
            if (y > 3) {
                y = 3;
            }
            break;
        case 1: // enter
            switch (y) {

           case 0:
                     system("cls");
                    agregarCliente();
                    system("pause");
                     system("cls");

                break;
            case 1:
                    system("cls");
                    listarCliente();
                    system("pause");
                     system("cls");

                break;
            case 2:
                system("cls");
                bajaLogicaCliente();
                cout<<"SE DIO DE BAJA EXITOSAMENTE"<<endl;
                system("cls");

                break;
            case 3:

                return 0;
                 system("cls");
                break;
        }
        default:
            break;
        }

    }
    return 0;
}
void agregarCliente(){
    Clientes reg;
    archivoClientes archi("Clientes.dat");
    ///Asignamos valores al objeto de memoria
    reg.Cargar();
    ///Escribimos el registro en el archivo
    if(archi.AgregarRegistro(reg)==true){
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

void listarCliente(){
    archivoClientes archi("Clientes.dat");
    archi.listarRegistros();
}

bool bajaLogicaCliente(){
    ///BUSCAR EL REGISTRO
    archivoClientes archi("Clientes.dat");
    int dni;
    cout<<"INGRESAR EL DNI DEL CLIENTE A DAR DE BAJA ";
    cin>>dni;
    ///VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int pos=archi.buscarDNI(dni);
    ///SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE DNI"<<endl;
        return false;
    }
    ///SI EXISTE, LEER EL REGISTRO
    Clientes reg=archi.leerRegistro(pos);
    if(reg.getDNI()==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
    }
    ///CAMBIAR EL VALOR DEL CAMPO/PROPIEDAD estado
    reg.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(reg, pos);
    return quePaso;
}


#endif // SUBMENUCLIENTES_H_INCLUDED
