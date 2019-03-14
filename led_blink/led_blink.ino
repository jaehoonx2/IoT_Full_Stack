int pin[7] = {D0, D1, D2, D3, D4, D5, D6};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<7; i++)
    pinMode(pin[i], OUTPUT);
}

void on(int pin){
  digitalWrite(pin, HIGH);
}

void off(int pin){
  digitalWrite(pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=0;i<7;i++){
    on(pin[i]);
    delay(10+i*20);
  }

  for(int i=6;i>-1;i--){
    off(pin[i]);
    delay(10+i*20);
  }
      
}
