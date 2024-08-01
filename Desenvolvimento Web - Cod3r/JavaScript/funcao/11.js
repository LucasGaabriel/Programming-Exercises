function bissexto(ano){
    if(ano % 400 == 0)
        console.log("Bissexto")
    else if(ano % 100 == 0)
        console.log("Não é bissexto")
    else if(ano % 4 == 0)
        console.log("Bissexto")
    else
        console.log("Não é bissexto")
}

bissexto(1998)
bissexto(2024)
bissexto(2025)
bissexto(2026)
bissexto(2028)