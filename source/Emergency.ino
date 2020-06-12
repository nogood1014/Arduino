void Emr(){
  Serial.println("Emr실행");
  tone(12,1020,20);

  delayMicroseconds(20000);

  tone(12,440,20);

    delayMicroseconds(20000);

  

  for(now;now>=1;now--){

    delayMicroseconds(10000);

  for(int pin =3; pin<10; pin++){
   digitalWrite(pin,digits[now-1][pin-3]);

   } 
  
   


}

now=1;
*lux=255;
*emr=true;
Serial.println("Emr종료");
}
