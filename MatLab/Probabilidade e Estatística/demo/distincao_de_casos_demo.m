

% Definição de duas funções: seno e cosseno
f1 = @(x) sin(x);
f2 = @(x) cos(x);

% O objetivo é calcular o valor absoluto de
% uma função, sem usar a fução do sistema 'abs'


sinabs = @(t) ifelse(sin(t) >= 0, ...
                    sin(t),
                    -sin(t)
              );



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%       G R Á F I C O    %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



% Eixo x como vetor de valores discretos entre -pi e pi com intervalo de 0.01
% A divisão é mais fina para evitar curvas não suaves
t = -pi:0.01:pi;

clf;  % Limpa gráfico
legenda = {};   % Inicializa célula que contém os rótulos dos objetos gráficos
hold on

plot(t, sin(t), '--r', 'linewidth', 1);
legenda{end+1} = 'sen(x)';    % Insere rótulo no final das células dos rótulos

plot(t, sinabs(t), '.g', 'linewidth', 1);
legenda{end+1} = '|sin(t)|';    % Insere rótulo no final das células dos rótulos

xlabel('t');
ylabel('sen(t), |sen(t)|');
title('Demostração de distinção de casos')
legend(legenda, 'location', 'northeast');
hold off
shg;  % Mostre gráfico
