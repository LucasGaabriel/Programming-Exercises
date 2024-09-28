function [X,Y] = RalstonFourthOrder(f, x0, y0, h, n )

    butcher.isEmbedded = false;
    s = 4;
    butcher.a = zeros(s,s);
    butcher.a(2,1) = 0.4;
    butcher.a(3,1) = 0.29697761; butcher.a(3,2) = 0.15875964;
    butcher.a(4,1) = 0.21810040; butcher.a(4,2) = -3.05096516; butcher.a(4,3) = 3.83286476;
    butcher.b = [0.17476028 -0.55148066 1.20553560 0.17118478];
    butcher.c = [0 0.4 0.45573725 1];

    [X,Y,~] = RungeKutta(f, x0, y0, h, n, butcher, s );

end
