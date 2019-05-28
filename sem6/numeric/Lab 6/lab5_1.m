time = [0, 3, 5, 8, 13];
distance = [0, 225, 383, 623, 993];
speed = [75, 77, 80, 74, 72];
point=10;

z=repelem(time,2);
distanceDup = repelem(distance, 2);
n=length(time);
m=zeros(2*n);
m(:,1) = distanceDup;
index = 1;
for i=1:2*n
    if(mod(i,2)~=0)
        m(i, 2) = speed((i+1)/2);
    else
        if(i~=2*n)
            m(i, 2) = (m(i+1, 1) - m(i, 1))/(z(i+1)-z(i));
        end
    end
end

for j = 3:2*n
    for i = 1:(2*n-j + 1)
        m(i, j) = (m(i + 1, j - 1) - m(i, j -1))/(z(i+j-1)-z(i));
    end
end

prod = 1;
sum = 0;
for i=1:2*n - 1
    prod = prod * (point - z(i));
    sum = sum + prod * m(1, i + 1);
end
distance(1) + sum
