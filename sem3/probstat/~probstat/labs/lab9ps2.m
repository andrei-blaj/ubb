%pb no 2 
conf_level = input('conf level= ');    %1-alpha in (0,1)
alpha = 1 - conf_level;
X = [99.8*ones(1,2),99.9*ones(1,5), 98.0*ones(1,3), 100.1*ones(1,4),100.5*ones(1,2),100.0*ones(1,2),100.2*ones(1,2)];
s = std(X); %case where sigma is unknown
n = length(X); %sample size
xbar = mean(X); %sample mean

%Quantiles
q1 = tinv(alpha/2, n-1);
q2 = tinv(1-alpha/2, n-1);
%alternatively, by simetry, q2 = -q1  (not always)

ci1 = xbar - s/sqrt(n) * q2; %limits of ci
ci2 = xbar - s/sqrt(n) * q1;

fprintf('confidence interval for the population mean, miu, case sigma unknown is: (%3.4f, %3.4f)\n', ci1,ci2)
