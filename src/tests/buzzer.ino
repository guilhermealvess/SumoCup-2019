#define BUZZER 9

void tocarBuzzer()
{
    // Implementar
    float seno;
    int frequencia;

    for (int x = 0; x < 180; x++)
    {
        //converte graus para radiando e depois obtém o valor do seno
        seno = (sin(x * 3.1416 / 180));
        //gera uma frequência a partir do valor do seno
        frequencia = 2000 + (int(seno * 1000));
        tone(9, frequencia);
        delay(1);
    }
}

void setup()
{
    pinMode(BUZZER, OUTPUT);
}

void loop()
{
    tocarBuzzer();
}