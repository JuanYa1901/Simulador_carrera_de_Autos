#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <chrono>
#include <mutex>
#include <string>
#include <algorithm> 

using namespace std;

// Estructura para asociar el ID del auto con su distancia recorrida
struct Resultado {
    int id;             // Identificador del auto
    int distancia;      // Distancia recorrida
};

mutex mtx;

// Función que simula la carrera de un auto
void pistaDeCarreras(int id, int distancia_total, int &resultado, vector<int> &arreglo) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);//se limita que los números randoms deben ser entre 1 a 10
    uniform_int_distribution<> tiempo(100, 500);

    int distancia_recorrida = 0;
    
    while (distancia_recorrida < distancia_total) {
        int avance = dist(gen);//se ingresan números randoms
        distancia_recorrida += avance;
        cout << "Auto " << id << " avanza " << avance << " metros (total: " << distancia_recorrida << " metros)\n";
        this_thread::sleep_for(chrono::milliseconds(tiempo(gen)));
    }

     {
        lock_guard<mutex> lock(mtx);  // Protegemos el acceso a "arreglo"
        arreglo.push_back(id);        // Agregamos el ID del auto en el vector cuando termina
    }

    resultado = distancia_recorrida;
    cout << "Auto " << id << " ha terminado la carrera.\n";
}

//Dentro del int main se ingresan parametros para que se ingresen los datos en la terminal
int main(int argc, char *argv[]) {
    // Verificamos si se ingresaron los parámetros correctos
    if (argc != 3) {

        //indica el mensaje de error
        cerr << "Uso: " << argv[0] << " <distancia_total> <numero_autos>\n";
        //indica que el programa ha terminado de manera anormal
        return 1;
    }

    int distancia_total;
    int numero_autos;

    try {
	//convierte los valores tipo string a un numero entero
        distancia_total = stoi(argv[1]);
        numero_autos = stoi(argv[2]);
	if (distancia_total <= 0 || numero_autos <= 0) {
        throw invalid_argument("Los valores deben ser mayores que 0.");
    }

    } catch (const invalid_argument &e) {

    	//muestra un error mostrando que ambos argumentos deben ser numeros enteros        
        cerr << "Error: Ambos argumentos deben ser números enteros.\n";
        return 1;

    } catch (const out_of_range &e) {
    	//muestra un error por si el número que ingresa es muy grande
        cerr << "Error: Los números ingresados son demasiado grandes.\n";
        return 1;

    }

    //se crea las hebras según la cantidad de autos que se ingresaron
    vector<thread> autos;
    vector<Resultado> resultados(numero_autos);  // Usamos la estructura Resultado para almacenar id y distancia
    vector<int> arreglo; 

    // Iniciamos las hebras para simular la carrera
    for (int i = 0; i < numero_autos; i++) {
        resultados[i].id = i;  // Asignamos el id del auto
        autos.emplace_back(pistaDeCarreras, i, distancia_total, ref(resultados[i].distancia), ref(arreglo));
    }

    // Esperamos a que todas las hebras terminen
    for (size_t i = 0; i < numero_autos; ++i) {
        autos[i].join();
    }


    // Mostramos el ranking final
    for (size_t i = 0; i < numero_autos; i++) {
        cout << "Lugar " << i + 1 << ": Auto " << arreglo[i] << "\n";
    }

    return 0;
}
