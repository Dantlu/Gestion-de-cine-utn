#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED
///PROTOTIPOS
void subMenuConfiguracion();
void EstablecerDatosdeInicio();
void CopiaDeDeguridadVentas();
void CopiaDeDeguridadAlimentos();
void CopiaDeDeguridadClientes();
void CopiaDeDeguridadPeliculas();
void restaurarVentas();
void restaurarClientes();
void restaurarPeliculas();
void restaurarAlimentos();

///FIN
void submenuconfiguracion(const char* texto, int posx, int posy, bool seleccionado) {
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

void subMenuConfiguracion(){
       int y = 0;
    bool salir = false;
    rlutil::cls();

    rlutil::hidecursor();
   while (salir==false) {

        rlutil::setColor(rlutil::color::WHITE);
        rlutil::hidecursor();
        submenuconfiguracion("MENU DE CONFIGURACIONES",47, 5,y==-1);
        submenuconfiguracion("-----------------------",47, 6,y==-2);
        submenuconfiguracion("COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS", 45, 7, y == 0);
        submenuconfiguracion("COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES", 45, 8, y == 1);
        submenuconfiguracion("COPIA DE SEGURIDAD DEL ARCHIVO DE PELICULAS", 45, 9, y == 2);
        submenuconfiguracion("COPIA DE SEGURIDAD DEL ARCHIVO DE ALIMENTOS", 45, 10, y == 3);
        submenuconfiguracion("RESTAURAR EL ARCHIVO DE VENTAS", 45, 11, y == 4);
        submenuconfiguracion("RESTAURAR EL ARCHIVO DE CLIENTES", 45, 12, y == 5);
        submenuconfiguracion("RESTAURAR EL ARCHIVO DE PELICULAS", 45, 13, y == 6);
        submenuconfiguracion("RESTAURAR EL ARCHIVO DE ALIMENTOS", 45, 14, y == 7);
        submenuconfiguracion("VOLVER AL MENU PRINCIPAL ", 48, 15, y == 8);
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
            if (y > 8) {
                y = 8;
            }
            break;
        case 1: // enter
            switch (y) {

           case 0:
                     system("cls");
                    CopiaDeDeguridadVentas();
                    system("pause");
                     system("cls");

                break;
            case 1:
                    system("cls");
                    CopiaDeDeguridadClientes();
                    system("pause");
                     system("cls");

                break;
            case 2:
                    system("cls");
                    CopiaDeDeguridadPeliculas();
                    system("pause");
                     system("cls");
                break;
            case 3:

                 system("cls");
                 CopiaDeDeguridadAlimentos();
                 system("pause");
                 system("cls");
                break;
            case 4:
                 system("cls");
                 restaurarVentas();
                 system("pause");
                 system("cls");
                break;
            case 5:
                 system("cls");
                 restaurarClientes();
                 system("pause");
                system("cls");
                break;
                 case 6:
                     system("cls");
                     restaurarPeliculas();
                 system("cls");
                break;
                case 7:
                     system("cls");
                     restaurarAlimentos();
                 system("cls");
                break;
                case 8:
                     return;
                 system("cls");
                break;

        }
        default:
            break;
        }

    }
}


void CopiaDeDeguridadVentas(){
    FILE* p;
    FILE* pVentasBackup;

    p = fopen("Ventas.dat", "rb");
     if (p == NULL) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    pVentasBackup = fopen("Ventas_backup.bak", "wb");
     if (pVentasBackup == NULL) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    Ventas reg;
    while (fread(&reg, sizeof(Ventas), 1, p) == 1) {
            if(reg.getEstado()){
                fwrite(&reg, sizeof(Ventas), 1, pVentasBackup);
            }
    }
    fclose(p);
    fclose(pVentasBackup);
    cout << "Copia de seguridad de jugadores realizada correctamente." << endl;

}

