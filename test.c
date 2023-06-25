#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Obtener la longitud de la contraseña
    printf("Ingrese la longitud de la contraseña: ");
    int length;
    scanf("%d", &length);

    // Generar la contraseña
    const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));
    char* password = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        int charIndex = rand() % (sizeof(chars) - 1);
        password[i] = chars[charIndex];
    }
    password[length] = '\0';

    // Imprimir la contraseña generada
    printf("Contraseña generada: %s\n", password);

    free(password);
    return 0;
}
