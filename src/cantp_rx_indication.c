#include "projectheader.h"
enum frame_indication{
    single_frame,first_frame,consecutive_frame,flow_control_frame
};
uint32_t pci;
uint64_t dcm_data;
uint16_t DLC;
enum frame_indication FI;
void can_tp_rxindication (uint8_t can_handle_id,
			       uint64_t * npdu_info_pointer){

   // printf ("\ncan haldle id = %llx \n ",  * npdu_info_pointer);
    pci=(uint32_t)(((*npdu_info_pointer |((uint64_t)(0xffffff<<40))))>>40);
    FI=(uint8_t)((pci&((uint32_t)0xf0<<16))>>20);
    DLC=(uint16_t)((pci&((uint32_t)0xfff<<8))>>8);
   // printf("%x\n",FI);
switch(FI){
case single_frame:{
uint8_t result;
//printf("\nsingle frame");
result=pdur_cantp_startof_resuption(DLC);
if(result==E_OK){
    pdur_cantp_copyRxdata(can_handle_id,npdu_info_pointer);
}
break;
}
case first_frame:{
printf("\n first frame");
break;
}
case consecutive_frame:{
printf("\n consecutive frame");
break;
}
case flow_control_frame:{
printf("\n flow control frame");
break;
}
}

}
