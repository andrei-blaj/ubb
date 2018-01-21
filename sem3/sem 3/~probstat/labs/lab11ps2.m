alpha = input('sign level = ');  %alpha in (0,1)

X = [99.8*ones(1,2),99.9*ones(1,5), 98.0*ones(1,3), 100.1*ones(1,4),100.5*ones(1,2),100.0*ones(1,2),100.2*ones(1,2)];

miu0 = 99.4; % test value

fprintf('H0: miu = 99.4 (miu <= miu0) \n')
fprintf('H1: miu > miu0 (left tailed) \n')

%TS = T -> student distr. N(0,1)
% a T-test -> ttest Matlab command

tail = 1;

[h,p,ci,stats]=ttest(X,miu0,alpha,tail);

if h==0
    fprintf('H0 is not rej, the energy bars are bought. \n')
else
    fprintf('H0 is rej, the energy bars are not bought. \n')
end

fprintf('Observed value of the test statistic is %3.4f\n', stats.tstat)
fprintf('P value is %3.4f\n', p);

q1 = tinv(1-alpha, stats.df);
fprintf('Rej. region RR is (%3.4f, inf)\n',q1)
