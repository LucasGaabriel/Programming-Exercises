# Aproximação de EDO por método de Euler
# f é a Equacao diferencial
function [X, Y] = Euler(f, x0, y0, h, n )
  % Initialize arrays to store the values
  X = zeros(1,n+1); 
  Y = zeros(1,n+1);

  % Set initial values
  X(1) = x0;
  Y(1) = y0;

  % Euler's method
  for i = 1:n
      Y(i+1) = Y(i) + h * f(X(i), Y(i));
      X(i+1) = X(i) + h;
  end

  % Plot the solution
  #plot(X, Y, '-o');
  #xlabel('x');
  #ylabel('y');
  #title('Approximate Solution using Euler''s Method');
