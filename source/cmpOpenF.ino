void cmpOpen(){
Serial.println("cmpOpen실행");
for(;*lux<255;*lux=*lux+5){ //*lux값대로 점점 열림
  analogWrite(11,*lux);
  delay(30);
  if(digitalRead(A4)){
    cmpClose();
    Serial.println(*lux);
    
    break;
  }
}

Serial.println("cmpOpen종료");
}



void cmpClose(){
  Serial.println("cmpClose실행");
  delay(1000);
  for(;*lux>0;*lux=*lux-5){ //i값에서 점점 닫힘
  analogWrite(11,*lux);
  delay(30);
  

  
}
Serial.println("cmpClose종료");
}
