alpha = input('sign level = ');  %alpha in (0,1)
X = [7 7 4 5 9 9 ...
    4 12 8 1 8 7 ...   % sample data
    3 13 2 1 17 7 ...
    12 5 6 2 1 13 ...
    14 10 2 4 9 11 ...
    3 5 12 6 10 7];
sigma = 5; % sigma known
miu0 = 9; % test value
fprintf('H0: miu = 9 (miu >= miu0) \n')
fprintf('H1: miu < miu0 (left tailed) \n')

%TS = Z -> normal std. distr.
% a Z-test -> ztest Matlab command
tail = -1;
[h,p,ci,zval]=ztest(X,miu0,sigma,alpha,tail);
if h==0
    fprintf('H0 is not rej, the efficiency standard is achieved. \n')
else
    fprintf('H0 is rej,the efficiency standard is not achieved. \n')
end

fprintf('Observed value of the test is %3.4f\n', zval)
fprintf('F value is %3.4f\n', p);

q1 = norminv(alpha,0,1);
fprintf('Rej. region RR is (-inf, %3.4f)\n',q1)

%b) 
v0 = 25
fprintf('H0: sigma = 5 <=> sigma^2 = 25 \n')
fprintf('H1: sigma != 5 <=> sigma^2 != 25 \n')
[h,p,ci,stat]=vartest(X,v0,alpha);

if h==0
    fprintf('H0 is not rej, the assumption is correct. \n')
else
    fprintf('H0 is rej,the assumption is incorrect. \n')
end

fprintf('Observed value of the test is %3.4f\n', stat.chisqstat)
fprintf('F value is %3.4f\n', p);

q2 = chi2inv(alpha/2,stat.df);
q3 = chi2inv(1 - alpha/2,stat.df);
fprintf('Rej. region RR is (-inf, %3.4f) U (%3.4f, inf) (\n',q2, q3)
