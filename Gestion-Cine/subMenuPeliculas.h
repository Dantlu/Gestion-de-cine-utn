#ifndef SUBMENUPELICULAS_H_INCLUDED
#define SUBMENUPELICULAS_H_INCLUDED

#include "clsPeliculas.h"

int subMenuPeliculas();
void agregarPelicula();
void listarPelicula();
bool bajaLogicaPelicula();


void submenupeliculas(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::color::CYAN);
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


int subMenuPeliculas(){
       int y = 0;
    bool salir = false;
    rlutil::cls();

    rlutil::hidecursor();
   while (salir==false) {

        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        submenupeliculas("GESTION DE PELICULAS",47, 5,y==-1);
        submenupeliculas("--------------------",47, 6,y==-2);
        submenupeliculas("AGREGAR PELICULA", 50, 7, y == 0);
        submenupeliculas("LISTAR PELICULAS", 50, 8, y == 1);
        submenupeliculas("ELIMINAR PELICULA", 50, 9, y == 2);
        submenupeliculas(" VOLVER AL MENU PRINCIPAL ", 45, 10, y == 3);
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
                    agregarPelicula();
                    system("pause");
                     system("cls");

                break;
            case 1:
                    system("cls");
                    listarPelicula();
                    system("pause");
                     system("cls");

                break;
            case 2:
                system("cls");
                bajaLogicaPelicula();
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

void agregarPelicula(){
     archivoPeliculas archi("Pelicula.dat");
     int contID = archi.contarRegistros();
     Pelicula reg;
    ///Asignamos valores al objeto de memoria
    reg.Cargar();
    reg.setID(contID + 1);
    ///Escribimos el registro en el archivo
    if(archi.AgregarRegistro(reg)==true){
        cout<<"REGISTRO AGREGADO"<<endl;;
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

void listarPelicula(){
    archivoPeliculas archi("Pelicula.dat");
    archi.listarRegistros();
}

bool bajaLogicaPelicula(){
    ///BUSCAR EL REGISTRO
    archivoPeliculas archi("Pelicula.dat");
    int ID;
    cout<<"INGRESAR EL ID DE LA PELICULA QUE QUIERE DAR DE BAJA ";
    cin>>ID;
    ///VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int pos=archi.buscarID(ID);
    ///SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE ID"<<endl;
        return false;
    }
    ///SI EXISTE, LEER EL REGISTRO
    Pelicula reg=archi.leerRegistro(pos);
    if(reg.getID()==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
    }
    ///CAMBIAR EL VALOR DEL CAMPO/PROPIEDAD estado
    reg.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(reg, pos);
    return quePaso;
}




#endif // SUBMENUPELICULAS_H_INCLUDED
