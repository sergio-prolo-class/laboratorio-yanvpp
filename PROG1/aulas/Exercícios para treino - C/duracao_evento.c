#include <stdio.h>

typedef struct
{
    int hh;
    int mm;
} Horario;

typedef struct
{
    Horario inicio;
    Horario termino;

} Evento;

int converter_para_minutos(Horario horario)
{
    int minutos;
    minutos = horario.mm + 60 * horario.hh;
    return minutos;
}

Horario converter_para_horario(int minutos)
{
    Horario horario;
    horario.hh = minutos / 60;
    horario.mm = minutos % 60;
    return horario;
}

Horario duracao_evento(Evento evento)
{
    int deltam;
    deltam = converter_para_minutos(evento.termino) - converter_para_minutos(evento.inicio);
    if (deltam <= 0) {
        deltam += 24 * 60;
    }
    return converter_para_horario(deltam);
}

int main()
{
    Evento evento;
    Horario duracao;

    printf("Entre com o horário de início (HH:MM): ");
    scanf("%d:%d", &evento.inicio.hh, &evento.inicio.mm);

    printf("Entre com o horário de término (HH:MM): ");
    scanf("%d:%d", &evento.termino.hh, &evento.termino.mm);

    duracao = duracao_evento(evento);

    printf("Duração do evento: %02d:%02d\n", duracao.hh, duracao.mm);

    return 0;
}