#define OPTICO_IN A3
#define OPTICO_OUT

void sensorLeitura()
{
    int valor = analogRead(OPTICO_IN);
    Serial.println();
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    sensorLeitura();
}