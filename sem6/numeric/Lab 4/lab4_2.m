%v = [4 8 14 16];
%v0 = [2 4 6 8];
%m = zeros(length(v0));
%m(:, 1) = v';
%n = length(v0);
%for j = 2:n
%  for i = 1:n-j+1
%    m(i, j) = (m(i+1, j-1) - m(i, j-1))/(v0(i+j-1) -v0(i));
%  end
%end
%m
%
%v0 = [1 1.5 2 3 4];
%v = [0 0.17609 0.30103 0.47712 0.60206];
%
%function z =  Fct(v,v0)
%    m = zeros(length(v0));
%    m(:,1) = v';
%    n = length(v0);
%    for j = 2:n
%        for i = 1:n-j
%            m(i,j) = (m(i+1, j-1) - m(i,j-1))/(v0(i+j-1)-v0(i));
%        end
%    end
%    z = m;
%end
%
%function Lmf =  Fct1(m,v,v0, point)
%    fx0=v(1);
%    m0 = 1;
%    sum = 0;
%    mm = length(v0);
%    while m0 <= mm
%        prod = 1;
%        i = 1;
%        while i <= m0
%            prod = prod * (point - v0(i));
%            i = i + 1;
%        end
%        m0 = m0+1;
%        prod = prod * m(1,i-1);
%        sum = sum+prod;
%    end
%    Lmf = fx0 + sum;
%end
%
%m = Fct(v,v0);
%sol = Fct1(m,v,v0,2.5);
%sol
%max = 0;
%for i = 10:1:35
%    y = i/10;
%    a = abs(log(y)-Fct1(m,v,v0,y));
%    if a > max
%        max = a;
%    end
%end
%max


v0 = [1 1.5 2 3 4];
v = [0 0.17609 0.30103 0.47712 0.60206];

function z =  Fct(v,v0)
    m = zeros(length(v0));
    m(:,1) = v';
    n = length(v0);
    for j = 2:n
        for i = 1:n-j
            m(i,j) = (m(i+1, j-1) - m(i,j-1))/(v0(i+j-1)-v0(i));
        end
    end
    z = m(1,2:end);
end

function Lmf =  Fct1(m,v,v0, point)
    fx0=v(1);
    m0 = 1;
    sum = 0;
    mm = length(v0)-1;
    while m0 <= mm
        prod = 1;
        i = 1;
        while i <= m0
            prod = prod * (point - v0(i));
            i = i + 1;
        end
        m0 = m0+1;
        prod = prod * m(1,i-1);
        sum = sum+prod;
    end
    Lmf = fx0 + sum;
end

m = Fct(v,v0);
sol = Fct1(m,v,v0,2.5);
sol
 max = 0;
 for i = 10:1:35
     y = i/10;
     a = abs(log(y)-Fct1(m,v,v0,y));
     if a > max
         max = a;
     end
 end
 max

 for i=1:0.01:5
    plot(i,Fct1(m,v,v0, i),'*r')
    hold on
end
