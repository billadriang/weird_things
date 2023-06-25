package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"time"
)

func main() {
	// Obtener la longitud de la contraseña
	fmt.Print("Ingrese la longitud de la contraseña: ")
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	var length int
	_, err := fmt.Sscanf(input, "%d", &length)
	if err != nil {
		fmt.Println("Error al leer la entrada:", err)
		return
	}

	// Generar la contraseña
	chars := "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
	rand.Seed(time.Now().UnixNano())
	password := make([]byte, length)
	for i := 0; i < length; i++ {
		charIndex := rand.Intn(len(chars))
		password[i] = chars[charIndex]
	}

	// Imprimir la contraseña generada
	fmt.Printf("Contraseña generada: %s\n", string(password))
}
