#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED
#include <iostream>
#include <cstring>
#include "funcionesGlobales.h"
#include "clsDetalleVentas.h"
#include "subMenuClientes.h"
#include "clsCliente.h"
using namespace std;
void Vectordinamico(int num);
class Ventas{
private:
    int _NumeroVenta;
    int _DNIcliente;
    float _MontoCobrado;
    Fecha _FechaVenta;
    int _MetodoDePago;
    int _CantidadEntradas;
    int _IdPelicula;
    bool _estado;
public:
///clase fecha actual tiene que llenar estos campos
    void setDia(int x) {
        _FechaVenta.setDia(x);
    }
    void setMes(int x) {
        _FechaVenta.setMes(x);
    }

    void setAnio(int x) {
        _FechaVenta.setAnio(x);
    }

    void setNumeroVenta(const int NumeroVenta){_NumeroVenta=NumeroVenta;}///hay que poner se se auto numere
    void setDNIcliente(const int DNI){_DNIcliente=DNI;}

    void setMontoCobrado(const float MontoCobrado){_MontoCobrado=MontoCobrado;}
    void setCantidadEntradas(const int CantidadEntradas){_CantidadEntradas=CantidadEntradas;}
    void setIdPelicula(const int IdPelicula){_IdPelicula=IdPelicula;}
    void setMetodoPago(const int metodo){if(metodo>=1&&metodo<=4){_MetodoDePago=metodo;}else{_MetodoDePago=0;}
    }
    void setEstado(bool e){
    _estado=e;
    }
    ///gets
    int getNumeroVenta(){return _NumeroVenta;}
    int getDNIcliente(){return _DNIcliente;}
    float getMontoCobrado(){return _MontoCobrado;}
    int getCantidadEntradas(){return _CantidadEntradas;}
    int getIdPelicula(){return _IdPelicula;}
    int getMetodo(){return _MetodoDePago;}
    Fecha getFechaVenta(){return _FechaVenta;}
    bool getEstado(){return _estado;}

    void Cargar(const int);
    void Mostrar();

};
void cargarventaDeAlimento(int NumeroVenta, float& totaldetalle){
    int codigoAlimento,cantidadAlimento;
    float detalle;
    char opcion;
    Alimentos alimen;
    archivoDetalleVenta archidetalle("DetalleVenta.dat");
    cout<<"DESEA COMPRAR ALIMENTOS: Y/N: ";
        cin>>opcion;

        if(opcion=='Y' || opcion=='y'){

            archivoAlimentos archiA("Alimentos.dat");
            archiA.listarRegistros();
            cout<<"INGRESE EL CODIGO DEL/LOS ALIMENTOS QUE DESEA (0 PARA FINALIZAR): ";
            cin>>codigoAlimento;
    while(codigoAlimento!=0){
            int pos=archiA.buscarCodigoAlimento(codigoAlimento);
            if(pos==-2){
            cout<<"EL ALIMENTO ESTA DADO DE BAJA "<<endl;
            cout<<"TE QUEDA UNA OPORTUNIDAD PARA INGRESAR CORRECTAMENTE UN CODIGO DE ALIMENTO "<<endl;
            cout<<"INGRESE UN CODIGO DE ALIMENTO VALIDO: ";
            cin>>codigoAlimento;
            pos=archiA.buscarCodigoAlimento(codigoAlimento);
            if(pos==-2){
                exit(0);
            }
        }
            if(pos!=-1){
                cout<<"CUANTAS UNIDADES QUIERE DE ESE ALIMENTO: ";
                cin>>cantidadAlimento;
                if(archiA.descontarstock(codigoAlimento,cantidadAlimento)){
                    alimen=archiA.leerRegistro(pos);
                    detalle=alimen.getPrecioUnitario()*cantidadAlimento;
                    DetalleVenta ventasdetalle(NumeroVenta,codigoAlimento,cantidadAlimento,detalle);
                    archidetalle.AgregarRegistro(ventasdetalle);
                }
              ///validar si el estado de todos esta activo
            }else {
                cout<<"NO EXISTE UN ALIMENTO CON ESE CODIGO"<<endl;
                }
            cout<<"INGRESE EL CODIGO DEL/LOS ALIMENTOS QUE DESEA (0 PARA FINALIZAR): ";
            cin>>codigoAlimento;
            totaldetalle=totaldetalle+detalle;
                }
        }
        }
/*
Ventas.dat
numero_venta
ID cliente
metodo de pago
monto_cobrado
Fecha
cantidad_entradas
Id película
*/

