//poisitvo para esquerda
//dir 1 vai pra esquerda

float y = 0;
float u = 0;
float e = 0;
float r = 1.2;
float Kp = 10.0;

#define enabl  9
#define dir1  10
#define dir2  11

void setup() {
  for(int count = 9; count <= 11; count++) {
    pinMode(count, OUTPUT);
     
  }
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  Serial.begin(115200);
}




void loop() {
  y=analogRead(0)*5.0/1023.0;
  r=2.0+1.0*(((millis()/3000)%2)==1);
  e=r-y;
  u=Kp*e;
  
  
  u=min(max(u,-5.0),5.0);
  digitalWrite(dir1,u>=0);
  digitalWrite(dir2,u<=0);
  analogWrite(enabl,abs(u)*175/5.0+80);
  
  Serial.print(r*100.0);
  Serial.print(',');
  Serial.println(y*100.0);
  /*Serial.print(',');
  Serial.print(u>=0);
  Serial.print(',');
  Serial.print(u<=0);
  Serial.println(u*100);
*/
    delay(25);

  


  


  
}