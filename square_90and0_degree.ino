#include<math.h>

double px=0;
double py=0;
double pz=0;
double theta1;
double theta2;
double theta3;

double a;
double b;
double c;
double c1;
double c2;

double rtheta1;
double rtheta2;
double rtheta3;

double incang=9.0;
double radius=0.010;

double sang1=0.0;
double fang1=90.0;

double sang2=90.0;
double fang2=180.0;

double sang3=180.0;
double fang3=270.0;

double sang4=270.0;
double fang4=360.0;



double pi=3.14159;
double degtorad=(pi/180);
double radtodeg=(180/pi);
double length1=0.390;
double length2=0.240;
double length3=0.195;

double rsquare;
double r;

double dsquare;
double d;
double deltax;
double deltay;


const int zAxisMotorDirection=7;//elbow motor J3
const int zAxisMotorPulse=11;

const int yAxisMotorDirection=6;//shoulder motor J2
const int yAxisMotorPulse=10;

const int xAxisMotorDirection=5;//base motor J1
const int xAxisMotorPulse=9;


void motor1 (double);

void motor2 (double);

void motor3 (double);


void simultaneous2(double sim2a,double sim2b,double sim2c);

double i;
double j;


double outpulserax=0;
double outpulseray=0;
double outpulseraz=0;


// pulse output for 360 degree
double pulsefinalx=(25800);//;(25900)
double pulsefinaly=-(24000);
double pulsefinalz=12800;

double degrax0=0;
double degray0=0;
double degraz0=-90;

double degrax1=-(13.3232);
double degray1=0;
double degraz1=-6.9011;//-5.74;//-6.9011

double degrax2=2.3655;
double degray2=0;
double degraz2=13.776;//(11.45);//13.776

double degrax3=10.9577;
double degray3=0;
double degraz3=6.8380;//(5.618);//6.8380

double degrax4=0;
double degray4=0;
double degraz4=-13.5745;//(-11.330);//-13.5745




void setup()
{
 pinMode (zAxisMotorDirection, OUTPUT);
pinMode (zAxisMotorPulse, OUTPUT);
pinMode (xAxisMotorDirection,OUTPUT);
pinMode (xAxisMotorPulse,OUTPUT);
pinMode (yAxisMotorDirection,OUTPUT);
pinMode (yAxisMotorPulse,OUTPUT);

digitalWrite(zAxisMotorDirection,LOW);
digitalWrite(zAxisMotorPulse,LOW);
digitalWrite(xAxisMotorDirection,LOW);
digitalWrite(xAxisMotorPulse,LOW);
digitalWrite(yAxisMotorDirection,LOW);
digitalWrite(yAxisMotorPulse,LOW);
Serial.begin(9600);  
}

void loop() {
  // position 0
//outpulserax=(pulsefinalx/360)*degrax0; 
 //outpulseraz=(pulsefinalz/360)*degraz0;
 // outpulseray=(pulsefinaly/360)*degray0;
//simultaneous2(outpulserax,outpulseray,outpulseraz);


// position 1
outpulserax=(pulsefinalx/360)*degrax1; 
 outpulseraz=(pulsefinalz/360)*degraz1;
  outpulseray=(pulsefinaly/360)*degray1;
simultaneous2(outpulserax,outpulseray,outpulseraz);

// position 2
outpulserax=(pulsefinalx/360)*degrax2; 
 outpulseraz=(pulsefinalz/360)*degraz2;
  outpulseray=(pulsefinaly/360)*degray2;
simultaneous2(outpulserax,outpulseray,outpulseraz);

// position 3
outpulserax=(pulsefinalx/360)*degrax3; 
 outpulseraz=(pulsefinalz/360)*degraz3;
  outpulseray=(pulsefinaly/360)*degray3;
simultaneous2(outpulserax,outpulseray,outpulseraz);

// position 4
outpulserax=(pulsefinalx/360)*degrax4; 
 outpulseraz=(pulsefinalz/360)*degraz4;
  outpulseray=(pulsefinaly/360)*degray4;
simultaneous2(outpulserax,outpulseray,outpulseraz);

}

