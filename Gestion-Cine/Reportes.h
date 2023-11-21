#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include "subMenuVentas.h"
#include "clsVentas.h"
#include "clsDetalleventas.h"

void subMenuReportes();
void listarTickets();
void listarPorMes();

void submenureportes(const char* texto, int posx, int posy, bool seleccionado) {
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
void subMenuReportes(){
       int y = 0;
    bool salir = false;
    rlutil::cls();

    rlutil::hidecursor();
   while (salir==false) {
        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        submenuclientes("REPORTES",47, 5,y==-1);
        submenureportes("--------",47, 6,y==-2);
        submenuclientes("LISTAR TODOS LOS REPORTES", 45, 7, y == 0);
        submenuclientes("LISTAR REPORTES POR MES POR MES", 45, 8, y == 1);
        submenuclientes(" VOLVER AL MENU PRINCIPAL ", 44, 9, y == 2);
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
                    listarTickets();
                    system("pause");
                     system("cls");

                break;
            case 1:
                    system("cls");
                    listarPorMes();
                    system("pause");
                     system("cls");

                break;
            case 2:
                      return ;
                 system("cls");
                break;
        }
        default:
            break;
        }

    }
    return ;
}

void listarTickets(){
    archivoVentas archi("Ventas.dat");
    archi.listarRegistros();
}

void listarPorMes(){
    int mes;
    Ventas venta;
    archivoVentas archi("Ventas.dat");

    cout<<"INGRESE EL MES DE LAS VENTAS QUE QUIERE LISTAR: ";
    cin>>mes;
    if(mes>=1 && mes<=12){
        if(mes == venta.getFechaVenta().getMes()){
            archi.listarRegistros();
        }
    }
}

#endif // REPORTES_H_INCLUDED
