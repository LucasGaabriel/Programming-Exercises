function [X,Y] = VanDerHouwenWray(f, x0, y0, h, n )

    butcher.isEmbedded = false;
    s = 3;
    butcher.a = zeros(s,s);
    butcher.a(2,1) = 8/15;
    butcher.a(3,1) = 1/4; butcher.a(3,2) = 5/12;
    butcher.b = [1/4 0 3/4];
    butcher.c = [0 8/15 2/3];

    [X,Y,~] = RungeKutta(f, x0, y0, h, n, butcher, s );

endfunction
