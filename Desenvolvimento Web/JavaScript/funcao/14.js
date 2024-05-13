function fruta(fruit){
    switch(fruit){
        case "Maçã":
            console.log("Não vendemos esta fruta aqui")
            break;
        case "Kiwi":
            console.log("Estamos com escassez de kiwis")
            break;
        case "Melancia":
            console.log("Aqui está, são 3 reais o quilo")
            break;
        default:
            console.log("Fruta inválida")
    }
}

fruta("Maçã")
fruta("Kiwi")
fruta("Teste")
fruta("Melancia")
