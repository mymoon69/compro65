#define Trig 2
#define Echo 3
const int LED = 4; //หลอดไฟ LED
long duration; //ตัวแปรตรวจจับ
int distance; //ระยะทาง cm
void setup() {
  pinMode(LED, OUTPUT); //LED เป็น OUTPUT
  pinMode(Trig, OUTPUT); //Trig เป็น OUTPUT
  pinMode(Echo, INPUT); //Echo เป็น INPUT
  pinMode(7 ,OUTPUT); //pin 7 เป็น OUTPUT
}
void loop(){
  digitalWrite(Trig, LOW); //ส่งคลื่นเสียง 0
  delayMicroseconds(5); //หน่วงเวลา
  digitalWrite(Trig, HIGH); //ส่งคลื่นเสียง 1
  delayMicroseconds(10); //หน่วงเวลา
  digitalWrite(Trig, LOW); //ส่งคลื่นเสียง 0
  duration = pulseIn(Echo, HIGH); //ระยะเวลาเดินทางของเสียง
  distance = duration * 0.034 / 2; //ระยะที่ได้
  if (distance <= 20){ //ถ้าระยะน้อยกว่า 20 cm
    digitalWrite(LED, HIGH); //LED สว่าง
    delay(500); //หน่วงเวลา
    digitalWrite(LED, LOW); //LED ดับ
    delay(500); //หน่วงเวลา
    tone(7, 400, 100); //คลื่นเสียง --> buzzer
    delay(500); //หน่วงเวลา
      }
  else {
      digitalWrite(LED, LOW); //LED ดับ
      }
}