#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <mutex>

using namespace std;

// Estructura para guardar la información de los autos
struct autoInformation {
    string nombreAuto;
    int pista;
};

// Vector para almacenar el ranking de llegada
vector<string> ranking;

// Mutex para proteger el acceso al ranking
mutex rankingMutex;
// Nuevo mutex para proteger la consola
mutex consoleMutex;  

// Función que ejecuta cada hebra (cada auto)
void* pistaDeCarreras(void* data) {
	
	srand(time(0) + pthread_self());  
	
    autoInformation* carData = static_cast<autoInformation*>(data);
    const string& nombreAuto = carData->nombreAuto;

    int metros_avanzados = 0;
    int meta = carData->pista;
    
    

    while (metros_avanzados <= meta) {
    	
        int avanzar = rand() % 10 + 1; 
        metros_avanzados += avanzar;

        // Bloquear la consola para evitar interferencias
		consoleMutex.lock(); 
        
        // Mostrar el avance del auto
        cout << nombreAuto << " avanza " << avanzar << " metros. ---------- (Total: " << metros_avanzados << " metros)" << endl;
		consoleMutex.unlock();  // Desbloquear la consola
		 
        sleep(4);
        
        cout<<"\n";
    }

    // Cuando el auto llega a la meta, lo agregamos al ranking
    rankingMutex.lock();  // Bloqueamos el acceso al ranking
    ranking.push_back(nombreAuto);  // Agregamos el nombre del auto al ranking
    rankingMutex.unlock();  // Desbloqueamos el acceso al ranking

    cout << nombreAuto << " ha llegado a la meta!" << endl;
    return nullptr;
}

int main() {
    cout << "\n\n-----------------------------------------------\n\n" << endl;
	srand(time(0));
    int pista, C_autos;

    // Ingresar los datos de la pista y la cantidad de autos
    cout << "Ingrese el largo de la pista de carreras (metros): ";
    cin >> pista;

    cout << "Ingrese la cantidad de autos: ";
    cin >> C_autos;

cout<<"\n";
cout<<"\n";
    // Vector de hebras y vector para los datos de cada auto
    vector<pthread_t> autos(C_autos);
    vector<autoInformation> carData(C_autos);

    // Crear las hebras con el nombre de cada auto
    for (int i = 0; i < C_autos; i++) {
        carData[i].nombreAuto = "Auto " + to_string(i + 1);
        carData[i].pista = pista;
        pthread_create(&autos[i], NULL, &pistaDeCarreras, (void*)&carData[i]);
    }

    // Unir todas las hebras (esperar que todos los autos terminen)
    for (int i = 0; i < C_autos; i++) {
        pthread_join(autos[i], NULL);
    }

    // Mostrar el ranking de la carrera
    cout << "\nRanking final:\n";
    for (size_t i = 0; i < ranking.size(); ++i) {
        cout << i + 1 << ". " << ranking[i] << endl;
    }

    cout << "\n\nFin de la carrera!\n\n" << endl;

    return 0;
}
