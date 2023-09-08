#include "projectheader.h"
void odometer (uint32_t * re);

void temp (uint32_t * re);

void indicators (uint32_t * re);

void wiper (uint32_t * re);

void door_locks (uint32_t * re);

void gear_status (uint32_t * re);

void speed (uint32_t * re);

struct signals
{				//structure for taking the signal values.
  uint8_t temp;

uint16_t speed:12;

uint32_t odometer;

uint8_t indicators:2;

uint8_t wiper:1;

uint8_t door_locks:4;

uint8_t gear_status:3;
};

struct signals s;


void
com_rxindication (uint8_t can_handle_id, uint64_t * ipdu_info_pointer)
{


printf ("handle id conformed\n");

s.temp = (*ipdu_info_pointer & 0x3f);	//separating the signal values by masking.

s.speed = ((*ipdu_info_pointer >> 8) & (0x3ff));

s.odometer = ((*ipdu_info_pointer >> 20) & 0xfffff);

s.indicators = ((*ipdu_info_pointer >> 52) & 0x3);

s.wiper = ((*ipdu_info_pointer >> 54) & 0x1);

s.door_locks = ((*ipdu_info_pointer >> 55) & 0xf);

s.gear_status = ((*ipdu_info_pointer >> 59) & 0x7);

if(*ipdu_info_pointer!=0){
    uint8_t d=1;
data_received(d);
}
}
void

com_receive_signal (uint8_t signal, uint32_t * si)
{				//giving the signal depending on the id.
//applying switch case to send signals to the application.
  uint32_t returnvalue = 0;

    //declaration of array of function pointer.
  void (*fun[8]) (uint32_t *) =
  {
  temp, speed, odometer, indicators, wiper, door_locks, gear_status};


    /* switch(signal){
       case 1:
       {
       printf("printing temp in range of 20 to 50\n");
       if(s.temp>20&&s.temp<50){
       *si=s.temp;}
       break;
       }
       case 2:
       {
       // foe example i am taking some old value for speed
       int old=23;
       printf("masked new not equal to masked old\n");
       if(((0x3ff)&s.speed)!= (0x3ff&old)){
       *si=s.speed;}
       break;
       }
       case 3:
       {
       printf("giving speed value always\n");
       if(s.odometer){
       *si=s.odometer;}
       break;
       }
       case 4:
       {
       //For example i am taking some x value
       int x=1;
       printf("masked new equals to x\n");
       if(0x01&s.indicators==x){
       *si=s.indicators;}
       break;
       }
       case 5:
       {
       //For example i am taking some x value
       int x=0;
       printf("masked new not  equals to x\n");
       if(0x01&s.wiper!=x){
       *si=s.wiper;}
       break;
       }
       case 6:
       {
       printf("printing temp in range of 20 to 50\n");
       if(s.temp<20&&s.temp>50){
       *si=s.door_locks;}
       break;
       }
       case 7:
       {
       printf("giving speed value always\n");
       if(s.gear_status){
       *si=s.gear_status;}
       break;
       }

       default:
       {
       break;
       }
       }
       return 0; */

fun[signal] (&returnvalue);

*si = returnvalue;

}

void

odometer (uint32_t * re)
{

printf ("giving speed value always\n");

if (s.odometer)
    {

*re = s.odometer;
    }

}



void
temp (uint32_t * re)
{

printf ("printing temp in range of 20 to 50\n");

if (s.temp > 20 && s.temp < 50)
    {

*re = s.temp;
    }


}

void
indicators (uint32_t * re)
{

    //For example i am taking some x value
  int x = 1;

printf ("masked new equals to x\n");

if ((0x01 & s.indicators) == x)
    {

*re = s.indicators;
    }

}


void
wiper (uint32_t * re)
{

    //For example i am taking some x value
  int x = 0;

printf ("masked new not  equals to x\n");

if ((0x01 & s.wiper) != x)
    {

*re = s.wiper;
    }

}


void
door_locks (uint32_t * re)
{

printf ("printing temp in range of 20 to 50\n");

if (s.temp < 20 && s.temp > 50)
    {

*re = s.door_locks;
    }

}


void
gear_status (uint32_t * re)
{

printf ("giving gear_status value always\n");

if (s.gear_status)
    {

*re = s.gear_status;
    }

}


void
speed (uint32_t * re)
{
  int old = 23;

printf ("masked new not equal to masked old\n");

if (((0x3ff) & s.speed) != (0x3ff & old))
    {

*re = s.speed;
    }


}



