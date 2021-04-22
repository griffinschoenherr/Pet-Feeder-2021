//Griffin Schoenherr
//Pet Feeder Project



//Set up libraries
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <SimpleTimer.h>
WidgetRTC rtc;
Servo servo;
SimpleTimer timer;

int start = 14;
int manTrigger = 0;
int timerTrigger = 0;
int timerEnable = 0;
int isFirstConnect = true;

//Get app connected to WiFi
char auth[] = "c0ZP4VcGUhpbrs60fw2gGMaeciOS1QgG"; //Authentication Token from the Blynk App by creating the new Project
char ssid[] = "scoobydoo12";   //Wifi Name
char pass[] = "Drakedog1970";   //Wifi Password
int i,j,n,h,m;

void clockDisplay()
{
if (isFirstConnect == true)
 {
//Store start time, relay with app
 String displayhour = String(hour(), DEC);
  int hourdigits = displayhour.length();
  if(hourdigits == 1)
  {
    displayhour = "0" + displayhour;
  }
 String displayminute = String(minute(), DEC);
  int minutedigits = displayminute.length();  
  if(minutedigits == 1)
  {
    displayminute = "0" + displayminute;
  }

//Date

 String displayday = String(day(), DEC);
  int daydigits = displayday.length();
  if(daydigits == 1)
  {
    displayday = "0" + displayday;
  }
 String displaymonth = String(month(), DEC);
  int monthdigits = displaymonth.length();  
  if(monthdigits == 1)
  {
    displaymonth = "0" + displaymonth;
  }


 
  String startTime = displayhour + ":" + displayminute;
  String startDate = displaymonth + "/" + displayday + "/" + year();

  // Send time to the App
  Blynk.virtualWrite(V17, startTime);
  // Send date to the App
  Blynk.virtualWrite(V18, startDate);
  
  

  //End store start time and date
 isFirstConnect = false;

 }
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  rtc.begin();
  servo.attach(2); 
   Blynk.virtualWrite(V5, manTrigger);// sets man trigger count to 0 on start
  Blynk.virtualWrite(V9, timerTrigger);// sets timerTrigger count to 0 on start
  timer.setInterval(100L, clockDisplay);


  
}





BLYNK_WRITE(V2)
{
  servo.write(180);
  delay(2000);
  servo.write(0);
}
BLYNK_WRITE(V1) //manual feed button function
{
  j=param.asInt();
  if(j==1)
  {
    Serial.print(n);
    servo.write(0);
    delay(1000);
  }
  for(int i=1;i<=n;i++)
  {
    Serial.print(i); //rotate servo
    servo.write(180);
    delay(1000);
    servo.write(0);
    delay(1000);
    manTrigger = manTrigger + 1 ; //updates counts on app
  Blynk.virtualWrite(V5, manTrigger);
  lastFedclock();
  }
 
  }

  BLYNK_WRITE(V0) //serving size portion



  
{
  n=param.asInt();
}
   BLYNK_WRITE(V8)// timer button
{
  if(param.asInt() == 1) {
    timerEnable = 1;
  }
    else
    {
    timerEnable = 0;
    
    
  }
} 
BLYNK_WRITE(V6) //1st Timer Feed
{
 
  if (param.asInt()== 1 && timerEnable == 1 )// checks for timer button
  {
  doTimerFeed();
  }
  
}
BLYNK_WRITE(V7) //2nd Timer Feed
{
 
  if (param.asInt()== 1 && timerEnable == 1 ) // checks for timer button
  {
  doTimerFeed();
  }
  
}

 void doFeed() // rotate feeder 
 {
Serial.print(i);
    servo.write(180);
    delay(1000);
    servo.write(0);
    delay(1000);
   lastFedclock();
 
 }

void doTimerFeed() // Timer feed rotate feeder 
 {
 Serial.print(i);
    servo.write(180);
    delay(1000);
    servo.write(0);
    delay(1000);

  timerTrigger = timerTrigger + 1 ; //Update counter
  Blynk.virtualWrite(V9, timerTrigger);
  lastFedclock();
   
 }
// Digital clock display of the time and date last fed
void lastFedclock()
{

//Store time fed and date
 String fedhour = String(hour(), DEC);
  int hourdigits = fedhour.length();
  if(hourdigits == 1)
  {
    fedhour = "0" + fedhour;
  }
 String fedminute = String(minute(), DEC);
  int minutedigits = fedminute.length();  
  if(minutedigits == 1)
  {
    fedminute = "0" + fedminute;
  }

//Date of feeding

 String fedday = String(day(), DEC);
  int daydigits = fedday.length();
  if(daydigits == 1)
  {
    fedday = "0" + fedday;
  }
 String fedmonth = String(month(), DEC);
  int monthdigits = fedmonth.length();  
  if(monthdigits == 1)
  {
    fedmonth = "0" + fedmonth;
  }


 
  String fedTime = fedhour + ":" + fedminute;
  String fedDate = fedmonth + "/" + fedday + "/" + year();

  // Send time to the App
  Blynk.virtualWrite(V11, fedTime);
  // Send date to the App
  Blynk.virtualWrite(V12, fedDate);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
