#include <iostream>
#include <string>
#include <cctype> // Para isdigit y isalpha
#include <locale.h>
#include <windows.h>

using namespace std;

// Función para verificar si es un dígito
bool esDigito(const string& cadena) {
    return cadena.size() == 1 && isdigit(cadena[0]);
}

// Función para verificar si es una letra
bool esLetra(const string& cadena) {
    return cadena.size() == 1 && isalpha(cadena[0]);
}

// Función para verificar si es una palabra (letra+)
bool esPalabra(const string& cadena) {
    for (size_t i = 0; i < cadena.size(); ++i) {
        if (!isalpha(cadena[i])) {
            return false;
        }
    }
    return !cadena.empty();
}

// Función para verificar si es un número entero (digito+)
bool esNumeroEntero(const string& cadena) {
    for (size_t i = 0; i < cadena.size(); ++i) {
        if (!isdigit(cadena[i])) {
            return false;
        }
    }
    return !cadena.empty();
}

// Función para verificar si es un número real (digito+ . digito+)
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

// Nueva función para verificar si es un identificador (letra seguida de paréntesis con letras/números)
bool esIdentificador(const string& cadena) {
    if (cadena.empty() || !isalpha(cadena[0])) {
        return false; // La cadena está vacía o no empieza con una letra
    }
    if (cadena.size() < 3 || cadena[1] != '(' || cadena[cadena.size() - 1] != ')') {
        return false; // Debe tener al menos "a()" y paréntesis válidos
    }
    for (size_t i = 2; i < cadena.size() - 1; ++i) {
        if (!isalnum(cadena[i])) { // Solo permite letras o números dentro de los paréntesis
            return false;
        }
    }
    return true;
}

// Función para verificar si es un operador
bool esOperador(const string& cadena) {
    return cadena == "=" || cadena == "+" || cadena == "-" ||
           cadena == "*" || cadena == "/" || cadena == "%";
}

// Función principal de validación
void validarCadena(const string& cadena) {
    if (esDigito(cadena)) {
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
        cout << "Error :( La cadena no cumple con ninguna expresión regular válida." << endl;
    }
}

int main() {
	setlocale(LC_ALL, "spanish");
    string entrada;
    cout << "Ingrese una cadena para validar: ";
    getline(cin, entrada);
	Beep(400, 400);
   	Beep(450, 450);
   	Beep(350, 350);
    validarCadena(entrada);

    return 0;
}

