#include "../inc/main.h"
#include <stdint.h> //uint16, uint8
#include <stdio.h>
#include <stdbool.h> //bool
#include <stdlib.h> //malloc
#include <modbus/modbus.h> //modbus

uint16_t read_reg(uint8_t n_reg, modbus_t * ctx){
	return 0;
}	

bool write_reg(uint8_t n_reg, uint16_t val, modbus_t * ctx){
	return 0;
}

struct hm310t_config * read_config(struct hm310t_config * config){
	config->voltage = 1;
	config->current = 2;
	config->output_state =0;
	return config;	
}

struct hm310t_data * read_data(struct hm310t_data * data){
	data->voltage = 1;
	data->current = 2;
	data->power = 3;
	return data;
}

bool write_config(struct hm310t_config * config){
	return 0;
}

int main() {
	//Allocation des tailles de structures
	/*struct hm310t_config config = malloc(sizeof(struct hm310t_config));
	struct hm310t_data data = malloc(sizeof(struct hm310t_data));
	modbus_t *ctx = NULL;
	*/
/*
    modbus_t *ctx = NULL;
    uint16_t reg_value;
	
    printf("Try to connect to modbus peripheral (address 1)\n");

    // Create Modbus RTU context
    ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
    if (ctx == NULL) {
<<<<<<< HEAD
        fprintf(stderr, "Cannot create Modbus RTU context.\n");
        return 1;
=======
        fprintf(stderr, "Impossible de créer le contexte Modbus RTU.\n");
        return EXIT_FAILURE;
>>>>>>> 391229033386017688215002db1757fa7ffaf1c8
    }

    // Configuration des paramètres série
    modbus_set_slave(ctx, 1); // Adresse de l'esclave Modbus

    // Connexion au périphérique Modbus
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Cannot connect to a Modbus peripheral.\n");
        modbus_free(ctx);
        return EXIT_FAILURE;
    }

    // Lecture de deux registres à partir de l'adresse 0
    if (modbus_read_registers(ctx, 0, LAST_REG, reg_data) == -1) {
        fprintf(stderr, "Cannot read Modbus registers.\n");
        modbus_close(ctx);
        modbus_free(ctx);
        return EXIT_FAILURE;
    }

    // Affichage des valeurs lues
	for(int i = 0; i < LAST_REG; i++){
    //printf("Register value %d : %d\n",i, reg_data[i]);
	}
    // Fermeture de la connexion
    modbus_close(ctx);
    modbus_free(ctx);
<<<<<<< HEAD
*/
    return 0;
}

