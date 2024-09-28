function Parte2

  pkg load statistics;

  %%%%% Tarefa 1 %%%%%
  semente = 2023;
  randn('seed', semente);

  mu = -2;
  sigma = 0.7;
  amostras = normrnd(mu, sigma, 1, 1000);

  n = length(amostras);
  k = ceil(1 + 3.322 * log(n));

  printf("Tarefa 1.3.3.1: Quantidade de barras = %d\n\n", k);

  %%%%% Tarefa 2 %%%%%
  [Y, X] = hist(amostras, k);
  Y = Y ./ trapz(X, Y);

  figure

  y_pdf = normpdf(X, mu, sigma);

  hold on

  bar(X, Y);
  bar(X, y_pdf)

  plot(X, y_pdf, "--", "LineWidth", 2);

  hold off

  RSS = sum((y_pdf - Y).^2);

  titulo = ["Histograma com ", num2str(k), " Barras\n", "Bondade de Ajuste = ", num2str(RSS)];
  title(titulo)
  xlabel("Intervalos");
  ylabel("Frequência");
  legend("y observado", "y predito pela FDP", "Ajuste com distribuição normal")

  printf("Tarefa 1.3.3.2: Residual Sum Of Squares = %f\n\n", RSS);

endfunction
