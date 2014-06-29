int E1 = 5,
    M1 = 4,
    E2 = 6,
    M2 = 7;

void setup() {
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
}

void loop() {
  analogWrite(E1, 255);
  analogWrite(E2, 255);
  
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  delay(30);
}

void Motor(int E, int M, int pwm_speed, boolean forward) {
  analogWrite(E, pwm_speed);
  if(forward) {
    digitalWrite(M, HIGH);  
  } else {
    digitalWrite(M, LOW);  
  }
}

void Controls(char signal, int pwm_speed) {
  switch(signal) {
    case 'f': //to move forward
      Motor(E1, M1, pwm_speed, true);
      Motor(E2, M2, pwm_speed, true);
      break;   
    case 'b': //to move backwards
      Motor(E1, M1, pwm_speed, false);
      Motor(E2, M2, pwm_speed, false);
      break;     
    case 'l': //to turn left
      Motor(E1, M1, pwm_speed, false);
      Motor(E2, M2, pwm_speed, true);
      break;   
    case 'r': //to turn right
      Motor(E1, M1, pwm_speed, true);
      Motor(E2, M2, pwm_speed, false);
      break;  
    case 's': //full stop
      Motor(E1, M1, 0, false);
      Motor(E2, M2, 0, false);
      break;  
  }
}