void CopiaDeDeguridadClientes(){
    FILE* p;
    FILE* pClientesBackup;

    p = fopen("Clientes.dat", "rb");
     if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    pClientesBackup = fopen("Clientes_backup.bak", "wb");
     if (pClientesBackup == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    Clientes reg;
    while (fread(&reg, sizeof(Clientes), 1, p) == 1) {
            if(reg.getEstado()){
                fwrite(&reg, sizeof(Clientes), 1, pClientesBackup);
            }
    }
    fclose(p);
    fclose(pClientesBackup);
    cout << "Copia de seguridad de Clientes realizada correctamente." << endl;

}

void CopiaDeDeguridadPeliculas(){
    FILE* p;
    FILE* pPeliBackup;

    p = fopen("Pelicula.dat", "rb");
     if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    pPeliBackup = fopen("Pelicula_backup.bak", "wb");
     if (pPeliBackup == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    Pelicula reg;
    while (fread(&reg, sizeof(Pelicula), 1, p) == 1) {
            if(reg.getEstado()){
                fwrite(&reg, sizeof(Pelicula), 1, pPeliBackup);
            }
    }
    fclose(p);
    fclose(pPeliBackup);
    cout << "Copia de seguridad de Peliculas realizada correctamente." << endl;

}

void CopiaDeDeguridadAlimentos(){
    FILE* p;
    FILE* pAlimentosBackup;

    p = fopen("Alimentos.dat", "rb");
     if (p == NULL) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    pAlimentosBackup = fopen("Alimentos_backup.bak", "wb");
     if (pAlimentosBackup == NULL) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    Alimentos reg;
    while (fread(&reg, sizeof(Alimentos), 1, p) == 1) {
            if(reg.getEstado()){
                fwrite(&reg, sizeof(Alimentos), 1, pAlimentosBackup);
            }
    }
    fclose(p);
    fclose(pAlimentosBackup);
    cout << "Copia de seguridad de Alimentos realizada correctamente." << endl;

}

void restaurarVentas(){
    FILE *p;
    FILE *pVentasBackup;
    pVentasBackup = fopen("Ventas_backup.bak", "rb");
    if (pVentasBackup == NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }
    p = fopen("Ventas.dat","wb");
    if(p==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }
    Ventas reg;
    while(fread(&reg,sizeof(Ventas),1, pVentasBackup)==1){
        fwrite(&reg,sizeof(Ventas),1,p);
    }
    fclose(pVentasBackup);
    fclose(p);
}



void restaurarClientes(){
    FILE *p;
    FILE *pClientesBackup;
    pClientesBackup = fopen("Clientes_backup.bak", "rb");
    if (pClientesBackup == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    p = fopen("Clientes.dat", "wb");
    if (p == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    Clientes reg;
    while (fread(&reg, sizeof(Clientes), 1, pClientesBackup) == 1){
           fwrite(&reg, sizeof(Clientes), 1, p);
    }
    fclose(pClientesBackup);
    fclose(p);
}

void restaurarPeliculas(){
    FILE *p;
    FILE *pPeliBackup;
    pPeliBackup = fopen("Pelicula_backup.bak", "rb");
    if (pPeliBackup == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    p = fopen("Pelicula.dat", "wb");
    if (p == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    Pelicula reg;
    while (fread(&reg, sizeof(Pelicula), 1, pPeliBackup) == 1){
        fwrite(&reg, sizeof(Pelicula), 1, p);
    }
    fclose(pPeliBackup);
    fclose(p);
}

void restaurarAlimentos(){
    FILE *p;
    FILE *pAlimentosBackup;
    pAlimentosBackup = fopen("Alimentos_backup.bak", "rb");
    if (pAlimentosBackup == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    p = fopen("Alimentos.dat", "wb");
    if (p == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    Alimentos reg;
    while (fread(&reg, sizeof(Alimentos), 1, pAlimentosBackup) == 1){
        fwrite(&reg, sizeof(Alimentos), 1, p);
    }
    fclose(pAlimentosBackup);
    fclose(p);
}

void EstablecerDatosdeInicio(){
    FILE* pVentas;
    FILE* pVentasInicio;


    pVentas = fopen("ventas.ini", "rb");
     if (pVentas == NULL) {
        cout << "ERRO AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    pVentasInicio = fopen("Ventas.dat", "wb");
     if (pVentasInicio == NULL) {
        cout << "ERRO AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    Ventas reg;
    while (fread(&reg, sizeof(Ventas), 1, pVentas) == 1) {
            if(reg.getEstado()){
                fwrite(&reg, sizeof(Ventas), 1, pVentasInicio);
            }
    }
    fclose(pVentas);
    fclose(pVentasInicio);

    FILE* pCl;
    FILE* pCli;

    pCl = fopen("clientes.ini", "rb");
     if (pCl == NULL) {
        cout << "ERROR DE ARCHIVOS" << endl;
        return;
    }
    pCli = fopen("Deportes.dat", "wb");
     if (pCli == NULL) {
        cout << "ERROR DE ARCHIVOS" << endl;
        return;
    }
    Clientes aux;
    while (fread(&aux, sizeof(Clientes), 1, pCl) == 1) {
            if(aux.getEstado()){
                fwrite(&aux, sizeof(Clientes), 1, pCli);
            }
    }
    fclose(pCl);
    fclose(pCli);

    FILE* pPeli;
    FILE* pPeliInicio;


    pPeli = fopen("pelicula.ini", "rb");
     if (pPeli == NULL) {
        cout << "ERRO AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    pPeliInicio = fopen("Pelicula.dat", "wb");
     if (pPeliInicio == NULL) {
        cout << "ERRO AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    Pelicula obj;
    while (fread(&obj, sizeof(Pelicula), 1, pPeli) == 1) {
            if(obj.getEstado()){
                fwrite(&obj, sizeof(Pelicula), 1, pPeliInicio);
            }
    }
    fclose(pPeli);
    fclose(pPeliInicio);


    cout << "DATOS ESTABLECIDOS CORRECTAMENTE" << endl;

}

#endif // SUBMENUCONFIGURACION_H_INCLUDED
