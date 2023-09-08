
#include "projectheader.h"


void
dcm_diag_ses_controlapi (struct msg_cont_type msg)
{
  //  printf("sss 0%x  ss \n",msg.sub_ID);

if (msg.dlc == 0x02)
    {

switch (msg.sub_ID)
	{

case 01:

	  {

if (D_S_C == progrraming || D_S_C == extended_diag)
	      {

printf ("0x%x 0x%x 0x%x P2 P2 P2* P2*\n", PRCD,
			 (PRID | msg.ser_ID), msg.sub_ID);

printf ("default sessiton activated\n");

D_S_C = default_s;
	      }

	    else

	      {

printf ("0x%x 0x%x 0x%x 0x%x\ncondition not currect\n", NRCD,
			 NRCID, msg.ser_ID, NRC22);

}

break;

}

case 02:

	  {

if (D_S_C == default_s)
	      {

printf ("0x%x 0x%x 0x%x P2 P2 P2* P2*\n", PRCD,
			 (PRID | msg.ser_ID), msg.sub_ID);

printf ("programming sessiton activated\n");

D_S_C = progrraming;

}

	    else

	      {

printf ("0x%x 0x%x 0x%x 0x%x\ncondition not currect", NRCD,
			 NRCID, msg.ser_ID, NRC22);

}

break;

}

case 03:

	  {

if (D_S_C == default_s)
	      {

printf ("0x%x 0x%x 0x%x P2 P2 P2* P2*\n", PRCD,
			 (PRID | msg.ser_ID), msg.sub_ID);

printf ("Extended diag sessiton activated\n");

D_S_C = extended_diag;

}

	    else

	      {

printf ("0x%x 0x%x 0x%x 0x%x\ncondition not currect", NRCD,
			 NRCID, msg.ser_ID, NRC22);

}

break;

}

default:

	  {

printf ("0x%x 0x%x 0x%x 0x%x\ncondition not currect", NRCD,
		     NRCID, msg.ser_ID, NRC12);

break;

}

}

}

  else

    {

printf ("0x%x 0x%x 0x%x 0x%x\n invalid length\n", NRCD, NRCID,
	       msg.ser_ID, NRC13);

}

}
