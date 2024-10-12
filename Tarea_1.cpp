#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include<conio.h>
#include<vector>
#include<random>

using namespace std;

void *pistaDeCarreras(void *data){

        
}

int main(){


    cout<<"\n\n-----------------------------------------------\n\n"<<endl;

    int metros = 0, C_autos = 0;

    cout<<"Ingrese la cantidad de autos:     ";
    cin>>C_autos;

    //Se crea la hebra de tipo vector de tamaño n (C_autos) que es ingresado por el usuario
    vector<pthread_t> autos(C_autos);

    //Crea las hebras con el nombre de autos acompañado con un número discriminador de i+1
    for(int i = 0; i<C_autos;i++){
        string Cars = "Auto " + to_string(i+1);
        pthread_create(&autos[i],NULL,&pistaDeCarreras,(void*)Cars.c_str());

    }

    //Aquí unimos todas las hebras
    for(int i=0; i<C_autos;i++){
        pthread_join(autos[i],NULL);
    }



    cout<<"\n\nHola Mundo :D\n\n"<<endl;

    getch();
    return 0;
}