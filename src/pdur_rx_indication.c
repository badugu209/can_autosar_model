#include "projectheader.h"
uint8_t id[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };


void
pdur_canif_rxindication (uint8_t can_handle_id, uint64_t * ipdu_info_pointer)
{

for (int i = 0; i < 16; i++)
    {

if (can_handle_id == id[i])
	{

//printf ("id=%d\n", can_handle_id);

com_rxindication (can_handle_id, ipdu_info_pointer);	//sending the IPDU to com layer.
	  break;

}

}

}
uint8_t pdur_cantp_startof_resuption(uint16_t DLC){

    uint8_t ret;
ret=DCM_startof_reception(DLC);
return ret;
}

void pdur_cantp_copyRxdata(uint8_t can_handle_id,uint64_t *npdu_info_pointer){
    dcm_copyrxdata(can_handle_id,npdu_info_pointer);
}
