#!/bin/bash
# Definición de colores
RESET='\033[0m'         # Resetear todos los estilos y colores
RED='\033[0;31m'        # Rojo
GREEN='\033[0;32m'      # Verde
YELLOW='\033[0;33m'     # Amarillo
BLUE='\033[0;34m'       # Azul
MAGENTA='\033[0;35m'    # Magenta
CYAN='\033[0;36m'       # Cyan


echo -e "${CYAN}#    ####   ######   ##  ##   ######   ######    #####     ####   ######     ##     ######   ##   ##  ##  ## #
#   ##  ##   ##  ##  ##  ##    ##  ##  # ## #   ##   ##   ##  ##   ##  ##   ####     ##  ##  ##   ##  ##  ## #
#  ##        ##  ##  ##  ##    ##  ##    ##     ##   ##  ##        ##  ##  ##  ##    ##  ##  ##   ##  ##  ## #
#  ##        #####    ####     #####     ##     ##   ##  ##        #####   ##  ##    #####   #######   ####  #
#  ##        ## ##     ##      ##        ##     ##   ##  ##  ###   ## ##   ######    ##      ##   ##    ##   #
#   ##  ##   ##  ##    ##      ##        ##     ##   ##   ##  ##   ##  ##  ##  ##    ##      ##   ##    ##   #
#    ####   #### ##   ####    ####      ####     #####     #####  #### ##  ##  ##   ####     ##   ##   ####  #${RESET}"





# Función para mostrar el menú
show_menu() {
    echo -e "${MAGENTA}Seleccione un método criptográfico:${RESET}\n"
    echo -e "${GREEN}1. MD5${RESET}\n"
    echo -e "${AZUL}2. SHA256${RESET}\n"
    echo -e "${RED}3. HMAC${RESET}\n"
    echo -e "${YELLOW}4. ROT13${RESET}\n"
}

# Función para ejecutar el programa seleccionado
execute_program() {
    case $1 in
        1) ./md5/main ;;
        2) ./sha256/main ;;
        3) ./hmac/main ;;
        4) ./rot13/main ;;
        *) echo "Opción no válida" ;;
    esac
}

# Mostrar el menú
show_menu

# Leer la selección del usuario
read -s choice

# salto  de linea despues de la entrada
echo 

# Ejecutar el programa seleccionado
execute_program $choice

