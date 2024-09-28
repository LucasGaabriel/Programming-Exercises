function Questao2()
  syms y(x);

  warning('off');

  ##fprintf("##### Solucao da Especificacao\n");
  ##f = @(x,y) (sin(x)/(x*x)-3*y)/x;
  ##edostr = 'Solucao da Especificacao';
  ##x0 = pi; y0 = 1; h = 1; n = 5;
  ##ode = diff(y, x) == (sin(x)/(x*x)-3*y)/x;
  ##SolveEDOMethods(f, edostr, x0, y0, h, n, ode);


  fprintf("##### Letra A\n");
  f = @(x,y) 1.0 / exp(x) - 2.0*y;
  edostr = 'PVI: dy/dx = 1/e^x - 2y, y(0)=1 --- Solução: y(x) = exp(-x)';
  x0 = 0; y0 = 1; h = 0.5; n = 5;
  ode = exp(x) * diff(y, x) + 2*exp(x) * y == 1;
  SolveEDOMethods(f, edostr, x0, y0, h, n, ode);


  fprintf("##### Letra B\n");
  f = @(x,y) sin(x)/x^3 - 3*y/x;
  edostr = 'PVI: dy/dx = sin(x)/x^3 - 3y/x, y(pi)=1 --- Solução: (-cos (x) - 1 + pi^3) / x^3';
  x0 = pi; y0 = 1; h = 1.0; n = 5;
  ode = x*diff(y, x)+3*y == sin(x)/x^2;
  SolveEDOMethods(f, edostr, x0, y0, h, n, ode);


  fprintf("##### Letra C\n");
  f = @(x,y) cos(x)^2-tan(x)*y;
  edostr = 'PVI: dy/dx = cos(x)^2-tan(x)y, y(pi/8)=1 --- Solução: (sin(x)- 3*sqrt(2)*sqrt(sqrt(2)+2)/2+5*sqrt(sqrt(2)+2)/2)*cos(x)';
  x0 = pi/8; y0 = 1; h = pi/16; n = 5;
  ode = diff(y, x)+tan(x)*y == cos(x)^2;
  SolveEDOMethods(f, edostr, x0, y0, h, n, ode);


  fprintf("##### Letra D\n");
  f = @(x,y) (1 - 1/x - 2*y)/x;
  edostr = 'PVI: dy/dx = (1 - 1/x - 2*y)/x, y(1)=1 --- Solução: (x^2/2-x+3/2)/x^2';
  x0 = 1; y0 = 1; h = 0.1; n = 5;
  ode = x*diff(y, x) + 2*y == 1-1/x;
  SolveEDOMethods(f, edostr, x0, y0, h, n, ode);

endfunction
