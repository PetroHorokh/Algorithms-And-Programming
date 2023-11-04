using System;
using System.IO;

namespace Lab8
{
    class SHTRUH_CODE
    {
        public string Code { get; set; }
        public string Name { get; set; }
        public int Price { get; set; }
        public int Amount { get; set; }
        public void add_to_list()
        {
            Amount--;
        }
        public SHTRUH_CODE()
        {
            Code = "";
            Name = "";
            Price = 0;
            Amount = 0;
        }
        public void download(string filename)
        {
            using (StreamReader rl = new StreamReader(filename))
            {
                string line;
                int i = 0;

                while (i < 5)
                {
                    line = rl.ReadLine();
                    i++;
                    switch (i)
                    {
                        case (1):
                            Code = line;

                            break;
                        case (2):
                            Name = line;

                            break;
                        case (3):
                            Price = Convert.ToInt32(line);

                            break;
                        case (4):
                            Amount = Convert.ToInt32(line);

                            break;
                    }
                }
            }
        }
    }
    class ITEM
    {
        public SHTRUH_CODE code;
        public ITEM()
        {
            code = new SHTRUH_CODE();
        }
        public void PrintItem()
        {
            Console.WriteLine("-------------------------");
            Console.WriteLine("Code: " + code.Code);
            Console.WriteLine("Name: " + code.Name);
            Console.WriteLine("Price: " + code.Price);
            Console.WriteLine("Amount: " + code.Amount);
            Console.WriteLine("-------------------------");
        }
    }
}
