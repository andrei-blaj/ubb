target = 1955;

x = [1930 1940 1950 1960 1970 1980];
f = [123203 131669 150697 179323 203212 226505];

function z = A(i, x)
   res = 1;
   for k = 1:length(x)
     if k ~= i
       res = res .* (x(i) - x(k));
     end
   end
   z = 1 ./ res;
end

d = 0;

for j = 1:length(x)
  d = d + (A(j, x) .* f(j)) ./ (target - x(j));
end

k = 0;

for j = 1:length(x)
  k = k + A(j, x) ./ (target - x(j));
end

fprintf("Populatia in %d este %f\n", target, d / k);
