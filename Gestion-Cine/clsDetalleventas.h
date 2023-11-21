#ifndef CLSDetalleVenta_H_INCLUDED
#define CLSDetalleVenta_H_INCLUDED

class DetalleVenta{
private:
    int _NumeroVentas;
    int _CodigoAlimento;
    int _cantidadA;
    float _Importe;
    bool  _estado;
public:



    DetalleVenta(int NumeroVentas=0,int CodigoAlimento=0, int cantidadA=0, float importe=0.0){
    setNumeroVentas(NumeroVentas);
    setCodigoAlimento(CodigoAlimento);
    setCantidadA(cantidadA);
    setImporte(importe);
     setEstado(true);
    }

    void setNumeroVentas(int nv){
    _NumeroVentas=nv;
    }
    void setCodigoAlimento(int id){
    _CodigoAlimento=id;
    }
    void setCantidadA(int cant){
    _cantidadA=cant;
    }
    void setImporte(float importe){
    _Importe=importe;
    }
     void setEstado(bool estado){
    _estado=estado;
    }

    int getNumeroVenta(){return _NumeroVentas;}
    int getCodigoAlimento(){return _CodigoAlimento;}
    int getCantidadA(){return _cantidadA;}
    float getImporte(){return _Importe;}
    bool getEstado(){return _estado; }
    void Mostrar();
};
    void DetalleVenta::Mostrar(){

    cout<<"CODIGO DE ALIMENTO: "<<_CodigoAlimento<<endl;
    cout<<"CANTIDAD DE ALIMENTO: "<<_cantidadA<<endl;
    cout<<"IMPORTE DE LOS ALIMENTOS: "<<_Importe;
    }
class archivoDetalleVenta {
private:
    char nombre[35];
public:
    archivoDetalleVenta(const char *n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(DetalleVenta reg);
    bool listarRegistros();
    DetalleVenta leerRegistro(int pos);
    int contarRegistros();
    int buscarNumeroVenta(int);
    bool modificarRegistro(DetalleVenta reg, int pos);
};

bool archivoDetalleVenta::AgregarRegistro(DetalleVenta reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int archivoDetalleVenta::buscarNumeroVenta(int COD){
    DetalleVenta reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(DetalleVenta),1,p)==1){
        if(reg.getNumeroVenta()==COD){
                if(reg.getEstado()==false ){
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



int archivoDetalleVenta::contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return 0;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(DetalleVenta);
      }

bool archivoDetalleVenta::listarRegistros(){
    DetalleVenta reg;
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


DetalleVenta archivoDetalleVenta::leerRegistro(int pos){
    DetalleVenta reg;
    reg.setNumeroVentas(-1);
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(DetalleVenta),1,p);
    fclose(p);

    if(leyo==0) reg.setNumeroVentas(-1);
    return reg;
}

bool archivoDetalleVenta::modificarRegistro(DetalleVenta reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");///+ le agrega al modo lo que no tiene
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(DetalleVenta),1,p);
    fclose(p);
    return escribio;
}


#endif // CLSDetalleVenta_H_INCLUDED
