int MA = 12, //motor channel A pin
    BA = 9, //brake channel A pin
    SA = 3, //motor spin speed channel A pin
    MB = 13, //motor channel B pin
    BB = 8, //brake channel B pin
    SB = 11; //motor spin speed channel B pin

void setup() {  
  //Setup Channel A
  pinMode(MA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(BA, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(MB, OUTPUT); //Initiates Motor Channel B pin
  pinMode(BB, OUTPUT);  //Initiates Brake Channel B pin
}

void loop() {
  //test - movement simulation - forward, back, left, right, stop
  Controller('f', 255, 3000);
  Controller('b', 255, 3000);
  Controller('l', 255, 2000);
  Controller('s', 0, 900);
  Controller('r', 255, 2000);
  Controller('s', 0, 3000);
}

void Controller(char signal, int pwm_speed, int time_delay) {
  switch(signal) {
    case 'f': //move forward
      Motor(MA, BA, SA, pwm_speed, true);
      Motor(MB, BB, SB, pwm_speed, true);
      break;   
    case 'b': //move backwards
      Motor(MA, BA, SA, pwm_speed, false);
      Motor(MB, BB, SB, pwm_speed, false);
      break;     
    case 'l': //turn left
      Motor(MA, BA, SA, 0, false);
      Motor(MB, BB, SB, pwm_speed, true);
      break;   
    case 'r': //turn right
      Motor(MA, BA, SA, pwm_speed, true);
      Motor(MB, BB, SB, 0, false);
      break;  
    case 's': //full stop
      Motor(MA, BA, SA, 0, false);
      Motor(MB, BB, SB, 0, false);
      break;  
  }
  delay(time_delay);
}

void Motor(int M, int B, int S, int pwm_speed, boolean forward) {
  if(forward) {
    digitalWrite(M, HIGH);  
    digitalWrite(B, LOW);  
  } else {
    digitalWrite(M, LOW); 
    digitalWrite(B, LOW);  
  }
  analogWrite(S, pwm_speed);
}
