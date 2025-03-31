//Sebastian Cambo CambiUPR
//801229348
//Asignacion 6: Figuras en 3D

#include <iostream>

using namespace std;

//Aqui van los prototipos que vamos a usar para las calculaciones de volumen y area

//Funcion para volumen de cilindro
double volumenCilindro(double radio, double altura){
    return 3.14159 * radio * radio * altura;
}

//Funcion para volumen de esfera
double volumenEsfera(double radio){
    return(4.0 / 3.0) * 3.14159 * radio * radio * radio;
}

//Funcion para volumen de rectangulo
double volumenRectangulo(double largo, double ancho, double altura){
    return largo * ancho * altura;
}

//Funcion para calcular la area del cilindro
double areaCilindro(double radio, double altura){
    return 2 * 3.14159 * radio * (radio + altura);
}

//Funcion para calcular el area de la esfera
double areaEsfera(double radio){
    return 4 * 3.14159 * radio * radio;
}

//Funcion para calcular area del rectangulo
double areaRectangulo(double largo, double ancho, double altura){
    return 2 * (largo * ancho * ancho * altura * altura * largo);
}

//Input validation
double entradaPositiva(string entrada){
    double input;
    do {
        cout << entrada;
        cin >> input;
        if(input <= 0 || cin.fail()){
            cout << "Ingrese un valor positivo. \n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (input <= 0 || cin.fail());
    return input;
}

//Ahora la invocacion como tal de main
int main(){
    char figura, operacion;
    cout << "Escoga una figura: \nA. Cilindro\nB. Esfera\nC. Rectangulo\n";
    cin >> figura;

    cout << "Escoge la calculacion: \nA. Volumen\nB. Area\n";
    cin >> operacion;

    double radio, altura, largo, ancho, resultado;


    switch(figura){
        case 'A': //Para el cilindro
            radio = entradaPositiva("Escribe el radio del cilindro: ");
            altura = entradaPositiva("Escribe la altura del cilindro: ");
            if(operacion == 'A'){
                resultado = volumenCilindro(radio, altura);
            } else {
                resultado = areaCilindro(radio, altura);
            }
            break;
        case 'B': //Para la esfera
            radio = entradaPositiva("Escribe el radio de la esfera: ");
            if(operacion == 'A'){
                resultado = volumenEsfera(radio);
            } else {
                resultado = areaEsfera(radio);
            }
            break;
        case 'C': // Para el rectangulo
            largo = entradaPositiva("Escribe el largo del rectangulo: ");
            ancho = entradaPositiva("Escribe el ancho del rectangulo: ");
            altura = entradaPositiva("Escribe la altura del rectangulo: ");
            if(operacion == 'A'){
                resultado = volumenRectangulo(largo, ancho, altura);
            } else {
                resultado = areaRectangulo(largo, ancho, altura);
            }
            break;
        default:
            cout << "Opcion escogida no es valida. \n";
            return 1;
        }

        cout.precision(2);
        cout << fixed;
        if(operacion == 'A'){
            cout << "El volume es: " << resultado << endl;
        } else {
            cout << "El area es: " << resultado << endl;
        }
        
        return  0;
    
}