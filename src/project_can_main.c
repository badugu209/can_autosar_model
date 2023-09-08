#include "projectheader.h"
#include<string.h>
struct signal_names
{				//structure for printing the name of the signal.
  uint8_t name[40];

}n[8];

int main ()
{				//giving the names of the signal
  strcpy (n[1].name, "temp");

  strcpy (n[2].name, "speed");

  strcpy (n[3].name, "odometer");

  strcpy (n[4].name, "indicators");

  strcpy (n[5].name, "wiper");

  strcpy (n[6].name, "door_locks");

  strcpy (n[7].name, "gearstate");

struct canbusdata *s;

//alocating the memory to the structure pointer.

s = malloc (3 * sizeof (struct canbusdata));




s->ifs = 0x07;


s->eof = 0x7f;


s->ack_delli = 0x01;


s->ack = 0x01;


s->crc_delli = 0x01;


s->crc_field = 0x6a29;


s->starto_f_frame = 0x01;


//s->arbitration_field = 0x000;


s->RTR = 0x00;

s->control_field = 0x2e;
//calling the can driver to read data from the can bus.
//I am taking this because of not having driver.
    can_rxintrupt(s);

//calling com to send data to application.

}
void os_call(){
    struct canbusdata *s;

    //alocating the memory to the structure pointer.

    s = malloc (3 * sizeof (struct canbusdata));
    can_rxintrupt(s);
}
data_received(uint8_t data){
    if(data==1){
	uint8_t signalID = 0;
    for (int i = 1; i < 8; i++)
        {
	uint32_t si;

    fflush (stdout);

    com_receive_signal (signalID, &si);

    printf ("%s = ", n[i].name);

    printf ("%d\n", si);

    printf ("\n");

    signalID++;
        }

    }
    else
	{
	printf("no data");
    }
}

