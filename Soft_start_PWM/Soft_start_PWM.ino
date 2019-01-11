int POT = A0;
int PWM =3;
float Duty=0;
float D=0;
      
  
void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
  pinMode(POT,INPUT);
  setPwmFrequency(3, 8); //Sets the pwm output to 3900Hz
}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void loop() {                
                D=analogRead(POT); 
                 
                  if (D<10){
                    D=0;
                    Serial.print("********");
                    }       
                    Duty=D/1024*255; 
                analogWrite(PWM,Duty);
                delay(2000);
                Serial.print("The duty cycle is:");
                Serial.println(D) ;  
              
        }
