%pb no 1 
conf_level = input('conf level= ');    %1-alpha in (0,1)
alpha = 1 - conf_level;
X = [7 7 4 5 9 9 ...
    4 12 8 1 8 7 ...   % sample data
    3 13 2 1 17 7 ...
    12 5 6 2 1 13 ...
    14 10 2 4 9 11 ...
    3 5 12 6 10 7];
sigma = 5; % case where sigma is known
n = length(X); %sample size
xbar = mean(X); %sample mean

%Quantiles
q1 = norminv(alpha/2, 0, 1);
q2 = norminv(1-alpha/2, 0, 1);
%alternatively, by simetry, q2 = -q1  (not always)

ci1 = xbar - sigma/sqrt(n) * q2; %limits of ci
ci2 = xbar - sigma/sqrt(n) * q1;

fprintf('confidence interval for the population mean, miu, case sigma known is: (%3.4f, %3.4f)\n', ci1,ci2)
