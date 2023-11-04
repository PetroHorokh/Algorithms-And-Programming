using System;
using System.Collections.Generic;
using System.IO;

namespace Lab9
{
    interface MAGAZUN_END
    {
        void print_end();
    }

    class MAGAZUN_FUNCTIONS:MAGAZUN_END
    {
        public Client client;
        protected CASA Casa;
        private List<ITEM> All_Items;
        private List<ITEM> Cart;
        private bool general_choise = true;

        public void print_end()
        {
            Console.WriteLine();
            Console.WriteLine("Program end!");
        }

        public MAGAZUN_FUNCTIONS()
        {
            Casa = new CASA();
            All_Items = new List<ITEM> { };
            Cart = new List<ITEM> { };
            load_list();
        }        

        public void add_new_client()
        {
            client = new Client();
        }

        public void print_all_items()
        {
            foreach (ITEM tmp in All_Items) tmp.PrintItem();
        }

        public void look_at_list()
        {
            client.Print_List();
            Console.WriteLine();
        }

        public void find_reguarded()
        {
            foreach (string product in client.List_of_buy)
            {
                foreach (ITEM item in All_Items)
                {
                    if (product == item.code.Name)
                    {
                        Cart.Add(item);

                        break;
                    }
                }
            }
            if (Cart.Count == 0) Console.WriteLine("There were no products as client mentioned");
            Console.WriteLine();
        }

        public void sell()
        {
            Casa.Sell(client, Cart);
        }

        public void load_list()
        {
            int i = 1;
            ITEM tmp;

            while (File.Exists(@"D:\Pete's\Studying\Labs\Lab9\ExpProduct" + i + ".txt"))
            {
                tmp = new ExpITEM();

                tmp.code.download(@"D:\Pete's\Studying\Labs\Lab9\ExpProduct" + i + ".txt");

                if (tmp.code.ExpDays < 0) continue;

                All_Items.Add(tmp);
                i++;
            }
            i = 1;

            while (File.Exists(@"D:\Pete's\Studying\Labs\Lab9\UnexpProduct" + i + ".txt"))
            {
                tmp = new UnexpITEM();

                tmp.code.download(@"D:\Pete's\Studying\Labs\Lab9\UnexpProduct" + i + ".txt");

                All_Items.Add(tmp);
                i++;
            }
        }

        public void create_gift()
        {
            ExpITEM gift = new ExpITEM();

            bool choise = true;

            Console.WriteLine("Choose products to add to gift bundle:");

            foreach (ITEM tmp in All_Items)
            {

                Console.WriteLine(tmp.code.Name);
                Console.WriteLine("Add this product? (Yes/No)");

                while (choise)
                {
                    if (Console.ReadLine() == "Yes" || Console.ReadLine() == "YES" || Console.ReadLine() == "yes")
                    {
                        if (tmp.code.Amount > 0)
                        {
                            gift.code.Name += tmp.code.Name + " ";
                            gift.code.Price += tmp.code.Price;
                            tmp.code.add_to_list();
                            choise = false;
                        }
                        else
                        {
                            Console.WriteLine($"Product {tmp.code.Name} is not in sufficient amount");
                            choise = false;
                        }
                    }
                    else if (Console.ReadLine() == "No" || Console.ReadLine() == "NO" || Console.ReadLine() == "no")
                    {
                        choise = false;
                    }
                    else
                    {
                        Console.WriteLine("Choose corect answer!");
                    }
                }
            }

            gift.code.Amount = 1;
            gift.code.Code = "01100111 01101001 01100110 01110100";
            gift.code.Name += "Gift";
            All_Items.Add(gift);
        }

        public void choose_another_cashier()
        {
            string name;
            int age;

            Console.WriteLine();
            Console.Write("Enter name of cashier:");
            name = Console.ReadLine();

            string tmp;

            Console.Write("Enter age of cashier:");
            if ((tmp = Console.ReadLine()) == "") age = 0;
            else age = Convert.ToInt32(tmp);

            if (name != "" && age == 0)
            {
                Casa = new CASA(name);
            }
            else if (name == "" && age != 0)
            {
                Casa = new CASA(age);
            }
            else if (name != "" && age != 0)
            {
                Casa = new CASA(age, name);
            }
            else
            {
                Casa = new CASA();
            }
        }

        public void reopen_casa()
        {
            CASA tmp = new CASA(Casa);

            Casa = null;

            Casa = new CASA(tmp);

            tmp = null;
        }

        public void Save_results()
        {
            Casa.Save_results();

            Console.WriteLine("Results are saved in file");
        }

        public override string ToString()
        {
            return $"Summerise for current state is: {Casa.Item_sold_get()} items sold and {Casa.Money_got_get()} money got.";
        }

        public void close_shop()
        {
            Save_results();
        }

        public int Client_menu()
        {
            Console.WriteLine("0 - Enter to admin menu");
            Console.WriteLine("1 - Cliet enter;");
            Console.WriteLine("2 - Look at client list;");
            Console.WriteLine("3 - Find reguarded products;");
            Console.WriteLine("4 - Sell products;");

            int choise;

            Console.WriteLine("Your choise: ");

            choise = Convert.ToInt32(Console.ReadLine());

            return choise;
        }

        public int Admin_menu()
        {
            Console.WriteLine("Admin menu:");
            Console.WriteLine("0 - Exit admin menu;");
            Console.WriteLine("1 - Choose another cashier;");
            Console.WriteLine("2 - Create gift bundle of a day;");
            Console.WriteLine("3 - Print current state;");
            Console.WriteLine("4 - Print all items;");
            Console.WriteLine("5 - Reopen casa;");
            Console.WriteLine("6 - Close shop;");

            int choise;

            do
            {
                Console.WriteLine("Your choise, admin: ");
                choise = Convert.ToInt32(Console.ReadLine());
            } while (choise < 0 && choise > 6);

            return choise;
        }

        public void Main_menu()
        {
            int choise = 1;

            choose_another_cashier();

            while (general_choise)
            {
                Console.WriteLine();

                switch (Client_menu())
                {
                    case 0:
                        choise = 1;
                        while (choise != 0)
                        {
                            switch (choise = Admin_menu())
                            {
                                case 0:
                                    choise = 0;

                                    break;
                                case 1:
                                    choose_another_cashier();

                                    break;
                                case 2:
                                    create_gift();

                                    break;
                                case 3:
                                    Console.WriteLine(ToString());

                                    break;
                                case 4:
                                    print_all_items();

                                    break;
                                case 5:
                                    reopen_casa();

                                    break;
                                case 6:
                                    close_shop();
                                    choise = 0;
                                    general_choise = false;

                                    break;
                                default:
                                    Console.WriteLine("Ups! Choose corect oprion");
                                    break;
                            }

                        }

                        break;
                    case 1:
                        print_all_items();
                        client = new Client();
                        Console.WriteLine();

                        break;
                    case 2:
                        look_at_list();

                        break;
                    case 3:
                        find_reguarded();

                        break;
                    case 4:
                        sell();

                        break;
                    default:
                        Console.WriteLine("Ups! Choose corect oprion");

                        break;
                }

            }
        }
    }

    sealed class MAGAZUN
    {
        static void Main(string[] args)
        {
            MAGAZUN_FUNCTIONS Magazun = new MAGAZUN_FUNCTIONS();
            Magazun.Main_menu();
            Magazun.print_end();
        }
    }
}