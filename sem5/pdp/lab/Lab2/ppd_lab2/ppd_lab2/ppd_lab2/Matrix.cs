using System.Collections.Generic;

namespace ppd_lab2
{
    public class Matrix<T>
    {
        public Matrix(int n, int m)
        {
            N = n;
            M = m;

            Items = new List<List<T>>();
            for (int i = 0; i < N; i++)
            {
                Items.Add(new List<T>(M));
            }
        }
        
        public int N { get; }
        
        public int M { get; }

        public List<List<T>> Items { get; }

        public T this[int i, int j]
        {
            get { return Items[i][j]; }
            set { Items[i][j] = value; }
        }

    }
}