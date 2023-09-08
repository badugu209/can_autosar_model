#include "projectheader.h"

struct msg_cont_type msg;
struct service ser[4]={
    {
        "dcm_diag_ses_controlapi",0x10
    },
    {
        "security_level" ,0x27
    },
    {
        "read_did",0x22
    },
    {
        "write_did",0x2E
    }
};
uint8_t DCM_startof_reception(uint16_t DLC){
    uint8_t ret;
    uint32_t PDLC=1024;

    if(DLC<PDLC){
	ret =E_OK;
    }
    else
	{
	ret=E_NOT_OK;
	}

    return ret;
}
void dcm_copyrxdata(uint8_t can_handle_id,uint64_t *npdu_info_pointer){



	msg.dlc = ((uint8_t)((*npdu_info_pointer&((uint64_t)0xff<<48))>>48));

	msg.ser_ID =  ((uint8_t)((*npdu_info_pointer&((uint64_t)0xff<<40))>>40));

	msg.sub_ID = ((uint8_t)((*npdu_info_pointer&((uint64_t)0xff<<32))>>32));

	if (msg.ser_ID == 0x10)
		{

	fflush (stdout);

	dcm_diag_ses_controlapi(msg);

	}

	      else if (msg.ser_ID == 0x27)
		{

	msg.key1 = ((uint8_t)((*npdu_info_pointer&((uint64_t)0xff<<24))>>24));

	msg.key2 = ((uint8_t)((*npdu_info_pointer&((uint64_t)0xff<<16))>>16));

	security_level (msg);

	}

	      else

		{

	printf ("0x%x 0x%x 0x%x 0x%x\nservice not supported\n", NRCD,
			   NRCID, msg.ser_ID, NRC11);

}
}


