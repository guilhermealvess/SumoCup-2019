#include <Ultrasonic.h>

#define ECHO_dir 10
#define TRIGGER_dir 11
#define ECHO_esq 12
#define TRIGGER_esq 13
Ultrasonic ultrasonicEsquerdo(TRIGGER_esq, ECHO_esq);
Ultrasonic ultrasonicDireito(TRIGGER_dir, ECHO_dir);

#define LED A3

#define MOTOR_D1 3
#define MOTOR_D2 4
#define MOTOR_E1 5
#define MOTOR_E2 6
#define PWMD 7
#define PWM 8
#define STDBY 9

#define OPTICO_A A0
#define OPTICO_B A1

#define SHARP A2

#define T 0.5

float diametro_arena = 77.0;
int limiar_piso_black = 500;

void rodaDireita(int velocidade, bool sentido)
{
    // true para frente e false para traz
    if (sentido)
    {
        digitalWrite(MOTOR_D1, 1);
        digitalWrite(MOTOR_D2, 0);
    }
    else
    {
        digitalWrite(MOTOR_D1, 0);
        digitalWrite(MOTOR_D2, 1);
    }
}

void rodaEsquerda(int velocidade, bool sentido)
{
    // true para frente e false para traz
    if (sentido)
    {
        digitalWrite(MOTOR_E1, 1);
        digitalWrite(MOTOR_E2, 0);
    }
    else
    {
        digitalWrite(MOTOR_E1, 0);
        digitalWrite(MOTOR_E2, 1);
    }
}

void frente(int velocidade)
{
    rodaDireita(velocidade, true);
    rodaEsquerda(velocidade, true);
    digitalWrite(STDBY, 0);
}

void traz(int velocidade)
{
    rodaDireita(velocidade, false);
    rodaEsquerda(velocidade, false);
    digitalWrite(STDBY, 0);
}

void parar()
{
    digitalWrite(MOTOR_D, 0);
    digitalWrite(MOTOR_E, 0);
    digitalWrite(STDBY, 1);
}

void giroHorario(int velocidade)
{
    rodaEsquerda(velocidade, true);
    rodaDireita(velocidade, false);
    digitalWrite(STDBY, 0);
}

void giroAntiHorario(int velocidade)
{
    rodaEsquerda(velocidade, false);
    rodaDireita(velocidade, true);
    digitalWrite(STDBY, 0);
}

void procurarOponente()
{
    while (isArena() && !isRadarDireito() && !isRadarEsquerdo())
    {
        giroHorario(255);
        //delay(T);
    }
}

float readUltrassonicoDireito()
{
    float distancia;
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

    Serial.println(distancia);
    return distancia;
}

float readUltrassonicoEsquerdo()
{
    float distancia;
    long microsec = ultrasonic.timing();
    distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

    Serial.println(distancia);
    return distancia;
}

bool isRadarDireito()
{
    distancia = readUltrassonicoDireito();
    if (distancia > diametroArena)
    {
        return false;
    }
    else if (distancia < diametroArena)
    {
        return true;
    }
}

bool isRadarEsquerdo()
{
    distancia = readUltrassonicoEsquerdo();
    if (distancia > diametroArena)
    {
        return false;
    }
    else if (distancia < diametroArena)
    {
        return true;
    }
}

bool isArena()
{
    //true para o caso do sensor estar na arena e false para nao
    int valor_piso_direito = analogRead(OPTICO_A);
    int valor_piso_esquerdo = analogRead(OPTICO_B);
    if (valor_piso_direito <= limiar_piso_black || valor_piso_esquerdo <= limiar_piso_black)
    {
        return false;
    }
    else
    {
        recuar();
        return true;
    }
}

bool isRadarFrente()
{
    double valorVolts = analogRead(SHARP) * 0.0048828125;
    double distancia = 4800 / (valorVolts * 200 - 20);

    if (distancia > diametro_arena)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void atacarOponente()
{
    while (isArena() && isRadarFrente())
    {
        frente(255);
        //delay(0.4);
    }
}

//Incluir sentido e formas diferentes de recuar
void recuar(int velocidade)
{
    rodaDireita(velocidade, false);
    rodaEsquerda(velocidade, false);
    delay(2 * T);
    parar();
}

void ledStart()
{
}

void setup()
{
    // setando pinos ultrasonico direito
    pinMode(ECHO_dir, INPUT);
    pinMode(TRIGGER_dir, OUTPUT);

    // setando pinos ultrasonico esquerdo
    pinMode(ECHO_esq, INPUT);
    pinMode(TRIGGER_esq, OUTPUT);

    // setando pinos buzzer
    pinMode(LED, OUTPUT);

    // setando PWM dos Motores
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);

    digitalWrite(PWMA, 1);
    digitalWrite(PWMB, 1);

    digitalWrite(LED, 1);
    delay(1);
    digitalWrite(LED, 0);
    delay(4);
    digitalWrite(LED, 1);
}

void loop()
{
    //PROCURAR OPONETE
    procurarOponente();

    //ATACAR OPONENTE
    atacarOponente();
}
