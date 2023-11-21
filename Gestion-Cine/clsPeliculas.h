#ifndef CLSPELICULAS_H_INCLUDED
#define CLSPELICULAS_H_INCLUDED

#include <iostream>
#include <cstring>
#include "funcionesGlobales.h"

class Pelicula{
private:
    float _precio;
    int _IDpelicula;
    char _titulo[35];
    int _tipoDePelicula;
    Fecha _fechaEstreno;
    Fecha _fechaSalida;
    bool _estado;
    char _Director[30];
    char _Actor[30];
public:
    Pelicula(const char *n = "NOMBRE") {
        strcpy(_titulo, n);
        _IDpelicula=0;
        _tipoDePelicula = 0;
        _estado = false;
        _precio=2000.0;
    }

    ///SETS

    void setFechaEstreno(Fecha e){_fechaEstreno=e;}
    void setFechaSalida(Fecha s){_fechaSalida=s;}

    void setPrecio(float p){
    _precio=p;
    }
    void setID(int id){
    _IDpelicula=id;
    }
    void setTitulo(const char *n) {
        strcpy(_titulo, n);
    }

    bool setTipo(int t) {
        if (t >= 1 && t <= 5) {
            _tipoDePelicula = t;
            return true;
        } else {
            return false;
        }
    }


    void setEstado(bool s) {
        _estado = s;
    }

    void setDirector(const char *dir){strcpy(_Director,dir);}
    void setActor(const char *ac){strcpy(_Actor,ac);}

    ///GETS
    float getPrecio(){return _precio;}
    int getID(){return _IDpelicula;}
    const char* getTitulo() {return _titulo;}
    int getTipo() {return _tipoDePelicula;}
    bool getEstado() {return _estado;}
    Fecha getfechaEstreno(){return _fechaEstreno;}
    Fecha getFechaSalida() {return _fechaSalida;}
    const char* getDirector(){return _Director;}
    const char* getActor(){return _Actor;}
    ///

    void Cargar();
    void Mostrar();
};

void Pelicula::Cargar(){
    cout<<"TITULO DE LA PELICULA: ";
    cargarCadena(_titulo, 35);
    cout<<"FECHA DE ESTRENO EN EL CINE: "<<endl;
    _fechaEstreno.Cargar();
    cout<<"FECHA DE SALIDA DEL CINE: "<<endl;
    _fechaSalida.Cargar();
    cout<<"INGRESE EL DIRECTOR DE LA PELICULA: ";
    cargarCadena(_Director, 30);
    cout<<"INGRESE EL/LA ACTOR/ACTRIZ PRINCIPAL: ";
    cargarCadena(_Actor, 30);
    cout<<"TIPO DE PELICULA (1.ACCION, 2.COMEDIA, 3.TERROR, 4.CIENCIA FICCION, 5.ANIMADA): ";
    int ti;
    cin>>ti;
    if(setTipo(ti)){
        _tipoDePelicula=ti;
    } else {
        cout<< "EL VALOR INGRESADO NO ES VALIDO";
        return;
    }
    _estado=true;
}

void Pelicula::Mostrar(){
    if(_estado==true){
             cout<<"----------------------------------------"<<endl;
        cout<<"ID DE LA PELICULA: "<<_IDpelicula<< endl;
        cout<<"TITULO DE LA PELICULA: "<<_titulo<<endl;
        cout<<"FECHA DE ESTRENO: ";
        _fechaEstreno.Mostrar();
        cout<<"FECHA DE SALIDA DEL CINE: ";
        ///FALTA INGRESAR FECHA DE SALIDA MAYOR A LA ACTUAL
        _fechaSalida.Mostrar();
        cout<<"DIRECTOR: "<<_Director<<endl;
        cout<<"ACTOR: "<<_Actor<<endl;
        cout<<"TIPO DE PELICULA (1.ACCION, 2.COMEDIA, 3.TERROR, 4.CIENCIA FICCION, 5.ANIMADA): "<<_tipoDePelicula<<endl;
        cout<<"PRECIO POR ENTRADA: "<<_precio<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<endl;
    }

}

class archivoPeliculas {
private:
    char nombre[35];
public:
    archivoPeliculas(const char* n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(Pelicula reg);
    bool listarRegistros();
    Pelicula leerRegistro(int pos);
    int contarRegistros();
    int buscarID(int ID);
    bool modificarRegistro(Pelicula reg, int pos);
};

bool archivoPeliculas::AgregarRegistro(Pelicula reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int archivoPeliculas::buscarID(int ID){
    Pelicula reg;
    FILE *pPep;
    pPep=fopen("Pelicula.dat","rb");
    if(pPep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Pelicula),1,pPep)==1){
        if(reg.getID()==ID){
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



int archivoPeliculas::contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return 0;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pelicula);
      }

bool archivoPeliculas::listarRegistros(){
    Pelicula reg;
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


Pelicula archivoPeliculas::leerRegistro(int pos){
    Pelicula reg;
    reg.setID(-1);
    FILE *p;
    p=fopen("Pelicula.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Pelicula),1,p);
    fclose(p);

    if(leyo==0) reg.setID(-1);
    return reg;
}

bool archivoPeliculas::modificarRegistro(Pelicula reg, int pos){
    FILE *p;
    p=fopen("Pelicula.dat","rb+");///+ le agrega al modo lo que no tiene
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Pelicula),1,p);
    fclose(p);
    return escribio;
}

#endif // CLSPELICULAS_H_INCLUDED
