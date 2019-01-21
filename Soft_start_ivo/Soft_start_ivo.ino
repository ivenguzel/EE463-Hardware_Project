int POT = A0;
int PWM =3;
float Duty=13;

float Switch =0;
      
  
void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
  pinMode(POT,INPUT);
  setPwmFrequency(3, 8); //Sets PWM freq to 3.9kHz
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
                Switch = analogRead(POT); 
                Serial.print("Switch is:");
                Serial.println(Switch) ; 
                
                  if ((Duty<20)&&(Switch>400)){

                    while(Duty<180){
                      Duty = Duty +1;
                      analogWrite(PWM,Duty);
                      delay(175);
                      Serial.print("The duty cycle is:");
                      Serial.println(Duty) ; 
                    }
                    }   
                   
               if ((Duty>150)&&(Switch<400)){

                    while(Duty>2){
                      Duty = Duty - 1;
                      analogWrite(PWM,Duty);
                      delay(175);
                      Serial.print("The duty cycle is:");
                      Serial.println(Duty) ; 
                    }
                    }   
             
                    
              
        }
