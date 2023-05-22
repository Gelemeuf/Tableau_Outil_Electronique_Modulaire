
//*****************
//  Command list
//*****************

#define help "h"
#define periph_list "pl"
#define 

//*****************
//     Struct
//*****************

struct periph{
	char type[64];
	char path[256];
	
};

struct command{
	char name[32];
	struct command_item[32];
};

struct command_item{
	int type;
	
};	

//*****************
//   Signature
//*****************

read_periph(char * file_name)
