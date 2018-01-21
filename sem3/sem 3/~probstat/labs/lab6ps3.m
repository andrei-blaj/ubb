%Simulation of Nbin(n, p) distr 
%Nbin distr is the sum of n ind Geo(p) variables
n = input('rank of succes = ');
p = input('p(in(o,1))= ');
%gen 1 var
for j = 1:n
    Y(j)=0;
    while rand>=p
        Y(j)=Y(j)+1;
    end
end
X = sum(Y);
%generate a sample
N = input('No. of simualations= ');
for i = 1:N
    for j = 1:n
        Y(j)=0;
        while rand>=p
            Y(j)=Y(j)+1;
        end
    end
    X(i) = sum(Y);
end

%Compare gaphically to Bino(n,p) distr
UX = unique(X); %only distinct values
nX = hist(X,length(UX)); %freq
relfr = nX/N; % rel freq

%True Bino(n,p) distr
k = 0:50; %values
pk = nbinpdf(k,n,p);
clf
plot(k,pk,'*',UX,relfr,'o','Markersize',10)
legend('Nbin distr','Simulation')