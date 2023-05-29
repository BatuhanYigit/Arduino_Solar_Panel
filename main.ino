#include <Servo.h>
//defining Servos
Servo servoyatay;
int servoy = 0;
int servo_y_LimitUst = 160;
int servo_y_LimitAlt = 20;

Servo servodikey; 
int servod = 0; 
int servo_d_LimitUst = 160;
int servo_d_LimitAlt = 20;
//Assigning LDRs
int ldr_ust_sol = 2; //top left LDR green
int ldr_ust_sag = 1; //top right LDR yellow
int ldr_alt_sol = 3; // bottom left LDR blue
int ldr_alt_sag = 0; // bottom right LDR orange

 void setup () 
 {
  servoyatay.attach(10);
 servoyatay.write(0);
  servodikey.attach(9);
  servodikey.write(0);
  delay(500);
 }

void loop()
{
  servoy = servoyatay.read();
  servod = servodikey.read();
  //capturing analog values of each LDR
  int ust_sol = analogRead(ldr_ust_sol);
  int ust_sag = analogRead(ldr_ust_sag);
  int alt_sol = analogRead(ldr_alt_sol);
  int alt_sag = analogRead(ldr_alt_sag);
  // calculating average
  int ortust = (ust_sol + ust_sag) / 2; //average of top LDRs
  int ortalt = (alt_sol + alt_sag) / 2; //average of bottom LDRs
  int ortsol = (ust_sol + alt_sol) / 2; //average of left LDRs
  int ortsag = (ust_sag + alt_sag) / 2; //average of right LDRs

  if (ortust < ortalt)
  {
    servodikey.write(servod +1);
    if (servod > servo_d_LimitUst) 
     { 
      servod = servo_d_LimitUst;
     }
    delay(10);
  }
  else if (ortalt < ortust)
  {
    servodikey.write(servov -1);
    if (servod < servo_d_LimitAlt)
  {
    servod = servo_d_LimitAlt;
  }
    delay(10);
  }
  else 
  {
    servodikey.write(servod);
  }
  
  if (ortsol > ortsag)
  {
    servoyatay.write(servoy +1);
    if (servoy > servo_y_LimitUst)
    {
    servoy = servo_y_LimitUst;
    }
    delay(10);
  }
  else if (ortsag > ortsol)
  {
    servoyatay.write(servoy -1);
    if (servoy < servo_y_LimitAlt)
     {
     servoy = servo_y_LimitAlt;
     }
    delay(10);
  }
  else 
  {
    servoyatay.write(servoy);
  }
  delay(50);
}