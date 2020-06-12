void seg(int noww){
    int digits[3][7]=
{
 
{0,0,0,0,0,1,1},//1
{1,0,1,1,1,1,0},//2
{1,0,0,1,1,1,1}//3
  
  };
for(int j=3; j<10; j++){
 
   digitalWrite(j,digits[noww-1][j-3]);
}

}
