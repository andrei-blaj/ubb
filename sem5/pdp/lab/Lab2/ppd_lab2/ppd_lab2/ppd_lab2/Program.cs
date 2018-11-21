using System;
using System.Collections.Generic;

namespace ppd_lab2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var a = Operations.randomize(10, 10);
            var b = Operations.randomize(10, 10);
            
            Console.WriteLine("\nA:");
            Operations.Print(a);
            
            Console.WriteLine("\nB:");
            Operations.Print(b);
            
            
            Console.WriteLine("\n A + B");
       
            var c = Operations.Add(a, b, 5);
            Operations.Print(c);
            
            Console.WriteLine("\n A x B");
            
            var d = Operations.Multiply(a, b, 5);
            Operations.Print(d);
        }
    }
}