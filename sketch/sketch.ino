
void setup()
{
       
       Serial.begin(9600);
}

void loop()
{
       Serial.print("Setting value.");
       digitalWrite(13, HIGH);
       delay(500);
       Serial.print("Got value:");
       int value = digitalRead(9);
       Serial.print(value);
       delay(1000);
}
