#ifndef CLSALIMENTOS_H_INCLUDED
#define CLSALIMENTOS_H_INCLUDED

#include <iostream>
#include <cstring>
#include "funcionesGlobales.h"

class Alimentos{
private:
    int _CodigoAlimento;
    char _Descripcion[30];
    int _Stock;
    float _PrecioUnitario;
    bool _Estado;

public:

    Alimentos(int s=0, int i=0,const char *d="nada", float p=0, bool e=true){
         _Stock=s;
        _CodigoAlimento=i;
        strcpy(_Descripcion, d);
        _PrecioUnitario=p;
        _Estado=e;
    }
    ///
   void setCodigoAlimento(int cod){_CodigoAlimento=cod;}
    void setDescripcion(const char *des){ strcpy(_Descripcion, des);}

    bool setStock(int sto){
        if (sto >= 0){
            _Stock=sto;
            return true;
        }else{
            return false;
         }
    }

    void setPrecio(float pre){_PrecioUnitario=pre;}
    void setEstado(bool es){_Estado=es;}

    ///
    int getCodigoAlimento(){return _CodigoAlimento;}
    const char* getDescripcion() {return _Descripcion;}
    int getStock() {return _Stock;}
    float getPrecioUnitario(){return _PrecioUnitario;}
    bool getEstado() {return _Estado;}

    ///
    void Cargar(int );
    void Mostrar();

};



class archivoAlimentos {
private:
    char nombre[35];
public:
    archivoAlimentos(const char* n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(Alimentos reg);
    bool listarRegistros();
    Alimentos leerRegistro(int pos);
    int contarRegistros();
    int buscarCodigoAlimento(int);
    bool modificarRegistro(Alimentos reg, int pos);
    bool descontarstock(int cod,int cant);
};

bool archivoAlimentos::AgregarRegistro(Alimentos reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    int pos = buscarCodigoAlimento(reg.getCodigoAlimento());

    if (pos == -1) {

        bool escribio = fwrite(&reg, sizeof(Alimentos), 1, p);
        fclose(p);
        return escribio;
    } else {
        cout << "EL CODIGO YA EXISTE EN EL ARCHIVO" << endl;
        fclose(p);
        return false;
    }
    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int archivoAlimentos::buscarCodigoAlimento(int COD){
    Alimentos reg;
    FILE *p;
    p=fopen("Alimentos.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Alimentos),1,p)==1){
        if(reg.getCodigoAlimento()==COD){
                if(reg.getEstado()==false){
                  fclose(p);
                  return -2;
                }else{
            fclose(p);
            return posRegistro;
        }
        }
        posRegistro++;
    }
    fclose(p);
    return -1;
}


int archivoAlimentos::contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return 0;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Alimentos);
      }

bool archivoAlimentos::listarRegistros(){
    Alimentos reg;
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


Alimentos archivoAlimentos::leerRegistro(int pos){
    Alimentos reg;
    reg.setCodigoAlimento(-1);
    FILE *p;
    p=fopen("Alimentos.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Alimentos),1,p);
    fclose(p);

    if(leyo==0) reg.setCodigoAlimento(-1);
    return reg;
}

bool archivoAlimentos::modificarRegistro(Alimentos reg, int pos){
    FILE *p;
    p=fopen("Alimentos.dat","rb+");///+ le agrega al modo lo que no tiene
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Alimentos),1,p);
    fclose(p);
    return escribio;
}

bool archivoAlimentos::descontarstock(int cod,int cant){
archivoAlimentos archiali("alimentos.dat");
Alimentos obj;
int pos=archiali.buscarCodigoAlimento(cod);
obj=archiali.leerRegistro(pos);
int valido;
valido=obj.getStock();
if(valido-cant>=0){
    obj.setStock(valido-cant);
    archiali.modificarRegistro(obj,pos);
    return true;
    }else {
    cout<<"NO HAY SUFICIENTES ALIMENTOS, EL STOCK ES DE: "<<obj.getStock()<<endl;
    return false;
    }

}

void Alimentos::Cargar(int cod=-1){
    if(cod==-1){
        cout<<"CODIGO DEL PRODUCTO: ";
        cin>>_CodigoAlimento;
    }
    else{
        _CodigoAlimento=cod;
    }
    archivoAlimentos archi("Alimentos.dat");
    archi.buscarCodigoAlimento(_CodigoAlimento);
    int validacion=archi.buscarCodigoAlimento(_CodigoAlimento);
    if(validacion!=-2){
    cout<<"DESCRIPCION DEL PRODUCTO: ";
    cargarCadena(_Descripcion,29);
    cout<<"STOCK DEL PRODUCTO: ";
    int s;
    cin>>s;
    if(setStock(s)){
        _Stock=s;
    } else {
        cout<< "EL VALOR INGRESADO NO ES VALIDO";
        return;
    }
    cout<<"INDIQUE EL PRECIO UNITARIO DEL PRODUCTO: ";
    cin>>_PrecioUnitario;
    _Estado=true;

}else{
    cout<<"EL ALIMENTO EXISTE Y ESTA DADO DE BAJA"<<endl;
    return;
        }
}



void Alimentos::Mostrar(){
    if(_Estado==true){
             cout<<"----------------------------------------"<<endl;
cout<<"CODIGO DEL PRODUCTO: "<<_CodigoAlimento<<endl;
cout<<"DESCRIPCION DEL PRODUCTO: "<<_Descripcion<<endl;
cout<<"STOCK DEL PRODUCTO: "<<_Stock<<endl;
cout<<"PRECIO DEL ALIMENTO: "<<_PrecioUnitario<<endl;
       cout<<"----------------------------------------"<<endl;
    }
}

#endif // CLSALIMENTOS_H_INCLUDED
