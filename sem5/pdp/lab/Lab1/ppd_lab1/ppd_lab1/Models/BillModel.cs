using System;
using System.Collections.Generic;
using System.Net.Configuration;

namespace ppd_lab1.Models
{
    public class BillModel
    {
        public BillModel(Dictionary<Item, int> records)
        {
            Records = records;
        }
        
        public Dictionary<Item, int> Records { get; }

        public override string ToString()
        {
            var str = "Product Name | Price | Inventory Count \n";
            
            foreach (var kvp in Records)
            {
                str += $"{kvp.Key.Name} | {kvp.Key.Price} | {kvp.Value}\n";
            }

            return str;
        }
    }
}