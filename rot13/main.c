#include <stdio.h>

char rot13(char c) {
  if (c >= 'a' && c <= 'z') {
    return (((c - 'a') + 13) % 26) + 'a';
  } else if (c >= 'A' && c <= 'Z') {
    return (((c - 'A') + 13) % 26) + 'A';
  } else {
    return c;
  }
}

void rot13_encrypt(char* message) {
  char* p = message;
  while (*p != '\0') {
    *p = rot13(*p);
    p++;
  }
}

int main() {
  char message[100]; // Definimos un array lo suficientemente grande para almacenar el mensaje

  // Pedimos al usuario que ingrese el mensaje
  printf("Ingrese el mensaje a cifrar en ROT13: ");
  scanf("%99[^\n]", message); // Leemos el mensaje hasta encontrar un salto de línea o hasta que alcancemos 99 caracteres
  
  // Limpieza del buffer de entrada
  while (getchar() != '\n');

  // Ciframos el mensaje
  rot13_encrypt(message);

  // Imprimimos el mensaje cifrado
  printf("Mensaje cifrado en ROT13: %s\n", message);

  return 0;
}

