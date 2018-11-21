using System;

namespace PPD_Lab4
{
    public class Lib
    {
        public static void initMatrix(Matrix<int> m, int value) {
            for (int i = 0; i < m.N; i++) {
                for (int j = 0; j < m.M; j++) {
                    m.set(i, j, value);
                }
            }
        }

        public static void printMatrix(Matrix<int> m) {
            for (int i = 0; i < m.N; i++) {
                for (int j = 0; j < m.M; j++) {
                    Console.Write(m.get(i, j));
                    Console.Write(' ');
                }
                Console.WriteLine();
            }
        }
    }
}