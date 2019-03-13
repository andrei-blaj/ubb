x0 = 0;
f = exp(x);
x = -1:0.01:3;
p1 = 1;
n = 6;

% for k = 0:n
% sum = p1 + (x  - x0).^k/factorial(k).* f;
% plot(x, sum, '-g');
% hold on
% p1 = sum;
% end

prod = 1;
for k = 1:n
    new_prod = prod * k;
    sum = p1 + (x  - x0).^k/new_prod.* f;
    plot(x, sum, '-g');
    hold on
    p1 = sum;
    prod = k_new;
end
hold off
