#include "../inc/main.h"
#include <stdio.h>
#include <modbus/modbus.h>

#define LAST_REG 125

int main() {
    modbus_t *ctx = NULL;
    uint16_t reg_data[LAST_REG];

    printf("Tentative de communication avec le premier esclave Modbus RTU (adresse 1)...\n");

    // Créer un contexte Modbus RTU
    ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
    if (ctx == NULL) {
        fprintf(stderr, "Impossible de créer le contexte Modbus RTU.\n");
        return 1;
    }

    // Configuration des paramètres série
    modbus_set_slave(ctx, 1); // Adresse de l'esclave Modbus

    // Connexion au périphérique Modbus
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Impossible de se connecter au périphérique Modbus.\n");
        modbus_free(ctx);
        return 1;
    }

    // Lecture de deux registres à partir de l'adresse 0
    if (modbus_read_registers(ctx, 0, LAST_REG, reg_data) == -1) {
        fprintf(stderr, "Échec de la lecture des registres Modbus.\n");
        modbus_close(ctx);
        modbus_free(ctx);
        return 1;
    }

    // Affichage des valeurs lues
	for(int i = 0; i < LAST_REG; i++){
    printf("Valeur du registre %d : %d\n",i, reg_data[i]);
	}
    // Fermeture de la connexion
    modbus_close(ctx);
    modbus_free(ctx);

    return 0;
}