void Ventas::Cargar(int nv=-1){
    int NumeroVenta;
    int DNIcliente;
    int metodoPago;
    int CantidadEntradas;
    int IdPelicula;
    Alimentos alimen;
    float totaldetalle=0;
        if(nv==-1){
        cout<<"NUMERO DE VENTA: ";
        cin>>NumeroVenta;
        setNumeroVenta(NumeroVenta);
    }
    else{
        NumeroVenta=nv;
        setNumeroVenta(NumeroVenta);
    }
        cout<<"DNI CLIENTE: ";
        archivoClientes archi("Clientes.dat");
        cin>>DNIcliente;
        int pos=archi.buscarDNI(DNIcliente);
       if(pos==-2){
            cout<<"EL CLIENTE ESTA DADO DE BAJA "<<endl;
            cout<<"TE QUEDA UNA OPORTUNIDAD PARA INGRESAR CORRECTAMENTE UN DNI "<<endl;
            cout<<"INGRESE UN DNI: ";
            cin>>DNIcliente;
            pos=archi.buscarDNI(DNIcliente);
            if(pos==-2){
                exit(0);
            }
        }
        if(pos==-1){
            cout<<"EL CLIENTE NO ESTA CARGADO, HAY QUE AGREGARLO!"<<endl;
            Clientes obj;
            obj.Cargar(DNIcliente);
            archi.AgregarRegistro(obj);
        }
        setDNIcliente(DNIcliente);
        cout<<endl;
        cout<<"LISTADO DE PELICULAS"<<endl;
        cout<<"--------------------"<<endl;
        archivoPeliculas archiP("Pelicula.dat");
        archiP.listarRegistros();
        cout<<endl<<endl;
        cout<<"ID PELICULA: ";
        cin>>IdPelicula;
        int posP=archiP.buscarID(IdPelicula);
        if(posP==-2){
            cout<<"LA PELICULA ESTA DADA DE BAJA "<<endl;
            cout<<"TE QUEDA UNA OPORTUNIDAD PARA INGRESAR CORRECTAMENTE UN ID "<<endl;
            cout<<"INGRESE UN ID DE PELICULA VALIDO: ";
            cin>>IdPelicula;
            posP=archiP.buscarID(IdPelicula);
            if(posP==-2){
                exit(0);
            }
        }
        while(posP==-1){
            cout<<"NO EXISTE UNA PELICULA CON ESTE ID, INGRESE OTRA: ";
            cin>>IdPelicula;
            posP=archiP.buscarID(IdPelicula);
        }
        setIdPelicula(IdPelicula);

        cout<<"CUANTAS ENTRADAS QUIERE: ";
        cin>>CantidadEntradas;
        setCantidadEntradas(CantidadEntradas);

       ///_________
        cargarventaDeAlimento(_NumeroVenta,totaldetalle);
       ///_________
        Pelicula peli;
        cout<<"MONTO A COBRAR: $";
        int total = CantidadEntradas*peli.getPrecio() + totaldetalle;///HACER PRECIO CON CODIGO ALIEMTO

        cout<<total;
        setMontoCobrado(total);
        cout<<endl;

            cout<<"COMO VA A ABONAR (1. tarjeta de debito, 2. tarjeta de credito, 3. efectivo, 4.MercadoPago)"<<endl;
            cout<<"**** ABONANDO CON DEBITO UN 10% DE RECARGO ****"<<endl;
            cout<<"**** ABONANDO CON CREDITO UN 20% DE RECARGO ****"<<endl;
            cout<<"**** ABONANDO EN EFECTIVO HAY 10% DE DESCUENTO ****"<<endl;
            cout<<"METODO DE PAGO: ";
            cin>>metodoPago;
            setMetodoPago(metodoPago);

        if(metodoPago==0){
            cout<<"EL METODO DE PAGO ES INCORRECTO, VUELVE A INGRESARLO"<<endl;


            if(metodoPago==0){
                exit(0);
            }
        }
        if(_MetodoDePago==1){
                cout<<"A COBRAR CON DEBITO: ";
                total=total*1.10;
                cout<<total<<endl;
        }
        if(_MetodoDePago==2){
            cout<<"A COBRAR CON CREDITO: ";
            total=total*1.20;
            cout<<total<<endl;
        }
        if(_MetodoDePago==3){
            cout<<"A COBRAR CON EFECTIVO: ";
            total=total*0.90;
            cout<<total<<endl;
        }

        cout<<"FECHA DE VENTA: "<<endl;
        _FechaVenta.Mostrar();

        _estado=true;

}

