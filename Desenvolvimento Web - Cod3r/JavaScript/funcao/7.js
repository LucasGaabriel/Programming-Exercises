function bhaskara(a, b, c){
    let delta = b**2-4*a*c

    if(delta < 0)
        return "Delta é negativo."

    let a1 = ( -b + Math.sqrt(delta) ) / 2 * a
    let a2 = ( -b - Math.sqrt(delta) ) / 2 * a

    return [a1, a2]
}

console.log(bhaskara(1, -3, 2))
console.log(bhaskara(1, 2, 5))
console.log(bhaskara(1, -4, 4))
console.log(bhaskara(1, 3, 2))