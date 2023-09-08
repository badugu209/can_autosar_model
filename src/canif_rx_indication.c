#include "projectheader.h"
enum Indication{
    pdur,cantp,canNM
};
enum Indication indi;
struct can_if_rx_ipdu
{				//structure for ipdu
  uint16_t handle_canid;

uint64_t * data_field;

};
struct can_TP_rx_ipdu
{				//structure for ipdu
  uint16_t handle_canid;

uint64_t * data_field;

};
void
can_if_rxindication (uint16_t lpdu_canid, uint64_t * lpdu_info_pointer)
{

uint8_t id = 0;

fflush (stdout);

//printf ("can_if_data\n");


struct can_if_rx_ipdu ipdu;
struct can_TP_rx_ipdu npdu;

ipdu.data_field = malloc (64 * sizeof (uint64_t));


//checking the msg id like a software filter.

uint16_t canid_values[] =
  {
  0x6a0, 0x6a1, 0x6a2, 0x6a3, 0x6a4, 0x6a5, 0x6a6, 0x6a7, 0x6a8, 0x6a9,
      0x6aa, 0x6ab, 0x6ac, 0x6ad, 0x6ae};

uint16_t canTPid_values[] =
  {
  0x704,0x705,0x707};
for (int i = 0; i < 15; i++)
    {


if (lpdu_canid == canid_values[i])
	{


//printf ("can id confirmed\n");


ipdu.handle_canid = id;	//giving the handle id to the msg.

*(ipdu.data_field) = *lpdu_info_pointer;
indi=0;

}
else if(lpdu_canid == canTPid_values[i]){
   // printf ("can TPid confirmed\n");


    npdu.handle_canid = id;	//giving the handle id to the msg.

    *(npdu.data_field) = *lpdu_info_pointer;

    indi=1;
}

      else
	{

id++;

}

}

fflush (stdout);
switch(indi){
case pdur:
    {
   // printf ("can haldle id = %d\n ", ipdu.handle_canid);

    pdur_canif_rxindication (ipdu.handle_canid, ipdu.data_field);	//sending the IPDU to pdur layer.
    }
case cantp:
    {
    //printf ("can haldle id = %d\n ", npdu.handle_canid);

    can_tp_rxindication (npdu.handle_canid, npdu.data_field);	//sending the IPDU to pdur layer.
    }
}

os_call();
}


