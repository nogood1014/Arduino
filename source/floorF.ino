void floorFc(){
  Serial.println("floor실행");
   if(onebtn==1){
    pressd=1;
   }
   if(twobtn==1){
    pressd=2;
   }
   if(thrbtn==1){
    pressd=3;
   }
   
   if(now==pressd){//깜빡깜빡
    for(int now=0; now<3; now++){
        for(int pin =3; pin<10; pin++){
   digitalWrite(pin,0);
   
   }
   delay(100);
       for(int pin =3; pin<10; pin++){
   digitalWrite(pin,digits[pressd-1][pin-3]);
   }
   delay(100);
    
   }
   
   }else if(now>pressd){
   for(now;now>=pressd;now--){
   for(int pin =3; pin<10; pin++){
   digitalWrite(pin,digits[now-1][pin-3]);
   } 
   delay(1000);
   if(now==pressd)
   break;
   }//내려감
   tone(12,880,300);
  delay(300);
tone(12,880,300);
delay(300);
 
tone(12,784,300);
delay(300);
tone(12,740,300);
delay(300);
 


  }else if(now<pressd){
   
     
   for(now;now<=pressd;now++){
   for(int pin =3; pin<10; pin++){
   digitalWrite( pin,digits[now-1][ pin-3]);
   //세그먼트 층표시
   }
   delay(1000);
   if(now==pressd)
   break;
   }//올라감
   tone(12,880,300);
delay(300);
tone(12,880,300);
delay(300);
 
tone(12,784,300);
delay(300);
tone(12,740,300);
delay(300);
 

   }
   
   
 
   

}
