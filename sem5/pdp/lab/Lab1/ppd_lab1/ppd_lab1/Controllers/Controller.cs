using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using static System.Threading.Thread;

namespace ppd_lab1.Models {
    public class Controller {
        private const int delayUntilNext = 2000;

        private static readonly Random _random = new Random();

        public bool finishedChecking { get; set; }
        
        public Dictionary<Item, int> Inventory { get; set; } 
        
        public int Wallet { get; set; }
        
        public List<ItemList> Lists { get; set; }

        public void Start() {
            Lists = new List<ItemList>();

            Task.Run(() => CheckerFunc(delayUntilNext));

            for (var i = 1; i <= 10; i++) {
                Task.Run(() => WorkerFunc(i * 1000));
            }
        }
        
        private Dictionary<Item, int> PickRandomItems()  {
            var order = new Dictionary<Item, int>();

            foreach (var kvp in Inventory) {
                if (kvp.Value <= 0) continue;
                
                var count = _random.Next(0, kvp.Value + 1);
                if (count > 0) {
                    order.Add(kvp.Key, count);
                }
            }

            return order;
        }

        private int getSum() {
            var sum = 0;
          
            foreach (var order in Lists) {
                foreach (var kvp in order.Records) {
                    sum += kvp.Value * kvp.Key.Price;
                }
            }
                 
            return sum;
        }

        private void WorkerFunc(int delay) {
            while (true) {
                lock (Inventory) {
                    if (finishedChecking) return;
                    var order = PickRandomItems();
                    Console.WriteLine($"Worker thread id : {CurrentThread.ManagedThreadId}");

                    foreach (var kvp in order)
                    {
                        Wallet += kvp.Value * kvp.Key.Price;
                        Inventory[kvp.Key] -= kvp.Value;
                    }

                    var itemList = new ItemList(order);
                    Lists.Add(itemList);

                    Console.WriteLine(itemList);
                }

                Thread.Sleep(delay);
            }
        }


        private void CheckerFunc(int delay) {
            while (true) {
                lock (Inventory) {
                    Console.WriteLine($"Thread id : {CurrentThread.ManagedThreadId}");

                    finishedChecking = Wallet != getSum() || Inventory.All(kvp => kvp.Value <= 0);

                    Console.WriteLine($"Finished: {finishedChecking}");
                }

                Thread.Sleep(delay);
            }
        }
        

    }
}