pkg load symbolic;
pkg load statistics;

%Questao 2
fdp_normal = @(x, mu, sigma) (1/sqrt(2*pi*sigma))*exp(-((x-mu).^2)/(2*sigma));

fprintf('Implementação FDP própria: ');

fprintf('%f\n\n',fdp_normal(1, 2, 9));

fprintf('Função do sistema normpdf: ');

%Questao 3
y = normpdf(1, 2, 3);

fprintf('%f\n\n',y);

fprintf('Diferença entre as implementações: %f\n\n',fdp_normal(1, 2, 9)-y);

%Questao 4
subplot(2, 1, 1);	% (rows, cols, index)

hold on;
leg = {};

% Pares (amplitude, frequencia)
param = {
  {0.0, 0.2},
  {0.0, 1.0},
  {0.0, 5.0},
  {-2.0, 0.5}
};

%usando a fdp_normal

t = -5:0.001:5;  % Intervalo de tempo

for i=1:length(param)
  A = param{i}{1};
  f = param{i}{2};
  y = fdp_normal(t, A, f);
  plot(t, y)
  leg{end+1} = sprintf('μ=%3.1f, v=%3.1f', A, f);
end


ylim([0 1]);
xlabel('X');
ylabel('p(X;μ,σ^2');
title('Função FDP');
h = legend(leg);
set (h, 'interpreter', 'tex', 'location', 'northeastoutside');
fname = './figs/fdp.eps'; format = '-depsc2';
fprintf('Salvando gráfico em %s ...\n\n', fname);
hold off;


%Questao 5

fda_normal = @(x,mu,sigma) (1/2)*(1 + erf((x-mu)/(sqrt(2*sigma))));

fprintf('Implementação FDA própria: ');

fprintf('%f\n\n',fda_normal(1, 2, 9));

fprintf('Função do sistema normcdf: ');

y = normcdf(1, 2, 3);

fprintf('%f\n\n',y);

fprintf('Diferença entre as implementações: %f\n\n',fda_normal(1, 2, 9)-y);

%Criando segunda imagem
figure;

subplot(2, 1, 2);	% (rows, cols, index)

hold on;
leg = {};

% Pares (amplitude, frequencia)
param = {
  {0.0, 0.2},
  {0.0, 1.0},
  {0.0, 5.0},
  {-2.0, 0.5}
};

%usando a fda_normal

t = -5:0.001:5;  % Intervalo de tempo

for i=1:length(param)
  A = param{i}{1};
  f = param{i}{2};
  y = fda_normal(t, A, f);
  plot(t, y) %;
  % Não funciona graphics_toolkit fltk; leg{end+1} = '... \n \newline \\';
  leg{end+1} = sprintf('μ=%3.1f, v=%3.1f', A, f);
end


ylim([0 1]);
xlabel('X');
ylabel('p(X;μ,σ^2');
title('Função FDA');
h = legend(leg);
set (h, 'interpreter', 'tex', 'location', 'northeastoutside');
fname = './figs/fda.eps'; format = '-depsc2';
fprintf('Salvando gráfico em %s ...\n\n', fname);
hold off;

%Questao 6

func_6 = @(percentil,mu,sigma) erfinv(2*percentil - 1)*sqrt(2*sigma) + mu;

res = func_6(0.99,-2,0.5);

fprintf('Valor de x para percentil 99 é %f\n',res);

%Questao 7

mu=-2;
sigma=0.5;
a=mu-(10*sqrt(sigma));
b=(-2 + erfinv(49/50));

fda =@(x)  (1/2)*(1 + erf((x-mu)/(sqrt(2*sigma))));

fda_sym = sym(fda);
I = int(fda_sym,a,b);%integral analitica
I = double(I);

fprintf('%f\n',double(I));

trap = @(n) integralTrapeziosRepetidaFunc(fda, a, b, n, 0);

simp13 = @(n) integralSimpsonRepetidaFunc(fda, a, b, n, 0);

simp38 = @(n) integralSimpson38RepetidaFunc(fda, a, b, n, 0);

C = coefGaussLegendre( 13 );
[T, A] = tabelaAbcissasPesosGaussLegendre( C );

gaussl = @(n) integralGaussLegendreFunc( fda, double(a), double(b), n, T, A, 0 );

%Questao 7

fprintf('Erro dos métodos diferentes de integração\n' );
fprintf('%s  %15s  %15s  %15s  %15s\n', 'Subdivisões', 'Trapézios', 'Simpson 1/3','Simpson 3/8', 'Quad. Gauss.' );
fprintf('---------------------------------------------------------------------------------------------------\n');

for i = 1:12
  fprintf('%2d %23f %15f %15f %15f\n',i, abs(trap(i)-I),abs(simp13(i)-I),abs(simp38(i)-I),abs(gaussl(i)-I));
end

%Questao 8

randn('seed',2023);

r = normrnd(-2,0.7,[1000 1]);

%Questao 9

soma = 0;

for i=1:length(r)
  soma=soma+r(i);
end

mu_aprox = soma / 1000;

fprintf('μ encontrado = %f\n\n',mu_aprox);

fprintf('Diferença de μ = %f\n\n',abs(mu_aprox - -2));

soma=0;

for i=1:length(r)
  soma = soma + (r(i)-mu_aprox)^2;
end

sigma_aprox = soma / 999;

sigma_aprox = sqrt(sigma_aprox);

fprintf('σ encontrado = %f\n\n',sigma_aprox);

fprintf('Diferença de σ = %f\n\n',abs(sigma_aprox - 0.7));

%Questao 10

eps = 1e-3;

syms f(x);

fstr = '(1/2)*(1 + erf((x-(-2.009189))/(sqrt(2)*(0.713661)))) - 0.99';

f(x) = eval(fstr);

func = matlabFunction(f);

raiz = raizBisecPosFalsa( false, func, -1, 0, eps, 11 );

fprintf('Raiz encontrada com metodo da bissecao: %f\n\n',raiz);

raiz_analitica = solve(f(x));

fprintf('Solucao analitica: %f\n\n',double(raiz_analitica));
