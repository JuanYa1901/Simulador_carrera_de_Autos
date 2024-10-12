#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include<conio.h>
#include<vector>
#include<unistd.h>
#include<ctime>
#include<cstdlib>

using namespace std;

struct autoInformation {

    const char* nombreAuto;
    int pista;

};

void *pistaDeCarreras(void *data){

    autoInformation* carData = static_cast<autoInformation*>(data);
    const char * nombreAuto = carData -> nombreAuto; 
    

    int metros_avanzados = 0;
    int meta = carData -> pista;

    while(metros_avanzados < meta){

        int avanzar = rand()%10+1;

        metros_avanzados += avanzar;

        cout << nombreAuto << " avanzó" << avanzar << "metros.  (Total: )"<<metros_avanzados<<" metros"<<endl;
        sleep(1);

    }

    cout<<nombreAuto << " Ha llegado a la meta!" <<endl;
    return nullptr;

}

int main(){


    cout<<"\n\n-----------------------------------------------\n\n"<<endl;

    int pista, C_autos;

    srand(time(0));
    
    cout<<"Ingrese el largo de la pista de carreras:     ";
    cin>>pista;

    cout<<"Ingrese la cantidad de autos:     ";
    cin>>C_autos;

    //Se crea la hebra de tipo vector de tamaño n (C_autos) que es ingresado por el usuario
    vector<pthread_t> autos(C_autos);

    //Crea las hebras con el nombre de autos acompañado con un número discriminador de i+1
    for(int i = 0; i<C_autos;i++){
        string Cars = "Auto" + to_string(i+1);
        pthread_create(&autos[i],NULL,&pistaDeCarreras,(void*)Cars.c_str());

    }

    //Aquí unimos todas las hebras
    for(int i=0; i<C_autos;i++){
        pthread_join(autos[i],NULL);
    }




    getch();
    return 0;
}