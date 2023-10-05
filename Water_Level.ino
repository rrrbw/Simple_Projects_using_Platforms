#define SensorPower 5
#define SensorPin A1

int Value = 0;

void setup() {

  pinMode(SensorPower, OUTPUT);
  digitalWrite(SensorPower, LOW);
  Serial.begin(9600);

}

void loop() {

  int Level = ReadSensor();
  
  Serial.print("Water Level: ");
  Serial.println(Level);
  
  delay(1000);

}

int ReadSensor() {

  digitalWrite(SensorPower, HIGH);	
  delay(10);				

  Value = analogRead(SensorPin);

  digitalWrite(SensorPower, LOW);	

  return Value;		
}