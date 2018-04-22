#include <Arduino.h>
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxx";

char ssid[] = "xxxxx";
char pass[] = "xxxxx";

BLYNK_WRITE(V3){
    int pinData = param.asInt(); //pinData variable will store value that came via Bridge
    if (param.asInt()){
       digitalWrite(D6, HIGH);
       Blynk.notify("Someone at the door !");
     }else{
       digitalWrite(D6, LOW);
     }
}




void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
