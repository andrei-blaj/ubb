using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;

namespace ppd_lab2
{
    public static class Operations
    {
        public static void Print(Matrix<int> a)
        {
            a.Items.ForEach(line =>
            {
                line.ForEach(item => Console.Write(item + " "));
                Console.WriteLine();
            });
        }
        
        public static Matrix<int> Multiply(Matrix<int> a, Matrix<int> b, int threadCount)
        {
            var threads = new List<Task>();

            var result = new Matrix<int>(a.N, a.N);


            for (var i = 0; i < a.N; i++)
            {
                var line = i;
                var threadIndex = line % threadCount;
                
                if (threads.Count <= threadIndex)
                {
                    threads.Add(new Task(() => lineMultiplication(a, b, result, line)));
                }
                else
                {
                    threads.Add(threads[threadIndex].ContinueWith(x => lineMultiplication(a, b, result, line)));
                }
            }

            for (var i = 0; i < threadCount; i++)
            {
                threads[i].Start();
            }
            
            threads.ForEach(thread => thread.Wait());

            return result;
        }
        
        public static Matrix<int> Add(Matrix<int> a, Matrix<int> b, int threadCount)
        {
            var threads = new List<Task>();

            var result = new Matrix<int>(a.M, b.N);


            for (var i = 0; i < a.N; i++)
            {
                var line = i;
                var threadIndex = line % threadCount;
                
                if (threads.Count <= threadIndex)
                {
                    threads.Add(new Task(() => lineSum(a, b, result, line)));
                }
                else
                {
                    threads.Add(threads[threadIndex].ContinueWith(x => lineSum(a, b, result, line)));
                }
            }

            for (var i = 0; i < threadCount; i++)
            {
                threads[i].Start();
            }
            
            threads.ForEach(thread => thread.Wait());

            return result;
        }

        public static void lineSum(Matrix<int> a, Matrix<int> b, Matrix<int> result, int line)
        {
            for (int i = 0; i < a.N; i++)
            {
                result.Items[line].Add(a.Items[line][i] + b.Items[line][i]);
            }
        }

        public static void lineMultiplication(Matrix<int> a, Matrix<int> b, Matrix<int> result, int line)
        {
            for (int i = 0; i < a.M; i++)
            {
                result.Items[line].Add(0);
                for (int j = 0; j < b.N; j++)
                {
                    result.Items[line][i] += a.Items[line][j] * b.Items[j][i];
                }
            }
        }

        public static Matrix<int> randomize(int n, int m)
        {
            var matrix = new Matrix<int>(n, m);
            var rand = new Random();
            foreach (var line in matrix.Items)
            {
                for (int j = 0; j < m; j++)
                {
                    line.Add(rand.Next(1, 10));
                }
            }

            return matrix;
        }
    }
}