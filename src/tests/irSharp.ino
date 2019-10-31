
#define SHARP A1

void setup()
{
    Serial.begin(9600);
}
void loop()
{

    double valorVolts = analogRead(SHARP) * 0.0048828125;
    double distancia = 4800 / (valorVolts * 200 - 20);

    Serial.println(distancia);
}
