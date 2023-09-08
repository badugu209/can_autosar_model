#ifndef PROJECTHEADER_H_
#define PROJECTHEADER_H_
//adding the libraries
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define E_OK 1
#define E_NOT_OK 0
struct canbusdata		//declaring the variables for can frame data by structure pointer.
{


uint8_t ifs:3;


uint8_t eof:7;


uint8_t ack_delli:1;


uint8_t ack:1;


uint8_t crc_delli:1;


uint16_t crc_field:15;


uint64_t data_field;


uint8_t control_field:6;


uint8_t RTR:1;


uint16_t arbitration_field:11;


uint8_t starto_f_frame:1;

};
uint8_t data[8];
//giving the function declarations.
void can_rxintrupt (struct canbusdata *s);

void can_if_rxindication (uint16_t lpdu_canid, uint64_t * lpdu_info_pointer);

void pdur_canif_rxindication (uint8_t can_handle_id,
			       uint64_t * ipdu_info_pointer);

void can_tp_rxindication (uint8_t can_handle_id,
			       uint64_t * npdu_info_pointer);

void com_rxindication (uint8_t can_handle_id, uint64_t * ipdu_info_pointer);

void com_receive_signal (uint8_t signal, uint32_t * si);

void data_received(uint8_t data);

uint8_t pdur_cantp_startof_resuption(uint16_t DLC);

uint8_t DCM_startof_reception(uint16_t DLC);

void pdur_cantp_copyRxdata(uint8_t can_handle_id,uint64_t *npdu_info_pointer);

void dcm_copyrxdata(uint8_t can_handle_id,uint64_t *npdu_info_pointer);

void os_call();
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define PRCD 06
#define PRID 64
#define NRCD 03
#define NRC11 17
#define NRC12 18
#define NRC13 19
#define NRC22 34
#define NRC24 36
#define NRC35 0x35
#define NRC36 0x36
#define NRC31 0x31
#define NRCID 127
#define E_OK 1
#define E_NOT_OK 0


struct msg_cont_type
{

uint8_t dlc;

uint8_t ser_ID;

uint8_t sub_ID;

uint8_t key1;

uint8_t key2;

};

enum active_session
{
default_s = 1, progrraming, extended_diag
};

enum levels
{
level1 = 1, klevel1, level2, klevel2, level3, klevel3
};

struct service{
uint8_t name[20];
uint8_t sercive_ID;
};

void security_level (struct msg_cont_type msg);

uint8_t data1[100];

int m;

static uint8_t D_S_C = 1;

void dcm_diag_ses_controlapi (struct msg_cont_type);
#endif	/* PROJECTHEADER_H_ */
