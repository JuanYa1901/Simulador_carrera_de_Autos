# Simulador de Carrera de Autos

Este proyecto es un simulador de carrera de autos desarrollado para ser ejecutado en un entorno Linux.

## Requisitos

- Sistema operativo: Linux
- Compilador: GCC o G++
- Librerías: pthread, thread (C++ estándar)

## Instalación

1. Clona el repositorio:
   ```bash
   git clone https://github.com/JuanYa1901/Simulador_carrera_de_Autos.git
   ```
2. Navega al directorio del proyecto:
   ```bash
   cd Simulador_carrera_de_Autos
   ```
3. Se tiene que ejecutar el comando make:
   ```bash
   se debe ejecutar el comando make para que se pueda ejecutar
   ```

## Uso

Para ejecutar el simulador, usa el siguiente comando:

```bash
./carrera <distancia_total> <numero_de_autos>
```

Donde `<distancia_total>` es la distancia total de la carrera en metros y `<numero_de_autos>` es el número de autos participantes.

## Descripción del Simulador

El simulador de carrera de autos utiliza programación multihebras. Cada automóvil competidor correrá en una hebra distinta. La carrera consiste en que cada auto recorrerá una distancia de M metros en intervalos de tiempo aleatorios.

Cada automóvil:

- Tendrá un identificador único (ej: Auto1, Auto2, etc.).
- Avanzará una cantidad aleatoria de metros en cada iteración (máximo de 10 metros).
- Se detendrá por un tiempo aleatorio (entre 100-500 ms) en cada iteración.

La carrera finalizará cuando todos los autos hayan terminado el recorrido. El programa mostrará el progreso de cada auto en la terminal y los resultados finales, incluyendo el ganador y el orden de llegada.
