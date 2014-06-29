int E1 = 6,
    M1 = 7,
    E2 = 5,
    M2 = 4;

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
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
      Motor(E1, M1, pwm_speed, true);
      Motor(E2, M2, pwm_speed, true);
      break;   
    case 'b': //move backwards
      Motor(E1, M1, pwm_speed, false);
      Motor(E2, M2, pwm_speed, false);
      break;     
    case 'l': //turn left
      Motor(E1, M1, 0, false);
      Motor(E2, M2, pwm_speed, true);
      break;   
    case 'r': //turn right
      Motor(E1, M1, pwm_speed, true);
      Motor(E2, M2, 0, false);
      break;  
    case 's': //full stop
      Motor(E1, M1, 0, false);
      Motor(E2, M2, 0, false);
      break;  
  }
  delay(time_delay);
}

void Motor(int E, int M, int pwm_speed, boolean forward) {
  analogWrite(E, pwm_speed);
  if(forward) {
    digitalWrite(M, HIGH);  
  } else {
    digitalWrite(M, LOW);  
  }
}
