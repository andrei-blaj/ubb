h = 0.25;
a = 1;
x = a:h:a+6.*h
m = zeros(7, 7);
m(:,1) = sqrt(5.*x.^2+1);

for j = 2:n+1
    for i = 1:n-j+2
        m(i,j) = m(i+1, j-1) - m(i, j-1);
    end
end

m
