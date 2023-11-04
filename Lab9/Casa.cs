using System;
using System.Collections.Generic;
using System.IO;

namespace Lab9
{
    class CASA
    {
        public string Cashier_Name { get; set; }

        public int Cashier_Age { get; set; }

        public CASA()
        {
            Cashier_Name = "Jane";

            Cashier_Age = 20;
        }

        public CASA(int age)
        {
            Cashier_Name = "Jane";

            Cashier_Age = age;
        }

        public CASA(string name)
        {
            Cashier_Name = name;

            Cashier_Age = 20;
        }

        public CASA(int age, string name)
        {
            Cashier_Name = name;

            Cashier_Age = age;
        }

        public CASA(CASA obj)
        {
            Cashier_Name = obj.Cashier_Name;
            Cashier_Age = obj.Cashier_Age;
        }

        static public int items_sold;

        static public int money_got;

        static public void Item_sell()
        {
            items_sold++;
        }

        static public void Money_sell(int money)
        {
            money_got += money;
        }

        static CASA() { items_sold = 0; money_got = 0; }

        public int Money_got_get()
        {
            return money_got;
        }

        public int Item_sold_get()
        {
            return items_sold;
        }

        public void Sell(Client client, List<ITEM> Cart)
        {
            foreach(ITEM item in Cart)
            {
                if(item.code.Amount>0)
                { 
                Money_sell(item.code.Price);
                item.code.add_to_list();
                Item_sell();
                }
                else 
                {
                    Console.WriteLine($"Product {item.code.Name} is not in sufficient amount" );
                }
            }
            Cart.Clear();
            client = null;
        }

        public void Save_results()
        {
            using (StreamWriter file = new StreamWriter(@"D:\Pete's\Studying\Labs\Lab8\Results.txt"))
            {
                file.WriteLine("Results of the day");
                file.WriteLine($"Item sold: {Item_sold_get().ToString()}");
                file.WriteLine($"Money got: {Money_got_get().ToString()}");
            }
        }
    }
}
