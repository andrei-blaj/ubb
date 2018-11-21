using System;
using System.Collections.Generic;
using System.Threading;
using ppd_lab1.Models;

namespace ppd_lab1 {
    internal class Program {
        public static void Main(string[] args) {

            var dt = DateTime.Now;
            
            var controller = new Controller {
                Inventory = new Dictionary<Item, int> {
                    {new Item("iMac Pro", 4999), 100},
                    {new Item("iPhone XS", 999), 1000},
                    {new Item("iPhone XS Max", 1099), 700},
                    {new Item("iPad Pro", 649), 400},
                    {new Item("Apple Watch", 399), 1000},
                    {new Item("MacBook Pro 15\"", 2799), 100},
                    {new Item("MacBook Pro 13\"", 1799), 150},
                }
            };
            
            controller.Start();
            SpinWait.SpinUntil(() => controller.finishedChecking);

            TimeSpan ts = DateTime.Now - dt;
            
            Console.Write(ts.TotalMilliseconds);
        }
    }
}