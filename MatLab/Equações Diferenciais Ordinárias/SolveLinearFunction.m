function SolveLinearFunction(yx, Qin, Qout, V0, t, t0, Vmax)
  strLeg = 'V(t)';
  
  if Qin < Qout
      solve = fsolve(@(t) yx(Qin, Qout, V0, t, t0), t0);
      fprintf('\nCaso a) Qin == %.2f, Qout == %.2f\nEvento excepcional em tempo = %.2f\n', Qin, Qout, solve);
      Xsup = solve;
  else if Qin > Qout
      solve = fsolve(@(t) yx(Qin, Qout, V0-Vmax, t, t0), t0);
      fprintf('\nCaso b) Qin == %.2f, Qout == %.2f\nEvento excepcional em %.2f\n', Qin, Qout, solve);
      Xsup = solve;
  else
      fprintf('\nCaso c) Qin == %.2f, Qout == %.2f\nConstancia de volume: V(t) == V(0) == %.2f\n\n', Qin, Qout, V0);
      Xsup = 500;
      strLeg = sprintf('V(t)=V0=%.2f L', V0);
  endif
  endif

  ax = [t0 Xsup+1 0 Vmax];
  
  t = t0 : 1 : 800;
  
  fontsize = 16;
  leg = {};

  figure;
  hold all;

  plot(t, yx(Qin, Qout, V0, t, t0), 'r-');
  line ('xdata',[0,Xsup], 'ydata',[V0,V0], 'linestyle', '--', 'color', 'b', "linewidth", 1.5);
  line ('xdata',[0,Xsup], 'ydata',[Vmax,Vmax], 'linestyle', '--', 'color', 'c', "linewidth", 1.5);
  
  leg{end+1} = sprintf('V0=%.2f L', V0);
  leg{end+1} = strLeg;
  leg{end+1} = sprintf('Vmax=5000.00 L', Vmax);
  if Qin > Qout
    line ('xdata',[Xsup,Xsup], 'ydata',[0,Vmax], 'linestyle', ':', 'color', 'r', "linewidth", 1.5);
    leg{end+1} = 'Transbordagem do tanque';
  else if Qin < Qout
    line ('xdata',[Xsup,Xsup], 'ydata',[0,Vmax], 'linestyle', ':', 'color', 'r', "linewidth", 1.5);
    leg{end+1} = 'Vazamento completo do tanque';  
  end
  end
  
  # Apresenta legenda
  h = legend(leg);
  set (h, 'fontsize', fontsize, 'location', 'east');
  hold off;
  shg;
  
  axis(ax);
  
  
  
  