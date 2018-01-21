%Simulation of Bino(n, p) distr is the sum of n ind. Bern

n = input('nr of trials = ');
p = input('p(in(o,1))= ');
%gen 1 var
U = rand(n,1);
X = sum(U<p);
%generate a sample
N = input('No. of simualations= ');
for i = 1:N
    U = rand(n,1);
    X(i) = sum(U<p);
end

%Compare gaphically to Bino(n,p) distr
UX = unique(X); %only distinct values
nX = hist(X,length(UX)); %freq
relfr = nX/N; % rel freq

%True Bino(n,p) distr
k = 0:n; %values
pk = binopdf(k,n,p);
clf
plot(k,pk,'*',UX,relfr,'o','Markersize',10)
legend('Bino distr','Simulation')