#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

#include "clsVentas.h"
#include "Reportes.h"
int subMenuVentas();
void agregarVenta();
void subMenuReportes();

void submenuventas(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::color::RED);
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


int subMenuVentas(){
       int y = 0;
    bool salir = false;
    rlutil::cls();

    rlutil::hidecursor();
   while (salir==false) {

        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        submenuventas("GESTION DE VENTAS",47, 5,y==-1);
        submenuventas("-----------------",47, 6, y==-2);
        submenuventas("AGREGAR VENTA", 50, 7, y == 0);
        submenuventas("IMPRIMIR REPORTES", 50, 8, y == 1);
        submenuventas(" VOLVER AL MENU PRINCIPAL ", 45, 9, y == 2);
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
            if (y > 2) {
                y = 2;
            }
            break;
        case 1: // enter
            switch (y) {

           case 0:
                    system("cls");
                    agregarVenta();
                    system("pause");
                    system("cls");

                break;
            case 1:
                    system("cls");
                    subMenuReportes();
                    system("pause");
                    system("cls");

                break;
            case 2:

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

void agregarVenta(){
    Ventas reg;
    archivoVentas archi("Ventas.dat");
    reg.Cargar();
    if(archi.AgregarRegistro(reg)==true){
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

void listarVenta(){
    archivoVentas archi("Ventas.dat");
    archi.listarRegistros();
}




#endif // SUBMENUVENTAS_H_INCLUDED
