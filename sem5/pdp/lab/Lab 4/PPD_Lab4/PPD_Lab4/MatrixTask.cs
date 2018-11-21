using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Numerics;
using System.Threading.Tasks;

namespace PPD_Lab4
{
    public class MatrixTask<T>
    {
        private class Trials {
            public Trials(int rowStart, int rowEnd) {
                RowStart = rowStart;
                RowEnd = rowEnd;
            }

            public int RowStart { get; }
            public int RowEnd { get; }
        }
        
        private class TaskInfo
        {

            public TaskInfo(Matrix<T> m1, Matrix<T> m2, Trials trials, Matrix<T> result)
            {
                M1 = m1;
                M2 = m2;
                Result = result;
                Trials = trials;
            }

            public Matrix<T> M1 { get; }

            public Matrix<T> M2 { get; }

            public Matrix<T> Result { get;}

            public Trials Trials { get;}
        }

        private readonly int _numTrials;

        private delegate Trials MatrixOperation(object info);
        
        public Matrix<T> computeSum(Matrix<T> m1, Matrix<T> m2, Matrix<T> m3)
        {
            Debug.Assert(m1.N == m2.N);
            Debug.Assert(m1.M == m2.M);
            
            var sumMatrix = new Matrix<T>(m1.N, m1.M);
            
            Solve(getTrialSum, m1, m2, m3, sumMatrix);
            
            return sumMatrix;
        }
        
        public Matrix<T> computeProduct(Matrix<T> m1, Matrix<T> m2, Matrix<T> m3)
        {
            Debug.Assert(m1.M == m2.N);
            Debug.Assert(m1.M == m3.N);
            
            var productMatrix = new Matrix<T>(m1.M, m3.N);
            
            Solve(getTrialProduct, m1, m2, m3, productMatrix);
            
            return productMatrix;
        }
        
        public MatrixTask(int numTrials)
        {
            _numTrials = numTrials;
        }

        private static IEnumerable<Trials> getTrials(int rows, int trialSize)
        {
            var trials = new List<Trials>();
            var rowsPerThread = rows / trialSize;
            int start = 0;

            for(var i = 0; i < trialSize; i++) 
            {
                trials.Add(new Trials(start, start + rowsPerThread));
                start+=rowsPerThread;
            }

            if (rows % trialSize == 0) return trials;
            
            var lastTrial = trials[(int) trialSize - 1];
            
            trials[(int)trialSize - 1] = new Trials(lastTrial.RowStart, rows);

            return trials;
        }
        
        private void Solve(MatrixOperation operation, Matrix<T> m1, Matrix<T> m2, Matrix<T> m3, Matrix<T> result)
        {
            var trials = getTrials(m1.N, _numTrials);
            
            var firstResult = new Matrix<T>(m1.M, m2.N);

            var tasks = trials
                .Select(trial => new TaskInfo(m1, m2, trial, firstResult))
                .Select(taskInfo => new Task<Trials>(() => operation(taskInfo)))
                .ToList();

            var continuation = tasks.Select((task) =>
                task.ContinueWith((t) => operation(new TaskInfo(firstResult, m3, t.Result, result)))).ToList();
            
            tasks.ForEach((task) => task.Start());
            
            Task.WaitAll(continuation.ToArray());
        }

        private static Trials getTrialSum(object info)
        {
            Debug.Assert(info != null);
            
            var th = info as TaskInfo;
            
            Debug.Assert(th != null);
            
            for(var i = th.Trials.RowStart; i < th.Trials.RowEnd; i++) {
                for (int j = 0; j < th.M1.M; j++) {
                    th.Result.set(i, j, Operation.add(th.M1.get(i, j), th.M2.get(i ,j)));
                }
            }

            return th.Trials;
        }

        private static Trials getTrialProduct(object info)
        {
            Debug.Assert(info != null);
            
            var th = info as TaskInfo;
            
            Debug.Assert(th != null);
            
            for(var i = th.Trials.RowStart; i < th.Trials.RowEnd; i++) 
            {
                for (int j = 0; j < th.M2.M; j++)
                {
                    var res = default(T);
                    
                    for (int k = 0; k < th.M1.M; k++)
                    {
                        res = Operation.add(res, Operation.mul(th.M1.get(i, k), th.M2.get(k, j)));
                    }
                    
                    th.Result.set(i , j, res);
                }
            }

            return th.Trials;
        }
    }
}