t = -1:0.01:1;
T1 = cos(acos(t));
T2 = cos(2*acos(t));
T3 = cos(3*acos(t));
plot(t, T1, '*r', t, T2, '-g', t, T3, '.b');

T0 = 1;
T1 = t;
plot(t, T0, '-g');
hold on
plot(t, T1, '*r');
hold on

for i = 3:10
T = 2.*t.*T1 - T0;
plot(t, T, '.b');
hold on
T0 = T1;
T1 = T;
end
hold off
