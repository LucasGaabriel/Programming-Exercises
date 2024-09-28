function Questao3_2()    
  pkg load symbolic;
    
  ### Q_1
  ## Determinar a função V(t)
  syms V(t) t0 V0 Qin Qout
  deltaQ = Qin - Qout;
  edo = diff(V(t), t) == deltaQ;
  cond = V(t0) == V0;
  
  fprintf('Solucao:\n');
  #sol = dsolve(edo, cond)
  
  fprintf('\nVersao numerica da solucao:\n');
  #yx = matlabFunction(sol)
  
  ## Determinar a funcao c(t):
  syms c(t) Qin cin c0 V(t) m(t)
    
  ode = diff(c, t) == Qin*(cin-c)/sol;
  cond = c(0) == c0;
  
  solC = dsolve(ode, cond);
  #disp('Solução Analítica: i(t): EDO='); solC
  
  ### Q_2 - Montar m(t) = c(t)*V(t)
  syms m(t);
  
  m(t) = sol*solC;
  
  ### Q_3 - Converter c(t) e m(t) em numeric function
  fun_c = matlabFunction(solC);
  fun_m = matlabFunction(m(t));
  
  ### Q_4
  Vmax = 5000;
  t0 = 0;
  V0 = 2000;
  c0 = 0.05;
  cin = 2;
  
  # a) Qin < Qout
  Qin = 40;    # Taxa de entrada
  Qout = 45;   # Taxa de saída
  
  Plot_Questao3(fun_c, fun_m, Qin, Qout, V0, c0, cin, t, t0, Vmax);
  
  # Qin == Qout
  Qin = 40;    # Taxa de entrada
  Qout = 40;   # Taxa de saída
  
  #Plot_Questao_3(fun_c, fun_m, Qin, Qout, V0, c0, cin, t, t0);
  
  # a) Qin > Qout
  Qin = 45;    # Taxa de entrada
  Qout = 45;   # Taxa de saída
  
  #Plot_Questao_3(fun_c, fun_m, Qin, Qout, V0, c0, cin, t, t0);