void simultaneous2(double sim2a,double sim2b,double sim2c)
{

  if (sim2a<0)
  {
    digitalWrite (xAxisMotorDirection,HIGH);
    delayMicroseconds(500);
  }
  else
  {

    digitalWrite (xAxisMotorDirection,LOW);
    delayMicroseconds(500);
    
  }

if (sim2b<0)
  {
    digitalWrite (yAxisMotorDirection,HIGH);
    delayMicroseconds(500);
  }
  else
  {

    digitalWrite (yAxisMotorDirection,LOW);
    delayMicroseconds(500);
    
  }


   if (sim2c<0)
  {
    digitalWrite (zAxisMotorDirection,HIGH);
    delayMicroseconds(500);
  }
  else
  {

    digitalWrite (zAxisMotorDirection,LOW);
    delayMicroseconds(500);
    
  }
  
double sim2x=0;
double sim2y=0;
double sim2z=0;

double greatestpulse;
double middlepulse;
double lowestpulse;
//float bb=2;
//float bbc=bb;

//Serial.println("expected pulses needed");
//Serial.println(sim2a,7);
//Serial.println(sim2b,7);
//Serial.println(sim2c,7);
 

    if (abs(sim2a)>=abs(sim2b) && abs(sim2a)>=abs(sim2c)) 
    {
greatestpulse=abs(sim2a);
        Serial.println("a is the largest number."); 
    }

    if (abs(sim2b)>=abs(sim2a) && abs(sim2b)>=abs(sim2c))
    {
greatestpulse=abs(sim2b);
      Serial.println("b is the largest number."); 
    }
 
    if (abs(sim2c)>=abs(sim2a) && abs(sim2c)>=abs(sim2b))
    {
greatestpulse=abs(sim2c);
        Serial.println("c is the largest number."); 
    }
double aa=abs(greatestpulse)/abs(sim2a);
double bb=abs(greatestpulse)/abs(sim2b);  
double cc=abs(greatestpulse)/abs(sim2c);  
  double aaa=aa;
  double bbb=bb;
  double ccc=cc;
  //x=a;
//y=b;
//z=c; 
//Serial.println(sim2a,7); 
//Serial.println(sim2b,7);  
//Serial.println(sim2c,7);      
//delay(500);
double i=0;
  double ii=0;
while (i<=abs(greatestpulse))
{
  //Serial.println("in loop");
  ii=ii+i;
  
  if(i>=aaa)
  {
    if(sim2a !=0)
    {
    digitalWrite (xAxisMotorPulse,HIGH);
    delayMicroseconds(1000);
    digitalWrite (xAxisMotorPulse,LOW);
    delayMicroseconds(1000);
    sim2x=sim2x+1;
    aaa=aaa+aa;
  }
  
  }
  
  if(i>=bbb)
  {
    if(sim2b !=0)
  
  {
    digitalWrite (yAxisMotorPulse,HIGH);
  
    delayMicroseconds(1000);
    digitalWrite (yAxisMotorPulse,LOW);
    delayMicroseconds(1000);
    sim2y=sim2y+1;
    bbb=bbb+bb;
  }
}
    
  if(i>=ccc)
  {
     if(sim2c !=0)
  
  {
    digitalWrite (zAxisMotorPulse,HIGH);
    delayMicroseconds(1000);
    digitalWrite (zAxisMotorPulse,LOW);
    delayMicroseconds(1000);
    sim2z=sim2z+1;
    ccc=ccc+cc;
  }
  }
  
  //Serial.println(sim2x,7);
 // delay(100);
   // Serial.println(sim2y,7);
  //delay(100);
   // Serial.println(sim2z,7);
 // delay(100);

   //Serial.println(i,7);
  //delay(10);
//Serial.println("actual pulses gone");
//Serial.println(sim2x,7);
//Serial.println(sim2y,7);
//Serial.println(sim2z,7);
  
  i=i+1;
}

}


void motor1(double g)
{
  if (g<0)
  {
    digitalWrite (zAxisMotorDirection,HIGH);
    delayMicroseconds(500);
  }
  else
  {

    digitalWrite (zAxisMotorDirection,LOW);
    delayMicroseconds(500);
    
  }

for(i=0;i<abs(g);i++)
 
  {
  
    digitalWrite (zAxisMotorPulse,HIGH);
    delayMicroseconds(500);
    digitalWrite (zAxisMotorPulse,LOW);
    delayMicroseconds(500);
    
   }
}

void motor2(double g)
{
  if (g<0)
  {
    digitalWrite (xAxisMotorDirection,HIGH);
    delayMicroseconds(500);
  }
  else
  {

    digitalWrite(xAxisMotorDirection,LOW);
    delayMicroseconds(500);

  }


 for(i=0;i<abs(g);i++)
 
  {

    digitalWrite (xAxisMotorPulse,HIGH);
    delayMicroseconds(500);
    digitalWrite (xAxisMotorPulse,LOW);
    delayMicroseconds(500);

  }
}


void motor3(double g)
{
  if (g<0)

  {
    digitalWrite (yAxisMotorDirection,HIGH);
    delayMicroseconds(500);
  }
  else
  {

    digitalWrite (yAxisMotorDirection,LOW);
    delayMicroseconds(500);

  }


for(i=0;i<abs(g);i++)
  {
    digitalWrite (yAxisMotorPulse,HIGH);
    delayMicroseconds(500);
    digitalWrite (yAxisMotorPulse,LOW);
    delayMicroseconds(500);

  }
  
}
