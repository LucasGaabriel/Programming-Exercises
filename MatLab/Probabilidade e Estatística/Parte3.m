function Parte3

  pkg load statistics;

  %%%%% TAREFA 1 %%%%%
  FDP_Weibull = @(x, lambda, k) (k / lambda) * (x / lambda).^(k - 1) .* exp(-(x / lambda).^k);

  %%%%% TAREFA 2 %%%%%
  x = 1;  % Valor/Valores de x para avaliar a função
  lambda = 1.0;  % Exemplo de valor para lambda
  k = 2.0;  % Exemplo de valor para k

  % Calculando a diferença entre as implementações
  diferenca = FDP_Weibull(x, lambda, k) - wblpdf(x, lambda, k);
  printf("Tarefa 1.4.2: Diferença entre Implementação 'Caseira' da FDP_Weibull e a do Sistema wblpdf: %f\n\n", diferenca);

  %%%%% TAREFA 3 %%%%%
  x = linspace(0, 2.5, 100);  % Valores de x para plotar
  lambda = [1.0];  % Valores para lambda
  k = [0.5, 1.0, 1.5, 5];  % Valores para k

  figure;
  hold on;
  for i = 1:numel(lambda)
      for j = 1:numel(k)
          plot(x, FDP_Weibull(x, lambda(i), k(j)));
      end
  end
  hold off;
  legend('λ=1, k=0.5', 'λ=1, k=1', 'λ=1, k=1.5', 'λ=1, k=5');
  xlabel('x');
  ylabel('FDP Weibull');

  %%%%% TAREFA 4 %%%%%
  FDA_Weibull = @(x, lambda, k) 1 - exp(-(x / lambda).^k);

  x = 1;  % Valor/Valores de x para avaliar a função
  lambda = 1.0;  % Exemplo de valor para lambda
  k = 2.0;  % Exemplo de valor para k

  diferenca = FDA_Weibull(x, lambda, k) - wblcdf(x, lambda, k);
  printf("Tarefa 1.4.4: Diferença entre Implementação 'Caseira' da FDA_Weibull e a do Sistema wblcdf: %f\n\n", diferenca);

  x = linspace(0, 2.5, 100);  % Valores de x para plotar
  lambda = [1.0];  % Valores para lambda
  k = [0.5, 1.0, 1.5, 5];  % Valores para k

  figure;
  hold on;
  for i = 1:numel(lambda)
      for j = 1:numel(k)
          plot(x, FDA_Weibull(x, lambda(i), k(j)));
      end
  end
  hold off;
  legend('λ=1, k=0.5', 'λ=1, k=1', 'λ=1, k=1.5', 'λ=1, k=5');
  xlabel('x');
  ylabel('FDA Weibull');

  %%%%% TAREFA 5 %%%%%
  n = 1000;  % Número de amostras
  lambda = 0.53;  % Valor para lambda
  k = 1.06;  % Valor para k

  amostras_weibull = wblrnd(lambda, k, [n, 1]);

  %%%%% TAREFA 6 %%%%%
  k_inicial = 1;

  soma1 = mean(amostras_weibull.^k_inicial .* log(amostras_weibull));
  soma2 = mean(amostras_weibull.^k_inicial);
  soma3 = mean(log(amostras_weibull));

  k_estimado = 1 / (soma1 / soma2 - soma3);
  lambda_estimado = (mean(amostras_weibull.^k_estimado))^(1/k_estimado);

  ## k_estimado_wblfit = wblfit(amostras_weibull) %%% WBLFIT NÃO IMPLEMENTADA

  printf("Tarefa 1.4.6: k Estimado = %f, Lambda Estimado = %f\n\n", k_estimado, lambda_estimado);

  %%%%% TAREFA 7 %%%%%
  % Gerar histograma
  k = ceil(1 + 3.322 * log(n)); % Quantidade de barras usando a Regra de Sturges
  [Y, X] = hist(amostras_weibull, k);
  Y = Y ./ trapz(X, Y);

  % Plotar histograma
  figure;

  y_pdf = wblpdf(X, lambda_estimado, k_estimado);

  hold on

  bar(X, Y);
  bar(X, y_pdf);

  plot(X, y_pdf, "--", "LineWidth", 2)

  hold off

  RSS = sum((y_pdf - Y).^2);

  titulo = ["Histograma com ", num2str(k), " Barras\n", "Bondade de Ajuste = ", num2str(RSS)];
  title(titulo);
  xlabel("Intervalos");
  ylabel("Frequência");
  legend("y observado", "y predito pela FDP", "Ajuste com distribuição: Weibull")

  printf("Tarefa 1.4.7: Residual Sum Of Squares = %f\n\n", RSS);

  %%%%% TAREFA 8 %%%%%
  % Ajustar os dados a uma distribuição Gaussiana
  mu = mean(amostras_weibull);
  sigma = std(amostras_weibull);

  % Gerar o gráfico comparando as distribuições
  x = amostras_weibull;
  k = ceil(1 + 3.322 * log(n));

  [Y, X] = hist(x, k);
  Y = Y ./ trapz(X, Y);

  figure;

  y_pdf = normpdf(X, mu, sigma);

  hold on;

  bar(X, Y);
  bar(X, y_pdf)

  plot(X, y_pdf, "--", "LineWidth", 2)

  hold off;

  RSS = sum((y_pdf - Y).^2);

  titulo = ["Histograma com ", num2str(k), " Barras\n", "Bondade de Ajuste = ", num2str(RSS)];
  title(titulo);
  xlabel("Intervalos");
  ylabel("Frequência");
  legend("y observado", "y predito pela FDP", "Ajuste com distribuição: Normal");

  printf("Tarefa 1.4.8: Residual Sum Of Squares = %f\n\n", RSS);

endfunction
