int PinLANC = 0;                // 5V limited input signal from LANC data
int PinCMD = 1;                 // Command to send to LANC
byte typeCam = B00101000;
byte typeVTR = B00011000;

bool setRec=1;
void setup() {


}

void loop() 
{
  int ZOOM = analogRead(A0); // get 
  if( ZOOM > 505 && ZOOM < 525 ) { ZOOM = 0; } 
  else if( ZOOM >= 530 ) { ZoomWide( map(ZOOM,525,1023,0,7) ); } 
  else if( ZOOM <= 500 ) { ZoomTele( map(ZOOM,505,0,0,7) ); }
  
  if(analogRead(A2)==0  )
  {
    if(setRec){
      setRec=0;
      sendCMD(typeVTR, B00110011); // start/stop
      //sendCMD(typeVTR, B00111001); // photo
      //sendCMD(typeVTR, B00101011); // photo
    }
  }
  else  setRec=1; 
}



//##################################################################################
//################################################################################## ZOOM CONTROL
//##################################################################################
void ZoomWide(int Wide)
{
  switch(Wide)
  {
    case 0: //speed 1
    sendCMD(typeCam, B00010000);
    break;
    case 1: //speed 2
    sendCMD(typeCam, B00010010);
    break;
    case 2: //speed 3
    sendCMD(typeCam, B00010100);
    break;
    case 3: //speed 4
    sendCMD(typeCam, B00010110);
    break;
    case 4: //speed 5
    sendCMD(typeCam, B00011000);
    break;
    case 5: //speed 6
    sendCMD(typeCam, B00011010);
    break;
    case 6: //speed 7
    sendCMD(typeCam, B00011100);
    break;
    case 7: //speed 8
    sendCMD(typeCam, B00011110);
    break;
  }
}
void ZoomTele(int Tele)
{
  switch(Tele)
  {
    case 0: //speed 1
    sendCMD(typeCam, B00000000);
    break;
    case 1: //speed 2
    sendCMD(typeCam, B00000010);
    break;
    case 2: //speed 3
    sendCMD(typeCam, B00000100);
    break;
    case 3: //speed 4
    sendCMD(typeCam, B00000110);
    break;
    case 4: //speed 5
    sendCMD(typeCam, B00001000);
    break;
    case 5: //speed 6
    sendCMD(typeCam, B00001010);
    break;
    case 6: //speed 7
    sendCMD(typeCam, B00001100);
    break;
    case 7: //speed 8
    sendCMD(typeCam, B00001110);
    break;
  }
}

//##################################################################################
//################################################################################## LANC SEND FUNC
//##################################################################################
int bitDuration = 96; /// 104 - 8 // Writing to the digital port takes about 8 microseconds so only 96 microseconds are left till the end of each bit
void sendCMD(unsigned char cmd1, unsigned char cmd2) 
{
    for (int     cmdRepeatCount = 0; cmdRepeatCount < 5; cmdRepeatCount++) {  //repeat 5 times to make sure the camera accepts the command
        while (pulseIn(PinLANC, HIGH) < 5000) {
            //"pulseIn, HIGH" catches any 0V TO +5V TRANSITION and waits until the LANC line goes back to 0V
            //"pulseIn" also returns the pulse duration so we can check if the previous +5V duration was long enough (>5ms) to be the pause before a new 8 byte data packet
            //Loop till pulse duration is >5ms
        }
        //LOW after long pause means the START bit of Byte 0 is here
        delayMicroseconds(bitDuration);  //wait START bit duration
        for( int i=0; i<8; i++){
            digitalWrite(PinCMD, (cmd1 & (1<<i) ) ? HIGH : LOW);  //Write bit 0.
            delayMicroseconds(bitDuration);
        }
        //Byte 0 is written now put LANC line back to +5V
        digitalWrite(PinCMD, LOW);
        delayMicroseconds(10); //make sure to be in the stop bit before byte 1

        while (digitalRead(PinLANC)) {
            //Loop as long as the LANC line is +5V during the stop bit
        }
        //0V after the previous stop bit means the START bit of Byte 1 is here
        delayMicroseconds(bitDuration);  //wait START bit duration

        for( int i=0; i<8; i++){
            digitalWrite(PinCMD, (cmd2 & (1<<i) ) ? HIGH : LOW);  //Write bit 0.
            delayMicroseconds(bitDuration);
        }
        //Byte 1 is written now put LANC line back to +5V
        digitalWrite(PinCMD, LOW);
        /*Control bytes 0 and 1 are written, now don’t care what happens in Bytes 2 to 7
        and just wait for the next start bit after a long pause to send the first two command bytes again.*/
    }
}
//##################################################################################
//##################################################################################
//##################################################################################

