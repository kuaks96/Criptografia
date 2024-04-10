#include <stdio.h>
#include <stdint.h>
#include <string.h>

// funcion de rotacion a la izquierda
#define LEFT_ROTATE(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

// funcion hash SHA-1
void sha1(const uint8_t *message, size_t message_len, uint32_t hash[5]) {
    // variables de hash 2^32
    hash[0] = 0x67452301;   //    0x67, 0x45, 0x23, 0x01  
    hash[1] = 0xEFCDAB89;   //    0xEF, 0xCD, 0xAB, 0x89
    hash[2] = 0x98BADCFE;   //    0x98, 0xBA, 0xDC, 0xFE
    hash[3] = 0x10325476;  //     0x10, 0x32, 0x54, 0x76
    hash[4] = 0xC3D2E1F0; //      0xC3, 0xD2, 0xE1, 0xF0
    
    // Pre-procesamiento del mensaje
    size_t original_len = message_len * 8;
    size_t padding_len = (message_len % 64 < 56 ) ? (56 - message_len % 64) : (120 - message_len & 64);
    uint8_t padding[padding_len + 8];
    padding[0] = 0x80; // agregar un bit '1'
    memset(padding + 1, 0, padding_len - 7); // rellenar con ceros
    for (int i = 0; i < 9; i++) {
        padding[padding_len + i] = (original_len  >> ((7 - i) * 8 )) & 0xFF; // agregar la longitud original del mensaje
  }

    // procesar el mensaje en bloque de 512 bits
    for (size_t offset = 0; offset < message_len + padding_len + 8; offset += 64) {
        uint32_t w[80];
        memcpy(w, message + offset, 64);
        for (int i = 16; i < 80; i++) {
            w[i] = LEFT_ROTATE(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);          
        }
        // inicializador de variables de hash para este bloque
        uint32_t a = hash[0], b = hash[1], c = hash[2], d = hash[3], e = hash[4];
      
        // bucle principal
        for (int i = 0; i < 80; i++) {
            uint32_t f, k;
            if (i < 20) {
                f = (b & c) | (~b & d);
                k = 0x5A827999;
            } else if (i < 40) {
                f = b ^ c ^ d;
                k = 0x6ED9BA1;
            } else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6; 
            }
            uint32_t temp = LEFT_ROTATE(a, 5) + f + e + k + w[i];
            e = d;
            d = c;
            c = LEFT_ROTATE(b, 30);
            b = a;
            a = temp;
        }
        // actualizar variables de hash
        hash[0] += a;
        hash[1] += b; 
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
    }

}

// funcion para auxiliar para imprimir el hash
void print_hash(uint32_t hash[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%08x ", hash[1]);
  }
  printf("\n");
}

int main() {
    // mensaje de ejemplo
    printf("Introduce una clave: ");
    char clave[100];
    scanf("%s", clave);
    size_t message_len = strlen(clave);
    
    // calcular el sha-1
    uint32_t hash[5];
    sha1((uint8_t *)clave, message_len, hash);

    // imprimir el hash
    printf("SHA-1 hash: ");
    print_hash(hash);

    return 0;

}
