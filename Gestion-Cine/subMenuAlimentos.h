#ifndef SUBMENUALIMENTOS_H_INCLUDED
#define SUBMENUALIMENTOS_H_INCLUDED
#include "clsAlimentos.h"
int subMenuAlimentos();
void agregarAlimentos();
void listarAlimentos();
bool ModificarPrecio();
bool bajaLogicaAlimentos();
void submenualimentos(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::color::MAGENTA);
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


int subMenuAlimentos(){
       int y = 0;
    bool salir = false;
    rlutil::cls();

    rlutil::hidecursor();
   while (salir==false) {

        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        submenualimentos("GESTION DE PRODUCTOS",47, 5,y==-1);
        submenualimentos("--------------------", 47, 6, y==-2);
        submenualimentos("AGREGAR PRODUCTO", 50, 7, y == 0);
        submenualimentos("LISTAR PRODUCTOS", 50, 8, y == 1);
        submenualimentos("MODIFICAR PRECIO", 50, 9, y == 2);
        submenualimentos("DAR DE BAJA UN ALIMENTO",50,10,y==3);
        submenualimentos("VOLVER AL MENU PRINCIPAL ", 48, 11, y == 4);
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
            if (y > 4) {
                y = 4;
            }
            break;
        case 1: // enter
            switch (y) {

           case 0:
                     system("cls");
                    agregarAlimentos();
                    system("pause");
                     system("cls");

                break;
            case 1:
                    system("cls");
                    listarAlimentos();
                    system("pause");
                     system("cls");

                break;
            case 2:
                    system("cls");
                    cout<<"===DEBIDO A LA INFLACION NOS VEMOS EN LA OBLIGACION DE MODIFICAR EL PRECIO DE LOS PRODUCTOS==="<<endl;
                    ModificarPrecio();
                    system("cls");
                break;
            case 3:
                system("cls");
               bajaLogicaAlimentos();
                cout<<"SE DIO DE BAJA EXITOSAMENTE"<<endl;
                system("cls");

                break;
            case 4:
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

void agregarAlimentos(){
    Alimentos reg;
    archivoAlimentos archi("Alimentos.dat");
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

void listarAlimentos(){
    archivoAlimentos archi("Alimentos.dat");
    archi.listarRegistros();
}

bool ModificarPrecio() {
    archivoAlimentos archi("Alimentos.dat");
    int COD;
    cout << "INGRESE EL CODIGO DEL PRODUCTO QUE QUIERE CAMBIAR EL PRECIO: ";
    cin >> COD;

    int pos = archi.buscarCodigoAlimento(COD);

    if (pos == -1) {
        cout << "NO EXISTE UN REGISTRO CON ESE ID" << endl;
        return false;
    }

    Alimentos reg=archi.leerRegistro(pos);

    if (reg.getCodigoAlimento() == -1) {
        cout << "NO EXISTE EL REGISTRO" << endl;
        return false;
    }

    int nuevoprecio;
    cout << "---NUEVO PRECIO DEL PRODUCTO---" << endl;
    cout << "PRECIO: ";
    cin >> nuevoprecio;


    reg.setPrecio(nuevoprecio);
    bool quePaso = archi.modificarRegistro(reg, pos);
    return quePaso;
}

bool bajaLogicaAlimentos(){
    ///BUSCAR EL REGISTRO
    archivoAlimentos archi("Alimentos.dat");
    int COD;
    cout<<"INGRESAR EL ID DEL ALIMENTO QUE QUIERE DAR DE BAJA ";
    cin>>COD;
    ///VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int pos=archi.buscarCodigoAlimento(COD);
    ///SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE ID"<<endl;
        return false;
    }
    ///SI EXISTE, LEER EL REGISTRO
    Alimentos reg=archi.leerRegistro(pos);
    if(reg.getCodigoAlimento()==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
    }
    ///CAMBIAR EL VALOR DEL CAMPO/PROPIEDAD estado
    reg.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(reg, pos);
    return quePaso;
}


#endif // SUBMENUALIMENTOS_H_INCLUDED
