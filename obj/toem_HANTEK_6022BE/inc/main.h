
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <modbus/modbus.h>

//***************************
//	Arg config API
//***************************

//Context flag for function call
#define READ_DATA "-rd"
#define READ_CONFIG "-rc"
#define WRITE_CONFIG "-wc"

//Number of arg into each request
#define READ_DATA_ARG_NUM 0
#define READ_CONFIG_ARG_NUM 0
#define WRITE_CONFIG_ARG_NUM 3

//***************************
//Register address definition
//***************************

//Adress range
#define MIN_REG 0 	//Premier registre utile
#define MAX_REG 125 	//Dernier registre

//Register saved power supply state on(1) or off(0)
#define OUTPUT_STATE 0x01

//Some data about power supply
#define CALIBER 0x03 //Model
#define NAME0 0x04 //probably supply reference
#define NAME1 0x05 //probably supply reference

//Real time data
#define ACTUAL_VOLTAGE 0x10
#define ACTUAL_CURRENT 0x11
#define ACTUAL_POWER_H 0x12
#define ACTUAL_POWER_L 0x13

//OVP & OCP & OPP
#define OVP 0x20
#define OCP 0x21
#define OPP_H 0x22
#define OPP_L 0x23

//Some Unknown data
#define UNKNOWN1 32
#define UNKNOWN2 33
#define UNKNOWN3 34
#define UNKNOWN4 35

//Data choosed
#define SET_VOLTAGE 48
#define SET_CURRENT 49
#define TIME_SPAN 50

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
bool write_reg(uint8_t n_reg, uint16_t value, modbus_t * ctx);
void read_config(struct hm310t_config * config, modbus_t * ctx);
void read_data(struct hm310t_data * data, modbus_t * ctx);
bool write_config(struct hm310t_config * config, modbus_t * ctx);

