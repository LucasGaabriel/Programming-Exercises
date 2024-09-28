% Aluno: Lucas Gabriel de Oliveira Costa
% Trabalho 1 - Paradigma Lógico
% Tema: Livros na Base de Dados Dbpedia

:- data_source(
   dbpedia_livros, sparql(
    "SELECT DISTINCT ?sujeito ?titulo ?genero ?pais ?linguagem ?autor ?editor ?lancamento ?paginas
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
",
	[ endpoint('https://dbpedia.org/sparql')])).

% Associa as "colunas" da base de dados com variáveis Prolog.
livros(Titulo, Genero, 
       Pais, Linguagem, 
       Autor, Editor, 
       Lancamento, Paginas,
       AnoLancamento, Idade) :- dbpedia_livros{titulo:Titulo, genero:Genero, pais:Pais, 
                                              linguagem:Linguagem, autor:Autor, editor:Editor,
                                              lancamento:Lancamento, paginas:Paginas,
                                              anoLancamento:AnoLancamento, idade:Idade}.
% Faz uma busca de livros pelo Gênero
livros_por_genero(Genero, Titulo) :-
    distinct([Titulo], livros(Titulo, Genero, _, _, _, _, _, _, _, _)).
	% Livros com título repetidos são ignorados pelo 'distinct'.

% Faz uma busca de livros pelo Autor
livros_por_autor(Autor, Titulo) :-
    distinct([Titulo], livros(Titulo, _, _, _, Autor, _, _, _, _, _)).
	% Livros com título repetidos são ignorados pelo 'distinct'.

% Faz uma busca por livros que contenham a quantidade de páginas no intervalo [MinPaginas, MaxPaginas]
livros_por_paginas(MinPaginas, MaxPaginas, Titulo) :-
    livros(Titulo, _, _, _, _, _, _, Paginas, _, _),
    Paginas >= MinPaginas,
    Paginas =< MaxPaginas.

% Faz uma busca por livros que tenham sido lançados no intervalo de anos [LimInferior, LimSuperior]
livros_por_ano_lancamento(LimInferior, LimSuperior, Titulo) :-
    livros(Titulo, _, _, _, _, _, _, _, AnoLancamento, _),
    AnoLancamento >= LimInferior,
    AnoLancamento =< LimSuperior.

% Faz uma busca por livros que tenham sido lançados nos últimos 'TempoMax' anos.
lancamentos_recentes(Genero, TempoMax, Titulo) :-
    livros(Titulo, Genero, _, _, _, _, _, _, _, Idade),
    Idade =< TempoMax.

% Faz uma busca por livros "semelhantes"
% É uma regra fictícia, levando em consideração que livros são semelhantes quando:
% - Possuem mesmo gênero
% - Diferença entre as datas de lançamento seja no máximo 2 anos
% - Diferença da quantidade de páginas seja no máximo 50.
livros_semelhantes(Genero, Titulo1, Titulo2) :-
    livros(Titulo1, Genero, _, _, _, _, _, Pags1, _, Idade1),
    livros(Titulo2, Genero, _, _, _, _, _, Pags2, _, Idade2),
	Titulo1 \= Titulo2,  		% Certifica que os títulos são diferentes
    abs(Idade1 - Idade2) =< 2,  % Diferença de data de lançamento máxima de 2 anos
    abs(Pags1 - Pags2) =< 50.   % A diferença de páginas máxima deve ser de 50 páginas
    
%%%%%%%%%% Exemplos de Consultas %%%%%%%%%%
% livros_por_genero("Crime fiction", Titulo)
% livros_por_genero("Novel", Titulo)
%
% livros_por_autor("C. S. Lewis", Titulo)
% livros_por_autor("J. K. Rowling", Titulo)
%
% livros_por_paginas(50, 100, Titulo)
% livros_por_paginas(200, 210, Titulo)
%
% distinct([Titulo], livros_por_ano_lancamento(2020, 2022, Titulo))
% distinct([Titulo], livros_por_ano_lancamento(1990, 1995, Titulo))
%
% lancamentos_recentes("Novel", 5, Titulo)
% lancamentos_recentes("Fantasy", 3, Titulo)
%
% livros_semelhantes("Fantasy", Titulo1, Titulo2)
% livros_semelhantes("Thriller (genre)", Titulo1, Titulo2)


