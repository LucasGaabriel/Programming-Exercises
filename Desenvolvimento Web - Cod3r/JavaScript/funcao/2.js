function tipoTriangulo(l1, l2, l3){
    if(l1 == l2 && l2 == l3)
        console.log("Equilátero")
    else if(l1 == l2 || l1 == l3 || l2 == l3)
        console.log("Isósceles")
    else
        console.log("Escaleno")
}

tipoTriangulo(1, 2, 3)
tipoTriangulo(1, 2, 2)
tipoTriangulo(3, 3, 3)
tipoTriangulo(9, 9, 7)