pkg load statistics;

%Tarefa 1

fdp_paretto = @(x, mu, sigma, csi) (1 / sigma) * (1 + (csi*(x - mu)/sigma)).^(-(1/csi)-1);

%Tarefa 2

x = linspace(0, 5, 100);  % Valores de x para plotar
mu = 0;
sigma = [1.0 1.0 1.0 2.0 2.0 2.0];
csi = [1.0 5.0 20.0 1.0 5.0 20.0];

figure;
hold on;

for i = 1:6
  plot(x, fdp_paretto(x,mu, sigma(i), csi(i)));
end

hold off;
legend('σ=1, ξ=1', 'σ=1, ξ=5', 'σ=1, ξ=20', 'σ=2, ξ=1', 'σ=2, ξ=5', 'σ=2, ξ=20');
xlabel('x');
ylabel('FDP Paretto');

%Tarefa 3

igual_zero = @(x, mu, sigma, csi) 1 - exp(1 - (-(x - mu) /sigma));

diferente_zero = @(x, mu, sigma, csi) 1 - (1 + (csi*(x - mu)/sigma)).^ (-1/csi);

iif = @(varargin) varargin{2 * find([varargin{1:2:end}], 1, 'first')}();
fda_paretto = @(x, mu, sigma, csi) iif(csi == 0, igual_zero(x, mu, sigma, csi), true, diferente_zero(x, mu, sigma, csi));



figure;
hold on;

for i = 1:6
  plot(x, fda_paretto(x,mu, sigma(i), csi(i)));
end

hold off;
legend('σ=1, ξ=1', 'σ=1, ξ=5', 'σ=1, ξ=20', 'σ=2, ξ=1', 'σ=2, ξ=5', 'σ=2, ξ=20');
xlabel('x');
ylabel('FDA Paretto');

%Tarefa 4

k=20;%valor definido de k para a funcao gprnd
sigma = 1.0;%valor definido de sigma para a funcao gprnd
mu = 0;

amostra = gprnd(k, sigma, mu, [1000 , 1]);

%Tarefa 5

parmhat = gpfit(amostra);

fprintf('Valor estimado dos parametros: %f %f\n\n',parmhat(1),parmhat(2));
