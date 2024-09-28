# Aluno: Lucas Gabriel de Oliveira Costa
# Trabalho 2 - Paradigma Funcional
# Tema: Livros na Base de Dados Dbpedia

from SPARQLWrapper import SPARQLWrapper, JSON
from functools import reduce
import pprint

# Endpoint
sparql = SPARQLWrapper("http://dbpedia.org/sparql") 

# Query
sparql.setQuery("""
PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>
PREFIX dbo: <http://dbpedia.org/ontology/>
PREFIX schema: <http://schema.org/>
PREFIX dbp: <http://dbpedia.org/property/>
PREFIX foaf: <http://xmlns.com/foaf/0.1/>
PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>

SELECT DISTINCT ?sujeito ?titulo ?genero ?pais ?linguagem ?autor ?editor ?lancamento ?paginas
(xsd:integer(SUBSTR(STR(?lancamento), 1, 4)) AS ?anoLancamento)
(YEAR(NOW()) - xsd:integer(SUBSTR(STR(?lancamento), 1, 4)) AS ?idade)
WHERE {
    ?sujeito a dbo:Book;
    rdfs:label ?titulo;
    dbo:publicationDate ?lancamento;
    dbp:country ?pais;
    dbp:author ?autorLink;
    dbp:publisher ?editorLink;
    dbo:numberOfPages ?paginas;
    dbp:language ?linguagem.
    
    {?sujeito dbp:genre ?genero.
    FILTER (lang(?genero) = 'en')}
    UNION
    {?sujeito dbp:genre ?recGenero.
    ?recGenero rdfs:label ?genero.
    FILTER (lang(?genero) = 'en')}
 
    ?editorLink foaf:name ?editor.
    ?autorLink foaf:name ?autor.
 
    FILTER (lang(?titulo) = 'en') .
}
ORDER BY (?titulo)
""")

# Set Return Format to JSON
sparql.setReturnFormat(JSON) 

# Execute Query and Returns Result in JSON Format
results = sparql.query().convert() 

# Pega os resultados da Query e retorna apenas as informações necessárias como uma lista de Dict
def getInformations(results):
    VALUES = results['results']['bindings']
    return list( map( lambda item: dict( map ( lambda key: (key, item[key]['value']) , item.keys() )) , VALUES) )

# Faz uma busca de livros pelo Gênero
def livros_por_genero(info: list, genero: str) :
    return list( filter(lambda x: x['genero']==genero, info) )

# Faz uma busca de livros pelo Autor
def livros_por_autor(info: list, autor: str):
    return list( filter(lambda x: x['autor']==autor, info) )

# Faz uma busca por livros que contenham a quantidade de páginas no intervalo [MinPaginas, MaxPaginas]
def livros_por_paginas(info: list, MinPaginas: int, MaxPaginas: int):
    return list( filter(lambda x: int(x['paginas'])>=MinPaginas and int(x['paginas'])<=MaxPaginas, info) )

# Faz uma busca por livros que tenham sido lançados no intervalo de anos [LimInferior, LimSuperior]
def livros_por_ano_lancamento(info: list, LimInferior: int, LimSuperior: int):
    return list( filter(lambda x: int(x['anoLancamento'])>=LimInferior and int(x['anoLancamento'])<=LimSuperior, info) )

# Faz uma busca por livros que tenham sido lançados nos últimos 'TempoMax' anos.
# O gênero do livro é opcional
def lancamentos_recentes(info: list, tempoMax: int, genero: str = None):
    if genero:
        return list( filter(lambda x: int(x['idade'])<=tempoMax and x['genero']==genero, info) )
    return list( filter(lambda x: int(x['idade'])<=tempoMax, info) )

# Faz uma busca por livros "semelhantes"
# É uma regra fictícia, levando em consideração que livros são semelhantes quando:
# - Possuem mesmo gênero
# - Diferença entre as datas de lançamento seja no máximo 2 anos
# - Diferença da quantidade de páginas seja no máximo 50.
def livros_semelhantes(info: list, genero: str):

    # Filtra inicialmente todos os livros do mesmo gênero
    livros_mesmo_genero = list(filter(lambda x: x['genero']==genero, info))

    def verifica_dois_livros_semelhantes(livro1: dict, livro2: dict):
        titulo1 = livro1['titulo']
        titulo2 = livro2['titulo']

        if titulo1 == titulo2: # Elimina repetição de titulos
            return False
        
        genero1 = livro1['genero']
        genero2 = livro2['genero']
        ano1 = int(livro1['anoLancamento'])
        ano2 = int(livro2['anoLancamento'])
        paginas1 = int(livro1['paginas'])
        paginas2 = int(livro2['paginas'])

        if genero1 == genero2: # Verifica se possuem o mesmo gênero
            if abs(ano1 - ano2) <= 2: # Verifica se a diferença entre as datas de lançamento é no máximo 2 anos
                if abs(paginas1 - paginas2) <= 50: # Verifica se a diferença na quantidade de páginas é no máximo 50
                    return True

        return False

    return list( filter(lambda x: verifica_dois_livros_semelhantes(x[0], x[1]), 
                                [(livro1, livro2) for livro1 in livros_mesmo_genero 
                                                        for livro2 in livros_mesmo_genero 
                                                                if livro1 != livro2]) )

# Retorna a quantidade de páginas já escritas por um determinado autor
def paginas_escritas_por_um_autor(info: list, autor: str):
    # Busca primeiro todos os livros de um autor
    livros_do_autor = list( filter(lambda x: x['autor']==autor, info) )
    return reduce(lambda x, y: x+y, map(lambda x: int(x['paginas']), livros_do_autor), 0)

if __name__ == "__main__":
    
    # Para imprimir um dicionario formatado
    # Cada item em uma linha
    pp = pprint.PrettyPrinter()
    
    # Pega os Resultados da Query
    info = getInformations(results)

    ##### Exemplos de Consultas #####
    # result = livros_por_genero(info, 'Novel')
    # result = livros_por_autor(info, 'C. S. Lewis')
    # result = livros_por_paginas(info, 200, 300)
    # result = livros_por_ano_lancamento(info, 2020, 2022)
    # result = lancamentos_recentes(info, 5)
    # result = livros_semelhantes(info, "Novel")
    result = paginas_escritas_por_um_autor(info, 'C. S. Lewis')

    # Imprime os resultados da consulta
    pp.pprint(result)
    