/*
#include <iostream>
#include <cstring>

using namespace std;

#include "clsPeliculas.h"
#include "clsCliente.h"

class Archivo{
    private:
         char _Nombre[30];
    public:
        Archivo(const char *nAr);

        const char *getNombre();
        FILE* openfile(const char* nombre,const char* modo);

        ///ESCRIBIR REGISTROS
        bool escribirRegistro(Pelicula reg);
        bool escribirRegistro(Clientes reg);


        ///LISTAR REGISTROS
        bool listarRegistros(Pelicula reg);
        bool listarRegistros(Clientes reg);


        ///CONTAR REGISTROS
        int contarRegistros(Pelicula reg);
        int contarRegistros(Clientes reg);


        ///LEER REGISTROS
        Pelicula leerRegistro(int pos);
        Clientes leerRegistro(int pos);


        ///MODIFICAR REGISTROS
        bool modificarRegistro(Pelicula reg, int pos);
        bool modificarRegistro(Clientes reg, int pos);


        ///BUSCAR SEGUN POSICION
        BuscarSegun(int ID);
        BuscarSegun(int dni);




        void listarRegistros(DetalleVenta reg);
        void listarRegistros(Alimentos reg);
        void listarRegistros(Ventas reg);
        void listarRegistros(Clientes reg);
        void listarRegistros(Pelicula reg);

        bool modificarRegistro(DetalleVenta reg, int pos);
        bool modificarRegistro(Alimentos reg, int pos);
        bool modificarRegistro(Ventas reg, int pos);
        bool modificarRegistro(Clientes reg, int pos);
        bool modificarRegistro(Pelicula reg, int pos);

        int PocisionDeRegistrossegun(Alimentos reg);
        int PocisionDeRegistrossegun(DetalleVenta reg);
        int PocisionDeRegistrossegun(Ventas reg);
        int PocisionDeRegistrossegun(Clientes reg);


        DetalleVenta leerRegistroDetalles(int pos);
        Alimentos leerRegistroAlimentos(int pos);
        Ventas leerRegistroVentas(int pos);
        Clientes leerRegistroClientes(int pos);
        Pelicula leerRegistro(int pos);


        bool escribirRegistro(Pelicula reg);
        bool escribirRegistro(DetalleVenta reg);
        bool escribirRegistro(Venta reg);
        bool escribirRegistro(Cliente reg);
        bool escribirRegistro(Alimentos reg);

        int contarRegistros();

        ///auto numeracion peliculas y ventas
        int Cantidadderegistro(Ventas reg);
        int Cantidadderegistro(pelicula reg);


};
Archivo::Archivo(const char *nAr){
            strcpy(_Nombre,nAr);
        }

FILE* Archivo::openfile(const char* nombre, const char* modo)
{
FILE* Pfile;
Pfile=fopen(nombre,modo);
if(Pfile ==nullptr)
{
cout<< "NO SE PUDO LEER EL ARCHIVO..."<<endl;
exit(-5);
}
return Pfile;
}

///
bool Archivo::escribirRegistro(Pelicula reg){
    FILE *p=openfile(_Nombre,"ab");
    bool escribio = fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

bool Archivo::escribirRegistro(Clientes reg){
    FILE *p=openfile(_Nombre,"ab");
    bool escribio = fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    return escribio;
}
///

int Archivo::contarRegistros(Pelicula reg){
        FILE *p=openfile(_Nombre,"rb");
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pelicula);
      }
}
int Archivo::contarRegistros(Clientes reg){
        FILE *p=openfile(_Nombre,"rb");
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Clientes);
}

///

bool Archivo::listarRegistros(Pelicula reg){
    FILE *p=openfile(_Nombre,"rb");
    while(fread(&reg, sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}
bool listarRegistros(Clientes reg){

}

void Archivo::listarRegistros(DetalleVenta reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}
void Archivo::listarRegistros(Alimentos reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}
void Archivo::listarRegistros(Ventas reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}
void Archivo::listarRegistros(Clientes reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}

bool Archivo::modificarRegistro(DetalleVenta reg, int pos){

    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}
bool Archivo::modificarRegistro(Alimentos reg, int pos)
{
    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}
bool Archivo::modificarRegistro(Ventas reg, int pos)
{
    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}
bool Archivo::modificarRegistro(Clientes reg, int pos)
{
    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}


int Archivo::PocisionDeRegistrossegun(Alimentos reg){


int idalimento,registro=0;
bool encontro=false;
   cout<<"Ingrese el Id del alimento a buscar"<<endl;
   cin>>idalimento;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getIdAlimento()==idalimento ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}
int Archivo::PocisionDeRegistrossegun(DetalleVenta reg){
int numerodeventa,registro=0;
bool encontro=false;
   cout<<"Ingrese el numero del detalle de venta a buscar"<<endl;
   cin>>numerodeventa;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getNumeroVenta()==numerodeventa ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}
int Archivo::PocisionDeRegistrossegun(Ventas reg){


int NumeroVenta,registro=0;
bool encontro=false;
   cout<<"Ingrese el numero del detalle de venta a buscar"<<endl;
   cin>>NumeroVenta;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getNumeroVenta()==NumeroVenta ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}
int Archivo::PocisionDeRegistrossegun(Clientes reg){
int DNI,registro=0;
bool encontro=false;
   cout<<"Ingrese el Dni del cliente a buscar"<<endl;
   cin>>DNI;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getDNI()==DNI ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}

DetalleVenta Archivo::leerRegistroDetalles(int pos){

    DetalleVenta reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}

Alimentos Archivo::leerRegistroAlimentos(int pos){
    Alimentos reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}

Ventas Archivo::leerRegistroVentas(int pos){
    Ventas reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}

Clientes Archivo::leerRegistroClientes(int pos){
    Clientes reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}
int Archivo::Cantidadderegistro(Ventas reg)
{
int CANTIDAD=0;

FILE* Pfile=openfile(_Nombre, "rb");

fseek(Pfile, 0 ,SEEK_END);
if(ftell(Pfile)/sizeof(reg)>=1){
CANTIDAD= ftell(Pfile)/sizeof(reg);
fclose(Pfile);
}else{ CANTIDAD=0;
}
return CANTIDAD;
}
int Archivo::Cantidadderegistro(peliculas reg)
{
int CANTIDAD=0;

FILE* Pfile=openfile(_Nombre, "rb");

fseek(Pfile, 0 ,SEEK_END);
if(ftell(Pfile)/sizeof(reg)>=1){
CANTIDAD= ftell(Pfile)/sizeof(reg);
fclose(Pfile);
}else{ CANTIDAD=0;
}
return CANTIDAD;
}


 Id=Cantidadderegistro(nombre);
    if(Id>1000){Id=0;}
    Id++;


Archivo::Archivo(const char *nAr){
            strcpy(_Nombre,nAr);
        }

FILE* Archivo::openfile(const char* nombre, const char* modo)
{
FILE* Pfile;
Pfile=fopen(nombre,modo);
if(Pfile ==nullptr)
{
cout<< "no se pudo leer el archivo..."<<endl;
exit(-5);
}
return Pfile;
}

void Archivo::listarRegistros(DetalleVenta reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}
void Archivo::listarRegistros(Alimentos reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}
void Archivo::listarRegistros(Ventas reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}
void Archivo::listarRegistros(Clientes reg){

        FILE *p=openfile(_Nombre,"rb");
      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }
    fclose(p);


}

bool Archivo::modificarRegistro(DetalleVenta reg, int pos){

    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}
bool Archivo::modificarRegistro(Alimentos reg, int pos)
{
    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}
bool Archivo::modificarRegistro(Ventas reg, int pos)
{
    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");

    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}
bool Archivo::modificarRegistro(Clientes reg, int pos)
{
    FILE *pfile;
    pfile=openfile(_Nombre,"rb+");///+ le agrega al modo lo que no tiene
    }
    fseek(pfile,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(reg),1,pfile);
    fclose(pfile);
    return escribio;
}


int Archivo::PocisionDeRegistrossegun(Alimentos reg){


int idalimento,registro=0;
bool encontro=false;
   cout<<"Ingrese el Id del alimento a buscar"<<endl;
   cin>>idalimento;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getIdAlimento()==idalimento ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}
int Archivo::PocisionDeRegistrossegun(DetalleVenta reg){
int numerodeventa,registro=0;
bool encontro=false;
   cout<<"Ingrese el numero del detalle de venta a buscar"<<endl;
   cin>>numerodeventa;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getNumeroVenta()==numerodeventa ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}
int Archivo::PocisionDeRegistrossegun(Ventas reg){


int NumeroVenta,registro=0;
bool encontro=false;
   cout<<"Ingrese el numero del detalle de venta a buscar"<<endl;
   cin>>NumeroVenta;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getNumeroVenta()==NumeroVenta ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}
int Archivo::PocisionDeRegistrossegun(Clientes reg){
int DNI,registro=0;
bool encontro=false;
   cout<<"Ingrese el Dni del cliente a buscar"<<endl;
   cin>>DNI;

       FILE* pfile=openfile(_Nombre ,"rb");
      while(fread(&reg, sizeof reg,1,pfile)==1){
            if(reg.getDNI()==DNI ){
          fclose(pfile);
          return registro;
          cout<<endl;}
            registro++;
            }
    fclose(pfile);

          return-1;
}

DetalleVenta Archivo::leerRegistroDetalles(int pos){

    DetalleVenta reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}

Alimentos Archivo::leerRegistroAlimentos(int pos){
    Alimentos reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}

Ventas Archivo::leerRegistroVentas(int pos){
    Ventas reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
}

Clientes Archivo::leerRegistroClientes(int pos){
    Clientes reg;

FILE* pfile=openfile(_Nombre,"rb");
    fseek(pfile,sizeof(reg)*pos,0);
    fread(&reg, sizeof reg,1,pfile);
    fclose(pfile);
    return reg;
*/
