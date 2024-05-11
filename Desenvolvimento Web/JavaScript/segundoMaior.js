function segundoMaior(array){
    array.sort((a, b) => a-b)
    console.log(array[array.length-2])
}

segundoMaior([12, 16, 1, 5])
segundoMaior([8, 4, 5, 6])