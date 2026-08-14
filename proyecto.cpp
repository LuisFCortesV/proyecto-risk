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

    cout << "[INFO] Escriba 'ayuda' para ver la lista de comandos disponibles." << endl;
    cout << "[INFO] Escriba 'ayuda <comando>' para ver como se usa un comando especifico." << endl;

    do{

    
    cout << "$ ";
    getline(cin, respuesta);

    // Separar el texto mandando por el usuario, separado por espacios

    vector<string> respuesta_dividida;
    stringstream ss(respuesta);
    string token;

    while(ss >> token){
        respuesta_dividida.push_back(token);
    }

    if(!respuesta_dividida.empty() && respuesta_dividida[0] == "salir"){
        break;
    }

    if(respuesta_dividida.empty()){
        cout << "[ERROR] Debe ingresar un comando" << endl;
        continue;
    }

    // Comando de ayuda donde se listan todos los comandos

    if(respuesta_dividida[0] == "ayuda" && respuesta_dividida.size() == 1){
        cout << "[INFO] Comandos disponibles:" << endl;
        for(int i = 0; i < lista_comandos.size(); i++){
            cout << " - " << lista_comandos[i].nombre_comando << " (" << lista_comandos[i].cantidad_parametros << " parametro(s))" << endl;
        }
        continue;
    }

    // Para mostrar como se usa un comando especifico

     if(respuesta_dividida[0] == "ayuda" && respuesta_dividida.size() == 2){
        bool encontrado = false;
        for(int i = 0; i < lista_comandos.size(); i++){
            if(lista_comandos[i].nombre_comando == respuesta_dividida[1]){
                cout << "[INFO] Comando: " << lista_comandos[i].nombre_comando << endl;
                cout << "[INFO] Parametros: ";
                if(lista_comandos[i].cantidad_parametros == 0){
                    cout << "no requiere parametros";
                }else{
                    for(int k = 0; k < lista_comandos[i].parametros.size(); k++){
                        cout << lista_comandos[i].parametros[k];
                        if(k < lista_comandos[i].parametros.size() - 1){
                            cout << ", ";
                        }
                    }
                }
                cout << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            cout << "[ERROR] El comando no fue encontrado" << endl;
        }
        continue;
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
            cout << "[EXITO] Comando correcto con parametros correctos" << endl;
        }else{
            cout << "[ERROR] El comando fue encontrado pero los parametros eran incorrectos" << endl;
        }
    }else{
        cout << "[ERROR] El comando no fue encontrado" << endl;
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