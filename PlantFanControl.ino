int relayPin = 9;      // Relay connected to digital pin 9
//bool sign = false;    // Decrease or increase rate
int rate = 1;         // Rate Divisor for speed control
int val = 0;         // variable to store the read value



void setup()

{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);   // sets the pin as output

}



void loop()

{
  if (val==0){
  val = 255/rate;   // aanalogWrite values from 0 to 255. Divide by rate for variable fan speed.
  }
  else{
  val = 0;
    if (rate==4){
      rate=1; 
    }
    else{
      rate+=1; 
    }
  }
  Serial.println(val);
  analogWrite(relayPin, val);  
  delay(1800000);
}
