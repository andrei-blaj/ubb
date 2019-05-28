% pb. 2
time = [1 2 3 4 5 6 7];
time_square = [1 4 9 16 25 36 49];
temp = [13 15 20 14 15 13 10];

m = length(time) - 1;

a = (m + 1) .* sum(time .* temp) - sum(time) .* sum(temp);
a = a ./ ((m + 1) .* sum(time_square) - sum(time) .^ 2)
b = (sum(time_square) .* sum(temp) - sum(time .* temp));
b = b / ((m + 1) .* sum(time_square) - sum(time) .^ 2)

x = 1:1:7;
y = a .* x + b;

hold on
plot(x, y, 'b');
plot(time, y, '*r');
plot(temp, y, '*g');
