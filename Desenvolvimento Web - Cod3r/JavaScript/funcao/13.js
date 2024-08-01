function qDiaEhHoje(dia){
    switch(dia){
        case 1: 
            console.log("Final de Semana");
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            console.log("Dia útil");
            break;
        case 7:
            console.log("Final de Semana");
            break;
        default:
            console.log("Dia inválido")
    }
}

qDiaEhHoje(1)
qDiaEhHoje(4)
qDiaEhHoje(6)
qDiaEhHoje(7)
qDiaEhHoje(9)
qDiaEhHoje(-4)
qDiaEhHoje(0)
qDiaEhHoje(-1)