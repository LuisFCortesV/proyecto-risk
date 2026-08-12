#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Comandos{

    string nombre_comando;
    int cantidad_parametros;
    vector<string> parametros;
};

int main(){

    // struct de los comandos

    Comandos c1 = {"inicializar", 1, {"archivo_texto"}};
    Comandos c2 = {"obtener_unidades", 1, {"nombre_jugador"}};
    Comandos c3 = {"atacar", 1, {"nombre_jugador"}};
    Comandos c4 = {"fortificar", 1, {"nombre_jugador"}};
    Comandos c5 = {"estado_juego", 0, {"no requiere parametros adicionales"}};

    Comandos c6 = {"guardar", 1, {"nombre_archivo"}};
    Comandos c7 = {"guardar_comprimido", 1, {"nombre_archivo"}};
    Comandos c8 = {"inicializar", 1, {"archivo_inicio"}};

    Comandos c9 = {"costo_conquista", 2, {"nombre_jugador","territorio"}};
    Comandos c10 = {"conquista_mas_barata", 1, {"nombre_jugador"}};

    vector<Comandos> lista_comandos = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10};

    // Mensaje por consola
    string respuesta;

    do{

    
    cout << "$ ";
    getline(cin, respuesta);

    // Separar el texto mandando por el usuario, separado por espacios

    vector<string> respuesta_dividida;
    stringstream ss(respuesta);
    string token;

    while(getline(ss, token, ' ')){
        respuesta_dividida.push_back(token);
    }

    // recorrer vector de comandos hasta encontrar respuesta

    bool comando_parametros = false;
    bool comando_c = false;

    for(int i = 0; i < lista_comandos.size(); i++){
        for(int j = 0; j < respuesta_dividida.size(); j++){
            if(lista_comandos[i].nombre_comando == respuesta_dividida[0]){
                comando_c = true;
                if(respuesta_dividida.size() - 1 == lista_comandos[i].cantidad_parametros){
                    comando_parametros = true;
                    break; 
                }
                else{
                    comando_parametros = false;
                }
            }
        }
    }

    if(comando_c){
        if(comando_parametros && comando_c){
            cout << "Comando correcto con parametros correctos" << endl;
        }else{
            cout << "El comando fue encontrado pero los parametros eran incorrectos" << endl;
        }
    }else{
        cout << "El comando no fue encontrado" << endl;
    }


}while(respuesta != "salir");


    return 0;
}

// COMPONENTE 1

// Inicializar archivo_texto - 1 parametro
// Obtener_unidades nombre_jugador - 1 parametro
// Atacar nombre_jugador - 1 parametro
// Fortificar nombre_jugador - 1 parametro
// Estado de juego - 0 parametro
// Salir

// COMPONENTE 2

// Guardar nombre_archivo - 1 parametro
// Guardar_comprimido nombre_archivo - 1 parametro
// inicializar archivo_inicio - 1 parametro

// COMPONENTE 3

// costo_conquista nombre_jugador territorio - 2 parametros
// conquista_mas_barata nombre_jugador - 1 parametro