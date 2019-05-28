v = [4 8 14 16];
v0 = [2 4 6 8];

m = zeros(length(v0));
m(:, 1) = v';

n = length(v0);

for j = 2:n
  for i = 1:n-j+1
    m(i, j) = (m(i + 1, j - 1) - m(i, j - 1)) / (v0(i + j - 1) - v0(i));
  end
end
m
