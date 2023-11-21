#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

class Clientes{
private:
    char _Nombre[35];
    char _Apellido[35];
    char _Email[35];
    int  _DNI;
    int  _Tipo_Cliente;
    bool _Estado;
public:

    ///sets
    void setDNI(int d){_DNI=d;}
    void setNombre(const char *n){strcpy(_Nombre,n);}
    void setApellido(const char *n){strcpy(_Apellido,n);}

    bool setTipoCliente(int t){
        if(t>=1&&t<=3){
            _Tipo_Cliente=t;
            return true;
        }else{
            return false;
        }
    }

    void setEmail(const char *n){strcpy(_Email,n);}
    void setEstado(bool e){_Estado=e;}
    ///gets
    const char *getNombre(){return _Nombre;}
    const char *getApellido(){return _Apellido;}
    const char *getEmail(){return _Email;}
    int getDNI(){return _DNI;}
    int getTipoCliente(){return _Tipo_Cliente;}
    bool getEstado(){return _Estado;}

    ///

    void Cargar(int);
    void Mostrar();

};

void Clientes::Cargar(int dni=-1){

    if(dni==-1){
        cout<<"DOCUMENTO: ";
        cin>>_DNI;
    }
    else{
        _DNI=dni;
    }

    cout<<"NOMBRE: ";
    cargarCadena(_Nombre, 34);
    cout<<"APELLIDO: ";
    cargarCadena(_Apellido,34);
    cout<<"EMAIL: ";
    cargarCadena(_Email, 34);
    cout<<"TIPO CLIENTE: ""(1:Consumidor final, 2:Monotributista ,3:Responsable Inscripto ): ";
    int tipo;
    cin>>tipo;
    if(setTipoCliente(tipo)){
        _Tipo_Cliente=tipo;
    } else {
        cout<< "EL VALOR INGRESADO NO ES VALIDO";
        return;
    }
    _Estado=true;
}



void Clientes::Mostrar(){
    if(_Estado==true){
         cout<<"-------------------------"<<endl;
        cout<<"DNI: ";
        cout<<_DNI <<endl;
        cout<<"NOMBRE: ";
        cout<<_Nombre <<endl;
        cout<<"APELLIDO: ";
        cout<<_Apellido <<endl;
        cout<<"EMAIL: ";
        cout<<_Email <<endl;
        cout<<"TIPO DE CLIENTE: ";
        cout<<_Tipo_Cliente <<endl;
         cout<<"-------------------------"<<endl;
         cout<<endl;
    }

}

class archivoClientes{
private:
    char nombre[35];
public:
    archivoClientes(const char* n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(Clientes reg);
    bool listarRegistros();
    Clientes leerRegistro(int pos);
    int contarRegistros();
    bool modificarRegistro(Clientes reg, int pos);
    int buscarDNI(int dni);
};

bool archivoClientes::AgregarRegistro(Clientes reg){
    FILE* pCli = fopen(nombre, "ab");
    if (pCli == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    int pos = buscarDNI(reg.getDNI());

    if (pos == -1) {

        bool escribio = fwrite(&reg, sizeof(Clientes), 1, pCli);
        fclose(pCli);
        return escribio;
    } else {
        cout << "EL DNI YA EXISTE EN EL ARCHIVO" << endl;
        fclose(pCli);
        return false;
    }
}


int archivoClientes::buscarDNI(int dni){
    Clientes reg;
    FILE *pCli;
    pCli=fopen("Clientes.dat","rb");
    if(pCli==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Clientes),1,pCli)==1){
        if(reg.getDNI()==dni){
                if(reg.getEstado()==false){
                     fclose(pCli);
                  return -2;
                }else{
            fclose(pCli);
            return posRegistro;
        }
        }
        posRegistro++;
    }
    fclose(pCli);
    return -1;
}

int archivoClientes::contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return 0;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Clientes);
      }

bool archivoClientes::listarRegistros(){
    Clientes reg;
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


Clientes archivoClientes::leerRegistro(int pos){
    Clientes reg;
    reg.setDNI(-1);
    FILE *p;
    p=fopen("Clientes.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Clientes),1,p);
    fclose(p);

    if(leyo==0) reg.setDNI(-1);
    return reg;
}

bool archivoClientes::modificarRegistro(Clientes reg, int pos){
    FILE *p;
    p=fopen("Clientes.dat","rb+");///+ le agrega al modo lo que no tiene
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Clientes),1,p);
    fclose(p);
    return escribio;
}


#endif // CLSCLIENTE_H_INCLUDED
