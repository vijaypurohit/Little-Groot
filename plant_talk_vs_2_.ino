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
 * 
 * Created on 17 April 2016 Under the guidance of Mr. ShivRam Meena
 * copyright 2016 Vijay Purohit <http://www.prepkida.com>
 * vijay.pu9@gmail.com
*/

int ledPin = 13;
int buz = 12;
int sensorPin = 0;
int senval = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() 
{
 senval = analogRead(sensorPin);

                                           // In case of no water 
 if(senval<400)
 {
   digitalWrite(ledPin, HIGH);
   digitalWrite(buz,HIGH);
   Serial.print("I am dying, Please Help Me, Urgently Need Water\n"); 
    delay(1000);
   digitalWrite(buz,LOW);
 }
           
                                          // In case of Little Water
 if(senval<800 && senval>500)
 {
   digitalWrite(buz, LOW);
   digitalWrite(ledPin, HIGH); 
   delay(500);
   digitalWrite(ledPin, LOW); 
   delay(500);
   Serial.print("Feed Me, Feed Me, Need Water. I need more rooms\n");
 }

                                         // In case of More Water
 if(senval>800) 
 {
   digitalWrite(buz,LOW);
   digitalWrite(ledPin, LOW);  
   Serial.print("Thank You!,\nThank You very much, Vijay\n");
   delay(1000);
 }
 
}
