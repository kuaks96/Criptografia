/*****Definimos la macro para md5 para poder compilar el codigo****/
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

// Fichero necesario
#include <iostream>
#include <string>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

int main() { // Definimos las variables
  std::string message;
  CryptoPP::Weak::MD5 md5;

  // solicitar el ingreso del mensaje
  std::cout << "Ingrese el mensaje: ";
  std::getline(std::cin, message);

  // Se calcula el hash MD5
  std::string digest;
  CryptoPP::StringSource(message, true, new CryptoPP::HashFilter(md5, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));

  // Imprimir el mensaje
  std::cout << "Mensaje cifrado en MD5: " << digest << std::endl;

  return 0;
}
