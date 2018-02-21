%simulation of Bern(p) distr
%Parameters

p = input('p(in(0,1))= ');
%generate 1 var
U = rand;
X = (U<p);
%generate a sample
N = input('No. of simualations= ');
for i = 1:N
    U = rand;
    X(i) = (U<p);
end

%X

%Compare to true Bern(p) distr.
UX = unique(X); %only distinct values
nX = hist(X,length(UX)); %freq
relfr = nX/N % rel freq