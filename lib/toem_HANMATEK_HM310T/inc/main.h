
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <modbus/modbus.h>

//***************************
//Register address definition
//***************************

//Adress range
#define MIN_REG 0 	//Premier registre utile
#define MAX_REG 125 	//Dernier registre

//Register saved power supply state on(1) or off(0)
#define OUTPUT_STATE 1

//Some data about power supply
#define CALIBER 3 //Caliber reference
#define NAME0 4 //probably supply reference
#define NAME1 5 //probably supply reference

//Real time data
#define ACTUAL_VOLTAGE 16
#define ACTUAL_CURRENT 17
#define ACTUAL_POWER_ARROUND 19
#define ACTUAL_POWER_NORMAL 21

//Some Unknown data
#define UNKNOWN1 32
#define UNKNOWN2 33
#define UNKNOWN3 34
#define UNKNOWN4 35

//Data choosed
#define SET_VOLTAGE 48
#define SET_CURRRENT 49
#define STEP_VOLTAGE_mV 50

//Supply maximum
#define MAX_VOLTAGE 64
#define MAX_CURRENT 65

//***************************
//        Structures
//***************************

struct hm310t_config{
	uint16_t voltage;
	uint16_t current;
	bool output_state;
};

struct hm310t_data{
	uint16_t voltage;
	uint16_t current;
	uint16_t power;
};

//***************************
//        Signatures
//***************************

uint16_t read_reg(uint8_t n_reg, modbus_t * ctx);
bool write_reg(uint8_t n_reg, uint16_t val, modbus_t * ctx);
struct hm310t_config * read_config(struct hm310t_config * config);
struct hm310t_data * read_data(struct hm310t_data * data);
bool write_config(struct hm310t_config * config);

