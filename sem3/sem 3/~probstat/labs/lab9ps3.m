%pb no 2 
conf_level = input('conf level= ');    %1-alpha in (0,1)
alpha = 1 - conf_level;
X = [1.48 1.26 1.52 1.56 1.48 1.46 ...
1.30 1.28 1.43 1.43 1.55 1.57 ...
1.51 1.53 1.68 1.37 1.47 1.61 ...
1.49 1.43 1.64 1.51 1.60 1.65 ...
1.60 1.64 1.51 1.51 1.53 1.74];
n = length(X); %sample size
ssq = var(X); %sample variance

%Quantiles
q1 = chi2inv(alpha/2, n-1);
q2 = chi2inv(1-alpha/2, n-1);
%alternatively, by simetry, q2 = -q1  (not always)

ci1 = (n-1)*ssq/q2; %limits of ci
ci2 = (n-1)*ssq/q1;

fprintf('confidence interval for the population variance, sigma square: (%3.4f, %3.4f)\n', ci1,ci2)
fprintf('confidence interval for the population std dev, sigma square: (%3.4f, %3.4f)\n', sqrt(ci1), sqrt(ci2))
