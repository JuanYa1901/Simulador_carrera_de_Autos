#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include<conio.h>

using namespace std;

/*void *procesoSeparado(void *data){

    int n = 0;
    char *texto = (char *) data;
    struct timespec tiempo = {1,0};
    while(n != 10){
                cout<<texto<<endl;
                pthread_delay_np(&tiempo);
                n++;

    }


}*/

int main(){


    cout<<"\n\n-----------------------------------------------\n\n"<<endl;

    /*int metros = 0, C_autos = 0;

    cout<<"Ingrese la cantidad de autos:     ";
    cin>>C_autos;

    array<pthread_t> autos(C_autos);

    for(int i = 0; i<C_autos;i++){
        
    }*7
   /* pthread_t proceso1;
    pthread_t proceso2;
    pthread_create(&proceso1, NULL, &procesoSeparado,(void*)"Hola");
    pthread_create(&proceso2, NULL, &procesoSeparado,(void*)"Adios");
    pthread_join(proceso1,NULL);
    pthread_join(proceso2,NULL);
    */


    cout<<"\n\nHola Mundo :D\n\n"<<endl;

    getch();
    return 0;
}