/*Utilizamos los ficheros necesario*/
#include <iostream>
#include <string>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

// variables
int main() {
  std::string message;
  CryptoPP::SHA256 sha256;

  // Ingresar el mensaje
  std::cout << "Ingrese el mensaje: ";
  std::getline(std::cin, message);

  // Calcular sha-256
  std::string digest;
  CryptoPP::StringSource(message, true, new CryptoPP::HashFilter(sha256, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));

  // imprimir el resultado
  std::cout << "Mensaje cifrado en SHA256: " << digest << std::endl;

  return 0;

}