void Ventas::Mostrar(){
    if(_estado==true){
        archivoPeliculas archPe("Pelicula.dat");
        Pelicula peli;
        int cant=archPe.contarRegistros();
        cout<<"-------------------------"<<endl;
        cout<<"DNI CLIENTE: "<< _DNIcliente<<endl;
        cout<<"NUMERO DE VENTA: "<<_NumeroVenta<<endl;
        cout<<"CANTIDAD DE ENTRADAS: "<<_CantidadEntradas<<endl;
        cout<<"ID PELICULA: "<<_IdPelicula<<endl;
        for(int i=0;i<cant;i++){
            peli=archPe.leerRegistro(i);
            if(peli.getID()==_IdPelicula){
                cout<<"TITULO: "<<peli.getTitulo()<<endl;
            }
        }
        Vectordinamico(_NumeroVenta);
         if(_MetodoDePago==1){
            _MontoCobrado=_MontoCobrado*1.10;
        }
        if(_MetodoDePago==2){
            _MontoCobrado=_MontoCobrado*1.20;
        }
        if(_MetodoDePago==3){
            _MontoCobrado=_MontoCobrado*0.90;
        }
        cout<<"MONTO TOTAL: $"<<_MontoCobrado<<endl;
        cout<<"FECHA DE VENTA: "<<endl;
        _FechaVenta.Mostrar();
        cout<<"-------------------------"<<endl;

    }
}

class archivoVentas {
private:
    char nombre[35];
public:
    archivoVentas(const char* n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(Ventas reg);
    bool listarRegistros();
    Ventas leerRegistro(int pos);
    int contarRegistros();
    int buscarNumeroVenta(int nv);
    bool modificarRegistro(Ventas reg, int pos);
};

bool archivoVentas::AgregarRegistro(Ventas reg){
    FILE* p = fopen(nombre, "ab");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    int pos = buscarNumeroVenta(reg.getNumeroVenta());

    if (pos == -1) {

        bool escribio = fwrite(&reg, sizeof(Ventas), 1, p);
        fclose(p);
        return escribio;
    } else {
        cout << "YA EXISTE UNA VENTA CON ESTE NUMERO" << endl;
        fclose(p);
        return false;
    }
}

int archivoVentas::buscarNumeroVenta(int nv){
    Ventas reg;
    FILE *pPep;
    pPep=fopen("Ventas.dat","rb");
    if(pPep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Ventas),1,pPep)==1){
        if(reg.getNumeroVenta()==nv){
                if(reg.getEstado()==false){
                    fclose(pPep);
                    return -2;
                           }else{
         fclose(pPep);
         return posRegistro;
        }
        }
        posRegistro++;
    }
    fclose(pPep);
    return -1;
}





int archivoVentas::contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return 0;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Ventas);
      }

bool archivoVentas::listarRegistros(){
    Ventas reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg, sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}


Ventas archivoVentas::leerRegistro(int pos){
    Ventas reg;
    reg.setNumeroVenta(-1);
    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Ventas),1,p);
    fclose(p);

    if(leyo==0) reg.setNumeroVenta(-1);
    return reg;
}

bool archivoVentas::modificarRegistro(Ventas reg, int pos){
    FILE *p;
    p=fopen("Ventas.dat","rb+");///+ le agrega al modo lo que no tiene
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Ventas),1,p);
    fclose(p);
    return escribio;
}

void cargarVector(DetalleVenta *d, int tam){

    DetalleVenta reg;
    archivoDetalleVenta archi("detalleventa.dat");

    int pos=0;
    for(int i=0; i<tam; i++){
        reg=archi.leerRegistro(i);
        d[pos]=reg;
        pos++;
    }
}

void mostrarVector(DetalleVenta *d,int tam,int num){
    archivoDetalleVenta archi("detalleventa.dat");
    for(int i=0; i<tam; i++){
        if(d[i].getNumeroVenta()==num){
            d[i].Mostrar();
            cout<<endl<<endl;
        }
    }
}

void Vectordinamico(int num){
    DetalleVenta *d;
    archivoDetalleVenta archi("detalleventa.dat");
    int tam = archi.contarRegistros();

    d=new DetalleVenta[tam];
    if(d==nullptr){
        cout<<"ERROR AL RESERVAR MEMORIA PARA EL VECTOR"<<endl;
        return;
    }

    cargarVector(d,tam);

    mostrarVector(d, tam,num);
    delete[] d;
}

#endif // CLSVENTAS_H_INCLUDED
