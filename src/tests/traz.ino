#define MOTOR_D1
#define MOTOR_D2
#define MOTOR_E1
#define MOTOR_E2
#define PWMD 3
#define PWME 5
#define STDBY 9

void setup()
{
    pinMode(MOTOR_D1, OUTPUT);
    pinMode(MOTOR_D1, OUTPUT);
    pinMode(MOTOR_E1, OUTPUT);
    pinMode(MOTOR_E1, OUTPUT);
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

void loop()
{
    traz(255);
    delay(2);
    parar();
    delay(1);
}