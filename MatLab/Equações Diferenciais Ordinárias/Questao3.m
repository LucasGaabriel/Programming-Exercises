function Questao3()
  ### Questao 3.1
  fprintf('\n### Questão 3.1 ###\n');
  ## Q_1
  syms V(t) t0 V0 Qin Qout;
  deltaQ = Qin - Qout;
  edo = diff(V(t), t) == deltaQ;
  cond = V(t0) == V0;

  fprintf('Solucao Analítica de V(t):\n');
  sol = dsolve(edo, cond)

  ## Q_2
  fprintf('\nVersao numerica da solucao de V(t):\n');
  yx = matlabFunction(sol)

  ## Q_3
  Vmax = 5000;  # Volume máximo
  t0 = 0;       # Valor inicial de t
  V0 = 2000;    # Volume inicial

  # a) Qin < Qout
  Qin = 45;    # Taxa de entrada
  Qout = 50;   # Taxa de saída
  SolveLinearFunction(yx, Qin, Qout, V0, t, t0, Vmax);

  # b) Qin > Qout
  Qin = 50;    # Taxa de entrada
  Qout = 45;   # Taxa de saída
  SolveLinearFunction(yx, Qin, Qout, V0, t, t0, Vmax);


  # c) Qin == Qout
  Qin = 50;    # Taxa de entrada
  Qout = 50;   # Taxa de saída
  SolveLinearFunction(yx, Qin, Qout, V0, t, t0, Vmax);

  ### Questao 3.2
  fprintf('\n### Questão 3.2 ###\n');
    
  ### Q_1
  ## Determinar a função V(t)
  syms V(t) t0 V0 Qin Qout;
  deltaQ = Qin - Qout;
  edo = diff(V(t), t) == deltaQ;
  cond = V(t0) == V0;
  
  sol = dsolve(edo, cond);

  
  ## Determinar a funcao c(t):
  syms c(t) Qin cin c0 V(t) m(t)
  ode = diff(c, t) == Qin*(cin-c)/sol;
  cond = c(0) == c0;
  fprintf('Solucao Analítica de c(t):\n');
  solC = dsolve(ode, cond)
  
  ### Q_2 - Montar m(t) = c(t)*V(t)
  syms m(t);
  
  m(t) = sol*solC;
  
  ### Q_3 - Converter c(t) e m(t) em numeric function
  fprintf('\nVersao numerica de V(t):\n');
  fun_V = matlabFunction(sol)
  fprintf('\nVersao numerica de c(t):\n');
  fun_c = matlabFunction(solC)
  fprintf('\nVersao numerica de m(t):\n');
  fun_m = matlabFunction(m(t))
  
  ### Q_4
  Vmax = 5000;
  t0 = 0;
  V0 = 2000;
  c0 = 0.05;
  cin = 2;
  
  # a) Qin = 40; Qout = 45
  Qin = 40;    # Taxa de entrada
  Qout = 45;   # Taxa de saída
  
  Plot_Questao3(fun_c, fun_m, Qin, Qout, V0, c0, cin, t, t0, Vmax, sol, yx);
  fprintf('\nCaso a) Qin == %.2f, Qout == %.2f\nEvento excepcional m(t) == V(t) == 0 em t == 400.00\n', Qin, Qout);
  
  # b) Qin = 40; Qout = 40
  Qin = 40;    # Taxa de entrada
  Qout = 40;   # Taxa de saída
  
  Plot_Questao3(fun_c, fun_m, Qin, Qout, V0, c0, cin, t, t0, Vmax, sol, yx);
  fprintf('\nCaso b) Qin == %.2f, Qout == %.2f\nConstancia de volume: V(t) = %.2f\nFuncao de concentracao c(t) tende a Cin: %.2f\nFuncao de matéria m(t)=V(t)*c(t) tende a V0*Cin: %.2f\n', Qin, Qout, V0, cin, V0*cin);
  
  # c) Qin = 45; Qout = 45
  Qin = 45;    # Taxa de entrada
  Qout = 45;   # Taxa de saída
  
  Plot_Questao3(fun_c, fun_m, Qin, Qout, V0, c0, cin, t, t0, Vmax, sol, yx);
  fprintf('\nCaso c) Qin == %.2f, Qout == %.2f\nConstancia de volume: V(t) = %.2f\nFuncao de concentracao c(t) tende a Cin: %.2f\nFuncao de matéria m(t)=V(t)*c(t) tende a V0*Cin: %.2f\n', Qin, Qout, V0, cin, V0*cin);