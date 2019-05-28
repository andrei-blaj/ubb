%ex 3
x= [0, 10, 20, 30, 40, 60, 80, 100];
y= [0.0061,  0.0123, 0.0234, 0.0424, 0.0738, 0.1992, 0.4736, 1.0133];

polyfit(x,y,45);

hold on
fplot(@(X) polyval(polyfit(x,y,2),X),[0,100])
plot(x, y,'*r')
hold off
