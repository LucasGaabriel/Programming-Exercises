function filtrarNumeros(array){
    const newArray = array.filter(a => typeof a == "number")
    console.log(newArray)
}

filtrarNumeros(["a", 13, 15, "17", "olá", 4])