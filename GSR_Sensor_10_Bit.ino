const int GSR = A16;             //Festlegung Variablen
int sensorValue = 0;
int gsr_average = 0;
int human_resistance = 0;
 
void setup(){
  Serial.begin(115200);
  pinMode(A16, INPUT);           //Deaktivierung des Pullup-Widerstands
}
 
void loop(){
  long sum = 0;
  for(int i=0; i<10; i++)              //Mittelwertbildung über 10 Werte, um Störung zu beseitigen
      {
      sensorValue = analogRead(GSR);   //Auslesen des analogen Pins
      sum += sensorValue;              //Summe der ausgelesenen Werte
      delay(5);
      }    
   gsr_average = sum/10;
   
   human_resistance = ((1024 + 2 * gsr_average) * 10000) / (512 - gsr_average);   //Berechnung Hautwiderstand

   //Ausgabe Messwerte
   //Serial.println("Rohwert (Spannung): ");   //nötig für die Kalibrierung des GSR Sensors (512)
   //Serial.println(gsr_average);
   Serial.println("Hautwiderstand in Ohm: ");
   Serial.println(human_resistance);
   //Serial.println("\n");
}
