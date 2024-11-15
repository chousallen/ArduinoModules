//Use hcsr04 with external interrupt
#define TRIG 7
#define ECHO 2

unsigned long start_time = 0;
bool state = 0, last_state = 0;

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    attachInterrupt(digitalPinToInterrupt(ECHO), interrupt, CHANGE);
    Serial.begin(115200);
    Serial.println("Start");
}

// the loop function runs over and over again forever
void loop() {
    if(Serial.read() > 0){
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG, LOW);
        //delayMicroseconds(1000000);
    }
    if(!last_state && state)
    {
        last_state = state;
        start_time = micros();
        //Serial.println("Read");
    }
    if(last_state && !state)
    {
        last_state = state;
        //Serial.print("distance: ");
        Serial.println((micros()-start_time)/58);
    }
}

void interrupt()
{
    state = !state;
}