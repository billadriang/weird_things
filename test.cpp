#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Obtener la longitud de la contraseña
    std::cout << "Ingrese la longitud de la contraseña: ";
    int length;
    std::cin >> length;

    // Generar la contraseña
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::srand(std::time(nullptr));
    std::string password;
    for (int i = 0; i < length; i++) {
        int charIndex = std::rand() % chars.length();
        password += chars[charIndex];
    }

    // Imprimir la contraseña generada
    std::cout << "Contraseña generada: " << password << std::endl;

    return 0;
}
