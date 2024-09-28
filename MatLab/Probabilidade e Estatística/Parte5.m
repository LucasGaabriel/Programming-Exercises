%Tarefa 1
%Identificar o site

%Tarefa 2
%Arquivo foi baixado

%Tarefa 3

file_path = '41002h2022.txt';

file = fopen(file_path, 'r');

wspd_vector = [];
wvht_vector = [];

% Read the rest of the file
while ~feof(file)


    line = fgetl(file);
    values = textscan(line, '%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f', 'Delimiter', '\t');





    value_wspd = values{7};
    value_wvht = values{9};

    %Tarefa 4 e 5 foram feitas nas proximas linhas, onde muda 0 para 0.1 e ignora 99

    if value_wspd == 0.00
      value_wspd = 0.1;
      wspd_vector = [wspd_vector; value_wspd];
    elseif value_wspd == 99.00
      %Nao faz nada
      value_wspd = NaN;
      wspd_vector = [wspd_vector; value_wspd];
    else
      wspd_vector = [wspd_vector; value_wspd];
    end

    if value_wvht == 0.00
      value_wvht = 0.1;
      wvht_vector = [wvht_vector; value_wvht];
    elseif value_wvht == 99.00
      %Nao faz nada
      value_wvht = NaN;
      wvht_vector = [wvht_vector; value_wvht];
    else
      wvht_vector = [wvht_vector; value_wvht];
    end

end




fclose(file);

%Tarefa 6
%Plotando WSPD
tamanho = length(wspd_vector);

figure;
hold on;

subsetIndices = 1:1:tamanho;
plot(subsetIndices, wspd_vector(subsetIndices),'-');

hold off;
legend('Velocidade Vento');
xlabel('t[10 min]');
ylabel('Velocidade [m/s]');

%Plotando WVHT

tamanho = length(wvht_vector);

figure;
hold on;

subsetIndices = 1:1:tamanho;
plot(subsetIndices, wvht_vector(subsetIndices),'.');

hold off;
legend('Altura das Ondas');
xlabel('t[10 min]');
ylabel('Altura [m]');

%Tarefa 7

%Pegando apenas os valores disponiveis
tam = 1:length(wspd_vector);
wspd_disponiveis = tam(~isnan(wspd_vector));

tam = 1:length(wvht_vector);
wvht_disponiveis = tam(~isnan(wvht_vector));

[mu_norm, sigma_norm] = normfit(wspd_disponiveis);


%Gerando histograma do WSPD
n = length(wspd_vector);
k = ceil(1 + 3.322 * log(n));

[Y, X] = hist(wspd_vector, k);

figure

%y_pdf = normpdf(wspd_disponiveis, mu_norm, sigma_norm);

hold on

bar(X, Y);

hold off
xlabel("Faixa de Velocidade [m/s]");
ylabel("Quantidade");
legend("y observado")

%Gerando histograma do WVHT
n = length(wvht_vector);
k = ceil(1 + 3.322 * log(n));

[Y, X] = hist(wvht_vector, k);

figure

hold on

bar(X, Y);

hold off
xlabel("Faixa de Altura [m]");
ylabel("Quantidade");
legend("y observado")

%Questao 8

%RSS = sum((y_pdf - Y).^2);

%printf("Residual Sum Of Squares normal = %f\n\n", RSS);


