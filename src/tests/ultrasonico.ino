#include <Ultrasonic.h>
Ultrasonic ultrasonicEsquerdo(trigger, echo);
Ultrasonic ultrasonicDireito(trigger, echo);

#define ECHO_dir
#define TRIGGER_dir
#define ECHO_esq
#define TRIGGER_esq

float diametroArena = 77.0;

void ultrassonico()
{
    float distancia;
    long microsec = ultrasonicEsquerdo.timing();
    distancia = ultrasonicEsquerdo.convert(microsec, Ultrasonic::CM);

    Serial.println("ESQUERD0 -> ");
    Serial.println(distancia);

    float distancia;
    long microsec = ultrasonicDireito.timing();
    distancia = ultrasonicDireito.convert(microsec, Ultrasonic::CM);

    Serial.println("DIREITO -> ");
    Serial.println(distancia);
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    ultrassonico();
}