%Simulation of Geo(p) 
%Geo distr is the number of failures before the occurence of the first
%succes

p = input('p(in(o,1))= ');
%gen 1 var
X=0; %initialize the number of failures with 0
while rand>=p
    X = X+1;   %counting no of failures
end            %while stops at first succes
%generate a sample
N = input('No. of simualations= ');

for i = 1:N
    X(i)=0; 
    while rand>=p
        X(i) = X(i)+1;   
    end 
end

%Compare gaphically to Bino(n,p) distr
UX = unique(X); %only distinct values
nX = hist(X,length(UX)); %freq
relfr = nX/N; % rel freq

%True Geo(p) distr
k = 0:50; %relevant values
pk = geopdf(k,p);
clf
plot(k,pk,'*',UX,relfr,'o','Markersize',10)
legend('Geo distr','Simulation')