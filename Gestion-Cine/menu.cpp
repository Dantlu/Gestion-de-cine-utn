#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "subMenuPeliculas.h"
#include "subMenuClientes.h"
#include "subMenuAlimentos.h"
#include "subMenuVentas.h"
#include "clsPeliculas.h"
#include "clsCliente.h"
#include "clsAlimentos.h"
#include "clsVentas.h"
#include "subMenuConfiguracion.h"
#include "Reportes.h"
#include "funcionesGlobales.h"
void mostrarcolor(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::color::LIGHTBLUE);
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




int menu() {
    int y = 0;
    bool salir = false;

    rlutil::hidecursor();
    while (salir == false) {


        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        mostrarcolor("BIENVENIDO AL SISTEMA DE GESTION DE CINEPOLIS RiLuGuia", 35, 5, y == -1);
        mostrarcolor("GESTIONAR PELICULAS", 50, 8, y == 0);
        mostrarcolor("GESTIONAR CLIENTES", 50, 9, y == 1);
        mostrarcolor("GESTIONAR ALIMENTOS", 50, 10, y == 2);
        mostrarcolor("GESTIONAR VENTAS", 50, 11, y == 3);
        mostrarcolor("MENU CONFIGURACION",50,12,y==4);
        mostrarcolor(" SALIR ", 55, 13, y == 5);


        switch (rlutil::getkey()) {
            case 119: // arriba
            case 14:
                y--;
                if (y < -1) {
                    y = -1;
                }
                break;
            case 115: // abajo
            case 15:
                y++;
                if (y > 5) {
                    y = 5;
                }
                break;
            case 1: // enter
                switch (y) {
                    case -1:
                        rlutil::cls();
                        rlutil::locate(45, 8);
                    rlutil::setColor(rlutil::CYAN);
                    cout<<"========Los Duenios del cine son========";
                    rlutil::locate(30, 9);
                    rlutil::setColor(rlutil::WHITE);
                    cout<<"Dante Luongo: ";
                    rlutil::locate(43, 9);
                    cout<<" 20 Años, jugador de basquet y estudiante de programacion";
                    rlutil::locate(30, 10);
                    rlutil::setColor(rlutil::YELLOW);
                    cout<<"Tomas Munguia: ";
                    rlutil::locate(45, 10);
                    cout<<"18 Anios, amante de los videojuegos, anime y de messi";
                    rlutil::locate(30, 11);
                    rlutil::setColor(rlutil::WHITE);
                    cout<<"Daniel Rios: ";
                    rlutil::locate(45, 11);
                    cout<<"23 Anios, amante del crossfit, anime y videojuegos";
                     rlutil::locate(30, 12);
                    rlutil::setColor(rlutil::CYAN);
                    cout<<"Muchas gracias por visitar nuestro cine! Presione ENTER para volver ";

                    std::cin.ignore();
                    rlutil::cls();
                    return menu();
                        break;
                    case 0:
                        subMenuPeliculas();
                        rlutil::cls();
                        break;
                    case 1:
                        subMenuClientes();
                        rlutil::cls();
                        break;
                    case 2:
                        subMenuAlimentos();
                        rlutil::cls();
                        break;
                    case 3:
                        subMenuVentas();
                        rlutil::cls();
                        break;
                    case 4:
                        subMenuConfiguracion();
                        rlutil::cls();
                        break;
                    case 5:
                        return 0;
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}



