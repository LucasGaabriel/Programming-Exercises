function removerPropriedade(objeto, propriedade){
    const copia = Object.assign({}, objeto)
    delete copia[propriedade]
    return copia
}

const objeto = {a: "A", b: "B"}
console.log("Objeto Inicial:", objeto)
const objetoModificado = removerPropriedade(objeto, "a")
console.log("Objeto Modificado:", objetoModificado)
console.log(`São o mesmo objeto? => ${Object.is(objeto, objetoModificado)}`)