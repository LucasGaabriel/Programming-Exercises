
%
% Uma função, chamada 'fmax', que recebe como parâmetros
%
% 1) Uma função, chamada 'f', que tem um ÚNICO parâmetro
% 2) Um valor x1
% 3) Um valor x2
%
% O resultado é o maior dos dois valores da função em x1 e em x2, ou seja,
% o maior dos dois valores f(x1), f(x2)

fmax = @(f, x1, x2) max(f(x1), f(x2))

%
% Como exemplo vamos definir como função 'f', o seno, que tem um argumento

f = @(x) sin(x)

% Então podemos perguntar: Qual é o maior valor do seno em
% x1 = 0, ou em x2 = pi/2 ?
% O resultado é 1

resultado = fmax(f, 0, pi/2)


% Agora queremos determinar o maior valor de uma função 'g', usando
% a função 'fmax', porém g tem TRÊS parâmetros.
% A chamada fmax(g, ...) não vai funcionar, pois 'fmax' aceita somente uma
% função com um argumento só.
%

g = @(x, m, b) m*x + b

% A solulçao é definir uma nova função 'wrapper_g' que tem um único argumento
% e fixou os outros dois argumentos de 'g'

m = 2;
b = 3;
wrapper_g = @(x) g(x, m, b) 

% Agora podemos passar 'wrapper_g' para fmax

x1 = 1;
x2 = 4;
resultado = fmax(wrapper_g, x1, x2)

