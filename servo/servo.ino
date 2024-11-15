//Control servo motor in 20ms pulse cycle
//not dependent to pwm pin

#define SERVO_PIN 8

const uint16_t period = 20000; //20ms
const uint16_t middle = 1500; //1.5ms
const uint16_t left = 2000; //2ms
const uint16_t right = 1000; //1ms

uint16_t duty = middle;

void servo_attach() 
{
    pinMode(SERVO_PIN, OUTPUT);
}

void servo_routine()
{
    digitalWrite(SERVO_PIN, micros() % period < duty);
}

bool servo_write_duty(uint8_t pin, uint16_t value)
{
    if(value > right || value < left)
    {
        return false;
    }
    duty = value;
    return true;
}

bool servo_write_angle(uint8_t pin, uint16_t angle)
{
    if(angle > 180 || angle < 0)
    {
        return false;
    }
    duty = map(angle, 0, 180, right, left);
    return true;
}

void setup() 
{
    servo_attach();
    servo_write_duty(SERVO_PIN, middle);
}

void loop() 
{
    servo_routine();
}