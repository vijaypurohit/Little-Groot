/*                            Project
 *                  --------------------------          
 *                        Little Groot                      (Name inspired from Guardian of Galaxy Movie Character)  
 *                   --------------------------
 * The plant monitor has a moisture sensor that measures how wet your
 * plant’s soil is. If the plant needs watering, an LED lights up and blink until the
 * plant’s been watered, and the string “Feed me!” is repeatedly sent to your computer.
 * When the plant has been watered, the LED switches off and the string “Thank you, Vijay!” is sent once to your computer.
 * This version of program is for normal plant.
 * There are Three conditions acccording to plant water requirement.
 * There is also sonar module inculded
 * Created on dec 03,2017 at Rajasthan Hackathon Udaipur
 * vijay.pu9@gmail.com
*/

int ledPin = 13;
int buz = 12;
int sensorPin = 0;
int senval = 0;
int flag ;   // old sensor value
char data = 0;            //Variable for storing received data
// sonar values
int trigPin=9;
int echoPin=10;
int sonarled =8;
long duration, distance, oldDist;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(sonarled, OUTPUT);
}

void sonar_read()
{
  //sonar distance led
    digitalWrite(trigPin,HIGH);
      delayMicroseconds(500);
    digitalWrite(trigPin,LOW);
      duration=pulseIn(echoPin,HIGH);
      distance=(duration/2)/29.1;

    Serial.print("the thing is at ");
    Serial.print(distance);
    Serial.print("CM");
     Serial.println("");
      
    if(distance<=20)
    {  
      digitalWrite(sonarled,HIGH); 
      digitalWrite(buz,HIGH);
    }
    else if(distance>=20)
    {  
      digitalWrite(sonarled,LOW); 
      digitalWrite(buz,LOW); 
    }
    return;
}

void loop() 
{
 senval = analogRead(sensorPin);;

//    if(Serial.available() > 0)      // Send data only when you receive data:
//   {
//      data = Serial.read();        //Read the incoming data & store into data
//      Serial.print(data);          //Print Value inside data in Serial monitor
//      Serial.print("\n");        
//      if(data == '1')              // Checks whether value of data is equal to 1
//         digitalWrite(7, HIGH);   //If value is 1 then LED turns ON
//      else if(data == '0')         //  Checks whether value of data is equal to 0
//         digitalWrite(7, LOW);    //If value is 0 then LED turns OFF
//   }

    sonar_read();
    Serial.println(senval);
     if(senval<400)                             // In case of no water 
     {
       digitalWrite(ledPin, HIGH);
       Serial.println("I am dying, Please Help Me, Urgently Need Water\n"); 
       digitalWrite(buz,HIGH);
        delay(500);
       digitalWrite(buz,LOW);
     }
                                              
     if(senval<600 && senval>400)                 // In case of Little Water
     {
           
        digitalWrite(ledPin, HIGH); 
       delay(500);
       digitalWrite(ledPin, LOW); 
       delay(500);
       Serial.println("Feed Me, Feed Me, Need Water. I need more water\n");
     }
                                                  
     if(senval>600)                             // In case of More Water
     {
       digitalWrite(buz,LOW);
       digitalWrite(ledPin, LOW);  
       Serial.println("Thank You!,\nThank You very much, Team Ravana\n");
       delay(1000);
     }
 
}
