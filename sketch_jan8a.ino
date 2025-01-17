

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2dkOdJkuq"
#define BLYNK_TEMPLATE_NAME "Alarm System"
#define BLYNK_AUTH_TOKEN "HipDvKRUq6pO8KkjBfGWRF7wYtDX1U0Z"

#include <SPI.h>
#include <WiFiS3.h>
#include <BlynkSimpleWifi.h>

int gas_value = 0;
char ssid[] = "TEKMATION WIFI";
char password[] = "+18478744871";


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
    gas_value = analogRead(A0);
    Serial.println(gas_value);
    delay(1000);

    if(gas_value > 300){
      Blynk.logEvent("gas_leak","Warning: GAS LEAK!!");
    }
    Blynk.run();
    delay(1000);


  // put your main code here, to run repeatedly:


}



