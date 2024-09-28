

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%          G R Á F I C O  P A R A M E T R I Z A D O         %%%%%%%
%%%%%%    V Á R I A S  Á R E A S  N A  M E S M A  J A N E L A    %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


constfunc = @(x, const) repmat([const], length(x), 1);  % Função constante


fig = gcf;	% handle to current figure
clf(fig);
close(fig);
close all;

%%%%%%%%%%%%%%%
%%%% Á R E A  1
subplot(2, 1, 1);	% (rows, cols, index)
%%%%%%%%%%%%%%%

hold on;
leg = {};

% https://pt.wikipedia.org/wiki/Senoide

% Pares (amplitude, frequencia)
param = {
  {1.0, 1.0},
  {1.0, 5.0},
  {1.0, 10.0},
  {2.0, 1.0},
  {2.0, 5.0},
  {2.0, 10.0},
};

func = @(t, A, f) A*sin(2*pi*f*t); % A função é seno parametrizado, https://pt.wikipedia.org/wiki/Senoide
funcstrsin = 'A sin(2 pi freq t)'; 
funcstrcos = 'A cos(2 pi freq t)'; 

t = 0:0.001:1;  % Intervalo de tempo

for i=1:length(param)
  A = param{i}{1};
  f = param{i}{2};
  y = func(t, A, f);
  plot(t, y)%, 'iterpreter', 'tex');
  % Não funciona graphics_toolkit fltk; leg{end+1} = '... \n \newline \\';
  leg{end+1} = sprintf('A=%3.1f, \\nu=%3.1f', A, f);
end
plot(t, constfunc(t, 0.0), '--k', 'linewidth', 1); leg{end+1} = 'A=0';


maxA = 2.1;
ylim([-maxA maxA]);
xlabel('t [sec]');
ylabel('f(t)');
title(funcstrsin);
h = legend(leg);
set (h, 'interpreter', 'tex', 'location', 'northeastoutside');
fname = './figs/seno.eps'; format = '-depsc2';
% fname = './figs/seno.svg'; format = '-dsvg';
fprintf('Salvando gráfico em %s ...\n', fname);
% print(fname, format)
hold off;


%%%%%%%%%%%%%%%
%%%% Á R E A  2
subplot(2, 1, 2);	% (rows, cols, index)
%%%%%%%%%%%%%%%

hold on;
leg = {};

% https://pt.wikipedia.org/wiki/Senoide

% Pares (amplitude, frequencia)
param = {
  {1.0, 1.0},
  {1.0, 5.0},
  {1.0, 10.0},
  {2.0, 1.0},
  {2.0, 5.0},
  {2.0, 10.0},
};

func = @(t, A, f) A*cos(2*pi*f*t); % A função é seno parametrizado, https://pt.wikipedia.org/wiki/Senoide

t = 0:0.001:2;  % Intervalo de tempo

for i=1:length(param)
  A = param{i}{1};
  f = param{i}{2};
  y = func(t, A, f);
  plot(t, y)%, 'iterpreter', 'tex');
  leg{end+1} = sprintf('A=%3.1f, \\nu=%3.1f', A, f);
end
plot(t, constfunc(t, 0.0), '--k', 'linewidth', 1); leg{end+1} = 'A=0';

maxA = 2.1;
ylim([-maxA maxA]);
xlabel('t [sec]');
ylabel('f(t)');
title(funcstrcos);
h = legend(leg);
set (h, 'interpreter', 'tex', 'location', 'northeastoutside');
fname = './figs/cosseno.eps'; format = '-depsc2';
% fname = './figs/cosseno.svg'; format = '-dsvg';
fprintf('Salvando gráfico em %s ...\n', fname);
% print(fname, format)
hold off;
