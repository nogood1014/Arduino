void openFc(){
Serial.println("open실행");
pressd=0;

for(;*lux<255;*lux=*lux+5){ //점점 열림
  Serial.println(*lux);//열림(빛)출력
  analogWrite(11,i);
  delay(50);

}
delay(2000);

if(!Emrused)
closeFc();
Serial.println("open종료");

}

 
void closeFc(){
  
  Serial.println("close실행");
 unsigned long curmil=millis();
 unsigned long premil=curmil;
 
   for(;*lux>0;*lux=*lux-5){//점점 닫힘
  analogWrite(11,*lux);
  delay(30);
  curmil=millis();
  
  if((curmil-premil)<=5000){//닫히지않고 열려있는시간이 5초이상
  if(digitalRead(A3)){ //열림버튼을 누를 경우
   cmpOpen();
   if((curmil-premil)>=2500){
    Serial.println("강제닫힘실행");
    tone(12,440,500);
    delay(500);
   }
   
  } 

}

}
Serial.println("close종료");

}
