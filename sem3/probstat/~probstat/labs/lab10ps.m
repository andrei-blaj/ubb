conf_level = input('conf level = '); % 1-alpha in (0,1)
alpha = 1 - conf_level;
X1 = [22.4, 21.7, 24.5, 23.4, 21.6, 23.3, 22.4, 21.6, 24.8, 20.0];
X2 = [17.7, 14.8, 19.6, 19.6, 12.1, 14.8, 15.4, 12.6, 14.0, 12.2];

xb1 = mean(X1);
xb2 = mean(X2);  %the 2 samples

s12 = var(X1);  %sample means
s22 = var(X2);

n1 = length(X1);  %sample var's
n2 = length(X2);

%a)
sp2 = ((n1 - 1)* s12 + (n2-1)*s22)/(n1+n2-2);
%q1 = tinv(alpha/2, n1 + n2 -2);
%q2 = tinv(1 - alpha/2, n1 + n2 -2);
%q2 = -q1;
%ci1 = xb1 - xb2 - sqrt(sp2) * q2 * sqrt(1/n1 + 1/n2);
%ci2 = xb1 - xb2 - sqrt(sp2) * q1 * sqrt(1/n1 + 1/n2);
%fprintf('C.I. for the diff of means, case sigma1 = sigma2, is (%3.4f, %3.4f) \n',ci1,ci2);

%b)
c = (s12/n1) / (s12 / n1 + s22/n2);
n = 1/ ((c^2/(n1-1)) + (1-c)^2/(n2 -1));
q1 = tinv(alpha / 2, n);
q2 = -q1;
ci1 = xb1 - xb2 -  q2 * sqrt(s12/n1 + s22/n2);
ci2 = xb1 - xb2 -  q1 * sqrt(s12/n1 + s22/n2);
fprintf('C.I. for the diff of means, case sigma1 = sigma2, is (%3.4f, %3.4f) \n',ci1,ci2);

%c)
f1 = finv(alpha / 2, n1-1, n2-1);
f2 = finv(1-alpha/2, n1-1,n2-1);
ci1 = 1/f2 * (s12/s22);
ci2 = 1/f1 * (s12 / s22);
fprintf('C.I. for the ratio of std derivation, case sigma1 = sigma2, is (%3.4f, %3.4f) \n',ci1,ci2);
