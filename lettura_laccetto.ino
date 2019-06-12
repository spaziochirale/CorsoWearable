
int laccetto;

void setup() {
 Serial.begin(9600);
 }
 
 void loop() {
 laccetto = analogRead(A0);
  int val;
  val=analogRead(A0);
  Serial.println(val);
  delay(100);
}
