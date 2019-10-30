#include <Ultrasonic.h>
Ultrasonic ultrasonicEsquerdo(trigger, echo);
Ultrasonic ultrasonicDireito(trigger, echo);

#define ECHO_dir
#define TRIGGER_dir
#define ECHO_esq
#define TRIGGER_esq

float diametroArena = 77.0;

bool ultrassonico()
{
    float distancia;
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

    Serial.println(distancia);

    if (distancia > diametroArena)
    {
        return false;
    }
    else if (distancia < diametroArena)
    {
        return true;
    }
    return false;
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    ultrassonico();
}