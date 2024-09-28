function [X, Y, YLow] = RungeKutta_Dormand_Prince_MButcher(f, x0, y0, h, n )

    s = 7;
    butcher.isEmbedded = true;
    butcher.a = zeros(s,s);
    butcher.a(2,1) = 1/5;
    butcher.a(3,1) = 3/40; butcher.a(3,2) = 9/40;
    butcher.a(4,1) = 44/45; butcher.a(4,2) = -56/15; butcher.a(4,3) = 32/9;
    butcher.a(5,1) = 19372/6561; butcher.a(5,2) = -25360/2187; butcher.a(5,3) = 64448/6561; butcher.a(5,4) = -212/729;
    butcher.a(6,1) = 9017/3168; butcher.a(6,2) = -355/33; butcher.a(6,3) = 46732/5247; butcher.a(6,4) = 49/176; butcher.a(6,5) = -5103/18656;
    butcher.a(7,1) = 35/384; butcher.a(7,3) = 500/1113; butcher.a(7,4) = 125/192; butcher.a(7,5) = -2187/6784; butcher.a(7,6) = 11/84;

    butcher.b = [35/384 0 500/1113 125/192 -2187/6784 11/84 0];
    butcher.bstar = [5179/57600 0 7571/16695 393/640 -92097/339200 187/2100 1/40];
    butcher.c = [0 1/5 3/10 4/5 8/9 1 1];

    [X, Y, YLow] = RungeKutta(f, x0, y0, h, n, butcher, s );
end
