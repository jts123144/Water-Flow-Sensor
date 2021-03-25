volatile int NbTopsFan; //measuring the rising edges of the signal
int Calc;  
float c=0.0;                            
int hallsensor = 2;    //The pin location of the sensor

void rpm ()     //This is the function that the interupt calls
{
 NbTopsFan++;  //This function measures the rising and falling edge of the

// hall effect sensors signal
}
// The setup() method runs once, when the sketch starts
void setup() //
{
 pinMode(hallsensor, INPUT); //initializes digital pin 2 as an input
 Serial.begin(9600); //This is the setup function where the serial port is
//initialised,

 attachInterrupt(0, rpm, RISING); //and the interrupt is attached
 Serial.println("Date&Time , FLow RaTE , VolUME");
}
// the loop() method runs over and over again,
// as long as the Arduino has power
void loop ()    
{
 NbTopsFan = 0;      //Set NbTops to 0 ready for calculations
 sei();            //Enables interrupts
 delay (1000);      //Wait 1 second
 cli();            //Disable interrupts
 Calc = (NbTopsFan * 60 / 7.5); //(Pulse frequency x 60) / 7.5Q, = flow rate
 float p;
 p=Calc*0.000000277;
 float t;
 t=Calc*0.277;
//in L/hour


if(Calc!=0){
 
c=c+t;

 Serial.print(",");
 Serial.print(Calc, DEC); //Prints the number calculated above
 Serial.print(" L/Hour\r ");//Prints "L/hour" and returns a  new line
 Serial.print(",");
 Serial.print(c,DEC);
 Serial.print(" ml/sec\r\n ");//Prints "L/hour" and returns a  new line
}
;
}

