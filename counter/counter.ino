

int RESET = 3;
int PLUS = 2;

int counter = 0;
void reset();
void plus();

void setup()
{
    Serial.begin(9600);
    Serial.println("Counter Start!");
    pinMode(RESET, INPUT_PULLUP);
    pinMode(PLUS, INPUT_PULLUP);

    attachInterrupt(0, reset, FALLING);
    attachInterrupt(1, plus, FALLING);
}
void loop()
{
    Serial.println(counter);
    delay(1000);
}

void reset()
{
    Serial.println("Reset!");
    counter = 0;
}

void plus()
{
    Serial.println("PLUS!");
    counter++;
}