using System.Diagnostics;
using System;

namespace PPD_Lab4
{
    public class Matrix<T>
    {
        private readonly T[,] _data;

        public Matrix(int n, int m)
        {
            N = n;
            M = m;
            _data = new T[n, m];
        }

        public int N { get; }

        public int M { get; }

        public T get(int n, int m)
        {
            Debug.Assert(n < N);
            Debug.Assert(m < M);
            
            return _data[n, m];
        }

        public void set(int n, int m, T value)
        {
            Debug.Assert(n < N);
            Debug.Assert(m < M);
            
            _data[n, m] = value;
        }
        
    }
}