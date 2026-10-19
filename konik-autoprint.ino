const int SERVO_PIN = 18;
const int BUTTON_PIN = 15;
volatile byte state = LOW;
volatile byte laststate = state;

long usToDuty(int us) {
  return (long)us * 65535 / 20000;
}

void setup() {
  Serial.begin(115200);
  // Nowe API w ESP32 core 3.x — bez ledcSetup/ledcAttachPin
  ledcAttach(SERVO_PIN, 50, 16);
  ledcWrite(SERVO_PIN, usToDuty(1500)); // środek
  delay(2000);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), blink, HIGH);
}

void loop() {
  if(laststate != state){
  if(state){
  ledcWrite(SERVO_PIN, usToDuty(500));
  Serial.println("0°");
  }
  else{
    ledcWrite(SERVO_PIN, usToDuty(1500));
  Serial.println("90°");
  }
  laststate = state;
  delay(400);
  }
  
}

void blink() {
  
  state = !state;

}