#include "projectheader.h"
uint8_t a = 4;

void
security_level (struct msg_cont_type msg)
{

static uint8_t *seed;

static uint8_t seed_flag;


if (D_S_C == extended_diag)
    {

if (msg.dlc == 2 && ((msg.sub_ID % 2) != 0))
	{

switch (msg.sub_ID)
	    {

case level1:

	      {

seed = &a;

seed[1] = 0x03;


printf ("seed values\n 0x%x 0x%x 0x%x 0x%x 0x%x\n",
			 (PRCD - 2), (PRID | msg.ser_ID), msg.sub_ID, seed[0],
			 seed[1]);

seed_flag = E_OK;

break;

}

case level2:
	      {

uint8_t a;

seed = &a;

printf ("seed values\n 0x%x 0x%x 0x%x 0x%x 0x%x\n",
			 (PRCD - 2), (PRID | msg.ser_ID), msg.sub_ID, seed[0],
			 seed[1]);

seed_flag = E_OK;

break;

}

case level3:

	      {

uint8_t a;

seed = &a;

printf ("seed values\n 0x%x 0x%x 0x%x 0x%x 0x%x\n",
			 (PRCD - 2), (PRID | msg.ser_ID), msg.sub_ID, seed[0],
			 seed[1]);

seed_flag = E_OK;

break;

}

default:

printf ("0x%x 0x%x 0x%x 0x%x\nsubfunction not supported\n",
		       NRCD, NRCID, msg.ser_ID, NRC12);

break;

}


}

      else if ((msg.dlc == 2 || msg.dlc == 4) && ((msg.sub_ID % 2) == 0))
	{

static uint8_t Number_of_attempts;

switch (msg.sub_ID)
	    {

case klevel1:

	      {


if (seed_flag == E_OK)
		  {

if (msg.dlc == 4)
		      {

if (seed[0] == msg.key1 && seed[1] == msg.key2)
			  {

printf ("0x%x 0x%x \nsecurity accessed\n", PRCD,
				     (PRID | msg.ser_ID));

seed_flag = E_NOT_OK;

}

			else
			  {

if (Number_of_attempts < 2)
			      {

printf
				  ("0x%x 0x%x 0x%x 0x%x\n invalid key\n",
				   NRCD, NRCID, msg.ser_ID, NRC35);

Number_of_attempts++;
				seed_flag = E_NOT_OK;

}

			    else
			      {

printf
				  ("0x%x 0x%x 0x%x 0x%x\n exceeded number of attempts\n",
				   NRCD, NRCID, msg.ser_ID, NRC36);

}

}

}

		    else
		      {

printf ("0x%x 0x%x 0x%x 0x%x\n invalid length \n",
				 NRCD, NRCID, msg.ser_ID, NRC13);


}

}

		else
		  {

printf ("0x%x 0x%x 0x%x 0x%x\n sequence errror\n", NRCD,
			     NRCID, msg.ser_ID, NRC24);

}

break;

}

case klevel2:
	      {

if (seed_flag == E_OK)
		  {

if (msg.dlc == 4)
		      {

if (seed[0] == msg.key1 && seed[1] == msg.key2)
			  {

printf ("0x%x 0x%x \nsecurity accessed\n", PRCD,
				     (PRID | msg.ser_ID));

seed_flag = E_NOT_OK;

}

			else
			  {

printf ("0x%x 0x%x 0x%x 0x%x\n invalid key\n",
				     NRCD, NRCID, msg.ser_ID, NRC35);

Number_of_attempts++;
			    seed_flag = E_NOT_OK;

if (Number_of_attempts == 2)
			      {

printf
				  ("0x%x 0x%x 0x%x 0x%x\n exceeded number of attempts\n",
				   NRCD, NRCID, msg.ser_ID, NRC36);

}

}

}

		    else
		      {

printf ("0x%x 0x%x 0x%x 0x%x\n invalid length \n",
				 NRCD, NRCID, msg.ser_ID, NRC13);

}

}

		else
		  {

printf ("0x%x 0x%x 0x%x 0x%x\n sequence error\n", NRCD,
			     NRCID, msg.ser_ID, NRC24);

}

break;

}

case klevel3:
	      {

if (seed_flag == E_OK)
		  {

if (msg.dlc == 4)
		      {

if (seed[0] == msg.key1 && seed[1] == msg.key2)
			  {

printf ("0x%x 0x%x \n security accessed\n", PRCD,
				     (PRID | msg.ser_ID));

seed_flag = E_NOT_OK;

}

			else
			  {

printf ("0x%x 0x%x 0x%x 0x%x\n invalid key\n",
				     NRCD, NRCID, msg.ser_ID, NRC35);

Number_of_attempts++;

seed_flag = E_NOT_OK;

if (Number_of_attempts == 2)
			      {

printf
				  ("0x%x 0x%x 0x%x 0x%x\n number of attempts exceeded\n ",
				   NRCD, NRCID, msg.ser_ID, NRC36);

}

}

}

		    else
		      {

printf ("0x%x 0x%x 0x%x 0x%x\n invalid length \n",
				 NRCD, NRCID, msg.ser_ID, NRC13);

}

}

		else
		  {

printf ("0x%x 0x%x 0x%x 0x%x\n sequence error \n", NRCD,
			     NRCID, msg.ser_ID, NRC24);


}

break;

}


default:

printf ("0x%x 0x%x 0x%x 0x%x\n sub function not supported\n ",
		       NRCD, NRCID, msg.ser_ID, NRC12);

break;

}

}

      else
	{

printf ("0x%x 0x%x 0x%x 0x%x\n invalid length \n", NRCD, NRCID,
		   msg.ser_ID, NRC13);

}

}
  else
    {

printf ("0x%x 0x%x 0x%x 0x%x\n condition not correct\n", NRCD, NRCID,
	       msg.ser_ID, NRC22);

}

}
