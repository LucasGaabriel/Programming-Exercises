function formatarNumero(valor){
    console.log(`R$${valor.toFixed(2).replace(".", ",")}`)
}

formatarNumero(0.2 + 0.1)
formatarNumero(32.456)
formatarNumero(99.9998)
formatarNumero(45.99)