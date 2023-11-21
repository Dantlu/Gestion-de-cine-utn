#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include <ctime>
using namespace std;
void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


bool esFechaValida(int dia, int mes, int anio);

class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        Fecha();

        Fecha(int d, int m, int a);

        void Cargar();
        void Mostrar();
        ///sets
        void setDia(int x);
        void setMes(int x);
        void setAnio(int x);
        ///gets
        int getDia();
        int getMes();
        int getAnio();

};
      Fecha::Fecha(){
        time_t t=time(NULL);
        struct tm *f= localtime(&t);
        _dia= f->tm_mday;
        _mes= f->tm_mon+1;
        _anio= f->tm_year + 1900;

        }

        Fecha::Fecha(int d, int m, int a){
            _dia=d;
            _mes=m;
            _anio=a;
        }

        void Fecha::setDia(int x){if(x>0 && x<32) _dia=x;}
        void Fecha::setMes(int x){if(x>0 && x<13)_mes=x;}
        void Fecha::setAnio(int x){_anio=x;}
        ///gets
        int Fecha::getDia(){return _dia;}
        int Fecha::getMes(){return _mes;}
        int Fecha::getAnio(){return _anio;}
 void Fecha::Cargar(){
      int dia, mes, anio;
    cout<<"DIA: ";
    cin>>dia;
    setDia(dia);
    cout<<"MES: ";
    cin>>mes;
    setMes(mes);
    cout<<"ANIO: ";
    cin>>anio;
    setAnio(anio);
}
void Fecha::Mostrar(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}


#endif // FUNCIONESGLOBALES_H_INCLUDED
