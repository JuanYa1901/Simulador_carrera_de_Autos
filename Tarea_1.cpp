#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <chrono>
#include <mutex>
#include <string>

//usamos esta declaración para evitar escribir std::
using namespace std;

void pistaDeCarreras(int id, int distancia_total, int &resultado) {

	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);
    uniform_int_distribution<> tiempo(100, 500);
    
    int distancia_recorrida = 0;
    
    while (distancia_recorrida < distancia_total) {
        int avance = dist(gen);
        distancia_recorrida += avance;
        cout << "Auto" << id << " avanza " << avance << " metros (total: " << distancia_recorrida << " metros)\n";
        this_thread::sleep_for(chrono::milliseconds(tiempo(gen)));
    }

    resultado = distancia_recorrida;
    cout << "Auto" << id << " ha terminado la carrera.\n";
}

//Dentro del int main se ingresan parametros para que se ingresen los datos en la terminal
int main(int argc, char *argv[]){
	
	//Se verifica si el ingreso de los parametros sea el nombre del archivo, distancia total y numeros de autos
	if (argc != 3) {
		
		//indica el mensaje de error
        cerr << "Uso: " << argv[0] << " <distancia_total> <numero_autos>\n";
        
        //indica que el programa ha terminado de manera anormal
        return 1;
    }
	
try {
		//convoerte los valores tipo string a un numero entero
        distancia_total = stoi(argv[1]);
        numero_autos = stoi(argv[2]);
        
    } catch (const invalid_argument &e) {
    	
    	//muestra un error mostrando que ambos argumentos deben ser numeros enteros
        cerr << "Error: Ambos argumentos deben ser números enteros.\n";
        return 1;
        
    } catch (const out_of_range &e) {
    	
    	//muestra un error por si el número que ingresa es muy grande
        cerr << "Error: Los números ingresados son demasiado grandes.\n";
        return 1;
        
    }
	
	//se crea un vector de threads llamado 'autos' y cada thread representa un auto para la carrera
	vector<thread> autos;
	//almacena la distancia total recorrida
    vector<int> resultados(numero_autos);
    
    //se crea los threads según la cantidad de autos que se ingresaron
    for (int i = 0; i < numero_autos; i++) {
        autos.emplace_back(pistaDeCarreras, i, distancia_total, ref(resultados[i]));
    }
    
    //Une todos los threads creados
    for (size_t i = 0; i < numeros_autos; ++i) {
    autos[i].join(); 
}
	cout << "Ranking final: \n";
    for (int i = 0; i < numero_autos; i++) {
        cout << i + 1 << ". " << resultados[i] << endl;
    }
	return 0;
}