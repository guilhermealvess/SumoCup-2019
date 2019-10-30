#define MOTOR_D
#define MOTOR_E
#define PWMD 3
#define PWME 5

void setup()
{
    pinMode(MOTOR_D, OUTPUT);
    pinMode(MOTOR_E, OUTPUT);
    pinMode(PWMD, OUTPUT);
    pinMode(PWME, OUTPUT);

    digitalWrite(PWMD, 1);
    digitalWrite(PWME, 1);
}

void rodaDireita(int velocidade, bool sentido)
{
    // true para frente e false para traz
    if (sentido)
    {
        digitalWrite(MOTOR_D, 1);
    }
    else
    {
        digitalWrite(MOTOR_D, 0);
    }
}

void rodaEsquerda(int velocidade, bool sentido)
{
    // true para frente e false para traz
    if (sentido)
    {
        digitalWrite(MOTOR_E, 1);
    }
    else
    {
        digitalWrite(MOTOR_E, 0);
    }
}

void frente(int velocidade)
{
    rodaDireita(velocidade, true);
    rodaEsquerda(velocidade, true);
}

void loop()
{
    frente(255);
}