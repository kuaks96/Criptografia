// ficheros necesario para el script
#include <iostream>
#include <string>
#include <cryptopp/hmac.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

int main() {
  // declaramos las variables
  std::string message;
  std::string key;
  std::string digest;

  // solicitamos al usuario que ingrese el mensaje a cifrar 
  std::cout << "Ingrese el mensaje a cifrar: ";
  std::getline(std::cin,message);

  // Calculamos el HMAC-SHA256 del mesaje utilizando la clave
  CryptoPP::HMAC<CryptoPP::SHA256> hmac((const CryptoPP::byte*)key.data(), key.size());
  CryptoPP::StringSource(message, true, new CryptoPP::HashFilter(hmac, new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest))));

  // Imprimir el resultado del HMAC-SHA256
  std::cout << "HMAC-SHA256 del mensaje: " << digest << std::endl;

  return 0;
}
