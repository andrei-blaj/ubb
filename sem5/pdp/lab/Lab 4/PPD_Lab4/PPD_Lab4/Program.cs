using System;
using System.Diagnostics;

namespace PPD_Lab4
{
    class Program
    {
        private const int noOfThreads = 2;
        private const int N = 4;
        
        static void Main(string[] args) {
            var matrixTask = new MatrixTask<int>(noOfThreads);
            
            var m1 = new Matrix<int>(N, N);
            var m2 = new Matrix<int>(N, N);
            var m3 = new Matrix<int>(N, N);
            
            Lib.initMatrix(m1, 1);
            Lib.initMatrix(m2, 1);
            Lib.initMatrix(m3, 1);
            
            Lib.printMatrix(m1);
            Console.WriteLine();
             Lib.printMatrix(m2);
             Console.WriteLine();
             Lib.printMatrix(m3);
             Console.WriteLine();
             
             var sumResult = matrixTask.computeSum(m1, m2, m3);
             
             Lib.printMatrix(sumResult);
             
             var productResult = matrixTask.computeProduct(m1, m2, m3);
             
             Lib.printMatrix(productResult);
         }
     }
 }