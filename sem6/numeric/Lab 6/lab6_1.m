% pb. 1 a)
x = [0, pi / 2, pi, (3 * pi) / 2, 2 * pi];
y = [0, 1, 0, -1, 0];

t = spline(x, [1, y, 1]);
ppval(t, pi / 4)
t1 = spline(x, y);
ppval(t1, pi / 4)

% pb. 1 b)
hold on
plot(x,y,'*g')
fplot(@(X) ppval(t, X), [0, 2 * pi])
fplot(@(X) ppval(t1, X), [0, 2 * pi])
hold off
