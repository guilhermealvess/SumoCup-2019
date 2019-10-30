#include <Ultrasonic.h>
Ultrasonic ultrasonicEsquerdo(trigger, echo);
Ultrasonic ultrasonicDireito(trigger, echo);

#define ECHO_dir
#define TRIGGER_dir
#define ECHO_esq
#define TRIGGER_esq
#define BUZZER

#define MOTOR_D
#define MOTOR_E
#define PWMA 3
#define PWMB 5

#define REFLETANCIA_IN
#define REFLETANCIA_OUT
#define BOTAO

#define diametro_arena 77.0

void setup()
{
    // setando pinos sharp

    // setando pinos ultrasonico direito
    pinMode(ECHO_dir, INPUT);
    pinMode(TRIGGER_dir, OUTPUT);

    // setando pinos ultrasonico esquerdo
    pinMode(ECHO_esq, INPUT);
    pinMode(TRIGGER_esq, OUTPUT);

    // setando pinos buzzer

    // setando pinos ponteH

    // setando pinos refletancia

    // setando pinos botão

    // setando PWM dos Motores
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);

    digitalWrite(PWMA, 1);
    digitalWrite(PWMB, 1);
}

void rodaDireita(int velocidade, bool sentido)
{
    // true para frente e false para traz
}

void rodaEsquerda(int velocidade, bool sentido)
{
    // true para frente e false para traz
}

void frente(int velocidade)
{
    rodaDireita(velocidade, true);
    rodaEsquerda(velocidade, true);
}

void traz(int velocidade)
{
    rodaDireita(velocidade, false);
    rodaEsquerda(velocidade, false);
}

void parar()
{
    digitalWrite(MOTOR_D, 0);
    digitalWrite(MOTOR_E, 0);
}

void giroHorario(int velocidade)
{
    rodaEsquerda(velocidade, true);
    rodaDireita(velocidade, false);
}

void giroAntiHorario(int velocidade)
{
    rodaEsquerda(velocidade, false);
    rodaDireita(velocidade, true);
}

void tocarBuzzer()
{
    // Implementar
}

void procurarOponente()
{
}

float getDistancia()
{
    return 0.1;
}

bool ring()
{
    return true;
}

void loop()
{
    if (digitalRead(BOTAO) == 1)
    {
        tocarBuzzer();
        delay(5000);

        while (1)
        {
            //PROCURAR OPONETE
        }
    }
}