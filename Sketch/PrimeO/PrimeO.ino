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
