#include "projectheader.h"
typedef struct
{				//structure for ipdu
  uint16_t canid;

uint8_t dlc:4;

uint64_t * data_field;

}can_if_rx_lpdu;


can_if_rx_lpdu lpdu;

void
can_rxintrupt(struct canbusdata *s)
{

lpdu.data_field = malloc (64 * sizeof (uint64_t));
int m=7;

for (int i = 0; i < 8; i++) {

        fflush(stdout);
        scanf("%hhx", &data[i]);
        fflush(stdout);
        printf(" ");

    }
s->data_field = 0x0000000000000000ULL;
fflush(stdout);
s->data_field= (s->data_field|(((uint64_t)data[0]) << 56))|(s->data_field|(((uint64_t)data[1]) << 48))|(s->data_field|(((uint64_t)data[2]) << 40))|(s->data_field|(((uint64_t)data[3]) << 32))|(s->data_field|(((uint64_t)data[4]) << 24))|(s->data_field|(((uint64_t)data[5]) << 16))|(s->data_field|(((uint64_t)data[6]) << 8))|(s->data_field|(((uint64_t)data[7]) << 0));

uint16_t msg_ID;
//s->data_field = 0xa45fe267a289431a;
fflush(stdout);
scanf("%hx",&msg_ID);
printf("id    %x\n \n",msg_ID);
s->arbitration_field =(msg_ID&0x7ff);

    //printing the can frame data.
   /* printf ("canbus data:\n");


printf ("start of frame = %x\n", s->starto_f_frame);


printf ("arbitration_field = %x\n", s->arbitration_field);


printf ("RTR = %x\n", s->RTR);


printf ("control_field = %x\n", s->control_field);


printf ("data field =%llX\n", s->data_field);


printf ("crc field = %x\n", s->crc_field);


printf ("crc deli = %x\n", s->crc_delli);


printf ("ack = %x\n", s->ack);


printf ("ackc deli = %x\n", s->ack_delli);


printf ("eof = %x\n", s->eof);


printf ("ifs = %x\n", s->ifs);*/

fflush (stdout);

//checking rtr bit to conform weather it is a data frame of remote frame.

if (s->RTR == 1)
    {

printf ("remote frame");

fflush (stdout);

}

  else
    {

printf ("data frame");

}

uint16_t mask_value = 0xff0;
uint16_t mask_value1 = 0xff0;

//checking the msg Id that is in the range or not by code and mask.

if ((s->arbitration_field & mask_value) == (0x6a0 & mask_value))
    {				//mask vlue=0x6f0 and code = 0x6a0.

fflush (stdout);


printf ("message is in the range of h/obj\n");


lpdu.canid = s->arbitration_field;	//copying can frame id;

*lpdu.data_field = s->data_field;	//copying data.

can_if_rxindication(lpdu.canid, lpdu.data_field);	//calling canif layer api.
    }
else if ((s->arbitration_field & mask_value1) == (0x700 & mask_value1))
    {				//mask vlue=0x6f0 and code = 0x6a0.

fflush (stdout);


printf ("message is in the range of h/obj\n");


lpdu.canid = s->arbitration_field;	//copying can frame id;

*lpdu.data_field = s->data_field;	//copying data.

can_if_rxindication (lpdu.canid, lpdu.data_field);	//calling canif layer api.

    }
else{
    printf("arbitration failed");
}
}



