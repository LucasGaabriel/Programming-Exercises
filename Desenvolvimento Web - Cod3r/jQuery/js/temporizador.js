(function ($) {
    $.fn.temporizador = function (opcoes) {
        const opcoesFinais = $.extend({
            mensagem: 'Em breve!',
            horario: '23:59:59'
        }, opcoes)

        const horaDezena = $('<span class="digito">').html('0')
        const horaUnidade = $('<span class="digito">').html('0')
        const minutoDezena = $('<span class="digito">').html('0')
        const minutoUnidade = $('<span class="digito">').html('0')
        const segundoDezena = $('<span class="digito">').html('0')
        const segundoUnidade = $('<span class="digito">').html('0')

        const separadorHora = $('<span class="separador">').html(':')
        const separadorMinuto = $('<span class="separador">').html(':')
        const mensagem = $('<div class="mensagem">').html(opcoesFinais.mensagem)

        $(this).addClass('temporizador')
        $(this).append(horaDezena, horaUnidade, separadorHora, 
                        minutoDezena, minutoUnidade, separadorMinuto, 
                        segundoDezena, segundoUnidade, mensagem)

        const regex = new RegExp(/(\d\d):(\d\d):(\d\d)/)
        const horarioAlvo = regex.exec(opcoesFinais.horario)

        let temporizador = setInterval(() => {
            const agora = new Date()
            const alvo = new Date()
            alvo.setHours(horarioAlvo[1])
            alvo.setMinutes(horarioAlvo[2])
            alvo.setSeconds(horarioAlvo[3])

            const diffInMillis = alvo.getTime() - agora.getTime()

            if (diffInMillis >= 0) {
                const diff = regex.exec(new Date(diffInMillis).toISOString())

                horaDezena.html(diff[1][0])
                horaUnidade.html(diff[1][1])
                minutoDezena.html(diff[2][0])
                minutoUnidade.html(diff[2][1])
                segundoDezena.html(diff[3][0])
                segundoUnidade.html(diff[3][1])
            } else {
                clearInterval(temporizador)
            }
        }, 1000)

        return this
    }
})(jQuery)