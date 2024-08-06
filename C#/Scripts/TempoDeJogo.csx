string[] input = Console.ReadLine().Split(' ');

int hora_inicial = int.Parse(input[0]);
int minuto_inicial = int.Parse(input[1]);
int hora_final = int.Parse(input[2]);
int minuto_final = int.Parse(input[3]);

if (hora_inicial == hora_final && minuto_inicial == minuto_final)
{
    Console.WriteLine("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)");
    return;
}

int hora_duracao = hora_final - hora_inicial;
int minuto_duracao = minuto_final - minuto_inicial;

if (minuto_duracao < 0)
{
    minuto_duracao += 60;
    hora_duracao--;
}

if (hora_duracao < 0)
{
    hora_duracao += 24;
}

Console.WriteLine($"O JOGO DUROU {hora_duracao} HORA(S) E {minuto_duracao} MINUTO(S)");