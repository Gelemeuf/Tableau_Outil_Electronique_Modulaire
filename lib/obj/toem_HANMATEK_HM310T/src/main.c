#include "../inc/main.h"
#include <stdint.h> //uint16_t, uint8_t
#include <stdio.h>
#include <stdbool.h> //bool
#include <stdlib.h> //malloc
#include <string.h> //strcmp
#include <modbus/modbus.h> //modbus

#define print_debug_info 0

uint16_t read_reg(uint8_t n_reg, modbus_t * ctx){
	uint16_t value;
	if (modbus_read_registers(ctx, n_reg, 1, &value) == -1){
		return 0xFFFF; //Data in case of an error
	}
	return value;
}	

bool write_reg(uint8_t n_reg, uint16_t value, modbus_t * ctx){
	if(modbus_write_register(ctx, n_reg, value) == -1){
		printf("wrong\n");
		return 0;
	}
	return 1; //1 if ok, 0 if error
}

void read_config(struct hm310t_config * config, modbus_t * ctx){
	config->voltage = read_reg(SET_VOLTAGE,ctx);
	config->current = read_reg(SET_CURRENT,ctx);
	config->output_state =read_reg(OUTPUT_STATE,ctx);
	return;
}

void read_data(struct hm310t_data * data, modbus_t * ctx){
	data->voltage = read_reg(ACTUAL_VOLTAGE,ctx);
	data->current = read_reg(ACTUAL_CURRENT,ctx);
	data->power = read_reg(ACTUAL_POWER_H,ctx);
	return;
}

bool write_config(struct hm310t_config * config, modbus_t * ctx){
	bool state = 1;
	state &= write_reg(SET_VOLTAGE, config->voltage, ctx);
	state &= write_reg(SET_CURRENT, config->current, ctx);
	state &= write_reg(OUTPUT_STATE, config->output_state, ctx);
	return state; //1 if ok, 0 if error
}

int main(int argc, char * argv[]) {
	//Memory struct allocation
	/*
	struct hm310t_config * config = malloc(sizeof(struct hm310t_config));
	struct hm310t_data * data = malloc(sizeof(struct hm310t_data));
	*/
	modbus_t *ctx = NULL;
    
    	// Create Modbus RTU context
    	ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
    	if (ctx == NULL) {
		if(print_debug_info)printf("cannot create modbus context\n");
        	return 1;
    	}
	if(print_debug_info)printf("modbus context created\n");

    	// Configuration des paramètres série
    	modbus_set_slave(ctx, 1); // Adresse de l'esclave Modbus

    	// Connexion au périphérique Modbus
    	if (modbus_connect(ctx) == -1) {
        	modbus_free(ctx);
		if(print_debug_info)printf("cannot connect to modbus peripheral\n");
        	return EXIT_FAILURE;
    	}
	if(print_debug_info)printf("modbus peripheral connected\n\n");

	/*
	while(1){
		read_data(data, ctx);
		if(print_debug_info)printf("%d;%d;%d",data->voltage,data->current,data->power);
	}
	*/

	if(argc > 1){
		if(strcmp(argv[1],READ_CONFIG)==0){
			if(argc != 2){
				return EXIT_FAILURE;
			}
			else{
				struct hm310t_config * config = malloc(sizeof(struct hm310t_config));
				read_config(config, ctx);
				printf("%d;%d;%d\n",config->voltage,config->current,config->output_state);
				free(config);
			}
		}
		else if(strcmp(argv[1],READ_DATA)==0){
			if(argc != 2){
				return EXIT_FAILURE;
			}
			else{
				struct hm310t_data * data = malloc(sizeof(struct hm310t_data));
				read_data(data, ctx);
				printf("%d;%d;%d\n",data->voltage,data->current,data->power);
				free(data);
			}
		}
		else if(strcmp(argv[1],WRITE_CONFIG)==0){
			if(argc != 5){
				printf("heuuuu\n");
				return EXIT_FAILURE;
			}
			else{
				struct hm310t_config * config = malloc(sizeof(struct hm310t_config));
				printf("%d,%d,%d\n",atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
				config->voltage = (uint16_t)atoi(argv[2]);
				config->current = (uint16_t)atoi(argv[3]);
				config->output_state = (bool)atoi(argv[4]);
				write_config(config,ctx);
				free(config);
			}
		}
	}

    	// Fermeture de la connexion
    	modbus_close(ctx);
    	modbus_free(ctx);
	
	//Analocation memory
	/*
	free(&config);
	free(&data);
	*/
    	return EXIT_SUCCESS;
}

