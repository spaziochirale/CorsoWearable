#define LEFT_LED 12
#define RIGHT_LED 6
#define LEFT_SENS A10
#define RIGHT_SENS A9
#define SOGLIA 3

int left, minLeft, maxLeft;
int right, minRight, maxRight;


void setup() {
  minLeft=20;
  maxLeft=720;
  minRight=150;
  maxRight=920;

  pinMode(LEFT_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  left = analogRead(LEFT_SENS);
  right = analogRead(RIGHT_SENS);
  if (left > maxLeft) left=maxLeft;
  if (left < minLeft) left=minLeft;
  if (right > maxRight) right=maxRight;
  if (right < minRight) right=minRight;
Serial.print("Left: ");
Serial.print(left);
Serial.print(" Right: ");
Serial.println(right);
  
  left = map(left,minLeft,maxLeft,1,10);
  right = map(right,minRight,maxRight,1,10);

Serial.print("NormLeft: ");
Serial.print(left);
Serial.print(" NormRight: ");
Serial.println(right);

  if (left > (right + SOGLIA)) digitalWrite(LEFT_LED, HIGH);
  else digitalWrite(LEFT_LED,LOW);
  if (right >(left + SOGLIA)) digitalWrite(RIGHT_LED, HIGH);
  else digitalWrite(RIGHT_LED, LOW);
  delay(500);
  
}
