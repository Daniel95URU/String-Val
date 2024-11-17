#include <iostream>
#include <string>
#include <cctype> // Para isdigit y isalpha
#include <locale.h>
#include <windows.h>

using namespace std;

bool esDigito(const string& cadena) {
    return cadena.size() == 1 && isdigit(cadena[0]);
}

bool esLetra(const string& cadena) {
    return cadena.size() == 1 && isalpha(cadena[0]);
}

bool esPalabra(const string& cadena) {
    for (size_t i = 0; i < cadena.size(); ++i) {
        if (!isalpha(cadena[i])) {
            return false;
        }
    }
    return !cadena.empty();
}

bool esNumeroEntero(const string& cadena) {
    for (size_t i = 0; i < cadena.size(); ++i) {
        if (!isdigit(cadena[i])) {
            return false;
        }
    }
    return !cadena.empty();
}

bool esNumeroReal(const string& cadena) {
    size_t punto = cadena.find('.');
    if (punto == string::npos) {
        return false; // No hay punto
    }
    string parteEntera = cadena.substr(0, punto);
    string parteDecimal = cadena.substr(punto + 1);

    return !parteEntera.empty() && !parteDecimal.empty() &&
           esNumeroEntero(parteEntera) && esNumeroEntero(parteDecimal);
}

/*
-----------------------------------------------------------------------------------------
CADENA QUE VALIDA UN IDENTIFICADOR DE LA FORMA a(cd) descartada en clase por el profesor.
----------------------------------------------------------------------------------------- 
Nueva forma de identificador: 	(letra|'_')+=(digito|letra|'_')+ 
	1. donde la expresión de la izquierda no puede empezar por dígitos.
	2. Pueden utilizarse '_' en ambos lados de la expresión regular
*/

//bool esIdentificador(const string& cadena) {
//    if (cadena.empty() || !isalpha(cadena[0])) {
//        return false; // La cadena está vacía o no empieza con una letra
//    }
//    if (cadena.size() < 3 || cadena[1] != '(' || cadena[cadena.size() - 1] != ')') {
//        return false; // Debe tener al menos "a()" y paréntesis válidos
//    }
//    for (size_t i = 2; i < cadena.size() - 1; ++i) {
//        if (!isalnum(cadena[i])) { // Solo permite letras o números dentro de los paréntesis
//            return false;
//        }
//    }
//    return true;
//}  				

// Función para verificar si es un identificador letra|palabra = (letra|digito|_)+
bool esIdentificador(const string& cadena) {
    size_t igual = cadena.find('=');
    if (igual == string::npos) {
        return false; // No contiene un signo igual
    }

    string izquierda = cadena.substr(0, igual);
    string derecha = cadena.substr(igual + 1);

    // Verifica que la parte izquierda no esté vacía y no comience con un dígito 
    bool identificador = !izquierda.empty() && !isdigit(izquierda[0]);
    for (size_t i = 0; i < izquierda.size() && identificador; ++i) {
        if (!isalnum(izquierda[i]) && izquierda[i] != '_') { 
            identificador = false;
        }
    }
    // Verifica que la parte derecha sea una combinación de letras, dígitos y '_'
    bool valor = !derecha.empty();
    for (size_t i = 0; i < derecha.size() && valor; ++i) {
        if (!isalnum(derecha[i]) && derecha[i] != '_') { 
            valor = false;
        }
    }

    return identificador && valor;
}

bool esOperador(const string& cadena) {
    return cadena == "=" || cadena == "+" || cadena == "-" ||
           cadena == "*" || cadena == "/" || cadena == "%";
}

// Función principal de validación
void validarCadena(const string& cadena) {
    if (esDigito(cadena)) {
    	system("color f0");
        cout << "Es un dígito." << endl;
    } else if (esLetra(cadena)) {
    	system("color f0");
        cout << "Es una letra." << endl;
    } else if (esPalabra(cadena)) {
    	system("color f0");
        cout << "Es una palabra." << endl;
    } else if (esNumeroEntero(cadena)) {
    	system("color f0");
        cout << "Es un número entero." << endl;
    } else if (esNumeroReal(cadena)) {
    	system("color f0");
        cout << "Es un número real." << endl;
    } else if (esIdentificador(cadena)) {
    	system("color f0");
        cout << "Es un identificador." << endl;
    } else if (esOperador(cadena)) {
    	system("color f0");
        cout << "Es un operador." << endl;
    } else {
    	system("color 40");
        cout << "\t\t\n\t\t\t\t\t\tError :( \n\n\n\t\t\t\t" << endl;
        cout << "\n\n\n\t\t\tLa cadena no cumple con ninguna de las expresiones regulares que se piden.\n\n\n\n" << endl;
        exit(-1);
    }
}

int main() {
    setlocale(LC_ALL, "spanish");
    string entrada;

    while (true) { 
        cout << "Ingrese una cadena para validar o el simbolo '|' para salir: \n";
        getline(cin, entrada);

        if (entrada == "|") {
            cout << "Saliendo del programa..." << endl;
            break; 
        }

        Beep(400, 400);
        validarCadena(entrada);
        Beep(450, 450);
    }

    system("pause");
    return 0;
}
