using System;
using System.IO;

namespace Lab9
{
    class SHTRUH_CODE
    {
        public string Code { get; set; }
        public string Name { get; set; }
        public int Price { get; set; }
        public int Amount { get; set; }
        public int ExpDays { get; set; }
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
            ExpDays = 0;
        }

        public void download(string filename)
        {
            using (StreamReader rl = new StreamReader(filename))
            {
                string line;
                int i = 0;

                while (i < 6)
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
                        case (6):
                            ExpDays = Convert.ToInt32(line);

                            break;
                    }
                }
            }
        }
    }
    abstract class ITEM
    {
        public SHTRUH_CODE code;

        public ITEM()
        {
            code = new SHTRUH_CODE();
        }
        public abstract void PrintItem();
    }
    class ExpITEM : ITEM
    {
        public ExpITEM() : base() { }

        public override void PrintItem()
        {
            Console.WriteLine(ToString());
        }

        public override string ToString()
        {
            return $"\nCode: {code.Code};\nName: {code.Name};\nPrice: {code.Price};\nExperation date: {code.ExpDays};\nAmount: {code.Amount};\n";
        }
    }
    sealed class UnexpITEM : ITEM
    {
        public UnexpITEM() : base() { }
        public override void PrintItem()
        {
            Console.WriteLine(ToString());
        }
        public override string ToString()
        {
            return $"\nCode: {code.Code};\nName: {code.Name};\nPrice: {code.Price};\nAmount: {code.Amount};\n";
        }
    }
}
