//인터럽트핀두개사용해서 비상정지, 닫힘 중 열림구현
   unsigned int curmil, premil;
  unsigned int cmil, pmil;
  int onebtn=0;
  int twobtn=0;
  int thrbtn=0;
  int opbtn=0;
  int clbtn=0;
  int now=1;//현재승강기 위치
  int pressd=0;//층버튼눌림
  
  boolean Emrused=0;
  boolean *emr=&Emrused;
 int i=0;
 int *lux=&i;
  
int digits[3][7]=
{

{0,0,0,0,0,1,1},//1
{1,0,1,1,1,1,0},//2
{1,0,0,1,1,1,1}//3
  
  };
void setup() {
digitalWrite(12,0);
for(int pin = 3;pin<13;pin++){
    pinMode(pin,OUTPUT);
  }
Serial.begin(9600);
attachInterrupt(0,Emr,RISING);
}


void loop() {
  Serial.println("loop실행");
thrbtn=digitalRead(A0);
twobtn=digitalRead(A1);
onebtn=digitalRead(A2);
opbtn=digitalRead(A3);
clbtn=digitalRead(A4);
analogWrite(11,*lux);
for(int pin =3; pin<10; pin++){
   digitalWrite(pin,digits[now-1][pin-3]);
}



if(!Emrused){
if((onebtn||twobtn)||thrbtn){
floorFc();
openFc();
}

if(opbtn==1){
  cmpOpen(); 
  cmil=millis();
  pmil=cmil;
  while(!((cmil-pmil)>2000)){
    cmil=millis();
  if(digitalRead(A4)){
    Serial.println("수동열림완전열림후수동닫힘실행");
    cmpClose();
    Serial.println(*lux);
    
    break;
  }
  }
  closeFc();
  
  
}
}

}
  




 

 
